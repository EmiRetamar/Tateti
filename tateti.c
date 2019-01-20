// vamos a hablar por aca pero en forma de comentarios dale? sino tenemos que andar
// cambiando de ventana a cada rato xD
// bueno arrancamos, primero voy a agregar la libreria stdio que se usa siempre
#include <stdio.h>
// hacemos una matriz de 3*3 dale? de tipo char ok? 
int main() {
	char tablero[3][3];
	int jugador, i, j, termina = 0, x, y, lleno; // Voy a usar la variable "termina" como si fuera un booleano, osea para saber si se lleno el tablero, o si se hizo tateti, cuando eso pase la cambio a 1.. para que salga del while
	// Las variables "x" e "y" van a tomar los valores que se ingresen de las coordenadas
	// La variable "i" es solamente para iterar en los for que se usen para recorrer la matriz, siempre que uses arreglos vas a tener que declarar variables para recorrerlos porque si tenes que hacer un procesamiento para cada elemento del arreglo es todo lo mismo va cambiando el elemento nomas.. osea el indice del arreglo.
	// Por ejemplo este codigo que use mas abajo lo uso para ir iterando las filas de la matriz
	/* for(i = 0; i < 3; i++) {
					printf("------------- \n");
					printf("| %c | %c | %c | \n", tablero[i][0], tablero[i][1], tablero[i][2]);
				}
	*/
	// Hacer eso es equivalente a hacer esto:
	/* 	printf("------------- \n");
		printf("| %c | %c | %c | \n", tablero[0][0], tablero[i][0], tablero[0][2]);
		printf("------------- \n");
		printf("| %c | %c | %c | \n", tablero[1][0], tablero[1][0], tablero[1][2]);
		printf("------------- \n");
		printf("| %c | %c | %c | \n", tablero[2][0], tablero[2][0], tablero[2][2]);
	*/
	// Es todo lo mismo, al usar el for evitas repetir todo el codigo, si te fijas lo unico que cambia es el primer indice
	// Aca porque tenemos solo 3 filas.. pero suponete que se tengan 100.. no vas a repetir 100 veces lo mismo.. entonces se usa el for para recorrerlo. Siempre que tengas arreglos y necesites recorrerlos para procesarlos, imprimir su contenido, o hacer lo que sea tenes que usar una iteracion.. como for o while la que quieras, por lo general se usa for es mas practica.
	// La variable "lleno" es para cuando se tenga que verificar si la matriz esta llena, para terminar el programa ya que no quedan casilleros para marcar y se debe terminar como empate. Capaz que no sea necesario usar esta variable seguro se puede verificar de otra forma pero esta es la unica forma que se me ocurrio jaja aca esta variable tambien funciona como un booleano. En C no existe el tipo de dato booleano por eso se usan varibles de tipo int como si fueran booleanos en vez de que se tengan los valores true o false se tienen el 0 y el 1.
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			tablero[i][j] = ' '; // Aca inicializo la matriz con espacios en blanco
	printf("Ingrese el jugador que debe comenzar \n");
	scanf("%d", &jugador);
	// Aca podriamos mostrar el tablero vacio, despues veo como armarlo
	while(termina == 0) {
		printf("Turno del jugador %d \n", jugador);
		printf("Ingrese las coordenadas donde desea marcar en el tablero \n");
		printf("Ingrese la coordenada referente a las filas \n");
		scanf("%d", &x);
		printf("Ingrese la coordenada referente a las columnas \n");
		scanf("%d", &y);
		while(tablero[x-1][y-1] != ' ') { // Como el enunciado dice que si esta ocupada no la va a tomar, mientras este ocupada pide que se ingrese otra casilla. Acordate que LOS ARREGLOS EMPIEZAN DE 0, por eso puse x-1 e y-1 porque si vos ingresas por ejemplo la posicion 3, 1 va a buscar en la posicion 4, 2 y la posicion 4 no existe. La matriz tiene las posiciones de las filas y las columnas de 0 a 2. La posicion 0 es la 1, la 1 es la 2 y la 2 es la 3.
		// Hago este while preguntando reiteradas veces si la posicion esa no esta ocupada
		// Porque si esta ocupada deberia pedir que se ingresen otros valores todas las veces que sean necesarias hasta que se ingrese una casilla desocupada
			printf("El casillero está ocupado, por favor elija otro. \n"); // el \n es un salto de linea, para que no quede todo en la misma linea sino queda re desprolijo jaj
			scanf("%d", &x); // Se vuelven a ingresar las coordenadas
			scanf("%d", &y); // Y nada esto va a iterar hasta que se ingrese una coordenada que sea valida, osea que no este ocupada
		}
			if(jugador == 1) { // Pregunto que jugador esta jugando en este momento para saber que marca dejar
				tablero[x-1][y-1] = '1'; // Ubico el 1 en la posicion anterior porque los arreglos comienzan desde la posicion 0 entonces si yo por ejemplo ingreso 1, 2 me lo va a ubicar en la posicion 2, 3 y no en la que le pido.
				for(i = 0; i < 3; i++) {
					printf("------------- \n"); // Esto lo hice a ojo fui probando hasta que me quedo bien el cuadradito, al principio me quedaban lineas demas, y despues me quedaban de menos y no me cerraba jajaj
					printf("| %c | %c | %c | \n", tablero[i][0], tablero[i][1], tablero[i][2]);
				}
				printf("------------- \n");
			}
			else {
				tablero[x-1][y-1] = '2';
				for(i = 0; i < 3; i++) {
					printf("------------- \n");
					printf("| %c | %c | %c | \n", tablero[i][0], tablero[i][1], tablero[i][2]);
				}
				printf("------------- \n");
			}
			for(i = 0; i < 3; i++) {
				if((tablero[i][0] == tablero[i][1]) && (tablero[i][0] != ' ' || tablero[i][1] != ' ')) { // Bueno aca comparo si se hizo tateti en alguna de las filas, primero comparo el contenido de la columna 0 con la columna 1 de la fila i (i va a valer 0, 1 y 2.. va a ir cambiando de valor en cada iteracion) y despues comparo que alguna de las dos posiciones no contenga un blanco, porque puede pasar que sean iguales los valores pero que ambos sean blancos y el programa va a funcionar como que se hizo tateti pero en realidad son casilleros vacios. (fijate que en este caso use el operador OR pregunta si uno o el otro no contiene blanco. Y entre las dos comparaciones use el AND.. osea que si el contenido de las posiciones son iguales Y alguna de las posiciones NO es blanco.. igual es obvio que si son iguales y alguna no es blanco la otra tampoco lo es jaja)
					if(tablero[i][1] == tablero[i][2]) { // Si son iguales con valores validos en la condicion anterior pregunto si la columna 1 es igual a la 2 (Ahi podria preguntar por si la 0 es igual a la 2 es lo mismo si la condicion anterior da verdadera es que en el columna 0 y 1 existe el mismo valor). Si aca pasa que son iguales entonces significa que se hizo tateti en alguna de las filas. En este if no uso las llaves {  y } porque como toma 1 sola linea no se necesitan, solo se usan cuando la condicion necesita tomar mas de 1 linea
						termina = 1; // Cambio el valor de la variable termina para que corte el while de arriba
						printf("El jugador %d es el ganador \n", jugador);
					}
				}
			}
			for(i = 0; i < 3; i++) { // Este caso es similar al anterior solo que en vez de recorrer la matriz por filas la recorro por columnas. Entonces voy verificando si se hizo tateti en alguna columna
				if((tablero[0][i] == tablero[1][i]) && (tablero[0][i] != ' ' || tablero[1][i] != ' ')) { // Solamente cambie el lugar de la i, aca la puse en el segundo indice (que es el de las columnas)
					if(tablero[1][i] == tablero[2][i]) { // Acordate que los arreglos arrancan de 0. Por eso en las posiciones escribi de 0 a 2 nada mas, pero 0 seria la posicion 1, 1 seria la 2, y 2 la 3 jaja
						termina = 1; // Si todas las comparaciones dan correctas, significa que se hizo tateti en alguna columna por eso dejo el termina en 1 asi corta el while
						printf("El jugador %d es el ganador \n", jugador);
				}
			}
			// Ahora queda verificar si se hizo tateti en alguna de las diagonales
			if((tablero[0][0] == tablero[1][1]) && (tablero[0][0] != ' ' || tablero[1][1] != ' ')) { // Aca esto yo lo hice con 2 if para que quede un poquito mas claro, pero tambien se puede hacer asi: if(tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) todo en un mismo if, es lo mismo. Con los casos anteriores pasa lo mismo si queres lo podes hacer con un solo if, si queres despues eso lo cambias como vos quieras
				if(tablero[1][1] == tablero[2][2]) {
					termina = 1;
					printf("El jugador %d es el ganador \n", jugador);
				}
			}
			} // Este if verifica la otra diagonal
			if((tablero[0][2] == tablero[1][1]) && (tablero[0][2] != ' ' || tablero[1][1] != ' ')) { // Y aca verifico la diagonal que falta
				if(tablero[1][1] == tablero[2][0]) {
					termina = 1;
					printf("El jugador %d es el ganador \n", jugador);
				}
			}
			// Y por ultimoooooo verifico si hay un empate, para eso recorro toda la matriz verificando que cada posicion tenga un valor que no sea el espacio en blanco. Osea que la matriz este llena.
			lleno = 1; // Lleno es una variable que me va a indicar si la matriz esta llena, la inicializo en 1 suponiendo que esta llena
			for(i = 0; (i < 3 && lleno != 0); i++) {
				for(j = 0; (j < 3 && lleno != 0); j++) { // Aca como tengo que preguntar por cada posicion en particular recorro tambien por columnas (como al principio cuando inicialice toda la matriz en espacios en blanco)
					if(tablero[i][j] == ' ') // Si alguna de las posiciones contiene un espacio en blanco, cambio la variable lleno a 0, para que corten las iteraciones de los for. Con que 1 espacio este vacio ya es suficiente para cortar la iteracion ya que la matriz no esta llena
						lleno = 0;
				}
			}
			if(lleno == 1) { // Pregunto si lleno es 1, si lleno es 1 significa que no se encontraron espacios en blanco en ninguna de las comparaciones anteriores entonces significa que la matriz esta llena
				termina = 1; // Por lo tanto es un empate
				printf("El partido termino en empate \n");
			}
			if(jugador == 1) // Como hay que ir intercambiando el jugador en cada turno, si el jugador que arranco es el 1, aumento en 1 la variable jugador asi en el siguiente turno juega el 2
				jugador++;
			else // Sino si el jugador que empezo fue el 2, disminuyo en 1 la variable jugador para que siga el jugador 1
				jugador--;
		} // // Y listo :) Se va a hacer todo este procesamiento por cada turno de los jugadores, cuando alguna de las verificaciones de si se hizo tateti de verdadera, la variable termina cambia a 1 entonces el bucle termina porque esta comparando con 0
	return (0); // Este return se pone solo porque la funcion main debe devolver un valor de tipo int entonces por lo general se pone que devuelve 0. Pero si estas usando windows y se te cierra la ventanita como la otra vez sacalo o mete un scanf algo de eso cosa que no se te cierre el programa
}
