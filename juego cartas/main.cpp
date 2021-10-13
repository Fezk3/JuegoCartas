#include <cstdlib>
#include "mazo.h"
using namespace std;


int main(int argc, char** argv) {
	mazo m;
	m.llenarMazo();
	cout<<m.mostrar();
	
	m.revolver();
	cout<<m.mostrar();
	return 0;
}

