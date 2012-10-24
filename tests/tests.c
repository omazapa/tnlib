#include<NumberTheory.h>
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
  eclides_extendido(a,b,&coef1,&coef2);
  printf("euclides extendido coef1=%ld  coef2=%ld\n",coef1,coef2);
  
  //este calcula el x0 automaticamente
  congruencia_lineal(a,b,m);
  //este nos da la seria empezando desde el x0 dado.
  congruencia_lineal_x0(a,b,m,4);
  return 0;
}
