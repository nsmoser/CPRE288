/* modified version of helloworld.c function given for lab 1 in order to achieve part 4 of
 * lab 1. Displays a message as a banner on top row of lcd screen. Scrolls from right to left.
 * Once message has completely crossed from right to left,the message begins scrolling from
 * right to left again. There is a 300ms delay between shifts so the message does not scroll
 * too fast. See inline comments for detailed explanations of code snippets
 */

#define LCD_MAX 19                                  //largest array location that can be
                                                    //displayed on the lcd screen
#include "Timer.h"                                  //necessary for delay function
#include "lcd.h"                                    //necessary for lcd functions
#include "string.h"                                 //necessary for strlen function


int main (void) {
    char phrase[]="microcontrollers aren't fun";
                                                    //line above is phrase that is to be
                                                    //scrolled across lcd. this comment is
                                                    //not inline as to spare formatting of
                                                    //inline comments
    char phrasePrint[21];                           //string that is printed by puts statement
                                                    //20 chars + 1 null char at the end
    short i=0,j=0,phraseLength=strlen(phrase);      //variables used for loop tracking and
                                                    //length of phrase
	timer_init();                                   //initialization steps
	lcd_init();                                     //initializes lcd and timer module
    for(i=0;i<=LCD_MAX;i++){                        //initializes phrasePrint string
            phrasePrint[i]=' ';                     //fills phrasePrint with spaces
        }
	phrasePrint[20]=0;                              //prevents glitch with puts that displays
	                                                //phrase more than once on screen by
	                                                //adding null to end of phrasePrint
	i=0;                                            //makes sure iteration counter is reset
	while(1){                                       //main loop, has no break condition
	                                                //no scenario specified where break
	                                                //needs to occur
	    for(j=0;j<LCD_MAX;j++){                     //loop that shifts characters in
	        phrasePrint[j]=phrasePrint[j+1];        //phrasePrint one location to the left
	    }	                                        //LCD_MAX is used as last location so that
	                                                //loop does not try and pull data in from
	                                                //outside phrasePrint's bounds and so that
	                                                //last character can remain null
	    if(i<phraseLength){                         //if the end of the phrase hasnt been reached
	        phrasePrint[LCD_MAX]=phrase[i];         //next character of phrase becomes last
	    }                                           //character of phrasePrint

	    else{                                       //if the end of phrase is reached
	        if(i==phraseLength){                    //if the end of phrase has just been reached
	            phrasePrint[LCD_MAX]=0;             //null character is added to end of
	        }                                       //phrasePrint
	        else{                                   //if end of phrase has already been reached
	            phrasePrint[LCD_MAX]=' ';           //blank space added to end of phrasePrint
	        }
	    }
        if(phrasePrint[0]==0){                      //if the end of phrasePrint is reached
            for(i=0;i<=LCD_MAX;i++){                //reset phrasePrint string
                    phrasePrint[i]=' ';             //replace all characters with spaces
                }
            i=0;                                    //reset iteration counter to zero
        }
        else{                                       //fi the end of phrasePrint isn't reached
            i++;                                    //increment the iteration counter
        }
        lcd_printf("%s",phrasePrint);               //print phasePrint to screen
        timer_waitMillis(300);                      //add mandatory 300ms delay
	}
	return 0;                                       //just in case it leaves the while loop
}                                                   //can exit cleanly
