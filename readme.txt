虽然只是要求驱动一个马达，但是这些代码不只是为了作业，更是要自己做个四驱小车，需要驱动多个马达，就设计了个马达驱动库，可以驱动多个同型号马达
驱动多个不同型号马达也可以只需改下const.h(宏定义实现(为提高性能)，未测试)

已在JGB37-520电机上测试
编码器精度11
减速比20
12V333RPM

实现函数
   motor.c:
	void Motor_SetSpeed(Motor_HandleTypeDef *motor,float speed);//速度设定( SPEED_MODE)
	void Motor_SetAngle(Motor_HandleTypeDef *motor,float angle);//角度设定( ANGLE_MODE)
	void Motor_SetMode(Motor_HandleTypeDef *motor,Motor_Mode mode);//模式设定
	void Motor_TIM_IRQWorker(Motor_HandleTypeDef *motor);//中断代码
	void Motor_Init(Motor_HandleTypeDef *motor);//初始化，启动马达
	void Motor_DeInit(Motor_HandleTypeDef *motor);//stop马达
	void Motor__SetSpeed(Motor_HandleTypeDef *motor,int16_t speed);//设定PWM

   main.c:(调用motor.c中函数实现)
	void MotorStart()
	void MotorStop()
	void MotorSetSpeed(flaot speed)
	void MotorSetAngle(float angle)
	void MotorSetMode(float MODE)

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
};


MOTOR(工程文件夹)
│  .mxproject
│  Motor.ioc
│  
├─BSP
│      const.h(定义常量，方便调试)
│      motor.c(马达控制库)
│      motor.h(马达控制库头文件)
│      pid.c(PID库)
│      pid.h(PID库)
│      
├─Core
│  ├─Inc
│  │      gpio.h
│  │      main.h(主程序)
│  │      stm32f1xx_hal_conf.h
│  │      stm32f1xx_it.h
│  │      tim.h
│  │      usart.h
│  │      
│  └─Src
│          gpio.c
│          main.c
│          stm32f1xx_hal_msp.c
│          stm32f1xx_it.c
│          system_stm32f1xx.c
│          tim.c
│          usart.c
│          
├─Drivers
│  ├─CMSIS
│  │  │  LICENSE.txt
│  │  │  
│  │  ├─Device
│  │  │  └─ST
│  │  │      └─STM32F1xx
│  │  │          │  LICENSE.txt
│  │  │          │  
│  │  │          ├─Include
│  │  │          │      ..................
│  │  │          │      
│  │  │          └─Source
│  │  │              └─Templates
│  │  └─Include
│  │        ..............
│  │          
│  └─STM32F1xx_HAL_Driver
│      │  LICENSE.txt
│      │  
│      ├─Inc
│      │  │  ....................
│      │  │  
│      │  └─Legacy
│      │          .....................
│      │          
│      └─Src
│              .....................................
│              
└─MDK-ARM
    │  Motor.uvguix.Administrator
    │  Motor.uvoptx
    │  Motor.uvprojx
    │  .................
    │  
    ├─DebugConfig
    │      ......................
    │      
    ├─Motor
    │      .............
    │      
    └─RTE
        └─_Motor
                RTE_Components.h

