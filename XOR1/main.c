#include <stdio.h>
#include <stdlib.h>



#include <time.h>
#include <math.h>
#include "xor.h"
#include "gen_xor.h"

double biais[3];
double weight[6];


void XOR()
{
  system("clear");
  generate_arrays_xor(biais,weight);
  printf("Training Neural Network to Xor\n\n");
  printf("Input   (0,0)   (0,1)   (1,0)   (1,1):\n\n");
  for(int i =0;i <= 100000;i++)
  {
    if( i % 10000 == 0)
    {
     printf("%d Trainings\n\n",i);
     double Error = Train(weight,biais,1);
     printf("Total Error = %g\n\n",Error);
    }
    else
    {
       Train(weight,biais,0);
    }
  }
}