// Tecnologico de Costa Rica - Estructuras de Datos Gr02 - Proyecto 3B-  Jose Pablo Aguero Mora 2021126372 - Katerine Guzman Flores 2019390523 - Prof: Victor Garro Abarca


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;


// ************************************************************ InvertirBit *******************************************************
// Coloca 0 si el bit es 1 y viceversa, en la posicion deseada
void InvertirBit(int& Simbolo, int cual)
{
	int Mascara = 1; // se pone el bit encendido

	Mascara = Mascara << cual; // Se coloca el bit encendido en la posicion cual
	Simbolo = Simbolo ^ Mascara; // Se procede a hacer un xor con la mascara y el byte inicial
}

// Se aplica el veneno correspondiente
void Veneno_1(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir = 0; // Se asigna la ubicacion del bit a invertir

	for (i = 0; i <= limite; i++) { // se hace un ciclo para ir introduciendo bit a bit los char del bloque
		int numero = atoi(Bloque); // se pasa el char que contiene el bloque a int para poder usarlo como parametro de simbolo en invertirBit
		InvertirBit(numero, posicion_a_invertir); // Se aplica la inversión
	}
}

// El antidoto consiste en aplicarle nuevamente el veneno al archivo generado despues de la inversion, de esta forma se recupera el archivo original
void Antidoto_1(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir = 0; // Se coloca la posicion a invertir dentro del byte

	for (i = 0; i <= limite; i++) { // introduce bit a bit
		int numero = atoi(Bloque);
		InvertirBit(numero, posicion_a_invertir); // se restaura el archivo, con el mismo peso
	}
}

// *********************************************************** Encender Bit ******************************************************

// Prende el bit deseado segun la posicion dos del byte, y si esta encendido, lo deja igual
void EncenderBit(int& Simbolo, int cual)
{
	int Mascara = 1; // Se pone el bit en 1 que indica que este estara encendido

	Mascara = Mascara << cual; // Se enciende el bit en la posicion cual
	Simbolo = Simbolo | Mascara; // Se realiza un or para poder encender el bit deseado
}

// Se aplica el veneno correspondiente
void Veneno_2(char Bloque[1000], int limite)
{
	int i;

	int posicion_a_encender = 1;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		EncenderBit(numero, posicion_a_encender);
	}
}

// Se aplica el antidoto correspondiente
void Antidoto_2(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_encender = 1;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		EncenderBit(numero, posicion_a_encender);
	}
}

// *********************************************************** Apagar Bit ********************************************************

// Apaga el bit deseado segun la posicion 0 del byte, y si esta apagado, lo deja igual en 0
void ApagarBit(int& Simbolo, int cual)
{
	int Mascara = 1; // Se pone el bit en 1 que indica que este estara encendido

	Mascara = Mascara << cual; // Se enciende el bit en la posicion cual
	Mascara = ~Mascara; // Se niega la máscara 
	Simbolo = Simbolo & Mascara; // Se aplica un and con mascara y simbolo(byte original)
}

// Se aplica el veneno correspondiente
void Veneno_3(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_apagar = 0;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		ApagarBit(numero, posicion_a_apagar);
	}
}

// Se aplica el antidoto correspondiente
void Antidoto_3(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_apagar = 0;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		ApagarBit(numero, posicion_a_apagar);
	}
}
// *********************************************************** Apagar Segundo Bit ********************************************

// Se apaga un bit en las posiciones deseada (dos y cuatro), a traves de negar la mascara y hacer un and con el byte original
void ApagarBitSegundoCuarto(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Mascara = ~Mascara;
	Simbolo = Simbolo & Mascara;
}

// Se aplica el veneno correspondiente
void Veneno_4(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_apagar_1 = 1;
	int posicion_a_apagar_2 = 3;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		ApagarBitSegundoCuarto(numero, posicion_a_apagar_1); // Se apaga el bit en posicion 2
		ApagarBitSegundoCuarto(numero, posicion_a_apagar_2); // Se apaga el bit en posicion cuatro
	}
}

// Se aplica el antidoto correspondiente
void Antidoto_4(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_apagar_1 = 1;
	int posicion_a_apagar_2 = 3;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		ApagarBitSegundoCuarto(numero, posicion_a_apagar_1);
		ApagarBitSegundoCuarto(numero, posicion_a_apagar_2);
	}
}

// ************************************************************ InvertirBit + Encender Bit *******************************************************

// Combinacion de metodo invertir bit y encender bit pero cambia la posicion del bit a psoicion cuatro y cinco
void InvertirBitEncenderBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Simbolo = Simbolo ^ Mascara;
}

