//WYB Motor Library
//motor.h
//Created by WYB
#define SPEED_MODE 1//速度PID模式
#define ANGLE_MODE 2//角度PID模式
#define NOPID_MODE 3//不使用PID，直接输出PWM
#define Motor_HandleTypeDef struct Motor
#define Motor_Mode uint8_t
#include "tim.h"
#include "pid.h"
#include "const.h"//定义常量
struct Motor{
	float speed,angle,targetspeed,targetangle;//当前速度,当前角度,目标速度,目标角度
	TIM_HandleTypeDef *encoder;//编码器
	//PWM输出
	TIM_HandleTypeDef *pwm1;uint32_t pwm1_channel;
	TIM_HandleTypeDef *pwm2;uint32_t pwm2_channel;
	//PID参数/变量
	PID_Increasement_DT *pid_angle;
	PID_Increasement_DT *pid_speed;
	//马达模式 SPEED_MODE ANGLE_MODE NOPID_MODE
	uint8_t MODE;
	MOTOR_ADDITIONAL_DATA//额外参数,在宏定义内添加
};

void Motor_SetSpeed(Motor_HandleTypeDef *motor,float speed);//速度设定( SPEED_MODE)
void Motor_SetAngle(Motor_HandleTypeDef *motor,float angle);//角度设定( ANGLE_MODE)
void Motor_SetMode(Motor_HandleTypeDef *motor,Motor_Mode mode);//模式设定
void Motor_TIM_IRQWorker(Motor_HandleTypeDef *motor);//中断代码
void Motor_Init(Motor_HandleTypeDef *motor);//初始化，启动马达
void Motor_DeInit(Motor_HandleTypeDef *motor);//stop马达
void _Motor_SetSpeed(Motor_HandleTypeDef *motor,int16_t speed);//设定PWM
