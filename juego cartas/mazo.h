#ifndef MAZO_H
#define MAZO_H
#include "carta.h"
#include <queue>
#include <vector>
#include <time.h>

class mazo {
public:
    mazo();
    virtual ~mazo();
    void llenarMazo();
    string mostrar();
	void revolver();
	//atributo
    queue<carta> maz;
};

#endif /* MAZO_H */

