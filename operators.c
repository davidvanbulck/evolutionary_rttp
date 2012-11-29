#include "operators.h"

void swapHomes(int **schedule, int team1, int team2, rttp *problem){
	int i;
	for(i=0;problem->n_rounds;i++){
		if(schedule[team1-1][i]==team2){
			schedule[team1-1][i]=-1*team2;
			schedule[team2-1][i]=team1;
		}
		if(schedule[team1-1][i]==(-1*team2)){
			schedule[team1-1][i]=team2;
			schedule[team2-1][i]=-1*team1;
		}
	}
}

void swapRounds(int **schedule, int round1, int round2, rttp *problem){
	int i,tmp;
	for(i=0;problem->n_teams;i++){
		tmp=schedule[i][round1];
		schedule[i][round1]=schedule[i][round2];
		schedule[i][round2]=tmp;
	}
}

void swapTeams(int **schedule, int team1, int team2, rttp *problem){
	int i,team_k,team_j,tmp,index_k,index_j;
	for(i=0;problem->n_rounds;i++){
		if(schedule[team1-1][i]!=team2 || schedule[team1-1][i]!=(-1*team2)){
			team_k=schedule[team1-1][i];
			schedule[team1-1][i]=schedule[team2-1][i];
			team_j=schedule[team2-1][i];
			schedule[team2-1][i]=team_k;
			if(team_k!=team2 || team_k!=(-1*team2)){
				//make team j play with team1
				if(team_j<0) index_j=(-1)*team_j; else index_j=team_j;
				if(team_j!=0){
					if(schedule[index_j][i]<0) tmp=-1; else tmp=1;
					schedule[index_j-1][i]=tmp*team1;
				}
				//make team k play with team2
				if(team_k<0) index_k=(-1)*team_k; else index_k=team_k;
				if(team_k!=0){
					if(schedule[index_k][i]<0) tmp=-1; else tmp=1;
					schedule[index_k-1][i]=tmp*team2;
				}
			}
		}
	}
}

void partialSwapRounds(int **schedule, int team, int round1, int round2, rttp *problem){
	int team_k,team_j,tmp,index_k,index_j;
	
	team_k=schedule[team-1][round1];
	if(team_k<0) index_k=(-1)*team_k; else index_k=team_k;
	//swap team_k round1-round2
	team_j=schedule[team-1][round2];
	if(team_j<0) index_j=(-1)*team_j; else index_j=team_j;
	//swap team1 round1-round2
	tmp=schedule[team][round1];
	schedule[team][round1]=schedule[team][round2];
	schedule[team][round2]=tmp;
	//swap teamk round1-round2
	
	//swap teamj round1-round2
}
