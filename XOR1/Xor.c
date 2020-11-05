#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* On définit la fonction sigmoïde*/
double Sigm(double x)
{
  return 1 / (1 + exp(-x));
}


/* 
 * On définit sa dérivé
 */
double Dsigm(double x)
{
  return x * (1 - x);
}


/* 
 * On définit la fonction activation qui
 * ajoute les valeurs des neurones 
 * dans un tableau après leur activation
 * X et Y sont les inputs                    
 */
void Activation(double act[],double We[], double Bi[],char x,char y)
{
  act[0] = Sigm( x * We[0] + y * We[2] + Bi[0]);
 /* printf("%g\n", x * We[0] + y * We[2] + Bi[0]);*/
  act[1] = Sigm( x * We[1] + y * We[3] + Bi[1]);
  act[2] = Sigm( act[0] * We[4] + act[1] * We[5] + Bi[2]);
 /* printf("%g %g %g \n", act[0],act[1],act[2]);*/
}


/* 
 * Cette fonction ajoute les modifications de tous les poids
 * dans l'array Ch pour un input donné
 */
void MuteWeight(double act[],double We[],double Ch[],char x,char y,char res)
{
  double Error = (act[2] - res) * Dsigm(act[2]);
  Ch[4] += Error * act[0];
  Ch[5] += Error * act[1];

  for(int i = 0;i < 2; i++)
  {
    double Nerror = Error * We[4 + i];
    for(int z = 0; z < 2;z++)
    {
      if(z == 0)
        Ch[i + z * 2] += Nerror * Dsigm(act[i]) * x;
      else
        Ch[i + z * 2] += Nerror * Dsigm(act[i]) * y;
    }
  }
}


/* 
 * On fait de même pour les biais
 */
void MuteBias(double act[],double We[],double Ch[],char res)
{
  double Error = (act[2] - res) * Dsigm(act[2]);
  Ch[2] += Error;
  Ch[0] += Error * Dsigm(act[0]) * We[4];
  Ch[1] += Error * Dsigm(act[1]) * We[5];
}


/* 
 * Fonction qui entraine le réseau
 */
double Train(double We[],double Bi[], char print)
{
  char input[4][2] = {{0,0},{0,1},{1,0},{1,1}};
  char target[4] = {0,1,1,0};
  double Chw[6] = {0,0,0,0,0,0};
  double Chb[3] = {0,0,0};
  double Acti[4][3];

  for(int i = 0; i < 4;i++)
  {
    Activation(Acti[i],We,Bi,input[i][0],input[i][1]);
    MuteWeight(Acti[i],We,Chw,input[i][0],input[i][1],target[i]);
    MuteBias(Acti[i],We,Chb,target[i]);
  }

  for(int i = 0; i < 6; i++)
    We[i] -= 0.2*Chw[i]/4;

  for(int i = 0; i < 3; i++)
    Bi[i] -= 0.2*Chb[i]/4;

  if(print == 1)
    printf("%g %g %g %g \n",Acti[0][2],Acti[1][2],Acti[2][2],Acti[3][2]);

  double Error = 0;

  for(int i = 0;i < 4;i++)
      Error += pow((Acti[i][2] - target[i]),2);

  return Error/4;
}