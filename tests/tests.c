#include<NumberTheory.h>
#include "../../root/include/rsaaux.h"
#include<stdio.h>
int main()
{
  int n=2;
  long long int primo=563851;
  long long int phiArg=14;
  long long int a=18,b=30,m=42;//18x=30mod42
  if(esPar(n))  printf("n=%d es par\n",n);
  if(esImpar(n+1)) printf("n+1=%d es impar \n",n+1);
  printf("gcd %d\n",gcd(a,b));
  printf("lcm %d\n",lcm(6,21));

  
  if(esPrimo(primo)) printf("%lld es primo\n",primo);

  long long i=2;
  while(true)
  {
    if(esPrimo(i)) printf("%lld\n",i);
    i+=i;
    if(i>primo) break;
  }
  
  printf("phiEuler(%d)=%d\n",phiArg,phiEuler(phiArg));
  
  long long int coef1,coef2;
  euclides_extendido(a,b,&coef1,&coef2);
  printf("euclides extendido coef1=%ld  coef2=%ld\n",coef1,coef2);
  
  //este calcula el x0 automaticamente
  congruencia_lineal(a,b,m);
  //este nos da la seria empezando desde el x0 dado.
  congruencia_lineal_x0(a,b,m,4);
  //ecuacion diofantica 2x+5y=28 donde a=2,b=5,m=28
  a=2;b=5;m=28;
  long long int t[]={-3,-2,1,2,3};//los valores de t para evaluar x & y
  n=5;
  printf("--------------------------------------------------------------------------------\n");
  ecucacion_diofantica(a,b,m,t,n);
  printf("--------------------------------------------------------------------------------\n");
  ecucacion_diofantica_x0_y0(a,b,m,t,n,4,4);
  
  //3m ≡ 1 (mod 11) //profe tomado de wikipedia y necesitado para el teorema chino xD
  //El m más pequeño que resuelve esta congruencia es 4; así pues, el multiplicador modular inverso de 3 (mod 11) es 4. 
  long long int inverso;
  if(inverso_modular(3,11,&inverso)) printf("inverso modular de 3m ≡ 1 (mod 11) = %ld\n",inverso);
  
  //el siguiente es el teorema chino del resto
  //prueba con ejercicio hecho en clase
  long long int x;
  long long int a_vector[]={2,3,2};
  long long int m_vector[]={3,5,7};
  if(teorema_chino(3,&x,a_vector,m_vector)) printf("teorema chino x = %ld\n",x);
 
  return 0;
}
