#include "selection.h"

int compare(const void *arg1, const void *arg2)
{
	genotype *ind1,*ind2;
	ind1=(genotype*)arg1;
	ind2=(genotype*)arg2;
	if(ind1->fitness<ind2->fitness)
		return -1;
	else if(ind1->fitness>ind2->fitness)
		return 1;
	else 
		return 0;
}

void ranking(rttp problem)
{
	int i,j,total_fitness=0;
	double p;
	genotype *nueva_pob;
	
	//se realiza un ranking de los individuos
	qsort(problem.population, problem.popsize, sizeof(genotype), compare);
	for(i=0;i<problem.popsize;i++)
		total_fitness+=i+1;
	//se calcula el relative fitness
	for(i=0;i<problem.popsize;i++)
		problem.population[i].rfitness=(double)(i+1)/(double)total_fitness;
	//se calcula el cumulative fitness
	problem.population[0].cfitness=problem.population[0].rfitness;
	for(i=1;i<problem.popsize;i++)
		problem.population[i].cfitness=problem.population[i-1].cfitness+problem.population[i].rfitness;
	
	//se seleccionan los individuos utilizando el cumulative fitness
	nueva_pob=malloc(sizeof(genotype)*problem.popsize);
	for(i=0;i<problem.popsize;i++)
	{
		p=randval();
		if(p<problem.population[0].cfitness)
			nueva_pob[i]=problem.population[0];
		else
		{
			for(j=0;j<problem.popsize-1;j++)
			{
				if(p>=problem.population[j].cfitness && p<problem.population[j+1].cfitness)
					nueva_pob[i]=problem.population[j+1];
			}
			if(p>=problem.population[problem.popsize-1].cfitness)
				nueva_pob[i]=problem.population[problem.popsize-1];
		}
	}

	//se realiza la copia de vuelta a la poblacion original
	for(i=0;i<problem.popsize;i++)
		problem.population[i]=nueva_pob[i];
	free(nueva_pob);
}

void tournament(rttp problem)
{
  genotype *nueva_pob;
  int i,ind1,ind2;
  nueva_pob=malloc(sizeof(genotype)*problem.popsize);
  for(i=0;i<problem.popsize;i++)
  {
    ind1=(int)randval_between(0.0,(double)problem.popsize);
    do
		ind2=(int)randval_between(0.0,(double)problem.popsize);
	while(ind2==ind1);
    
    /*se selecciona al mejor de estos individuos*/
    if(problem.population[ind1].fitness>problem.population[ind2].fitness)
      nueva_pob[i]=problem.population[ind1];
    else
      nueva_pob[i]=problem.population[ind2];
  }
  
  //se realiza la copia de vuelta a la poblacion original
	for(i=0;i<problem.popsize;i++)
		problem.population[i]=nueva_pob[i];
	free(nueva_pob);
}

void proportional(rttp problem)
{
	int i,j,peor;
	double p,total_fitness=0.0;
	genotype *nueva_pob;
	//se busca el individuo con el menor fitness
	peor=0;
	for(i=0; i<problem.popsize; i++) {
		if(problem.population[i].fitness<problem.population[peor].fitness)
			peor=i;
	}
	//se dejan todos los fitness con valores positivos y se calcula el fitness total
	for(i=0; i<problem.popsize; i++) {
		problem.population[i].nfitness=problem.population[i].fitness+2*fabs(problem.population[peor].fitness);
		total_fitness+=problem.population[i].nfitness;
	}
	//se calcula el relative fitness
	for(i=0; i<problem.popsize; i++)
		problem.population[i].rfitness=problem.population[i].nfitness/total_fitness;
	//se calcula el cumulative fitness
	problem.population[0].cfitness=problem.population[0].rfitness;
	for(i=1; i<problem.popsize; i++)
		problem.population[i].cfitness=problem.population[i-1].cfitness+problem.population[i].rfitness;
	//se seleccionan los individuos utilizando el cumulative fitness
	nueva_pob=malloc(sizeof(genotype)*problem.popsize);
	for(i=0; i<problem.popsize; i++) {
		p=randval();
		if(p<problem.population[0].cfitness)
			nueva_pob[i]=problem.population[0];
		else {
			for(j=0; j<problem.popsize-1; j++) {
				if(p>=problem.population[j].cfitness && p<problem.population[j+1].cfitness)
					nueva_pob[i]=problem.population[j+1];
			}
			if(p>=problem.population[problem.popsize-1].cfitness)
				nueva_pob[i]=problem.population[problem.popsize-1];
		}
	}
	//se realiza la copia de vuelta a la poblacion original
	for(i=0; i<problem.popsize; i++)
		problem.population[i]=nueva_pob[i];
	free(nueva_pob);
}
