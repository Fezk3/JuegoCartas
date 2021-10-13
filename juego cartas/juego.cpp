#include "juego.h"
#include <sstream>

juego::juego() {
	jugador maquina("maquina");
	maquina.setMonedas(999);
	jugadores.push_back(maquina);
	
}

void juego::resetRonda(){
	
	jugadores.at(0).setMonedas(999);
	
	for(int i=0;i<jugadores.size()-1;i++){
		
		jugadores.at(i).setPuntaje(0);
		
		while(!jugadores.at(i).pila.empty()){
			
			jugadores.at(i).pila.pop();
			
		}
		
	}
	
}

void juego::agregarJugador(jugador* nuevo){
	jugadores.push_back(*nuevo);
}

void juego::reparteCarta(){
	
	for(int i=0;i<jugadores.size()-1;i++){
		
		jugadores.at(i).recibeCarta(mazito.getMaz().front());
		mazito.getMaz().pop();
		
	}
}

void juego::apostarMonedas(jugador actual){
	
}

string juego::decidirGanadorRonda(){
	
	stringstream x;
	for(int i=0;i<jugadores.size()-1;i++){
		
		if(jugadores.at(i).getPuntaje()==21){
			
			int apuesta=jugadores.at(i).getApuesta()*2;
			int monenasRest =jugadores.at(i).getMonedas();
			jugadores.at(i).setMonedas(monenasRest + apuesta);
			x<<jugadores.at(i).toString()<<"\n";
		}
		
	}
	return x.str();
}

jugador juego::decidirGanador(){
	jugador ganador;
	stringstream x;
	for(int i=0;i<=jugadores.size()-2;i++){
		
		
		if(jugadores.at(i).getMonedas()<jugadores.at(i+1).getMonedas()){
			
			ganador=jugadores.at(i+1);
		}else{
			ganador=jugadores.at(i);
		}
		
	}
	return ganador;
}

string juego::mostrarJugadores(){
	stringstream x;
	for(int i=0;i<jugadores.size()-1;i++){
		
		x<<jugadores.at(i).toString();
	}
	return x.str();
}

