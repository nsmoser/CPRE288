#include "open_interface.h"             //iRobot interface library
#include "moveCommands.h"               //movement commands library

int main(void)
{
    int i=0;                            //iteration counter, use as needed
    oi_t *sensor_data = oi_alloc();     //create pointer for iRobot sensor data
    oi_init(sensor_data);               //initialize sensor data pointer
    while(i!=4){                        //causes loop to run four times
        moveForward(sensor_data,50);    //move forward 50 cm

        turnClockwise(sensor_data,90);  //turn 90 degrees

        i++;                            //increment counter
    }

    oi_free(sensor_data);               //free up sensor data
	return 0;
}

