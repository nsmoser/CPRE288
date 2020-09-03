/*
 * move_commands.c
 *
 *  Created on: Sep 2, 2020
 *      Author: nsmoser
 *
 *      see moveCommands.h for usage instructions
 *
 * NOTE: 5 degrees is subtracted from angle argument for while loop used in turnClockwise.
 * Robot seems to overshoot the angle argument every time, and this is the perfect angle
 * correction for this turn speed. Angle correction will need adjusted with speed adjustment.
 * Angle correction distance was determined with guess and check, so good luck.
 *
 */
#include "open_interface.h"

void moveForward(oi_t *sensor_data, int cm){            //forward movement function
    double distance=0;                                  //distance variable, must be double
                                                        //since sensor distance is a double
    oi_setWheels(200,200);                              //move forward at moderate speed
    while(distance<(cm*10)){                            //while measured distance is less than
                                                        //distance argument
        oi_update(sensor_data);                         //update sensor data struct
        distance+=sensor_data->distance;                //add change in distance to
    }                                                   //measured distance
    oi_setWheels(0,0);                                  //turn off wheels
}

void turnClockwise(oi_t *sensor_data, int degrees){     //clockwise turn function
    double angle=0;                                     //angle variable, must be double
                                                        //since sensor angle is double
    oi_setWheels(200,-200);                             //move left forward and right backward]
                                                        //turns slow to avoid turning too far
    while(angle<(degrees-5)){                           //while measured angle is less than
                                                        //angle argument
        oi_update(sensor_data);                         //update sensor data struct
        angle+=sensor_data->angle;                      //add change in angle to
    }                                                   //measured angle
    oi_setWheels(0,0);                                  //turn off wheels
}


