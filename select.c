
#include "type.h"
#include <stdlib.h>

double f_random();

int roulette(IPTR pop, double sumFitness, int popsize)
{ 

  /* select a single individual by roulette wheel selection */
  
  double rand,partsum;
  int i;

  partsum = 0.0; i = 0;
  rand = f_random() * sumFitness; 
  
  i = -1;
  do{
    i++;
    partsum += pop[i].fitness;
  } while (partsum < rand && i < popsize - 1) ;
  
  return i;
}


int ranking(IPTR pop, int ind, int popSize){
	 IPTR tmp = (IPTR) calloc (popSize, sizeof(INDIVIDUAL));
	 int *index = (int *) calloc (popSize, sizeof(int));
	 for(int i=0; i<popSize; i++){
	 	tmp[i] = pop[i];
	 	index[i] = i;
	 }
	 INDIVIDUAL t;
	 int r;
	 for(int i=0; i<popSize; i++){
	 	for(int j=i+1; j<popSize; j++){
	 		if(tmp[i].fitness < tmp[j].fitness){
	 			t = tmp[i];
	 			tmp[i] = tmp[j];
	 			tmp[j] = t;
	 			
	 			r=index[i];
	 			index[i] = index[j];
	 			index[j] = r;
	 		}
	 	}
	 }
	 return index[ind];
}
