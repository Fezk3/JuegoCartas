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
	void menuUniversal(int);
	
	void apostar(int );
	void esAs(carta , int);
	void doblarApuesta(int );
	void pidiendoSegundaCarta(int );
	void continuar(bool );
};

#endif
