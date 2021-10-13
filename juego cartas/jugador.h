#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include <stack>

class jugador {
public:
    jugador(string nombre);
    virtual ~jugador();
	void recibeCarta(carta);
	void setMonedas(int);
	int getMonedas();
	void setApuesta(int);
	int getApuesta();
	int DoblarApuesta();
    string toString();
    
private:
    string nombre;
    int monedas;
	int apuesta;
    stack<carta> pila;
};

#endif /* JUGADOR_H */

