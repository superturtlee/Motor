WYB Motor Library
马达驱动库，可以驱动多个同型号马达
驱动多个不同型号马达也可以只需改下const.h(宏定义实现(为提高性能)，未测试)

实现函数
   motor.c:
	void Motor_SetSpeed(Motor_HandleTypeDef *motor,float speed);//速度设定( SPEED_MODE)
	void Motor_SetAngle(Motor_HandleTypeDef *motor,float angle);//角度设定( ANGLE_MODE)
	void Motor_SetMode(Motor_HandleTypeDef *motor,Motor_Mode mode);//模式设定
	void Motor_TIM_IRQWorker(Motor_HandleTypeDef *motor);//中断代码
	void Motor_Init(Motor_HandleTypeDef *motor);//初始化，启动马达
	void Motor_DeInit(Motor_HandleTypeDef *motor);//stop马达
	void Motor__SetSpeed(Motor_HandleTypeDef *motor,int16_t speed);//设定PWM


定义结构体
Motor_HandleTypeDef{
	float speed;
	float angle;
	float targetspeed;
	float targetangle;
	TIM_HandleTypeDef *encoder;
	TIM_HandleTypeDef *pwm1;
	uint32_t pwm1_channel;
	TIM_HandleTypeDef *pwm2;
	uint32_t pwm2_channel;
	PID_Increasement_DT *pid_angle;
	PID_Increasement_DT *pid_speed;
	uint8_t MODE;
	MOTOR_ADDITIONAL_DATA//const中补充 
};