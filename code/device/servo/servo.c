#include "servo.h"
#include "servo.h"

servo_obj_t servo_init(pwm_channel_enum pin, vuint32 freq, vuint32 duty, float min_pulse, float max_pulse, float max_angle)
{
    // min_pulse, max_pulse (ms)
    servo_obj_t obj;

    obj.pin = pin;

    obj.min_duty = (vuint32)(min_pulse / (1000.0f / freq) * PWM_DUTY_MAX); // 计算最小占空比
    obj.max_duty = (vuint32)(max_pulse / (1000.0f / freq) * PWM_DUTY_MAX);
    obj.max_angle = max_angle;

    pwm_init(pin, freq, duty);

    return obj;
}

void servo_set_angle(servo_obj_t *obj, float angle)
{
    float duty;

    if (angle > obj->max_angle)
        angle = (obj->max_angle);

    // max_duty 对应 max_angle
    // min_duty 对应 0
    duty = (float)obj->min_duty + ((float)obj->max_duty - (float)obj->min_duty) * (angle / obj->max_angle);

    pwm_set_duty(obj->pin, duty);
}

void servo_set_duty(servo_obj_t *obj, vuint32 duty)
{
    CLAMP(duty, obj->min_duty, obj->max_duty);

    pwm_set_duty(obj->pin, duty);
}