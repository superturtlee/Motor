#define TIME_MUL 100 //1000/10=100
#define MOTOR_LIMIT1 230//���PWM
#define MOTOR_LIMIT2 25//����
#define MOTOR_BASIC_SPEED 120
#define Tslowdown_rate 30//must ���ٱ�
#define Thall 11//must ����������
#define ERRM 10//�ɺ��ԽǶ�����С
#define PID_ANGLE {3,0.0,0.05}//�Ƕ�PID����
#define PID_SPEED {7,0.15,0.02}//�ٶ�PID����
#define PWM_A htim3
#define PWM_B htim3
#define PWM_A_CHANNEL TIM_CHANNEL_1
#define PWM_B_CHANNEL TIM_CHANNEL_2
#define ENCODER htim2
#define WORKING_MODE ANGLE_MODE
#define MOTOR_ADDITIONAL_DATA //����motor�ṹ���ж�����Ҫ���� �� float a;uint16_t b;

/*
��ͬ�ͺ����������
#define TIME_MUL 100 //1000/10=100
#define MOTOR_LIMIT1 230//���PWM
#define MOTOR_LIMIT2 25//����
#define MOTOR_BASIC_SPEED 120
#define Tslowdown_rate motor->slowdownrate//must ���ٱ�
#define Thall motor->accu//must ����������
#define ERRM 10//�ɺ��ԽǶ�����С
#define PID_ANGLE {3,0.0,0.05}//�Ƕ�PID����
#define PID_SPEED {7,0.15,0.02}//�ٶ�PID����
#define PWM_A htim3
#define PWM_B htim3
#define PWM_A_CHANNEL TIM_CHANNEL_1
#define PWM_B_CHANNEL TIM_CHANNEL_2
#define ENCODER htim2
#define WORKING_MODE ANGLE_MODE
#define MOTOR_ADDITIONAL_DATA int slowdownrate;int accu;
*/