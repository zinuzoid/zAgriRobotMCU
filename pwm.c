
#include "init.h"

void SetMotorPWM(unsigned char L,unsigned char R)
{
	DUTYFL=0xFF-L;
	DUTYBL=0xFF-L;
	DUTYFR=0xFF-R;
	DUTYBR=0xFF-R;
}