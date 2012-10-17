#include"NumberTheory.h"
#include<stdio.h>
#include<stdlib.h>

bool esPar(long long int n)
{
  if((n%2)==0) return true;
  else return false;
}

bool esImpar(long long int n)
{
  if(esPar(n)) return false;
  else return true;
}

long long int gcd(long long int a,long long int b)
{
  //casos particulares
  //gcd(a,0)=a
  if((a>0)&&(b==0)) return a;
  if((b>0)&&(a==0)) return b;
  
  //gcd(a,a)=a
  if(a==b) return a;
  
  //caso general
  //basado en la definicion hallar un c tal q 
  // c|a y c|b
 long long  int c=elMenor(a,b);
  long long int result;
  while(c>=1)
  {
    //miro si divide a los dos desde el menor de los dos
    if(((a%c)==0)&&((b%c)==0)) 
    {
      result=c;
      break;
    }
    c--;
  }
  return result;
}

long long int lcm(long long int a,long long int b)
{
  //caso general
  //basado en la definicion hallar un c tal q 
  // a|c y b|c
long long int c=1;
long long int result=1;
  while(true)
  {
    if(((c%a)==0)&&((c%b)==0)) 
    {
      result=c;
      break;
    }
    c++;
  }
  return result;  
}

long long int elMayor(long long int a, long long int b)
{
  if(a>b) return a;
  else return b;
}

long long int elMenor(long long int a,long long int b)
{
  if(a<b) return a;
  else return b;
}

bool esPrimo(long long int a)
{
  if(a<=1) return false;//estan definidos para a>1
  if((a>2)&&esPar(a)) return false;// los numero pares mayores que 2 son primos

  //contador cuenta cuantas veces es divisible, si es mayor que 1 hasta la mitad
  //
  int contador=0,i=1;
  //como a es impar sumando 1 garantizo que la division por dos es entera
  //y solo miro hasta la mitad para optimizar tiempo de computo, despues
  // de ese numero no tiene sentido
  while(i<=((a+1)/2))
  {
    if((a%i)==0)
    {
//       printf("divisor=%d\n",i);
      contador++;
      if(contador==2)//si antes de llegar a la mitad ya hay 2 divisores que pare pq no es primo
      {
	break;
      }
    }
    i++;
  }
  if(contador==1) return true;
  else return false;
}

bool sonPrimosRelativos(long long int a,long long int b)
{
  if(gcd(a,b)==1) return true;
  else return false;
}

//la funcion phi de euler tambien conocida como la function totient se define como
//phi(N)=|{i/1<=i<=N ^ gcd(i,N)=1}| osea que i es primo relativo
long long int phiEulerPow(long long int N, long long int exp)
{
    if(N<1)
    {
     printf("Error la funcion phiEuler(N) con N=%d (N<1)  deberia ser N>=1\n",N);
     exit(1);
    }
  if(exp==1)
  {
    long long int i;
    long long int counter=0;
    if(N==1) return 1;
    if(N==2) return 2;
    if(N==3) return 3;
    for(i=1;i<=N;i++)
    {
      if(sonPrimosRelativos(i,N)) 
      {  
//          printf("gcd(%ld,%ld)=%ld\n",i,N,gcd(i,N));
         counter=counter+1;//cada que hallamos un primo relativo sumamos el contador
      }
    }
    return counter;    
  }else
  {
    return phiEulerPow(N,exp)-phiEulerPow(N,exp-1); //uso la propieda de phi(p^k)=p^k - p^(k-1)
  }
}

long long int phiEuler(long long int N)
{
  return phiEulerPow(N,1);
}

void eccDiofantica(long long int a, long long int b, long long int t[], int n)
{
  
}
