#include <z51.h>

#include "queue.h"
#include "delay.h"
#include "init.h"
#include "drill.h"
#include "pwm.h"

ZQUEUE qSerial;

void Serial_ISR()	interrupt 4
{
	if(RI)
	{
		RI=0;
		QueueInsert(&qSerial,SBUF);
	}
}

int main()
{
	PortInit();
	SerialInit();
	QueueInit(&qSerial);
	EnableSerialISR();
	MotorDirInit();
	PWMInit();
	
	delay(1000);

	while(1)
	{
		if(!QueueIsEmpty(&qSerial))
		{
			unsigned char stmp=0;
			QueueDelete(&qSerial,&stmp);
			SBUF=stmp;
			
			/*
			process
			structure bit
			7				6		5		4		3		2		1		0
			(RUN|DRILL)		(N\A)	(L1)	(L2)	(L3)	(R1)	(R2)	(R3)
			*/
			
			
			if(stmp==191)//streight
			{
				SetMotorPWM(255,255);
			}
			else if(stmp==184)
			{
				SetMotorPWM(255,0);
			}
			else if(stmp==135)
			{
				SetMotorPWM(0,255);
			}
			else if(stmp==0x3F)//0b00111111drill
			{
				SetMotorPWM(0,0);
				
				/* spray here!!!!
				while(QueueIsEmpty(&qSerial));
				
				*/
				
				DisableSerialISR();
				
				Rotate_Saws(12);
				PunchDOWN();
				delay(5000);
				PunchUP();
				
				QueueInit(&qSerial);
				EnableSerialISR();
			}
			else//stop
			{
				SetMotorPWM(0,0);
			}
			/*
			if(stmp&bit7)
			{
				unsigned char lduty,rduty;
				lduty=(stmp&0x07)<<5;//0b00000111
				rduty=(stmp&0x38)<<2;//0b00111000
				//lduty=lduty|0x1F;
				//rduty=rduty|0x1F;
				lduty=0xFF-lduty;
				rduty=0xFF-rduty;
				CCAP0H=lduty;
				CCAP1H=lduty;
				CCAP2H=rduty;
				CCAP3H=rduty;
			}
			*/
		}
	}	
	return 0;
}


