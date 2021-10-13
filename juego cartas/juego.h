#ifndef JUEGO_H
#define JUEGO_H
#include "jugador.h"
#include "mazo.h"

class juego {
public:
	juego();
	void agregarJugador(jugador*);
	void reparteCarta();
	jugador decidirGanador();
	string decidirGanadorRonda();
	void apostarMonedas(jugador actual);
	string mostrarJugadores();
	void resetRonda();
	string decidirPerdedoresRonda();
	
private:
	vector<jugador> jugadores; 
	mazo mazito;
};

#endif

