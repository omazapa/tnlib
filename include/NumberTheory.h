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

bool primos_dosados(int n,long long int *primos);

void euclides_extendido(long long int  a, long long int b, long long int *coef1, long long int  *coef2);

void congruencia_lineal(long long int a,long long int b,long long int m);

void congruencia_lineal_x0(long long int a,long long int b,long long int m,long long int x0);

//soluciona la ecc diofantica para los coefficientes ax+by=m 
//y evalua los valores de t del array donde n es el tamano de n
void ecucacion_diofantica(long long int a, long long int b,long long int m, long long int t[], int n);

void ecucacion_diofantica_x0_y0(long long int a, long long int b,long long int m, long long int t[], int n,long long int x0,long long int y0);

//resulve el sistema 
//x=a(i)mod(m(i)) para 0<i<n
//retorna false o true si se genera o no un error
bool teorema_chino(int n,long long int  *x, long long int  *a, long long int  *m);
bool inverso_modular(long long int a,long long int m,long long int *inverso);

#endif

