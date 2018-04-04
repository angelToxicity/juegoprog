#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string nombre1, nombre2;
	unsigned char next;
	int numRobot = 1, ocupado = 1, intento = 6, i, j, h, x, y;
	int tablero[6][6], matriz[6][6];

	cout << "Bienvenido a Decodificado\n" << endl;
	cout << "\nReglas del juego: \n 1.El juego se desenvuelve en un tablero, el cual es una cuadrícula de 6x6\n 2.Se solicitarán las coordenadas de cada uno de los robots\n 3.Una vez posicionados los 6 robots en el tablero, empieza el juego.\n 4.El jugador indicará una coordenada y si ese cuadro está ocupado por un robot, este será decodificado y esa casilla es libre.\n 5.El juego termina cuando se hayan decodificado todos los robots o se hayan agotado las oportunidades." << endl;
	cout << "\nPresione Enter para continuar!" << endl;
	next = getchar();

	if(next) {

		cout << "Introduzca el nombre del 1er jugador:"  << endl;
		cin >> nombre1;
		cout << "Introduzca el nombre del 2do jugador:"  << endl;
		cin >> nombre2;

		//Inicializo matriz: tablero
		i = 0;
		j = 0;
		h = 0;
		while(i < 6) {
		    while(j < 6) {
		        tablero[i][j] = 0;
		        j++;
		    }
		    j = 0;
		    i++;
		}

		i = 0;
		j = 0;
		h = 0;

		while(i < 6) {
		    while(j < 6) {
		        matriz[i][j] = 0;
		        j++;
		    }
		    j = 0;
		    i++;
		}

		//Lleno la matriz: tablero
		i = 0;
		j = 0;


		while(numRobot < 7) {
			cout << "\nIngrese la coordenada en X del robot n°" << numRobot << endl;
			cin >> i;
			if(i < 0 || i > 5) {
				while(i < 0 || i > 5) {
					cout << "Esta posición no es válida. Intente otra posición" << endl;
					cout << "\nIngrese la coordenada en X del robot n°" << numRobot << endl;
					cin >> i;
				}
			}
			cout << "\nIngrese la coordenada en Y del robot n°" << numRobot << endl;
			cin >> j;
			if(j > 4 || j < 0) {
				while(j > 4 || j < 0) {
					cout << "Esta posición no es válida. Intente otra posición\n" << endl;
					cout << "\nIngrese la coordenada en Y del robot n°" << numRobot << endl;
					cin >> j;
				}
			}
			for (int t = 0; t < 6; ++t)
			{
				if(tablero[i][t] != 0) {
					h++;
				}
			}
			if(h > 0) {
				cout << endl;
				cout << "---------------------------------------------" << endl;
				cout << "Esta fila está llena. Intente otra posición\n" << endl;
				cout << "---------------------------------------------" << endl;
				h = 0;
			}
			else {
				tablero[i][j] = ocupado;
				matriz[i][j] = ocupado;
				tablero[i][j+1] = ocupado;
				matriz[i][j+1] = ocupado;
				numRobot++;
				ocupado++;
			}
		}
	}

	//Jugador 2.
	x = 0;
	y = 0;

	while(intento > 0) {
	
		cout << "\nListo, " << nombre2 << ". Ingrese las coordenadas solicitadas para decodificar los robots" << endl;
		cout << "\n\nTiene " << intento << " intentos." << endl;
		cout << "\nIngrese la coordenada en X" << endl;
		cin >> x;
		if(x < 0 || x > 5) {
			while(x < 0 || x > 5) {
				cout << "Esta posición no es válida. Intente otra posición" << endl;
				cout << "\nIngrese la coordenada en X" << endl;
				cin >> x;
			}
		}
		cout << "\nIngrese la coordenada en Y" << endl;
		cin >> y;
		if(y > 4 || y < 0) {
			while(y > 4 || y < 0) {
				cout << "Esta posición no es válida. Intente otra posición\n" << endl;
				cout << "\nIngrese la coordenada en Y" << endl;
				cin >> y;
			}
		}
		if (tablero[x][y] != 0)
		{
			if(tablero[x][y] == tablero[x][y+1]) {
				tablero[x][y] = 0;
				tablero[x][y+1] = 0;

				h = 0;
				for (int w = 0; w < 6; ++w)
				{
					for (int l = 0; l < 6; ++l)
					{
						if(tablero[w][l] == 0) {
							h++;
						}
					}
				}
				if(h == 36) {
					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << nombre2 << " ha ganado.\n" << endl;
					cout << "---------------------------------------------" << endl;
					break;
				}
				else{
					cout << "Decodificó un robot. Tiene otra oportunidad.\n" << endl;
				}

			}
			else {
				tablero[x][y] = 0;
				tablero[x][y-1] = 0;

				h = 0;
				for (int w = 0; w < 6; ++w)
				{
					for (int l = 0; l < 6; ++l)
					{
						if(tablero[w][l] == 0) {
							h++;
						}
					}
				}
				if(h == 36) {
					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << nombre2 << " ha ganado.\n" << endl;
					cout << "---------------------------------------------" << endl;
					break;
				}
				else{
					cout << "Decodificó un robot. Tiene otra oportunidad.\n" << endl;
				}
			}
		}else{
			intento--;
			cout << "No Decodificó ningún robot. Ha perdido una oportunidad.\n" << endl;
		}
	}

	if (intento == 0)
	{
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << nombre2 << " ha perdido. Se ha quedado sin intentos\n" << endl;
		cout << "---------------------------------------------" << endl;
		cout << endl;
		cout << endl;
		//Blucle para mostrar matriz
		for (i = 0; i < 6; i++)
		{	
			for (j = 0; j < 6; j++)
			{	
				printf("[%d]",matriz[i][j]);							
			}
			printf("\n");
		}
	}
	cout << "¿Desea volver a jugar?\n" << endl;
	cout << "Introduzca s para continuar el juego." << endl;
	cout << "Introduzca n para finalizar el juego." << endl;
	cin >> vuelta;
/*	else{
	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << nombre2 << " ha perdido. Aún quedan robots sin decodificar\n" << endl;
	cout << "---------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	//Blucle para mostrar matriz
	for (i = 0; i < 6; i++)
	{	
		for (j = 0; j < 6; j++)
		{	
			printf("[%d]",matriz[i][j]);							
		}
		printf("\n");
	}

}*/

	return 0;
}