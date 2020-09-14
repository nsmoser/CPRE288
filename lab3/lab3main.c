/**
 * lab3_template.c
 * 
 * Template file for CprE 288 lab 3
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 */

#include "button.h"
#include "Timer.h"
#include "lcd.h"
#include "cyBot_uart.h"  // Functions for communiticate between CyBot and Putty (via UART)
                         // PuTTy: Buad=115200, 8 data bits, No Flow Control, No Party,  COM1
#include "resetSimulation.h"
#include "open_interface.h"
#include "moveCommands.h"

#define REPLACEME 0



int main(void) {
	//resetSimulationBoard();
    button_init();
	lcd_init();
    cyBot_uart_init();
    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);
	uint8_t buttonPressed=0;
	int previousButton=0;
	int charReceived=0;
	            // Don't forget to initialze the cyBot UART before trying to use it

	// YOUR CODE HERE
	
	
	while(1){
	    charReceived=cyBot_getByte();
	    /*buttonPressed=button_getButton();
	    if(buttonPressed!=previousButton){
	        cyBot_sendByte(buttonPressed);
	    }
	    previousButton=buttonPressed;*/
	    //lcd_printf("%c",cyBot_getByte());
	    if(charReceived=='w'){moveForward(sensor_data,50);}
	    else if(charReceived=='s'){moveBackward(sensor_data,50);}
	    else if(charReceived=='a'){turnCCW(sensor_data,90);}
	    else if(charReceived=='d'){turnCW(sensor_data,90);}




      // YOUR CODE HERE

  


	
	}
	oi_free(sensor_data);
	
}
