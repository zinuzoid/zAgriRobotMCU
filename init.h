#include <z51.h>

/*
DUTYFL CEX0 P1.3
DUTYBL CEX1 P1.4
DUTYFR CEX2 P1.5
DUTYBR CEX3 P1.6
*/

#define MotorFRDir P2_0
#define MotorFLDir P2_1
#define MotorBRDir P2_2
#define MotorBLDir P2_3

#define DUTYFL	CCAP0H
#define DUTYBL	CCAP1H
#define DUTYFR	CCAP2H
#define DUTYBR	CCAP3H

//define drill	
#define DrillContactUP		P1_0
#define DrillContactDOWN	P1_1
#define SawEncoder			P2_7   

#define PunchDir			P2_4
#define PunchPWM			P0_4

#define SawDir				P2_5
#define SawPWM	     	 	P0_5
//end define drill

//define SPRAY
#define CannonWater_N			P0_0
#define CannonWater_P			P0_1
#define CannonWater_K			P0_2
#define CannonWater_TT			P0_3
//end define SPRAY


void PortInit();
void SerialInit();
void EnableSerialISR();
void DisableSerialISR();
void PWMInit();
void MotorDirInit();

void MotorCannonInit();


