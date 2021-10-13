#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include <stack>

class jugador {
public:
    jugador(string nombre);
    virtual ~jugador();
    string toString();
    
private:
    string nombre;
    int monedas;
    stack<carta> pila;
};

#endif /* JUGADOR_H */

