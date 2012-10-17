//Por Omar Andres Zapata Mesa 

#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H
typedef long int entero;
#include <stdbool.h>
bool esPar(long long int n);

bool esImpar(long long int n);

long long int gcd(long long int a,long long int b);

long long int lcm(long long int a,long long int b);

long long int elMayor(long long int a,long long int b);

long long int elMenor(long long int a,long long int b);

bool esPrimo(long long int a);


long long int phiEulerPow(long long int i, long long int exp);
long long int phiEuler(long long int i);//para exponente 1 por defecto

//soluciona la ecc diofantica para los coefficientes ax+by=c 
//y evalua los valores de t del array donde n es el tamano de n
void eccDiofantica(long long int a, long long int b, long long int t[],int n);

#endif