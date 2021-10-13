#include <cstdlib>
#include "control.h"
using namespace std;


int main(int argc, char** argv) {
	

	/*
	mazo m;
	m.llenarMazo();
	//cout<<m.mostrar();
	
	m.revolver();
	
	//cout<<m.mostrar();*/
	
	control *n = new control();
	n->menu();
	
	return 0;
}

