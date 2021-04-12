// CESAR LENGUA MÁLAGA

#include<iostream>

using namespace std;

void ValoresMatriz(char matriz[3][3]);
void Tablero(char matriz[3][3]);


int main(){
	char matriz[3][3];
	
	ValoresMatriz(matriz);
	Tablero(matriz);

	return 0;
}

void ValoresMatriz(char matriz[3][3]){ // Funcion para crear la matriz
	char aux='1'; // inicializamos un aux para luego darle valores a la matriz
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			matriz[i][j] = aux++; // damos valores en la matriz
		}
	}

}
void Tablero(char matriz[3][3]){ // Función para dibujar tablero
	
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
