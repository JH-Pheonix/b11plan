#ifndef _DEVICE_IMU_H_
#define _DEVICE_IMU_H_

#include "zf_device_imu660rb.h"
#include "zf_device_imu660ra.h"
#include "zf_device_imu963ra.h"

#define gyroscope_threshold 5

typedef enum
{
    IMU_DEVICE_660RA,
    IMU_DEVICE_660RB,
    IMU_DEVICE_963RA,
    IMU_DEVICE_ADIS16505,
} imu_device_enum;

typedef struct
{
    float accel_x, accel_y, accel_z; // 加速度 (m/s²)
    float gyro_x, gyro_y, gyro_z;    // 角速度 (°/s)
} imu_data_t;

#ifdef __cplusplus
extern "C"
{
#endif
    void imu_init(imu_device_enum device);
    imu_data_t imu_get_data(void);
    void imu_remove_offset(imu_data_t *data);
    void imu_init_offset(void);
    imu_data_t imu_get_tmp_data();
    void imu_rotate(imu_data_t *data);
#ifdef __cplusplus
}
#endif

#endif