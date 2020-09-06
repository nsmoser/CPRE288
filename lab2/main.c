#include "open_interface.h"             //iRobot interface library
#include "moveCommands.h"               //movement commands library\
#include "resetSimulation.h"

int main(void)
{
    //resetSimulationBoard();
    int i=0;                            //iteration counter, use as needed
    oi_t *sensor_data = oi_alloc();     //create pointer for iRobot sensor data
    oi_init(sensor_data);               //initialize sensor data pointer
   /* while(i!=4){                        //causes loop to run four times
        moveBackward(sensor_data,50);    //move forward 50 cm

        turnCCW(sensor_data,90);  //turn 90 degrees

        i++;                            //increment counter
    }*/
    moveForward(sensor_data,200);

    oi_free(sensor_data);              //free up sensor data
	return 0;
}

