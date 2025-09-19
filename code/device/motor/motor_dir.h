#ifndef _DEVICE_MOTOR_DIR_H_
#define _DEVICE_MOTOR_DIR_H_

#include "zf_driver_pwm.h"
#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"

typedef struct
{
    pwm_channel_enum pwm_pin;
    gpio_pin_enum dir_pin;
    vuint32 freq;
    vuint8 status;
    vuint32 deadzone;
    vint8 dir; // 1正转 -1反转
} motor_dir_obj_t;

motor_dir_obj_t motor_dir_init(pwm_channel_enum pwm_pin, gpio_pin_enum dir_pin, vuint32 freq, vuint32 deadzone, vint8 dir);
void motor_dir_set_pwm(motor_dir_obj_t *motor, vint32 duty);

#endif