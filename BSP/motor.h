//WYB Motor Library
//motor.h
//Created by WYB
#define SPEED_MODE 1//�ٶ�PIDģʽ
#define ANGLE_MODE 2//�Ƕ�PIDģʽ
#define NOPID_MODE 3//��ʹ��PID��ֱ�����PWM
#define Motor_HandleTypeDef struct Motor
#define Motor_Mode uint8_t
#include "tim.h"
#include "pid.h"
#include "const.h"//���峣��
struct Motor{
	float speed,angle,targetspeed,targetangle;//��ǰ�ٶ�,��ǰ�Ƕ�,Ŀ���ٶ�,Ŀ��Ƕ�
	TIM_HandleTypeDef *encoder;//������
	//PWM���
	TIM_HandleTypeDef *pwm1;uint32_t pwm1_channel;
	TIM_HandleTypeDef *pwm2;uint32_t pwm2_channel;
	//PID����/����
	PID_Increasement_DT *pid_angle;
	PID_Increasement_DT *pid_speed;
	//���ģʽ SPEED_MODE ANGLE_MODE NOPID_MODE
	uint8_t MODE;
	MOTOR_ADDITIONAL_DATA//�������,�ں궨�������
};

void Motor_SetSpeed(Motor_HandleTypeDef *motor,float speed);//�ٶ��趨( SPEED_MODE)
void Motor_SetAngle(Motor_HandleTypeDef *motor,float angle);//�Ƕ��趨( ANGLE_MODE)
void Motor_SetMode(Motor_HandleTypeDef *motor,Motor_Mode mode);//ģʽ�趨
void Motor_TIM_IRQWorker(Motor_HandleTypeDef *motor);//�жϴ���
void Motor_Init(Motor_HandleTypeDef *motor);//��ʼ�����������
void Motor_DeInit(Motor_HandleTypeDef *motor);//stop���
void _Motor_SetSpeed(Motor_HandleTypeDef *motor,int16_t speed);//�趨PWM
