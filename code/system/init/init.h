#ifndef _SYSTEM_INIT_H_
#define _SYSTEM_INIT_H_

#include "imu.h"
#include "motor.h"
#include "servo.h"
#include "key.h"
#include "lcd.h"
#include "attitude.h"
#include "encoder.h"
#include "zf_device_mt9v03x.h"

void system_init(void);

extern motor_obj_t motor_left;
extern motor_obj_t motor_right;
extern servo_obj_t motor_servo;

extern encoder_obj_t encoder_left;
extern encoder_obj_t encoder_right;

#endif