#ifndef _CONTROL_PID_CONTROL_H_
#define _CONTROL_PID_CONTROL_H_

#include "zf_common_typedef.h"
#include "encoder.h"

float pid_turn_control(float target_yaw);
float pid_vel_control(encoder_obj_t *obj_l, encoder_obj_t *obj_r, float target_vel);

#endif