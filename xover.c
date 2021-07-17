#include "type.h"
#include <stdlib.h>
#include <stdio.h>

int rnd(int low, int high);
int flip(double);
int muteX1(POPULATION *p, IPTR c);
int muteX2(POPULATION *p, IPTR c);
int muteX3(POPULATION *p, IPTR c);
int muteX4(POPULATION *p, IPTR c);

//-ORDER-X------------------------------
void crossover1(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
	int point1, point2, i, flag = 0;
	int *pi1,*pi2,*ci1,*ci2;

	pi1 = p1->chrom;
	pi2 = p2->chrom;
	ci1 = c1->chrom;
	ci2 = c2->chrom;

	if (flip(p->pCross)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
			point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);
		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}
		//-----------------CHILD-1--------------------------------------------
		for (i = point1; i <= point2; i++)
		{
			ci1[i] = pi1[i];
		}
		int counter_c = (i % p->lchrom);
		for (; i < p->lchrom; i++)
		{
			for (int j = point1; j <= point2; j++)
				if (pi2[i] == pi1[j]) {
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			ci1[counter_c] = pi2[i];
			counter_c = (counter_c + 1) % p->lchrom;
		}
		for (i = 0; i < p->lchrom,counter_c!=point1; i++)
		{
			for (int j = point1; j <= point2; j++)
				if (pi2[i] == pi1[j]) {
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			ci1[counter_c] = pi2[i];
			counter_c = (counter_c + 1) % p->lchrom;
		}
		//-----------------CHILD-2--------------------------------------------
		for (i = point1; i <= point2; i++)
		{
			ci2[i] = pi2[i];
		}
		counter_c = (i % p->lchrom);
		for (; i < p->lchrom; i++)
		{
			for (int j = point1; j <= point2; j++)
				if (pi1[i] == pi2[j]) {
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			ci2[counter_c] = pi1[i];
			counter_c = (counter_c + 1) % p->lchrom;
		}
		for (i = 0; i < p->lchrom, counter_c != point1; i++)
		{
			for (int j = point1; j <= point2; j++)
				if (pi1[i] == pi2[j]) {
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			ci2[counter_c] = pi1[i];
			counter_c = (counter_c + 1) % p->lchrom;
		}
		muteX2(p, c1);
		muteX2(p, c2);
	}

	else{
		for(i = 0; i < p->lchrom; i++){
		      ci1[i] = pi1[i];
		      ci2[i] = pi2[i];
		}
		muteX2(p, c1);
		muteX2(p, c2);
	}
	/*for (int i = 0; i < p->lchrom; i++)
		printf("%d ", pi1[i]);
	printf(" ");
	for (int i = 0; i < p->lchrom; i++)
		printf("%d ", pi2[i]);
	printf(" ");
	for (int i = 0; i < p->lchrom; i++)
		printf("%d ", ci1[i]);
	printf(" ");
	for (int i = 0; i < p->lchrom; i++)
		printf("%d ", ci2[i]);
	printf("\n");*/
	
}

//--PMX------------------------------------------
int FindIndex(int *arr,int num,int size){
	for (int i = 0; i <size; i++)
		if (arr[i]==num)
			return i;

	return -1;
}
void crossover2(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
	int point1, point2, i, flag = 0;
	int *pi1,*pi2,*ci1,*ci2;

	pi1 = p1->chrom;
	pi2 = p2->chrom;
	ci1 = c1->chrom;
	ci2 = c2->chrom;

	if (flip(p->pCross)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
			point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);
		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}
		//-----------------CHILD-1--------------------------------------------
		int index,num,*setArr,flag=0;
		setArr = (int *) calloc (p->lchrom, sizeof(int));
		for (int i = 0; i < p->lchrom; i++)
			setArr[i]=0;

		for (i = point1; i <= point2; i++)
		{
			ci1[i] = pi1[i];
			setArr[i]=1;
		}

		for (i = point1; i <= point2; i++){

			for (int j = point1; j <= point2; j++)
				if (pi1[j]==pi2[i])
					flag=1;

			if (flag==1)
			{
				flag=0;
				continue;
			}

			num=pi1[i];
			index=FindIndex(pi2,num,p->lchrom);
			if (index<point1 || index>point2)
			{
				ci1[index]=pi2[i];
				setArr[index]=1;
			}
			else{
				while(index>=point1 && index<=point2){
					num=pi1[index];
					index=FindIndex(pi2,num,p->lchrom);	
				}
				ci1[index]=pi2[i];
				setArr[index]=1;
			}
		}

		for (int i = 0; i < p->lchrom; i++)
		{
			if (setArr[i]==0)
			{
				ci1[i]=pi2[i];
			}
		}

		//-----------------CHILD-2--------------------------------------------
		flag=0;
		for (int i = 0; i < p->lchrom; i++)
			setArr[i]=0;

		for (i = point1; i <= point2; i++)
		{
			ci2[i] = pi2[i];
			setArr[i]=1;
		}

		for (i = point1; i <= point2; i++){
			for (int j = point1; j <= point2; j++)
				if (pi2[j]==pi1[i])
					flag=1;

			if (flag==1)
			{
				flag=0;
				continue;
			}

			num=pi2[i];
			index=FindIndex(pi1,num,p->lchrom);
			if (index<point1 || index>point2)
			{
				ci2[index]=pi1[i];
				setArr[index]=1;
			}
			else{
				while(index>=point1 && index<=point2){
					num=pi2[index];
					index=FindIndex(pi1,num,p->lchrom);	
				}
				ci2[index]=pi1[i];
				setArr[index]=1;
			}
		}

		for (int i = 0; i < p->lchrom; i++)
		{
			if (setArr[i]==0)
			{
				ci2[i]=pi1[i];
			}
		}

		muteX2(p, c1);
		muteX2(p, c2);
	}

	else{
		for(i = 0; i < p->lchrom; i++){
		      ci1[i] = pi1[i];
		      ci2[i] = pi2[i];
		}
		muteX2(p, c1);
		muteX2(p, c2);
	}
	
}

