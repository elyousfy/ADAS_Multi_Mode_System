/**********************************/
/* Author:Fakhr Eldin    		  */
/* SWC :LKA             		  */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :Octobar 21,2023		  */
/* Last Edit :N/A                 */
/**********************************/

#ifndef ALK_IR_INTERFACE_H_
#define ALK_IR_INTERFACE_H_

/*--------------------------------------------------------------------------------------------------------------------
 /**
 * @brief Implement the Line Keeping Assistance (LKA) algorithm.
 *
 * This function first initializes the ALKA IR sensor. Then, it reads the values of the left and right IR sensors.
 * Based on the sensor values, the function takes the following actions:
 *
 * * If both IR sensors are black, the function moves the robot forward.
 * * If both IR sensors are white, the function stops the robot.
 * * If the right IR sensor is white, the function turns the robot right.
 * * If the left IR sensor is white, the function turns the robot left.
 *
 * @return None
 */
void APP_LKA(void);
*
/--------------------------------------------------------------------------------------------------------------------*/
void APP_LKA(void);


/*--------------------------------------------------------------------------------------------------------------------
 *
 * @brief Initialize the IR sensors.
 *
 * This function initializes the HIR peripherals for the IR sensors and sets the pins as input mode with pull-up resistors.
 *
 * @return None
 *
/--------------------------------------------------------------------------------------------------------------------*/
void ALKA_IR_Init();

/*--------------------------------------------------------------------------------------------------------------------
/**
 * @brief Read the IR sensor on the right side of the car.
 *
 * This function reads the state of the IR sensor on the right side of the car and returns a value of 1 if the sensor is detecting an object, and 0 otherwise.
 *
 * @return u8 The state of the IR sensor (1 for White lane detected, 0 for no object detected).
 *
/--------------------------------------------------------------------------------------------------------------------*/
u8  ALKA_IR_Right();

/*--------------------------------------------------------------------------------------------------------------------
/**
 * @brief Read the IR sensor on the Left side of the car.
 *
 * This function reads the state of the IR sensor on the right side of the car and returns a value of 1 if the sensor is detecting an object, and 0 otherwise.
 *
 * @return u8 The state of the IR sensor (1 for White lane detected, 0 for no object detected).
 *
/--------------------------------------------------------------------------------------------------------------------*/
u8  ALKA_IR_Left();


#endif