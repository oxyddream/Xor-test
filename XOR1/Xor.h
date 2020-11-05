
// neural_network_XOR.h
  
#ifndef XOR_H
#define XOR_H

double Sigm(double x);

double Dsigm(double x);

void Activation(double act[],double We[], double Bi[],char x,char y);

void MuteWeight(double act[],double We[],double Ch[],char x,char y,char res);

void MuteBias(double act[],double We[],double Ch[],char res);

double Train(double We[],double Bi[], char print);

#endif