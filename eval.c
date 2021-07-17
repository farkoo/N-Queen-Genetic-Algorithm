#include <stdio.h>
#include <stdlib.h>
#include <math.h>    /* for pow(x, y) */
#include "type.h"

double eval(POPULATION *p, IPTR pj) 
     /* Called from gen.c and init.c */
{
    int num = p->lchrom;
    int* cro = pj->chrom;    //{0,1,2,3,4,5,6,7};
    int vertical_collisions = 0;
    int diagonal_collisions = 0;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(cro[i] == cro[j] && i != j)
                vertical_collisions++;
        }
    }
    vertical_collisions /= 2;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(abs(cro[i] - cro[j]) == abs(i - j) && i != j)
                diagonal_collisions++;
        }
    }
    diagonal_collisions /= 2;
    int maxfitness = (num*(num-1))/2;

    return maxfitness - (vertical_collisions + diagonal_collisions);
}

