#include <z51.h>

#include "delay.h"
#include "init.h"

#define SPRAY_DELAY_CALIBRATE 10000
void EnableSpray(unsigned char N,unsigned char P,unsigned char K)
{

	unsigned char count=0,CN=0,CP=0,CK=0;
	CannonWater_TT=0;//off
	
	CannonWater_N=1;
	CannonWater_P=1;
	CannonWater_K=1;
/*	
	delay(1000);
	CannonWater_N=0;
	CannonWater_P=0;
	CannonWater_K=0;
*/
	while(!(CN&&CP&&CK))
	{
		delay(SPRAY_DELAY_CALIBRATE);
		if(count==N)
		{
			CannonWater_N=0;
			CN=1;
		}
		 if(count==P)
		{
			CannonWater_P=0;
			CP=1;
		}
		 if(count==K)
		{
			CannonWater_K=0;
			CK=1;
		}		
		count++;	
	}
	
	delay(20000);
	CannonWater_TT=1;
	delay(50000);
	CannonWater_TT=0;
}
