#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "create_solutions.h"
#include "utils.h"

void print_schedule(int** matrix, int rows, int cols)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		printf("%-3d ",i+1);
		for(j=0;j<cols;j++)
		{
			printf("%d   ",matrix[i][j]);
		}
		printf("\n");
	}
}

int has_byes(int **schedule,int team, rttp *problem,int round){
	int j,count_byes=0;
	for(j=0;j<round;j++){
		if(schedule[team-1][j]==0)
			count_byes++;
		if(count_byes==problem->params.byes_arg)
			return 0;
	}
	return 1;
}

int verify_matches_home_left(int **schedule,int team1, int team2, rttp *problem,int round){
	int j;
	for(j=0;j<round;j++){
		if(schedule[team1-1][j]==team2)
			return 0;			
	}
	return 1;
}

int verify_matches_visit_left(int **schedule,int team1, int team2, rttp *problem,int round){
	int j;
	for(j=0;j<round;j++){
		if(schedule[team1-1][j]==-1*team2)
			return 0;
	}
	return 1;
}

int verify_matches_left(int **schedule,int team1, int team2, rttp *problem,int round){
	int j,total_matches=0;
	for(j=0;j<round;j++){
		if(schedule[team1-1][j]==-1*team2 || schedule[team1-1][j]==team2)
			total_matches++;
		if(total_matches==2)
			return 0;
	}
	return 1;
}

void create_solutions(rttp *problem){
	GArray *garray;
	int i,rand_team,rand_team2,rand_factor,factor;
	int team1,team2,round,count_pop,count_team_byes;
	
	/* first we need to create pop_size individuals for the population */
	problem->population=malloc(sizeof(genotype)*(problem->popsize+1));
	for(i=0;i<problem->popsize;i++)
		problem->population[i].genes=create_matrix_int(problem->n_teams,2*(problem->n_teams-1)+problem->params.byes_arg);
		
	for(count_pop=0;count_pop<problem->popsize;count_pop++){
		for(round=0;round<problem->n_rounds;round++){
			/* an array to store the teams that remains to assign a match in the round */
			garray = g_array_new(FALSE,FALSE,sizeof(gint));
			
			for(i=1;i<=problem->n_teams;i++)
				g_array_append_val(garray, i);
			/* until there is no teams to assign a match */
			while(garray->len>0){
				rand_team=randval_between(0.0,(double)garray->len);
				rand_factor=(int)randval_between(0.0,3.0);
				if(rand_factor==0)
					factor=-1;
				else if(rand_factor==1)
					factor=0;
				else 
					factor=1;
				if(factor!=0 && garray->len>1){
					team1=g_array_index(garray,gint,rand_team);
					/* we need to choose an extra team from the list */
					do
						rand_team2=randval_between(0.0,(double)garray->len);
					while(rand_team2==rand_team);
					team2=g_array_index(garray,gint,rand_team2);
					if(factor==1 && !verify_matches_home_left(problem->population[count_pop].genes,team1,team2,problem,round))
						factor=-1;
					if(factor==-1 && !verify_matches_visit_left(problem->population[count_pop].genes,team1,team2,problem,round))
						factor=1;
					if(verify_matches_left(problem->population[count_pop].genes,team1,team2,problem,round)==1){
						garray=g_array_remove_index(garray,rand_team);
						if(rand_team<rand_team2)
							garray=g_array_remove_index(garray,rand_team2-1);
						else
							garray=g_array_remove_index(garray,rand_team2);						
						/* we make teams to play between them */
						problem->population[count_pop].genes[team1-1][round]=factor*team2;
						problem->population[count_pop].genes[team2-1][round]=-1*factor*team1;
					}
				}else{
					/* its a free round, as n_teams is even if we assign a team a free round then we need to assign to a another
					   team also a free round, for simmetry */
					team1=g_array_index(garray,gint,rand_team);
					if(has_byes(problem->population[count_pop].genes,team1,problem,round)==1){
						garray=g_array_remove_index_fast(garray,rand_team);
						/* double free round, if we check all the list, then there is no posibility, break */
						count_team_byes=0;
						do{
							rand_team2=randval_between(0.0,(double)garray->len);
							team2=g_array_index(garray,gint,rand_team2);
							count_team_byes++;
						}while(has_byes(problem->population[count_pop].genes,team2,problem,round)!=1 && count_team_byes<garray->len);
						if(count_team_byes==garray->len && has_byes(problem->population[count_pop].genes,team2,problem,round)!=1){
							g_array_append_val(garray, team1);
							continue;
						}
						problem->population[count_pop].genes[team1-1][round]=0;
						garray=g_array_remove_index_fast(garray,rand_team2);
						problem->population[count_pop].genes[team2-1][round]=0;
					}
				}
			}
			g_array_free(garray,TRUE);
		}
	}
	
	/*printf("\n");
	for(i=0;i<problem->popsize;i++){
		print_schedule(problem->population[i].genes,problem->n_teams,problem->n_rounds);
		printf("\n");
	}*/
}	


