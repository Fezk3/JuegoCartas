#ifndef CONTROL_H
#define CONTROL_H
#include "juego.h"

class control{
	
private:
	
	//juego jue;
	
public:
	
	juego jue;
	
	control();
	~control();
	void menu();
	void menu1ply();
	void menu2ply();
	void menu3play();
	
	
	void apostar(int );
	void esAs(carta dar1, int);
	void doblarApuesta(int i);
};

#endif
