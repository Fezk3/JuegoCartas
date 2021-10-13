#include "juego.h"

juego::juego() {
	
}

void juego::agregarJugador(jugador* nuevo){
	jugadores.push_back(*nuevo);
}
