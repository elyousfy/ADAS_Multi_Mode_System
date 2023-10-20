/**********************************/
/* Author:Gp Group 				  */
/* SWC :UltraSonic Sensor		  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 7,2023		      */
/* Last Edit :N/A                 */
/**********************************/


#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MTIMER_interface.h"
#include "HULTRASONIC_interface.h"
#include "HULTRASONIC_private.h"
#include "HULTRASONIC_config.h"



static volatile u32 Local_u32FinalValue=0;
volatile u32 Global_u32Distance;
void HULTRASONIC_voidInit(void)
{
	/*Set Trigger Pin to output*/
	MGPIO_voidSetPinMode(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_MEDIUMSPEED);
	
	/*Set Echo Pin to altrenate function of timer2 */
	MGPIO_voidSetPinMode(ULTRASONIC_ECHO_PORT_PIN,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetAlternateFunction(ULTRASONIC_ECHO_PORT_PIN,1);
}

void HULTRASONIC_voidGetDistance(void)
{
	/*Make Trigger Pin to High for 10us the Low*/
	/*Make Timer 2 Count From Zero*/
//	MTIMER2_voidClearCount();
	MGPIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_HIGH);
	MSYSTICK_voidSetDelay(10);
	MGPIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_LOW);
}


void TIM2_IRQHandler(void)
{

		/*Second time Echo Low*/
		Local_u32FinalValue=MTIMER2_u32CaptureValue(ULTRASONIC_ECHO_CHANNEL);
		MTIMER2_voidClearCount();

		/*34 is speed of sound 34cm/ms=0.034 cm/us */
		/*Distance=SpeedofSound*Time)/2 */
		/*for ex: Timer 2 freq =25MHZ ,PreScaler=64,TickTime=64/25=2.56  MicroSeconnd*/
		/*Global_u32Distance=(((0.034 * (Local_u32FinalValue-Local_u32initalValue)*8))/2);	*/
		Global_u32Distance=(0.136 * (Local_u32FinalValue));

}


/*in case of you dont want to use extern */
u32 HULTRASONIC_u32Distance(void)
{
	return Global_u32Distance;
} 











