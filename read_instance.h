/**
* @file   read_instance.h
* @brief  Functions for parse an specific instance of the rttp problem into a
* 	      rttp struct.
* @author dacuna <diego.acuna@usm.cl>
*/

#ifndef READ_INSTANCE_H_INCLUDED
#define READ_INSTANCE_H_INCLUDED

#include "utils.h"
#include "genotype.h"

void read_instance(rttp *problem, char* instance);

#endif