#include "juego.h"

juego::juego() {
	
}

void juego::agregarJugador(jugador* nuevo){
	jugadores.push_back(*nuevo);
}

void juego::reparteCarta(){
	
	for(int i=0;i<3;i++){
		jugador actual = jugadores.at(i);
		actual.recibeCarta(mazito.);
	}
}
