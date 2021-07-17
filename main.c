#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
int erfunc(char *s, int val);
void initialize(char *argv[], POPULATION *p);
void generation(POPULATION *p, int gen);
void report(int gen, POPULATION *p, IPTR  pop);
void statistics(POPULATION *p, IPTR pop);

void findBest(POPULATION *p, IPTR op, IPTR np){
	 IPTR tmp = (IPTR) calloc (2*p->popSize, sizeof(INDIVIDUAL));
	 for(int i=0; i<p->popSize; i++){
	 	tmp[i] = op[i];
	 }
	 for(int i=0; i<p->popSize; i++){
	 	tmp[i+p->popSize] = np[i];
	 }
	 INDIVIDUAL Max;
	 int Max_i = 0;
	 for(int j=0; j<p->popSize; j++){
	 	 Max.fitness = 0; 
		 for(int i=0; i<2*p->popSize; i++){
		 	if(tmp[i].fitness > Max.fitness){
		 		Max = tmp[i];
		 		Max_i = i;
		 	}
		 }
		op[j] = Max;
		tmp[Max_i].fitness = 0;
	}
}

//generation by generation (GENITOR)
int main(int argc, char *argv[])
{
  IPTR tmp, op, np;
  POPULATION population;
  POPULATION *p = &population;

  p->gen = 0;
  if(argc != 2) erfunc("Usage: ga <inputfile name> ", argc);
  initialize(argv, p);
  while(p->gen < p->maxGen){
    p->gen++;
	 generation(p, p->gen);
	 statistics(p, p->np);
	 report(p->gen, p, p->np);
    tmp = p->op;
    p->op = p->np;
    p->np = tmp;
  }
}


//Meritocracy (m+n)
/*int main(int argc, char *argv[])
{
  IPTR tmp, op, np;
  POPULATION population;
  POPULATION *p = &population;

  p->gen = 0;
  if(argc != 2) erfunc("Usage: ga <inputfile name> ", argc);
  initialize(argv, p);
  while(p->gen < p->maxGen){
    p->gen++;
	 generation(p, p->gen);
	 statistics(p, p->np);
	 report(p->gen, p, p->np);
    findBest(p, p->op, p->np);
  }
}*/
