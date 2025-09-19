#ifndef Mahony_ATTITUDE_H
#define Mahony_ATTITUDE_H

#include "zf_common_typedef.h"

typedef struct
{
    float roll;
    float pitch;
    float yaw;
} euler_angle_t;

typedef enum
{
    ATTITUDE_EKF,
    ATTITUDE_MADGWICK,
    ATTITUDE_MAHONY
} Attitude_algorithm;

void attitude_init(Attitude_algorithm algo);
void attitude_cal();
float attitude_get_yaw();
float attitude_get_pitch();
float attitude_get_roll();

extern euler_angle_t g_euler_angle;
extern euler_angle_t g_euler_angle_bias;

#endif
