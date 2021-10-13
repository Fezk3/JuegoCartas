#ifndef CONTROL_H
#define CONTROL_H
#include "juego.h"

class control{
	
private:
	
	juego *jue;
	
public:
	
	control();
	~control();
	void menu();
	void menu1ply();
	void menu2ply();
	void menu3play();
	
};

#endif
