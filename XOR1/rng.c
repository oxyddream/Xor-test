#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





float Randoms() 
{ 
    float rnd;
    float a = 1.0;
    srand(time(NULL));
    for (int i=0;i<2;i++)
    {
        rnd = ((float)rand()/(float)(RAND_MAX)) * a;
    }
    return rnd;
}


int main()
{
    printf("%f\n", Randoms());
    return 0;
}