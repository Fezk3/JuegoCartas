#include <sstream>

#include "mazo.h"
#include <algorithm>
#include <random>

mazo::mazo() {

}

mazo::~mazo() {
}

void mazo::llenarMazo() {

    for (int i = 3; i < 7; i++) {

        for (int j = 1; j < 14; j++) {

            if (i == 3) {
                if (j == 1) {
                    maz.push(*(new carta('\3', "A")));
                } else if (j == 11) {
                    maz.push(*(new carta('\3', "J")));
                } else if (j == 12) {
                    maz.push(*(new carta('\3', "Q")));
                } else if (j == 13) {
                    maz.push(*(new carta('\3', "K")));
                } else {
                    stringstream j2;
                    j2 << j;

                    string numero = j2.str();

                    maz.push(*(new carta('\3', numero)));
                }
            } else if (i == 4) {
                if (j == 1) {
                    maz.push(*(new carta('\4', "A")));
                } else if (j == 11) {
                    maz.push(*(new carta('\4', "J")));
                } else if (j == 12) {
                    maz.push(*(new carta('\4', "Q")));
                } else if (j == 13) {
                    maz.push(*(new carta('\4', "K")));
                } else {
                    stringstream j2;
                    j2 << j;

                    string numero = j2.str();

                    maz.push(*(new carta('\4', numero)));
                }
            } else if (i == 5) {
                if (j == 1) {
                    maz.push(*(new carta('\5', "A")));
                } else if (j == 11) {
                    maz.push(*(new carta('\5', "J")));
                } else if (j == 12) {
                    maz.push(*(new carta('\5', "Q")));
                } else if (j == 13) {
                    maz.push(*(new carta('\5', "K")));
                } else {
                    stringstream j2;
                    j2 << j;

                    string numero = j2.str();

                    maz.push(*(new carta('\5', numero)));
                }
            } else if (i == 6) {
                if (j == 1) {
                    maz.push(*(new carta('\6', "A")));
                } else if (j == 11) {
                    maz.push(*(new carta('\6', "J")));
                } else if (j == 12) {
                    maz.push(*(new carta('\6', "Q")));
                } else if (j == 13) {
                    maz.push(*(new carta('\6', "K")));
                } else {
                    stringstream j2;
                    j2 << j;

                    string numero = j2.str();

                    maz.push(*(new carta('\6', numero)));
                }
            }
        }

    }
}

void mazo::revolver() {
    vector<carta> barajaCopia;
	//generar barajados distintos cada vez
	while(!maz.empty()){
		carta a=maz.front();
		barajaCopia.push_back(a);
		maz.pop();
	}
	std::random_device rand;
	std::default_random_engine rng(rand());
	shuffle(barajaCopia.begin(), barajaCopia.end(), rng);
	
	/*for(int i=0;i<52;i++){
		carta a=barajaCopia.at(i);
		cout<<a.toString()<<endl;
	}*/
	
	for(int i=0;i<52;i++){
		carta a=barajaCopia.at(i);
		maz.push(a);
	}
	
	//https://www.delftstack.com/howto/cpp/shuffle-vector-cpp/
}

string mazo::mostrar() {
    stringstream x;
    while (!maz.empty()) {
        x << "\t" << maz.front().toString() << "\n";
        maz.pop();
    }
    return x.str();
}

queue<carta> mazo::getMaz(){
	
}
