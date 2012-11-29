/**
* @file   selection.h
* @brief  Selection schemes for the evolutive algorithm.
* @author dacuna <diego.acuna@usm.cl>
*/

#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include "utils.h"

void ranking(rttp problem);
void tournament(rttp problem);
void proportional(rttp problem);

#endif