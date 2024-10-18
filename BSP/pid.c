//WYB Motor Library
//pid.h
//Created by WYB
#include "pid.h"
inline float PID_Increasement(PID_Increasement_DT *pid,float current,float target){//ÔöÁ¿PID
	float err=target-current;float out;
	out=pid->out_last+
	      pid->kp*(err-pid->error1)+//P
	      pid->ki*err+//I
	      pid->kd*(err+pid->error2-2*pid->error1);//D
	pid->error2=pid->error1;
	pid->error1=err;
	pid->out_last=out;
	return out;
}
