//WYB Motor Library
//motor.c
//Created by WYB
#include "motor.h"
void Motor_SetSpeed(Motor_HandleTypeDef *motor,float speed){
	motor->targetspeed=speed;
}
void Motor_SetAngle(Motor_HandleTypeDef *motor,float angle){
	motor->targetangle=angle;
}
void Motor_SetMode(Motor_HandleTypeDef *motor,Motor_Mode mode){
	motor->MODE=mode;
}
void _Motor_SetSpeed(Motor_HandleTypeDef *motor,int16_t speed)
{
	if(speed>0){
		__HAL_TIM_SET_COMPARE(motor->pwm1,motor->pwm1_channel,speed);
		__HAL_TIM_SET_COMPARE(motor->pwm2,motor->pwm2_channel,0);
	}else{
		__HAL_TIM_SET_COMPARE(motor->pwm1,motor->pwm1_channel,0);
		__HAL_TIM_SET_COMPARE(motor->pwm2,motor->pwm2_channel,-speed);
	}
}

void Motor_TIM_IRQWorker(Motor_HandleTypeDef *motor){
	uint16_t tmpA=__HAL_TIM_GetCounter(motor->encoder);
	//�ٶȻ�ȡ
	motor->speed=(tmpA-32768)*60*TIME_MUL/(4*Tslowdown_rate*Thall);
	//NOPIDģʽ
	if(motor->MODE==NOPID_MODE) {_Motor_SetSpeed(motor,motor->targetspeed);__HAL_TIM_SetCounter(motor->encoder,32768);return;}
	//�Ƕ�ģʽ
	if(motor->MODE==ANGLE_MODE){
		//�ٶȻ�ȡ
		motor->angle+=(tmpA-32768)*360/(4*Tslowdown_rate*Thall);//caculate angle
		motor->targetspeed=PID_Increasement(motor->pid_angle,motor->angle,motor->targetangle);
		//����360������
		if(motor->pid_angle->error1>360)
			motor->targetspeed=MOTOR_BASIC_SPEED;
		if(motor->pid_angle->error1<-360)
			motor->targetspeed=-MOTOR_BASIC_SPEED;
		//���Կɺ������
		if(motor->pid_angle->error1<=ERRM&&motor->pid_angle->error1>=-ERRM){motor->targetspeed=0;}
	}
	//��ʱ�����㣬Ϊ��֤�и�����Ϊ32768
	__HAL_TIM_SetCounter(motor->encoder,32768);
	int16_t setspeed;
	setspeed=PID_Increasement(motor->pid_speed,motor->speed,motor->targetspeed);
	//����ٶȿ���
	if(setspeed>MOTOR_LIMIT1)setspeed=MOTOR_LIMIT1;
	if(setspeed<-MOTOR_LIMIT1)setspeed=-MOTOR_LIMIT1;
	//��������
	if(setspeed>MOTOR_LIMIT2||setspeed<-MOTOR_LIMIT2){_Motor_SetSpeed(motor,setspeed);return;};
	//�������ٶ�ֱ��Ϊ0
	_Motor_SetSpeed(motor,0);
}
void Motor_Init(Motor_HandleTypeDef *motor){
	HAL_TIM_Encoder_Start(motor->encoder,TIM_CHANNEL_ALL);
	HAL_TIM_Base_Start_IT(motor->encoder);
	__HAL_TIM_SetCounter(motor->encoder,32768);//��ʱ�����㣬Ϊ��֤�и�����Ϊ32768
	HAL_TIM_PWM_Start(motor->pwm1,motor->pwm1_channel);
	HAL_TIM_PWM_Start(motor->pwm2,motor->pwm2_channel);
}
void Motor_DeInit(Motor_HandleTypeDef *motor){
	HAL_TIM_Encoder_Stop(motor->encoder,TIM_CHANNEL_ALL);
	HAL_TIM_Base_Stop_IT(motor->encoder);
	__HAL_TIM_SetCounter(motor->encoder,32768);//��ʱ�����㣬Ϊ��֤�и�����Ϊ32768
	HAL_TIM_PWM_Stop(motor->pwm1,motor->pwm1_channel);
	HAL_TIM_PWM_Stop(motor->pwm2,motor->pwm2_channel);
}
