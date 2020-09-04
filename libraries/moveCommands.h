/*
 * move_commands.h
 *
 *  Created on: Sep 2, 2020
 *      Author: nsmoser
 *      If any function from this header is to be used, these lines must be included
 *      before any of the functions are called
 *
 *      oi_t *sensor_data = oi_alloc();
 *      oi_init(sensor_data);
 *
 *      sensor_data can be changed to whatever name is appropriate to the project
 *
 *      the following line of code needs to be added to the end of any project that
 *      uses these functions
 *
 *      oi_free(sensor_data);
 *
 *      this frees up any memory used by the sensor_data struct.
 */

#ifndef MOVECOMMANDS_H_
#define MOVECOMMANDS_H_

void moveForward(oi_t *sensor, int cm);             //forward movement definition

void moveBackward(oi_t *sensor, int cm);            //backward movement definition

void turnCW(oi_t *sensor, int degrees);             //clockwise turn definition

void turnCCW(oi_t *sensor, int degrees);            //counter-clockwise turn definition



#endif /* MOVECOMMANDS_H_ */
