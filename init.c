#include <z51.h>

#include "init.h"

void PortInit()
{
	P0=0x00;
	P1=0x78;
	P2=0x00;
	
  	DrillContactUP=1;
	DrillContactDOWN=1;
	SawEncoder=1;
}

void SerialInit()
{	
	SCON=0x50;
	SMOD=0x00;
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
	RI=0;
	TI=0;
}

void EnableSerialISR()
{
	IE=0x90;
}

void DisableSerialISR()
{
	IE=0x00;
}

void PWMInit()
{
	CMOD=0x02;//clk/6//18k
	CCON=0x40;//run
	
	CCAPM0=0x42;//en pwm
	CCAPM1=0x42;
	CCAPM2=0x42;
	CCAPM3=0x42;
	
	CCAP0H=0xFF;
	CCAP1H=0xFF;
	CCAP2H=0xFF;
	CCAP3H=0xFF;
}

void MotorDirInit()
{
	MotorFRDir=1;
	MotorFLDir=1;
	MotorBLDir=1;
	MotorBRDir=1;
}

