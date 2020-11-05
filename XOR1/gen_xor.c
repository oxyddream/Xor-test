#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gen_xor.h"


void generate_arrays_xor(double biais[], double weight[])
{
    srand(time(NULL));
    int i = 0;
    for(i = 0; i < 3; i++)
      biais[i] = randnum(0.3, 0.7);
    i = 0;
    for(i = 0; i < 6; i++)
      weight[i] = randnum(0.3, 0.7);
}


double randnum(double min, double max)
{
    int nmin = (int)(min * 100);
    int nmax = (int)(max * 100);
    printf("%d\n", (((rand() % (int)(((nmax) + 1) - (nmin))) + (nmin))/100));
    return (double)((rand() % (int)(((nmax) + 1) - (nmin))) + (nmin))/100;
}