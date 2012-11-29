#include <stdio.h>
#include "gengetopt/read_parameters.h"
#include "genotype.h"
#include "read_instance.h"
#include "create_solutions.h"

//command-line arguments
struct gengetopt_args_info params;

int main(int argc, char **argv)
{
	rttp instance;
	int generations=0;
	
	//call cmdline_parser from gengetopt
	if(cmdline_parser(argc,argv,&params)!=0)
		return 0;
	instance.params=params;
	instance.popsize=params.pop_arg;
	
	//random seed
	srand(params.srand_arg);
	
	read_instance(&instance,params.instance_arg);
	create_solutions(&instance);
	
	while(generations<instance.params.numgen_arg){
		generations++;
	}
	
	printf("%f\n",instance.population[instance.popsize].fitness);
	
	cmdline_parser_free(&(instance.params));

	return 0;
}
