/*
 * button.c
 *
 *  Created on: Jul 18, 2016
 *      Author: Eric Middleton, Zhao Zhang, Chad Nelson, & Zachary Glanz.
 *
 *  @edit: Lindsey Sleeth and Sam Stifter on 02/04/2019
 *  @edit: Phillip Jone 05/30/2019: Mearged Spring 2019 version with Fall 2018
 */
 


//The buttons are on PORTE 3:0
// GPIO_PORTE_DATA_R -- Name of the memory mapped register for GPIO Port E, 
// which is connected to the push buttons
#include "button.h"


/**
 * Initialize PORTE and configure bits 0-3 to be used as inputs for the buttons.
 */
void button_init() {
	static uint8_t initialized = 0;

	//Check if already initialized
	if(initialized){
		return;
	}



	// 1) Turn on PORTE system clock, do not modify other clock enables
	SYSCTL_RCGCGPIO_R |= 0b010000;

	// 2) Set the buttons as inputs, do not modify other PORTE wires
	GPIO_PORTE_DIR_R &= 0b11110000;
	
	// 3) Enable digital functionality for button inputs, 
	//    do not modify other PORTE enables
	GPIO_PORTE_DEN_R |= 0b00001111;

	
	initialized = 1;
}

uint8_t button_getButton() {
    /*function checks buttons by checking buttons left to right across screen
     * highestButton gets greater as greater value button is pressed.
     */
    uint8_t highestButton=0;    //condition if no button pressed
	
	if(!((GPIO_PORTE_DATA_R)&1)){highestButton='1';}      //checks b1
	if(!((GPIO_PORTE_DATA_R>>1)&1)){highestButton='2';}   //checks b2
	if(!((GPIO_PORTE_DATA_R>>2)&1)){highestButton='3';}   //checks b3
	if(!((GPIO_PORTE_DATA_R>>3)&1)){highestButton='4';}   //checks b4
	return highestButton;                               //returns highest button value
}





