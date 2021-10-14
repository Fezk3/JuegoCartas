#include "juego.h"
#include <sstream>

juego::juego() {
	/*jugador maquina("maquina");
	maquina.setMonedas(999);
	jugadores.push_back(maquina);*/
	
}

void juego::resetRonda(){
	
	jugadores.at(1).setMonedas(999);
	
	for(int i=0;i<jugadores.size();i++){
		
		jugadores.at(i).setPuntaje(0);
		
		while(!jugadores.at(i).pila.empty()){
			
			jugadores.at(i).pila.pop();
			
		}
		jugadores.at(i).setApuesta(0);
	}
	
}

// si alguien no puede apostar, se termina el juego!
bool juego::checkeaMonedas(){
	
	for(int i=0;i<jugadores.size();i++){
		
		if(jugadores.at(i).getMonedas()<50){
			
			return false;
			
		}
		
	}
	
	return true;
	
}

void juego::agregarJugador(jugador* nuevo){
	jugadores.push_back(*nuevo);
}

carta juego::reparteCarta(){
	
	carta dar =  mazito.maz.front();
	cout<<"Su carta es: "<<dar.toString()<<"\n";
	mazito.maz.pop();
	
	return dar;
	
}

string juego::decidirGanadorRonda(){
	
	stringstream x;
	for(int i=0;i<jugadores.size()-1;i++){
		
		if(jugadores.at(i).getPuntaje()==21){
			x<<"BLACKJACK!!\n";
			int apuesta=jugadores.at(i).getApuesta()*6;
			int monenasRest =jugadores.at(i).getMonedas();
			jugadores.at(i).setMonedas(monenasRest + apuesta);
			x<<"Jugador:	"<<jugadores.at(i).getNombre()<<"\n";
			x<<"Puntaje:	"<<jugadores.at(i).getPuntaje()<<"\n\n";
		}
		else if(jugadores.back().getPuntaje()<jugadores.at(i).getPuntaje() && jugadores.at(i).getPuntaje()<21){
			x<<"GANADOR!!\n";
			int apuesta=jugadores.at(i).getApuesta()*2;
			int monenasRest =jugadores.at(i).getMonedas();
			jugadores.at(i).setMonedas(monenasRest + apuesta);
			x<<"Jugador:	"<<jugadores.at(i).getNombre()<<"\n";
			x<<"Puntaje:	"<<jugadores.at(i).getPuntaje()<<"\n\n";
			
		}
		else if(jugadores.back().getPuntaje()==jugadores.at(i).getPuntaje()){
			x<<"TABLAS!!\n";
			int apuesta=jugadores.at(i).getApuesta();
			int monenasRest =jugadores.at(i).getMonedas();
			jugadores.at(i).setMonedas(monenasRest + apuesta);
			x<<"Jugador:	"<<jugadores.at(i).getNombre()<<"\n";
			x<<"Puntaje:	"<<jugadores.at(i).getPuntaje()<<"\n\n";
			
		}
	}

	return x.str();
}

jugador juego::decidirGanador(){
	jugador ganador;
	stringstream x;
	if(jugadores.size()==2){
		return jugadores.at(0);
	}
	for(int i=jugadores.size()-1;i>0;i--){
		
		if(jugadores.at(i).getMonedas()<jugadores.at(i-1).getMonedas()){
			
			ganador=jugadores.at(i-1);
		}else{
			ganador=jugadores.at(i);
		}
		
	}
	return ganador;
}

string juego::mostrarJugadores(){
	stringstream x;
	for(int i=0;i<jugadores.size();i++){
		
		x<<jugadores.at(i).toString();
	}
	return x.str();
}
