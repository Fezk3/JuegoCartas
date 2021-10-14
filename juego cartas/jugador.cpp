#include <sstream>

#include "jugador.h"

// Si no puede apostar lo minimo o pierde todas las monedas, pierde y termina el juego

jugador::jugador(){
	nombre = "";
	monedas = 0;
	puntaje = 0;
}

jugador::jugador(string nombre) {
    this->nombre=nombre;
    monedas=500;
	puntaje = 0; 
}

jugador::~jugador() {
}

string jugador::getNombre(){
	
	return nombre;
	
}

void jugador::recibeCarta(carta nueva){
	if(nueva.getValor()!="A"){
		definirPuntaje(nueva);
		pila.push(nueva);
	}else{
		pila.push(nueva);
	}
}

void jugador::setMonedas(int mone){
	
	this->monedas = mone;
	
}

int jugador::getMonedas(){
	
	return monedas;
	
}

void jugador::setApuesta(int apu){
	
	this->apuesta=apu;
	
}

int jugador::getApuesta(){
	
	return apuesta;
	
}

void jugador::DoblarApuesta(){
	
	monedas -= apuesta;
	apuesta = apuesta * 2;
	
}

void jugador::setPuntaje(int pts){
	
	this->puntaje = pts;
	
}

int jugador::getPuntaje(){
	
	return puntaje;
	
}

string jugador::toString(){
	
    stringstream x;
    x<<"El nombre es: "<<nombre<<"\n";
	x<<"Cantidad de monedas: "<<monedas<<"\n";
	x<<"Cartas en mano: \n";
	
    while(!pila.empty()){
        carta aux = pila.top();
		x<<aux.toString();
        pila.pop();
    }
    x<<"Esta apostando: "<<apuesta<<"\n";
	x<<"el puntaje de las cartas es: "<<puntaje<<"\n"; 
	x<<"\n";
    return x.str();
}

void jugador::definirPuntaje(carta actual){
	if(actual.getValor()=="J" || actual.getValor()=="Q" || actual.getValor()=="K"){
		puntaje+=10;
	}else{
		switch(stoi(actual.getValor())){
		case 2:
			puntaje+=2;
			break;
		case 3:
			puntaje+=3;
			break;
		case 4:
			puntaje+=4;
			break;
		case 5:
			puntaje+=5;
			break;
		case 6:
			puntaje+=6;
			break;
		case 7:
			puntaje+=7;
			break;
		case 8:
			puntaje+=8;
			break;
		case 9:
			puntaje+=9;
			break;
		case 10:
			puntaje+=10;
			break;
		
		}
	}
}
