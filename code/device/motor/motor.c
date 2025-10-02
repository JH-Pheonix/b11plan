#include "motor.h"
#include "common.h"

motor_obj_t motor_init(pwm_channel_enum pwm_pin, gpio_pin_enum dir_pin, vuint32 freq, vuint32 deadzone, vint8 dir)
{
    motor_obj_t motor;

    motor.pwm_pin = pwm_pin;
    motor.dir_pin = dir_pin;
    motor.freq = freq;
    motor.deadzone = deadzone;
    motor.dir = dir;

    pwm_init(motor.pwm_pin, motor.freq, 0);          // 初始化PWM，默认占空比为0
    gpio_init(motor.dir_pin, GPO, 1, GPO_PUSH_PULL); // 初始化方向引脚，默认输出低电平
    motor.status = 1;
    return motor;
}

void motor_set_pwm(motor_obj_t *motor, vint32 duty)
{
    duty *= motor->dir;
    if (motor->status == 0) // 未初始化
    {
        return;
    }
    if (duty != 0)
    {
        duty += (duty > 0) ? motor->deadzone : -motor->deadzone;
    }

    CLAMP_ABS(duty, 9999);

    if (duty >= 0)
    {
        gpio_set_level(motor->dir_pin, 0);
        pwm_set_duty(motor->pwm_pin, duty);
    }
    else
    {
        gpio_set_level(motor->dir_pin, 1);
        pwm_set_duty(motor->pwm_pin, -duty);
    }
}