#include <iostream>
#include <string>

using namespace std;



int main(int argc, char const *argv[])
{
	string nombre1, nombre2;
	char intento;
	int numRobot = 1, i, j, ocupado = 1;
	int tablero[6][6];

	cout << "Bienvenido a Decodificado\n" << endl;
	cout << "Introduzca el nombre del 1er jugador:"  << endl;
	cin >> nombre1;
	cout << "Introduzca el nombre del 2do jugador:"  << endl;
	cin >> nombre2;

	i = 0;
	j = 0;

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

	while(numRobot < 7) {
		cout << "\nIngrese las coordenadas en X del robot n°" << numRobot << endl;
		cin >> j;
		if(j >= 5 || j < 0) {
			while(j >= 5 || j < 0) {
				cout << "Esta posición no es válida. Intente otra posición\n" << endl;
				cout << "\nIngrese las coordenadas en X del robot n°" << numRobot << endl;
				cin >> j;
			}
		}
		cout << "\nIngrese las coordenadas en Y del robot n°" << numRobot << endl;
		cin >> i;
		if(i < 0 || i > 5) {
			while(i < 0 || i > 5) {
				cout << "Esta posición no es válida. Intente otra posición" << endl;
				cout << "\nIngrese las coordenadas en Y del robot n°" << numRobot << endl;
				cin >> i;
			}
		}
		while() {
			while() {
				cout << "Esta posición está ocupada. Intente otra posición" << endl;
				cout << "\nIngrese las coordenadas en X del robot n°" << numRobot << endl;
				cin >> j;
			}
			cout << "Esta posición está ocupada. Intente otra posición" << endl;
				cout << "\nIngrese las coordenadas en Y del robot n°" << numRobot << endl;
				cin >> i;
		}
		tablero[i][j] = ocupado;
		tablero[i][j+1] = ocupado;
		numRobot++;
		ocupado++;
	}



/*	do
	{
		while(numRobot < 7) {
			cout << "\nIngrese las coordenadas en X del robot" << numRobot << endl;
			cout << "\nIngrese las coordenadas en Y del robot" << numRobot << endl;
		}
 	} while (intento == 'n');*/

	//Función de mostrar array
	for (i=0;i<6;i++)
	{	
		for (j=0;j<6;j++)
		{	
			printf("[%d]",tablero[i][j]);							
		}
		printf("\n");
	}
	/*cout << "\nReglas del juego: \n 1.El juego se desenvuelve en un tablero, el cual es una cuadrícula de 6x6\n 2.Se solicitarán las coordenadas de cada uno de los robots\n 3.Una vez posicionados los 6 robots en el tablero, empieza el juego.\n 4.El jugador indicará una coordenada y si ese cuadro está ocupado por un robot, este será decodificado y esa casilla es libre.\n 5.El juego termina cuando se han decodificado todos los robots o se han agotado las oportunidadeas." << endl;*/

	return 0;
}