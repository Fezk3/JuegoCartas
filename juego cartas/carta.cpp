#include <sstream>

#include "carta.h"

carta::carta(){
    
}
carta::carta(char signo, string valor) {
    this->signo=signo;
    this->valor=valor;
}

carta::~carta() {
}

string carta::toString(){
    stringstream x;
    x<<signo<<"."<<valor<<"\n";
    return x.str();
}

string carta::getValor(){
	return valor;
}
