#include "motor_undir.h"

motor_undir_obj_t motor_undir_init(pwm_channel_enum pwm_pin, vuint32 freq, vuint32 deadzone)
{
    motor_undir_obj_t motor;

    motor.pwm_pin = pwm_pin;
    motor.freq = freq;
    motor.deadzone = deadzone;

    pwm_init(motor.pwm_pin, motor.freq, 0); // 初始化PWM，默认占空比为0
    motor.status = 1;
    return motor;
}

void motor_undir_set_pwm(motor_undir_obj_t *motor, vint32 duty)
{
    if (motor->status == 0) // 未初始化
    {
        return;
    }

    if (duty != 0)
    {
        duty += motor->deadzone;
    }

    CLAMP(duty, 9999);

    pwm_set_duty(motor->pwm_pin, duty);
}