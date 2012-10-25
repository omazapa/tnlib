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

//Números primos entre si dos a dos son aquellos donde cada uno es primo con cada uno de los demas. 
//Así 33, 8, 7 y 55 son primos entre si ya que cada uno es primo entre si con los demas
//http://enciclopedia.us.es/index.php/N%C3%BAmero_natural_primo
//n es el tamaño del array primos el array con los numeros a mirar si son dos a dos
bool primos_dosados(int n,long long int *primos)
{
  	int i,j;

	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++) {
			if (gcd(primos[i],primos[j])!=1) return false;
		}
	return true;
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

//http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Formal_description_of_the_algorithm
//el algoritmo extendido de euclides que me permite hallar a*coef1+b*coef2=gcd(a,b)
//dados un a y b me retorna coef1, coef2 
//NOTA: el m para este ejercicio es gcd(a,b)
void euclides_extendido(long long int a, long long int b, long long int *coef1, long long int *coef2)
{
  //el valor inicial de residue uno para que entre iterando en el while
  long long int x,y,lastx,lasty,quotientr1,quotientr2,quotient,residue=1;
	
	if (a<b){
	  //necesito que a>=b para la divison que hay mas abajo
	  euclides_extendido(b,a,coef2,coef1);
	  return;
	}
	x=1; y=0;
	lastx=0; lasty=1;
	while (residue != 0) {
		quotient = a/b;
		residue = a%b;
		quotientr1 = x - quotient*lastx;
		quotientr2 = y - quotient*lasty;
		x=lastx; y=lasty;
		lastx=quotientr1 ; lasty=quotientr2 ;
		a =b ; b =residue ;
	}
	//paso los valores a los punteros
	coef1[0]=x;
	coef2[0]=y;
}

//calcula el sistema linel (a)x=(b)mod(m)
//calcula automaticamente el x0

void congruencia_lineal(long long int a,long long int b,long long int m)
{
  long long int mcd=gcd(a,b);
  long long int coef1,coef2;
  if (b%mcd!=0) 
  {
		printf("El sistema es inconsistente, la congruencia lineal no se puede resolver.\n");
		return;
  }
  euclides_extendido(a,b,&coef1,&coef2);
  
  //solucion inicial x0
  long long int x0 = (coef1*b/mcd)%m;
  printf("x0 = %ld\n",x0);
 //itero las demas soluciones
  long long int t;
   for (t=0; t<mcd; t++) printf("x=%ld  \n",x0+t*(m/mcd));    
}

//es la congruencia lineal pero nosotros le damos el valor inicial
void congruencia_lineal_x0(long long int a,long long int b,long long int m,long long int x0)
{
  long long int mcd=gcd(a,b);
  long long int coef1,coef2;
  if (b%mcd!=0) 
  {
		printf("El sistema es inconsistente, la congruencia lineal no se puede resolver.\n");
		return;
  }
  euclides_extendido(a,b,&coef1,&coef2);
  
 //itero las demas soluciones
  long long int t;
   for (t=0; t<mcd; t++) printf("x=%ld  \n",x0+t*(m/mcd));   
}

void ecucacion_diofantica(long long int a, long long int b,long long int m, long long int t[], int n)
{
    long long int coef1,coef2;
    long long int mcd=gcd(a,b);
    euclides_extendido(a,b,&coef1,&coef2);
	if (m%mcd!= 0) {
		printf("El sistema es inconsistente, la ecuación diofantica no se puede resolver\n");
		return;
	}
     //con esto tengo una posible condicion inicial
     //si quiero poner condiciones iniciales uso la otra funcion
     //ecucacion_diofantica_x0_y0
     long long int x0=coef1*m/mcd;
     long long int y0=coef2*m/mcd;
     int i;
     //ya tenemos las condiciones iniciales solo es iterar sobre t
     //los n elementos dados en el array para imprimir los x(i), y(i)
     long long int xi;
     long long int yi;
     //los for son para imprimir los datos en tablas, \t es un tab como espacio
     //referencia http://www.tenouk.com/Module5.html
     for(i=0;i<n;i++){
       if(i==0)   printf("t=%ld\t\t|",t[i]);
       else   printf("%ld\t\t|",t[i]);
      }
     printf("\n");
     for(i=0;i<n;i++)
     {
       xi=x0+(b/mcd)*t[i];
        if(i==0)  printf("x=%ld\t\t|",xi);
       else printf("%ld\t\t|",xi);
     }
      printf("\n");
     for(i=0;i<n;i++)
     {
        yi=x0-(a/mcd)*t[i];
        if(i==0)  printf("y=%ld\t\t|",yi);
        else printf("%ld\t\t|",yi);
     }
      printf("\n");
}

