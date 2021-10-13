#include "juego.h"
#include <sstream>

juego::juego() {
	jugador maquina("maquina");
	maquina.setMonedas(999);
	jugadores.push_back(maquina);
	
}

void juego::agregarJugador(jugador* nuevo){
	jugadores.push_back(*nuevo);
}

void juego::reparteCarta(){
	
	for(int i=0;i<4;i++){
		jugador actual = jugadores.at(i);
		actual.recibeCarta(mazito.getMaz().front());
		mazito.getMaz().pop();
		
	}
}

void juego::apostarMonedas(jugador actual){
	
}

string juego::decidirGanadorRonda(){
	
	stringstream x;
	for(int i=0;i<4;i++){
		jugador actual = jugadores.at(i);
		if(actual.getPuntaje()==21){
			
			int apuesta=actual.getApuesta()*2;
			int monenasRest =actual.getMonedas();
			actual.setMonedas(monenasRest + apuesta);
			x<<actual.toString()<<"\n";
		}
		
	}
	return x.str();
}

jugador juego::decidirGanador(){
	jugador ganador;
	stringstream x;
	for(int i=0;i<3;i++){
		jugador actual = jugadores.at(i);
		jugador siguiente = jugadores.at(i+1);
		if(actual.getMonedas()<siguiente.getMonedas()){
			
			ganador=siguiente;
		}else{
			ganador=actual;
		}
		
	}
	return ganador;
}

string juego::mostrarJugadores(){
	stringstream x;
	jugador a=jugadores.at(0);
	x<<a.toString();
	return x.str();
}
