#include "init.h"

#define PIT_KEY_T 10
#define PIT_ATTITUDE_T 2
#define PIT_CONTROL_T 10

motor_obj_t motor_left;
motor_obj_t motor_right;
servo_obj_t motor_servo;

encoder_obj_t encoder_left;
encoder_obj_t encoder_right;

void system_init(void)
{

    lcd_init();

    motor_left = motor_init(ATOM0_CH0_P22_1, P22_0, 10000, 500, -1);
    motor_right = motor_init(ATOM0_CH4_P22_3, P22_2, 10000, 500, 1);

    motor_servo = servo_init(ATOM2_CH4_P33_12, 50, 0, 0.5, 2.5, 180);

    // imu_init(IMU_DEVICE_963RA);
    // attitude_init(ATTITUDE_EKF);

    // pit_ms_init(CCU60_CH1, PIT_ATTITUDE_T);
    // pit_enable(CCU60_CH1);

    encoder_left = encoder_init(TIM5_ENCODER, TIM5_ENCODER_CH1_P10_3, TIM5_ENCODER_CH2_P10_1);
    encoder_right = encoder_init(TIM2_ENCODER, TIM2_ENCODER_CH1_P33_7, TIM2_ENCODER_CH2_P33_6);

    // mt9v03x_init();
    servo_set_angle(&motor_servo, 90);
    motor_set_pwm(&motor_left, 1000);
    motor_set_pwm(&motor_right, 1000);
    // key_init_rewrite(KEY_NUM); // 初始化按键
    // pit_ms_init(CCU60_CH0, PIT_KEY_T);
    // pit_enable(CCU60_CH0);

    // control_init();
    // pit_ms_init(CCU61_CH0, PIT_CONTROL_T);
    // pit_enable(CCU61_CH0);
}