void ecucacion_diofantica_x0_y0(long long int a, long long int b,long long int m, long long int t[], int n,long long int x0,long long int y0)
{
      long long int coef1,coef2;
    long long int mcd=gcd(a,b);
    euclides_extendido(a,b,&coef1,&coef2);
	if (m%mcd!= 0) {
		printf("El sistema es inconsistente, la ecuación diofantica no se puede resolver\n");
		return;
	}
     int i;
     //ya tenemos las condiciones iniciales solo es iterar sobre t
     //los n elementos dados en el array para imprimir los x(i), y(i)
     long long int xi;
     long long int yi;
     //los for son para imprimir los datos en tablas, \t es un tab como espacio
     //referencia http://www.tenouk.com/Module5.html
     for(i=0;i<n;i++){
       if(i==0)   printf("t=%ld\t\t|",t[i]);
       else   printf("%ld\t\t|",t[i]);
      }
     printf("\n");
     for(i=0;i<n;i++)
     {
       xi=x0+(b/mcd)*t[i];
        if(i==0)  printf("x=%ld\t\t|",xi);
       else printf("%ld\t\t|",xi);
     }
      printf("\n");
     for(i=0;i<n;i++)
     {
        yi=x0-(a/mcd)*t[i];
        if(i==0)  printf("y=%ld\t\t|",yi);
        else printf("%ld\t\t|",yi);
     }
      printf("\n");
}

//resulve el sistema 
//x=a(i)mod(m(i)) para 0<i<n
//http://www.dma.fi.upm.es/java/matematicadiscreta/Aritmeticamodular/congruencias2.html
//en el link anterior explican como se saca con el inverso modular
bool teorema_chino(int n,long long int  *x, long long int  *a, long long int  *m)
{
  //miramos si son primos entre si o primos dos a dos (coprimos)
  if (primos_dosados(n,m) != 1) return false;
  long long int productoria=1;//termino con el que hago la productoria de los modulos m
  long long int i;
  //variables temporales
  long long int divisores[n],inversos_mudulares[n];
  
  for(i=0;i<n;i++) productoria*=m[i];
  
        for (i=0; i<n; i++) {
                divisores[i]= productoria / m[i];
                inverso_modular(divisores[i],m[i],&inversos_mudulares[i]);
        }
        x[0]= 0;
	for (i=0; i<n; i++)
		x[0] +=  a[i] * divisores[i] * inversos_mudulares[i];
	x[0] %= productoria;
	return true;
}

//tomado de wikipedia, el algoritmo hecho con euclides_extendido
//http://es.wikipedia.org/wiki/Inverso_multiplicativo_(aritm%C3%A9tica_modular)
//3m ≡ 1 (mod 11)
//El m más pequeño que resuelve esta congruencia es 4; así pues, el multiplicador modular inverso de 3 (mod 11) es 4. 
bool inverso_modular(long long int a,long long int m,long long int *inverso)
{
  long long int coef1, coef2, mcd=1;
        euclides_extendido(a,m,&coef1,&coef2);
	mcd=gcd(a,m);
	
	if (mcd!=1) return false;
	*inverso = coef1;
	if (*inverso<0) *inverso += m;
	return true;
}
