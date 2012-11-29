#include <stdio.h>
#include <stdlib.h>
#include "read_instance.h"

void read_instance(rttp *problem, char* instance)
{
	int i,j,total_distance=0;	
	FILE *file;
	
	file=fopen(instance,"r");
	/* read the number of teams */
	fscanint(file, &(problem->n_teams));
	problem->n_rounds=2*(problem->n_teams-1)+problem->params.byes_arg;
	/* allocate memory for distance matrix */
	problem->distance_matrix=create_matrix_int(problem->n_teams,problem->n_teams);
	/* read distance matrix */
	for(i=0;i<problem->n_teams;i++)
		for(j=0;j<problem->n_teams;j++){
			fscanint(file, &(problem->distance_matrix[i][j]));
			total_distance+=problem->distance_matrix[i][j];
		}
	/* calculate average distance between teams (for fitness purposes) */
	problem->average_distance=total_distance/((problem->n_teams*problem->n_teams)-problem->n_teams);
}