// Se aplica el veneno correspondiente
void Veneno_5(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir_1 = 4; // Se coloca la posicion cinco a invertir 5 dentro del byte
	int posicion_a_invertir_2 = 3; // Se coloca la posicion cuatro a invertir 4 dentro del byte

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		InvertirBitEncenderBit(numero, posicion_a_invertir_1);
		EncenderBit(numero, posicion_a_invertir_2);
	}
}

// Se aplica el antidoto correspondiente
void Antidoto_5(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir_1 = 4;
	int posicion_a_invertir_2 = 3;

	for (i = 0; i <= limite; i++) {
		int numero = atoi(Bloque);
		InvertirBitEncenderBit(numero, posicion_a_invertir_1);
		EncenderBit(numero, posicion_a_invertir_2);
	}
}

using namespace std;
int main(int argc, char* argv[]) {

	//----------------------------------------------------------------------
	// Pintando a pantalla los argumentos que recibe el programa :  Se esperan en esta prueba 3: 
	// Ejecutable e/d FileOrigen FileDestino
	// e/d = e=encritar   d=desencriptar

	// hasta 4
	for (int i = 0; i < argc; ++i) {
		cout << "argumento " << i << ": " << argv[i] << "\n";
	}
	//----------------------------------------------------------------------

	// Archivos logicos : Buffers tipo FILE
	// Se crean dos archivos
	FILE* ArchivoOrigen, * ArchivoDestino;

	//----------------------------------------------------------------------
	// APERTURA DE ARCHIVO FUENTE Y DESTINO
	/* Apertura del archivo original, para lectura en binario*/
	fopen_s(&ArchivoOrigen, argv[3], "rb");
	if (ArchivoOrigen == NULL)
	{
		perror("No se puede abrir archivo origen ");//, argv[2]
		return -1;
	}

	/* Apertura del archivo destino, para escritura en binario*/
	fopen_s(&ArchivoDestino, argv[4], "wb");
	if (ArchivoDestino == NULL)
	{
		perror("No se puede abrir archivo destino"); // , argv[2]
		return -1;
	}

	//----------------------------------------------------------------------
	// PROCESAMIENTO DE ARCHIVOS FUENTE Y DESTINO

	/* Bloque de 1000 bytes, para meter lo que vamos leyendo del archivo */
	char buffer[1000];
	/* Para guardar el número de items leidos o si ha habido error */
	int leidos;
	char opcion = argv[1][0]; // (strcmp(opcion, 'e')
	char tipo = argv[2][0]; // se toma el segundo argumento para decidir cual metodo usar segun la opcion

	if (opcion == 'e') // Da verdadero si se quiere "e"ncriptar, cualquier otro es desencriptar
	{  // ENCRIPTANDO

		leidos = fread(buffer, 1, 1000, ArchivoOrigen);

		/* Mientras se haya leido algo ... */
		while (leidos > 0) {
			switch (tipo) {
				// ************************************************ VENENOS ************************************************
			case '1': // invertir bit
				Veneno_1(buffer, leidos); // Ojo esta usando el mismo metodo de desencriptar ya que solo INVIERTE el Bit 0
				break;

			case '2':
				Veneno_2(buffer, leidos); // encender bit
				break;

			case '3':
				Veneno_3(buffer, leidos); // apagar bit
				break;


			case '4':
				Veneno_4(buffer, leidos); // ApagarBit Segundo y Cuartos
				break;

			case '5':
				Veneno_5(buffer, leidos); // Invierte bit en posicion 4 y enciende bit en posicion 5

				break;

			}
			/* ... meterlo en el fichero destino */
			fwrite(buffer, 1, leidos, ArchivoDestino);

			/* y leer siguiente bloque */
			leidos = fread(buffer, 1, 1000, ArchivoOrigen);
		}
	}
	else // DESENCRIPTANDO
	{
		leidos = fread(buffer, 1, 1000, ArchivoOrigen);

		/* Mientras se haya leido algo ... */
		while (leidos > 0)
		{
			// ************************************************ ANTIDOTO **********************************************
			switch (tipo) {
				// ************************************************ VENENOS ************************************************
			case '1':

				Antidoto_1(buffer, leidos); // invertir bit
				break;

			case '2':
				Antidoto_2(buffer, leidos); // encender bit
				break;

			case '3':
				Antidoto_3(buffer, leidos); // apagar bit
				break;


			case '4':
				Antidoto_4(buffer, leidos); // ApagarBit Segundo y Cuarto
				break;

			case '5':
				Antidoto_5(buffer, leidos); // Invierte bit en posicion 4 y enciende bit en posicion 5
				break;

			}

			/* ... meterlo en el fichero destino */
			fwrite(buffer, 1, leidos, ArchivoDestino);

			/* y leer siguiente bloque */
			leidos = fread(buffer, 1, 1000, ArchivoOrigen);
		}
	}

	// Se cierran los archivos

	fclose(ArchivoOrigen);
	fclose(ArchivoDestino);


}