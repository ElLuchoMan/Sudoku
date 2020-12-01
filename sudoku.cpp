//Charles Andrés Hurtado Cod:20142020142, Daniel Uribe Cod: 20142020139, Brayan Luis Cod: 20142020136.
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;
int cuadricula [9][9];

void cuadro (int, int);
void verificar(int, int);
void ingresar(int, int);
void azar();
void revisar (int,int);
int comprobar (int,int,int);

int menu()    {
    int opcion;
    cout<<"\n   MENU\n";
    cout<<"1. Iniciar nuevo juego\n";
    cout<<"2. Inicio aleatorio\n";
    cout<<"3. Ingresar valor\n";
    cout<<"99. Salir\n";
    cout<<"Digite la opcion deseada: ";
    cin>> opcion;
    return opcion; 
}    

int main ()       {
    system ("color b0");
    srand (time (NULL));
    int filas, columnas;
    int opcion;
    int a, b;
    do   {
    	printf("                SUDOKU UD             ");
        opcion=menu();
             switch(opcion)          {    
                case 1: cuadro (a,b); 
						break;     
				case 2:	azar ();	
				        cuadro (a,b);                                  
                		break;				
                case 3: for (int i=0; i<80; i++) {
                        ingresar (filas, columnas);
                        revisar (a,b); 
						system("cls");
						printf("                SUDOKU UD             ");
						cout<<endl;
						cuadro(a,b);
						cout<<endl;
						}
                        break;  
				//case 2: verificar (a,b);		               
        }       //        break;
   } while (opcion!=99);                    
    system("pause"); 
} 

 void revisar (int a, int b)  {
 	int valor;
 	a=9;
 	b=9;
 	for (int k=0; k<a; k++)   {
 		cuadricula[k][1]=valor;
      if (valor=cuadricula[k+1][1] )	{
       if (valor=cuadricula[k+2][1] )
        if (valor=cuadricula[k+3][1] )
         if (valor=cuadricula[k+4][1] )
          if (valor=cuadricula[k+5][1] )
           if (valor=cuadricula[k+6][1] )
             cout<< "ERROR"<<endl;
		     valor=0; 
		     cuadricula[k][1]=valor;
		     cout<<"Numero no permitido"<<endl;
             //cuadro(a,b); 
		}   
}  
  }   
 
 void cuadro (int a,int b) 
    {
    int x,z;
    int i,j;
    int it=0,ij=0;
    a=9;
    b=9;
    for (i=0;i<a;i++)
    {
   	
        if ((i==3 || i==6) && it==0){
          for(j=0; j<11; j++)
             cout<<"__";
             cout<<endl;
             it=1;
          }
        else
          it =0;
          for(j=0; j<b; j++)
             if((j==3 || j==6) && ij==0){
                cout<<"| ";
                j--;
                ij=1;
                }
             else {
                    	     
				cout<<cuadricula[i][j]<<" ";
                ij=0;}
                cout<<endl;
    }
    }
 
 void azar ()   {  
int total, numcolocar, filas, columnas, valido=0, num2=0;
	srand(time(NULL));
		total=rand()%10+16;
	do{																	//funcion para generar numeros al azar , respetando las condiciones.
	filas=rand()%9;
		columnas=rand()%9;
			numcolocar=rand()%9+1;
	valido=comprobar(filas, columnas, numcolocar);				//funcion que permite comprobar si los numeros generados son validos.
		if(valido==0){
			cuadricula[filas][columnas]=numcolocar;
			num2++;
		}
	}while(total>=num2);
}
 
 
 
 void ingresar(int filas, int columnas)  {
 	  system("color b0");
 	  int a,b,valor,fila,columna,x,validacion;
      cout<<"Ingrese la fila " ;                 
      cin>> filas;
        if (filas==0 || filas>9)   { 
          while (filas==0 || filas>9)  {
		   cout<<"Fila inexistente en el tablero"<<endl;
		   cout<<"Digite nuevamente la fila"<<endl;
		   cin>>filas;
	      }}
      cout<<"Ingrese la columna ";                      
      cin>> columnas;
        if (columnas==0 || columnas>9) {
          while (columnas==0 || columnas>9)  {              
		   cout<<"Columna inexistente en el tablero"<<endl;
		   cout<<"Digite nuevamente la columna"<<endl;
		   cin>>columnas;
	    } }
      cout<<"Ingrese el valor ";                      
      cin>> valor; 
           
    if (valor==0 || valor>9)    {  
       while (valor==0 || valor>9)  {
	    cout<<"Valor invalido"<<endl;
	   	cout<<"Digite el valor nuevamente"<<endl;
	  	cin>> valor;
     }
     validacion=comprobar(filas-1, columnas-1, valor);
     if(validacion==0){
		 cuadricula[filas-1][columnas-1]=valor; 
         cuadro (a,b); 
         
				printf("\nEl numero se ha asignado");
 }
}
}
int comprobar(int fila, int columna, int numero){
	int aux=0;												
	for (int i=0;i<9;i++){
		if(cuadricula[fila][i]==numero)
			aux=1;
		else
			if(cuadricula[i][columna]==numero)					
			aux=1;
	}
	return aux;
}
 
