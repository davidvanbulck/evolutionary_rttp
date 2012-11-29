#include "evaluate.h"

//se deben sumar la matriz de distancias y se aprovechan de contar las penalizaciones
//en el mismo proceso
void evaluate(rttp problem)
{
	int i,j,k,d_total;
	int actual,match_anterior;
	//penalization variables
	int counter; //count how many home or away games (depending on status) have been ocurred
	int status; //if status=0 we are checking home games, if 1 then away games
	int non_repeaters;  //the non-repeaters constraint
	int penalizations; //number of penalizations counted
	
	for(i=0;i<problem.popsize;i++){
		d_total=0;
		counter=0;
		non_repeaters=0;
		penalizations=0;
		for(j=0;j<problem.n_teams;j++){
			for(k=0;k<problem.n_rounds;k++){
				//the team its on the inner tournament
				if(k!=0){
					//two posibilities: 
					//  - match_anterior visit and match_anterior home (free round doesn't count because we don't need it,
					//its more easy to skip free rounds and let teams remember only their last match, so previous match will
					//never be zero)
					if(match_anterior>0){
						//previous match was at home
						actual=problem.population[i].genes[j][k];
						
						//check the nonrepeaters contraint
						//@todo: consultar si esta restriccion aplica cuando hay rondas libres!
						if(abs(match_anterior)==abs(actual))
							non_repeaters++;
						
						//two posibilities: actual match => home match -> don't do anything because team j its already at home
						//actual match => visit match -> sum from local to visit
						if(actual<0){
							d_total+=problem.distance_matrix[j][((-1)*actual)-1];
							match_anterior=actual;
							
							//the away game, so we need to check if status=1 (away games), if then do counter++
							//if status=0 then its a changue, we need to verify the counter and calculate the penalization
							if(status==1){
								counter++;
							}else{
								if(counter<problem.params.lower_arg || counter>problem.params.upper_arg) //PENALIZE!
									penalizations++;
								status=1;
								counter=1;
							}
						}
						
						//for penalization purposes we need to know if this match is home (away situation already checked above)
						if(actual>0){
							//home game, so we need to check if status=0 (home games), if then do counter++
							//if status=1 then its a changue, we need to verify the counter and calculate the penalization
							if(status==0){
								counter++;
							}else{
								if(counter<problem.params.lower_arg || counter>problem.params.upper_arg) //PENALIZE!
									penalizations++;
								status=0;
								counter=1;
							}
						}
						
						//if actual its a free round, don't update de previous match (teams stay where they 
						//are in their free rounds)
					}else{
						//previous match was out of home
						actual=problem.population[i].genes[j][k];
						
						//check the nonrepeaters contraint
						//@todo: consultar si esta restriccion aplica cuando hay rondas libres!
						if(abs(match_anterior)==abs(actual))
							non_repeaters++;
						
						if(actual>0){
							//team travels from previous match to their home
							d_total+=problem.distance_matrix[((-1)*match_anterior)-1][j];
							match_anterior=actual;
							
							//a home game, so we need to check if status=0 (home games), if then do counter++
							//if status=1 then its a changue, we need to verify the counter and calculate the penalization
							if(status==0){
								counter++;
							}else{
								if(counter<problem.params.lower_arg || counter>problem.params.upper_arg) //PENALIZE!
									penalizations++;
								status=0;
								counter=1;
							}
						}else if(actual<0){
							//team travels from previous match to home of actual team
							d_total+=problem.distance_matrix[((-1)*match_anterior)-1][((-1)*actual)-1];
							match_anterior=actual;
							
							//the away game, so we need to check if status=1 (away games), if then do counter++
							//if status=0 then its a changue, we need to verify the counter and calculate the penalization
							if(status==1){
								counter++;
							}else{
								if(counter<problem.params.lower_arg || counter>problem.params.upper_arg) //PENALIZE!
									penalizations++;
								status=1;
								counter=1;
							}
						}else
							continue;
					}
				}else{
					//the first round for this team, we only need to sum up the distance from its home to
					//the city where its going to play
					actual=problem.population[i].genes[j][k];
					status=0; //the initialization process, we assume that in the first round, team plays a home match
							  //or has a free round
					if(actual<0){
						d_total+=problem.distance_matrix[j][(-1)*(actual-1)];
						status=1; //wrong assumption, the team has a away game
					}
					if(actual!=0){
						match_anterior=actual;
						counter++;     //we add counter because the team played a game
					}
					else
						match_anterior=j+1;
				}
			}
		}
		problem.population[i].fitness=d_total+(problem.average_distance*(problem.n_teams-1)*penalizations)+
			(problem.average_distance*(problem.n_teams-1)*non_repeaters);
	}
	/*for(i=0;i<pob.tam_poblacion;i++)
		printf("INDIVIDUO %d FITNESS: %f\n",i,pob.individuos[i].fitness);*/
}
