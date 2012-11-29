#include "elitism.h"

void elitism(rttp problem)
{
	int best,worst,i;
	best=worst=0;
	/* se encuentra al mejor y el peor de los individuos */
	for(i=0;i<problem.popsize;i++)
	{
		if(problem.population[i].fitness>problem.population[best].fitness)
			best=i;
		if(problem.population[i].fitness<problem.population[worst].fitness)
			worst=i;
	}
	/* se actualizan los individuos si es que corresponde */
	if(problem.population[problem.popsize].fitness<problem.population[best].fitness)
	{
		copy_matrix(problem.population[best].genes,problem.population[problem.popsize].genes,problem.n_teams,problem.n_rounds);
		problem.population[problem.popsize].fitness=problem.population[best].fitness;
	}
	else
	{
		copy_matrix(problem.population[problem.popsize].genes,problem.population[worst].genes,problem.n_teams,problem.n_rounds);
		problem.population[worst].fitness=problem.population[problem.popsize].fitness;
	}
}

void keep_the_best(rttp problem)
{
	int i,best=0;
	copy_matrix(problem.population[0].genes,problem.population[problem.popsize].genes,problem.n_teams,problem.n_rounds);
	problem.population[problem.popsize].fitness=problem.population[0].fitness;
	for(i=0;i<problem.popsize;i++)
	{
		if(problem.population[i].fitness>problem.population[problem.popsize].fitness)
		{
			problem.population[problem.popsize].fitness=problem.population[i].fitness;
			best=i;
		}
	}
	//copy the best
	copy_matrix(problem.population[best].genes,problem.population[problem.popsize].genes,problem.n_teams,problem.n_rounds);
	problem.population[problem.popsize].fitness=problem.population[best].fitness;
}
