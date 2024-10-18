//WYB Motor Library
//pid.h
//Created by WYB
#define PID_Increasement_DT volatile struct PID_Increasement_data
struct PID_Increasement_data
{
	float kp,ki,kd;
	float error1;
	float error2;
	float out_last;
};
float PID_Increasement(PID_Increasement_DT *pid,float current,float target);