//-INVERSION--------------------------------------------
int muteX1(POPULATION *p, IPTR c)
{
	int point1, point2,i;
	int *ci, *cMuti;

	ci = c->chrom;
	cMuti = (int *) calloc (p->lchrom, sizeof(int));;

	/*for (int i = 0; i < p->lchrom; i++)
		printf("%d ", cMuti[i]);
	printf(" ");
	for (int i = 0; i < p->lchrom; i++)
		printf("%d ", ci[i]);
	printf("\n");*/

	if (flip(p->pMut)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
		point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);

		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}

		int index2 = point2;
		for (i = 0; i< point1; i++)
			cMuti[i] = ci[i];

		for (; i <= point2; i++,index2--)
			cMuti[i] = ci[index2];

		/*int tmp = ci[point1];
                ci[point1] = ci[point2];
                ci[point2] = tmp;*/

	
		for (;i< p->lchrom; i++)
			cMuti[i] = ci[i];
		for(int i=0; i<p->lchrom; i++){
			ci[i] = cMuti[i];
		}
	}
		
	/*for (int i = 0; i < p->lchrom; i++)
		printf("%d ", cMuti[i]);
	printf(" ");
	for (int i = 0; i < p->lchrom; i++)
		printf("%d ", ci[i]);
	printf("\n");*/
}

//-SWAP-----------------------------------
int muteX2(POPULATION *p, IPTR c)
{
	int point1, point2,i;
	int *ci,*cMuti;

	ci = c->chrom;
	cMuti = (int *) calloc (p->lchrom, sizeof(int));;

	if (flip(p->pMut)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
		point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);

		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}

		for(int i=0; i<p->lchrom; i++){
			cMuti[i]=ci[i];
		}

		cMuti[point1]=ci[point2];
		cMuti[point2]=ci[point1];

		for(int i=0; i<p->lchrom; i++){
			ci[i] = cMuti[i];
		}
	}
	
}

//-SCRAMBLE-----------------------------------
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int muteX3(POPULATION *p, IPTR c)
{
	int point1, point2,i;
	int *ci,*cMuti;

	ci = c->chrom;
	cMuti = (int *) calloc (p->lchrom, sizeof(int));;

	if (flip(p->pMut)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
		point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);

		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}


		for(int i=0; i<p->lchrom; i++){
			cMuti[i]=ci[i];
		}

		for (int i=point2; i>point1; i--)
  	   {
        // Pick a random index from 0 to i
        int j = rnd(point1, point2);
        swap(&cMuti[i], &cMuti[j]);
        }

		for(int i=0; i<p->lchrom; i++){
			ci[i] = cMuti[i];
		}
	}	
}

//-INSERT-------------------------------------

int muteX4(POPULATION *p, IPTR c)
{
	int point1, point2,i;
	int *ci,*cMuti;

	ci = c->chrom;
	cMuti = (int *) calloc (p->lchrom, sizeof(int));;

	if (flip(p->pMut)) {

		point1 = rnd(0, p->lchrom - 1);
		do {
		point2 = rnd(0, p->lchrom - 1);
		} while (point2 == point1);

		if (point1 > point2) {
			int temp = point1;
			point1 = point2;
			point2 = temp;
		}

		
		for (i = 0; i<= point1; i++)
			cMuti[i] = ci[i];

		cMuti[point1+1]=ci[point2];
		int index = point1+2;

		for (i=point1+1; i<p->lchrom; i++,index++)
		{
			if (i==point2)
			{
				i++;
			}
			cMuti[index] = ci[i];
		}

		for(int i=0; i<p->lchrom; i++){
			ci[i] = cMuti[i];
		}
	}
	
}

