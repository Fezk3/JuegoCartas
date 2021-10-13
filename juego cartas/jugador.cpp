#include <sstream>

#include "jugador.h"
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

void jugador::recibeCarta(carta nueva){
	
	pila.push(nueva);
	
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

int jugador::DoblarApuesta(){
	
	return getApuesta() * 2;
	
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
        x<<&pila.top()<<"\n";
        pila.pop();
    }
	
    return x.str();
}
