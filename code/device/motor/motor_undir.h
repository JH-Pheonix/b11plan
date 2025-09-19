#ifndef _DEVICE_MOTOR_UNDIR_H_
#define _DEVICE_MOTOR_UNDIR_H_

#include "zf_driver_pwm.h"
#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"
#include "common.h"

typedef struct
{
    pwm_channel_enum pwm_pin;
    vuint32 freq;
    vuint8 status;
    vuint32 deadzone;
} motor_undir_obj_t;

motor_undir_obj_t motor_undir_init(pwm_channel_enum pwm_pin, vuint32 freq, vuint32 deadzone);
void motor_undir_set_pwm(motor_undir_obj_t *motor, vint32 duty);

#endif