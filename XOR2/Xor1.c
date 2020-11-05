#ifndef XOR_H
#define XOR_H

# include <SDL/SDL.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

typedef struct Neural_Network Netw;

struct Neural_Network
{
    int nbInput;
    int nbHidden;
    int nbOutput;

    //Arrays
    double *InputValue;
    double *Goal;
    //Weight Arrays
    double *WeightIH;
    double *WeightHO;
    //Bias Array
    double *BiasH;
    //Bias output
    double BiasO;
    //Output Hidden
    double *OutputH;
    //Output of output
    double OutputO;
    //Array of delta bias for hidden
    double *dBiasH;
    //delta bias for output
    double dBiasO;
    //delta weight
    double *dWeightIH;
    double *dWeightHO;
    //delta of output
    double dOutputO;
    //delta of hidden
    double *dHidden;
    
    double ErrorRate;
    double eta;
    double alpha;
};