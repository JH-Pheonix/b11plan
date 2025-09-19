#include "pid_control.h"
#include "attitude.h"
#include "pid.h"
#include "encoder.h"
#include "imu.h"

pid_type_def pid_yaw;
pid_type_def pid_zvel;
pid_type_def pid_vel;

float pid_yaw_params[3] = {8.0, 0.0f, 0.0f};
float pid_zvel_params[3] = {200.0f, 0.0f, 0.0f};
float pid_vel_params[3] = {1.0f, 0.0f, 0.0f};

void pid_control_init(void)
{
    pid_init(&pid_yaw, pid_yaw_params, 9999, 9999);
    pid_init(&pid_zvel, pid_zvel_params, 9999, 9999);
    pid_init(&pid_vel, pid_vel_params, 9999, 9999);
}

float pid_turn_control(float target_yaw)
{
    static uint16 cnt = 0;
    float turn_diff = 0.0f;

    cnt++;

    // 角度环
    static float target_zvel;
    if (cnt % pid_yaw.cycle == 0)
    {
        float curr_yaw = attitude_get_yaw();
        target_zvel = pid_position(&pid_yaw, curr_yaw, target_yaw);
    }

    // 角速度环
    if (cnt % pid_zvel.cycle == 0)
    {
        float curr_zvel = imu_get_tmp_data().gyro_z;
        turn_diff = pid_position(&pid_zvel, curr_zvel, target_zvel);
    }

    if (cnt % pid_zvel.cycle == 0 && cnt % pid_yaw.cycle == 0)
    {
        cnt = 0;
    }

    return turn_diff;
}

float pid_vel_control(encoder_obj_t *obj_l, encoder_obj_t *obj_r, float target_vel)
{
    static uint32 cnt = 0;
    float vel = 0.0f;

    if (cnt % pid_vel.cycle == 0)
    {
        float curr_vel = encoder_get_data(obj_l) + encoder_get_data(obj_r);
        vel = pid_position(&pid_vel, curr_vel, target_vel);
    }

    return vel;
}