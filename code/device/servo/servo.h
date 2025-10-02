#ifndef _DEVICE_SERVO_H_
#define _DEVICE_SERVO_H_

#include "zf_common_typedef.h"
#include "zf_driver_pwm.h"
#include "common.h"

typedef struct
{
    pwm_channel_enum pin;
    vint32 max_duty;
    vint32 min_duty;
    float max_angle;
} servo_obj_t;

servo_obj_t servo_init(pwm_channel_enum pin, vuint32 freq, vuint32 duty, float min_pulse, float max_pulse, float max_angle);
void servo_set_angle(servo_obj_t *obj, float angle);

#endif