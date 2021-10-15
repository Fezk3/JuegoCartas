#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include <stack>

class jugador {
public:
	jugador();
    jugador(string nombre);
    virtual ~jugador();
	void recibeCarta(carta);
	void setMonedas(int);
	int getMonedas();
	void setApuesta(int);
	int getApuesta();
	void setPuntaje(int);
	int getPuntaje();
	void DoblarApuesta();
    string toString();
	void definirPuntaje(carta);
	string getNombre();
    
	//Atributo Pila
	stack<carta> pila;
	
private:
    string nombre;
    int monedas;
	int apuesta;
	int puntaje;
	
};

#endif /* JUGADOR_H */

