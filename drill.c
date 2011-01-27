#include <z51.h>

#include "delay.h"
#include "init.h"

void Rotate_Saws(unsigned char saw_count)
{
	unsigned char count=0;
	
	SawDir=0;
	SawEncoder=1;
	
	if(DrillContactUP==1)
	{
		SawPWM=1;
		while(count!=saw_count)
		{
			if(SawEncoder==1)
			{
				count++;
				while(SawEncoder);
				delay(100);
			}
		}
		SawPWM=0;
	}
}

void PunchDOWN()
{
	DrillContactDOWN=1;
	
	PunchDir=0;		
 	PunchPWM=1;
	while(!DrillContactDOWN);
	PunchPWM=0;
	
}

void PunchUP()
{
	DrillContactUP=1;
	
	PunchDir=1;	
 	PunchPWM=1;
	while(!DrillContactUP);
	delay(22300);
	PunchPWM=0;
}