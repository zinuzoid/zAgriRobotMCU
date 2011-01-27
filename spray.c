#include <z51.h>

#include "delay.h"
#include "init.h"

#define SPRAY_DELAY_CALIBRATE 100
void EnableSpray(unsigned char N,unsigned char P,unsigned char K)
{

	unsigned char count=0,CN=0,CP=0,CK=0;
	CannonWater_TT=1;//off
	
	CannonWater_N=1;
	CannonWater_P=1;
	CannonWater_K=1;
	while(!(CN&&CP&&CK))
	{
		delay(SPRAY_DELAY_CALIBRATE);
		count++;
		if(count==N)
		{
			CannonWater_N=0;
			CN=1;
		}
		else if(count==P)
		{
			CannonWater_P=0;
			CP=1;
		}
		else if(count==K)
		{
			CannonWater_K=0;
			CK=1;
		}			
	}
	CannonWater_TT=0;
	delay(2000);
	CannonWater_TT=167;
}
