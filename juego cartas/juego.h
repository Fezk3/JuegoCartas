#ifndef JUEGO_H
#define JUEGO_H
#include "jugador.h"
#include "mazo.h"

class juego {
public:
	juego();
	void agregarJugador(jugador*);
	carta reparteCarta();
	jugador decidirGanador();
	string decidirGanadorRonda();
	string mostrarJugadores();
	void resetRonda();
	bool checkeaMonedas();
	void definirPuntaje();
	
	//atributos
	vector<jugador> jugadores; 
	mazo mazito;
};

#endif

