#ifndef _ALGO_PID_H_
#define _ALGO_PID_H_

#include "zf_common_typedef.h"

typedef struct
{
    // PID 三参数
    float Kp;
    float Ki;
    float Kd;

    float max_out;  // 最大输出
    float max_iout; // 最大积分输出

    float set;
    float fdb;

    float out;
    float Pout;
    float Iout;
    float Dout;
    float Dbuf[3];  // 微分项 0最新 1上一次 2上上次
    float error[3]; // 误差项 0最新 1上一次 2上上次
    uint8 cycle;
} pid_type_def;

void pid_init(pid_type_def *pid,
              const float PID[3],
              float max_out,
              float max_iout);
float pid_position(pid_type_def *pid, float ref, float set);
float pid_delta(pid_type_def *pid, float ref, float set);
void pid_clear(pid_type_def *pid);

#endif