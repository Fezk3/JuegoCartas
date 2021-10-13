#ifndef JUEGO_H
#define JUEGO_H
#include "jugador.h"
#include "mazo.h"

class juego {
public:
	juego();
	void agregarJugador(jugador*);
	void reparteCarta()
private:
	vector<jugador> jugadores; 
	mazo mazito;
};

#endif

