# N-Queen-Genetic-Algorithm

The **N-Queen** is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. This means that no two Queens should be in the same row or column or diameter.

In computer science and operations research, a genetic algorithm (GA) is a metaheuristic inspired by the process of natural selection that belongs to the larger class of evolutionary algorithms (EA). Genetic algorithms are commonly used to generate high-quality solutions to optimization and search problems by relying on biologically inspired operators such as mutation, crossover and selection.

**In this problem, we want to solve the n queen problem with the help of genetic algorithm.**

## Mutation:
* Insert
* Scramble
* Inversion
* Swap

## Parent selection:
* Roulette wheel
* Ranking

## Crossover
* PMX
* Order

## Survivor selection:
* Genitor
* m + n

## Our result:
### 8-Queen
**PopSize**     |     **Parent selection**      |     **Crossover**     |       **Mutation**      |     **Survivor selection**| **Result**
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
150             |           Roulette            |          PMX          |         Inversion       |          Genitor          |      3                    
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
50             |           Ranking            |          Order          |         Swap       |          m + n         |      6                    


### 16-Queen
**PopSize**     |     **Parent selection**      |     **Crossover**     |       **Mutation**      |     **Survivor selection**| **Result**
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
1000             |           Roulette            |          PMX          |         Inversion       |          Genitor          |      176                    
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
700             |           Ranking            |          PMX          |         Swap       |          Genitor         |      1
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
150             |           Ranking            |          Order          |         Scramble       |          m + n          |      73                    
:--------------:|:-----------------------------:|:---------------------:|:-----------------------:|:-------------------------:|:----------:
500             |           Ranking            |          Order          |         Insert       |          m + n         |      5                    

