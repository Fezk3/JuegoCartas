#include <sstream>

#include "jugador.h"


jugador::jugador(string nombre) {
    this->nombre=nombre;
    monedas=500;
    pila;
}

jugador::~jugador() {
}

string jugador::toString(){
    stringstream x;
    x<<"El nombre es: "<<nombre<<"\n";
    x<<"Cantidad de monedas"<<monedas<<"\n";
    while(!pila.empty()){
        x<<&pila.top()<<"\n";
        pila.pop();
    }
    x.str();
}