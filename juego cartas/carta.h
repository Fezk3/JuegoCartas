#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class carta {
public:
    carta();
    carta(char signo, string valor);
    virtual ~carta();
    string toString();
private:
    char signo;
    string valor;
};

#endif 