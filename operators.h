/**
* @file   operators.h
* @brief  Mutation and Crossover operators for the evolutive algorithm, also contains
* 		  different types of moves that operators can apply.
* @author dacuna <diego.acuna@usm.cl>
*/

#ifndef OPERATORS_H_INCLUDED
#define OPERATORS_H_INCLUDED

#include "genotype.h"

void swapHomes(int **schedule, int team1, int team2, rttp *problem);
void swapRounds(int **schedule, int round1, int round2, rttp *problem);
void swapTeams(int **schedule, int team1, int team2, rttp *problem);
void partialSwapRounds(int **schedule, int team, int round1, int round2, rttp *problem);


#endif