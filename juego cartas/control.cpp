#include "control.h"

control::control(){
	
	jue = new juego;
	
}

control::~control(){
	
}

void control::menu(){
	
	string op;
	
	do{
		
		cout<<"Bienvenido a BlackJack\n\n";
		cout<<"Digite el numero de jugadores: \n";
		cout<<"1. Un jugador vs Maquina\n";
		cout<<"2. Dos jugadores y la maquina\n";
		cout<<"3. Tres jugadores y la maquina\n";
		cout<<"4. Salir\n";
		cin>>op;
		system("pause");
		system("cls");
		
		try{
			
			if(op != "1" && op != "2" && op != "3" && op!="4"){
				
				throw op;
				
			}else{
				
				do{
					
					switch(stoi(op)){
						
					case 1:
						menu1ply();
						subF = true;
						system("pause");
						system("cls");
						break;
					case 2:
						//menu2ply();
						subF = true;
						system("pause");
						system("cls");
						break;
					case 3:
						//menu3play();
						subF = true;
						system("pause");
						system("cls");
						break;
					case 4:
						cout<<"Saliendo, gracias por jugar!\n";
						subF = true;
						fin = true;
						system("pause");
						system("cls");
						break;
					default:
						
						cout<<"Opcion invalida\n";
						system("pause");
						system("cls");
						break;
					}
					
				} while(!subF);
				subF = false;
				
			}
			
		}catch(string op){
			
			cout << "\nLa opcion que digito es invalida, vuelva a intentar\n\n";
			system("pause");
			system("cls");
			
		}
		
	} while(!fin);
	
}

void control::menu1ply(){
	
	cout<<"Menu 1 Jugador\n";

}
