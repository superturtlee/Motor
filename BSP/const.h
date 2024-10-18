#define TIME_MUL 100 //1000/10=100
#define MOTOR_LIMIT1 230//最大PWM
#define MOTOR_LIMIT2 25//死区
#define MOTOR_BASIC_SPEED 120
#define Tslowdown_rate 30//must 减速比
#define Thall 11//must 编码器精度
#define ERRM 10//可忽略角度误差大小
#define PID_ANGLE {3,0.0,0.05}//角度PID参数
#define PID_SPEED {7,0.15,0.02}//速度PID参数
#define PWM_A htim3
#define PWM_B htim3
#define PWM_A_CHANNEL TIM_CHANNEL_1
#define PWM_B_CHANNEL TIM_CHANNEL_2
#define ENCODER htim2
#define WORKING_MODE ANGLE_MODE
#define MOTOR_ADDITIONAL_DATA //定义motor结构体中额外需要变量 如 float a;uint16_t b;

/*
不同型号马达驱动：
#define TIME_MUL 100 //1000/10=100
#define MOTOR_LIMIT1 230//最大PWM
#define MOTOR_LIMIT2 25//死区
#define MOTOR_BASIC_SPEED 120
#define Tslowdown_rate motor->slowdownrate//must 减速比
#define Thall motor->accu//must 编码器精度
#define ERRM 10//可忽略角度误差大小
#define PID_ANGLE {3,0.0,0.05}//角度PID参数
#define PID_SPEED {7,0.15,0.02}//速度PID参数
#define PWM_A htim3
#define PWM_B htim3
#define PWM_A_CHANNEL TIM_CHANNEL_1
#define PWM_B_CHANNEL TIM_CHANNEL_2
#define ENCODER htim2
#define WORKING_MODE ANGLE_MODE
#define MOTOR_ADDITIONAL_DATA int slowdownrate;int accu;
*/