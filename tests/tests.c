#include<NumberTheory.h>
#include<stdio.h>
int main()
{
  int n=2;
  long long int primo=563851;
  long long int phiArg=14;
  if(esPar(n))  printf("n=%d es par\n",n);
  if(esImpar(n+1)) printf("n+1=%d es impar \n",n+1);
  printf("gcd %d\n",gcd(24,6248));
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
  return 0;
}