#include <iostream>
#include <stdlib.h>
#include <cmath>  // Me daba error con 1 + random() % 9
#include <windows.h>
#include <time.h> // para el srand(time(NULL));	
 
using namespace std;


char matriz[3][3];
void escoger(char &jugador1, char &jugador2);
void ValMatriz(char matriz[3][3]);
void tablero(char matriz[3][3]);
void Player(char matriz[3][3], char jugador1, char jugador2, string nombre1);
void Player2(char matriz[3][3], char jugador1, char jugador2);
int ganador(char matriz[3][3], char jugador1 ,char jugador2);

int main(){
	cout<<"\t!!BIENVENIDOS AL JUEGO DE 3 EN RAYA!!"<<endl;
	
	string nombre1; cout<<"Inserte su nombre o nickname: "; cin>>nombre1;
	string nombre2; cout<<"Inserta el nombre o nickname de su oponente: "; cin>>nombre2;
	
	system("cls");
	
	char matriz[3][3];
 	char jugador1, jugador2;
 	char jugada;
 
	escoger(jugador1, jugador2);
	Sleep(1000);
	
	ValMatriz(matriz);
	tablero(matriz);
	
	int i=0, j;
	
	do{
		
		system("cls");
		tablero(matriz);
	
		if( i%2 == 0){
			Player(matriz,jugador1, jugador2,nombre1);

		} 
		else{
			Player2(matriz, jugador1,jugador2);
		}
		j = ganador(matriz, jugador1, jugador2);
		i++;
		
	}while( i<=9 && j==2);
	
	system("cls");
	tablero(matriz);
	
	if (j == 0){
		cout<<"FELICITACIONES "<< nombre1 <<" GANASTEEEE!\n";
	}
	else if (j == 1){
		cout<<"FELICITACIONES "<< nombre2 <<" GANASTEEEE!\n";
	}
	else{
	cout<<"HUBO UN EMPATE!"<<endl;
	}

}

void escoger(char &jugador1, char &jugador2){
  	cout<<"Digite que ficha desea ser 'X' o 'O': "; cin>>jugador1;
  	cout<<endl;
  	if(jugador1=='X'){
		jugador2 ='O';
		cout<<"Elegiste "<<jugador1<<endl;
		cout<<"El oponente juega con la ficha "<<jugador2<<endl;
  	}
  	else if(jugador1=='O'){
    	jugador2 ='X';
    	cout<<"Elegiste "<<jugador1<<endl;
    	cout<<"El oponente juega con la ficha "<<jugador2<<endl;
	
	}
}

void Player(char matriz[3][3], char jugador1, char jugador2, string nombre1){
	int i,j,z=0;
	char jugada;
	
	do{
		do{
			cout<<"\n";
			cout<<nombre1<<", digite la posicion donde desea colocar la ficha: "; cin>>jugada;
		}while (jugada < '1' || jugada > '9');
		
		z = 0;
		
		switch(jugada){
			
			case '1':
				i = 0; j = 0;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
			
			case '2':
				i = 0; j = 1;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
				
			case '3':
				i = 0; j = 2;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
				
			case '4':
				i = 1; j = 0;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
				
			case '5':
				i = 1; j = 1;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
				
			case '6':
				i = 1; j = 2;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
				
			case '7':
				i = 2; j = 0;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
			
			case '8':
				i = 2; j = 1;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
			
			case '9':
				i = 2; j = 2;
				if(matriz[i][j] == jugador1 || matriz[i][j] == jugador2){
					z = 1;
					cout<<"Posicion ocupada, intente en otra posicion\n";
				}
				break;
					
		}
	} while (z == 1);
	matriz[i][j] = jugador1;
}

void Player2(char matriz[3][3], char jugador1,char jugador2){
	int i, j, z;
	 
	srand(time(NULL));	
	
	do{
		i = rand() % 3;
		j = rand() % 3;	
		z = 0;
			
		if(matriz[i][j] == jugador1 && matriz[i][j] == jugador2){
			z = 1;
		} 
		break;
		
	}while (z==1);	
	matriz[i][j] = jugador2;
}

int ganador(char matriz[3][3], char jugador1 ,char jugador2){
	if( matriz[0][0] == jugador1 || matriz[0][0] == jugador2){
		if (matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]){ // 1 2 3
			if(matriz[0][0] == jugador1){
				return 0;
			}
			else return 1;
		}	
		
			if (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]){ // 1 4 7
				if(matriz[0][0] == jugador1){
					return 0;
				}
				else return 1;
			}
	}	
	
	
	if (matriz[1][1] == jugador1 || matriz[1][1] == jugador2){
		if (matriz[1][1] == matriz[0][0] && matriz[1][1] == matriz[2][2]){ // 1 5 9
			if(matriz[0][0] == jugador1){
				return 0;
			}
			else return 1;
		}
		if (matriz[1][1] == matriz[1][0] && matriz[1][1] == matriz[1][2]){ // 4 5 6
			if(matriz[1][1] == jugador1){
				return 0;
			}
			else return 1;
			
		}
		if  (matriz[1][1] == matriz[2][0] && matriz[1][1] == matriz[0][2]){  // 7 5 3
			if(matriz[1][1] == jugador1){
				return 0;
			}
			else return 1;
		}
		if  (matriz[1][1] == matriz[0][1] && matriz[1][1] == matriz[2][1]){  // 2 5 8
			if(matriz[1][1] == jugador1){
				return 0;
			}
			else return 1;
		}	

		
	}
	
	if(matriz[2][2] == jugador1 || matriz[2][2] == jugador2){
		if(matriz[2][2] == matriz[2][0] && matriz[2][2] == matriz[2][1]){ // 7 8 9
			if (matriz[2][2] == jugador1){
				return 0;
			}
			else return 1;
		}
		
		if(matriz[2][2] == matriz[0][2] && matriz[2][2] == matriz[1][2]){ // 3 6 9
			if (matriz[2][2] == jugador1){
				return 0;
			}
			else return 1;
		}
	}
	return 2;
}


void ValMatriz(char matriz[3][3]){ // Funcion para crear la matriz
	char aux='1'; // inicializamos un aux para luego darle valores a la matriz
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			matriz[i][j] = aux++; // damos valores en la matriz
		}
	}
}

void tablero(char matriz[3][3]){ // Función para dibujar tablero	
	cout<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(j>0 && j<3){ // Condicional para que no imprima | <- en la primera columna y ultima columna
				cout<<" | "<<matriz[i][j];
			}
			else{
				cout<<"  "<<matriz[i][j];
			}
		}
		if(i<2){ // Condicional para que en la ultima fila no imprima -> -----------
			cout<<"\n-------------\n";
		}
	
	}
	cout<<endl; // Salto de linea para darle un espacio al final
}
