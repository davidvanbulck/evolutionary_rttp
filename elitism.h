/**
* @file   elitism.h
* @brief  Elitism and keep the best functions for maintain the best individual over the entire 
* 		  run of the algorithm.
* @author dacuna <diego.acuna@usm.cl>
*/

#ifndef ELITISM_H_INCLUDED
#define ELITISM_H_INCLUDED

#include "utils.h"

void elitism(rttp problem);
void keep_the_best(rttp problem);

#endif