#include "attitude.h"
#include "QuaternionEKF.h"
#include "Madgwick.h"
#include "Mahony.h"

euler_angle_t g_euler_angle;
euler_angle_t g_euler_angle_bias;

static Attitude_algorithm current_algorithm;

void attitude_init(Attitude_algorithm algo)
{
    current_algorithm = algo;
    imu_data_t data = imu_get_data(); // 获取一个初始的acc信息加速收敛
    switch (current_algorithm)
    {
    case ATTITUDE_EKF:
        IMU_QuaternionEKF_Init(10, 0.001, 10000000, 1, 0.002f, 0);
        break;
    case ATTITUDE_MADGWICK:
        MadgwickAHRS_init();
        break;
    case ATTITUDE_MAHONY:
        MahonyAHRS_init();

        MahonyAHRS_calibrate(data);
        break;
    default:
        MahonyAHRS_init();
        MahonyAHRS_calibrate(data);
        break;
    }

    imu_init_offset(); // 初始化零飘
}

void attitude_cal()
{
    imu_data_t data = imu_get_data();
    imu_remove_offset(&data);

    switch (current_algorithm)
    {
    case ATTITUDE_EKF:
        IMU_QuaternionEKF_Update(data);
        break;
    case ATTITUDE_MADGWICK:
        MadgwickAHRS_update(data);
        break;
    case ATTITUDE_MAHONY:
        MahonyAHRS_update(data);
        break;
    default:
        MahonyAHRS_update(data);
        break;
    }

    switch (current_algorithm)
    {
    case ATTITUDE_EKF:
        g_euler_angle.roll = EKF_get_roll();
        g_euler_angle.pitch = EKF_get_pitch();
        g_euler_angle.yaw = EKF_get_yaw();
        break;
    case ATTITUDE_MADGWICK:
        g_euler_angle.roll = MadgwickAHRS_get_roll();
        g_euler_angle.pitch = MadgwickAHRS_get_pitch();
        g_euler_angle.yaw = MadgwickAHRS_get_yaw();
        break;
    case ATTITUDE_MAHONY:
        g_euler_angle.roll = MahonyAHRS_get_roll();
        g_euler_angle.pitch = MahonyAHRS_get_pitch();
        g_euler_angle.yaw = MahonyAHRS_get_yaw();
        break;
    default:
        g_euler_angle.roll = EKF_get_roll();
        g_euler_angle.pitch = EKF_get_pitch();
        g_euler_angle.yaw = EKF_get_yaw();
        break;
    }

    // g_euler_angle.yaw = 360.0f - g_euler_angle.yaw; // 0~360
    // g_euler_angle.yaw > 360 ? (g_euler_angle.yaw -= 360)
    //                         : g_euler_angle.yaw; // 0~360
}

float attitude_get_yaw()
{
    return g_euler_angle.yaw;
}

float attitude_get_pitch()
{
    return g_euler_angle.pitch;
}

float attitude_get_roll()
{
    return g_euler_angle.roll;
}