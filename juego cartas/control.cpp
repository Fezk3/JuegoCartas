#include "control.h"

control::control(){
	
}

control::~control(){
	
}

void control::menu(){
	
	string op;
	bool subF = false, fin = false;
	
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
	
	// pido nombre al jugador -> vector
	// maquina -> vector
	string nombre;
	int apuesta = 50, apu, op1, as1, as2, as3, op;
	bool fin1 = false, finale = true;

	cout<<"Digite su nombre: \n";
	cin>>nombre;
	
	jugador *ply1 = new jugador(nombre);
	jugador *maquina = new jugador("Maquina");
	
	jue.agregarJugador(ply1);
	jue.agregarJugador(maquina);
	cout<<"\n\n";
	system("pause");
	system("cls");
	
	do{
		
		jue.mazito.llenarMazo();
		jue.mazito.revolver();
		jue.jugadores.at(1).setMonedas(999);
		jue.jugadores.at(1).setApuesta(50);
		
		
		//  seleccion de apuesta
		do{
			
			cout<<"Usted dispone de: "<<jue.jugadores.at(0).getMonedas()<<"\n";
			cout<<"Digite el numero de monedas que quiere apostar en esta ronda: \n";
			cin>>apuesta;
			system("pause");
			system("cls");
			
			try{
				
				if(apuesta < 50 || apuesta > jue.jugadores.at(0).getMonedas()){
					
					throw apuesta;
					
				}else{
					
					if(apuesta < 50 || apuesta > jue.jugadores.at(0).getMonedas()){
						
						throw apuesta;
						
					}else{
						
						jue.jugadores.at(0).setApuesta(apuesta);
						jue.jugadores.at(0).setMonedas(jue.jugadores.at(0).getMonedas() - apuesta);
						fin1 = true;
						
					}
					
				}
				
			}catch(int apuesta){
				
				cout<<"Apuesta invalida, el minimo es de 50 y no debe de exeder su numero de monedas\n";
				system("pause");
				system("cls");
				
			}
			
		} while(!fin1);
		
		
		// inicio de ronda hasta que pierda
		cout<<"Repartiendo Cartas\n";
		cout<<"Carta para "<<jue.jugadores.at(0).getNombre()<<"\n";
		
		carta dar1 = jue.reparteCarta();
		
		if(dar1.getValor() == "A"){
			
			bool fin = false;
			
			do{
				
				try{
					
					cout<<"Cuanto quiere que valga el As\n";
					cout<<"1. Uno 		2. Once\n";
					cin>>as1;
					
					
					if(as1 != 1 && as1!=2){
						
						throw as1;
						
					}else{
						
						if(as1==2){
							
							as1 = 11;
							
						}
						
						jue.jugadores.at(0).setPuntaje(jue.jugadores.at(0).getPuntaje() + as1);
						fin = true;
						
					}
					
					
				}catch(int as1){
					
					cout<<"Opcion invalida\n";
					system("pause");
					system("cls");
					
				}
				
			} while(!fin);
			
			
		}
		
		jue.jugadores.at(0).recibeCarta(dar1);
		system("pause");
		system("cls");
		
		cout<<"Carta para la maquina\n";
		carta dar2 = jue.reparteCarta();
		if(dar2.getValor() == "A"){
			
			jue.jugadores.at(1).setPuntaje(jue.jugadores.at(1).getPuntaje() + 1);
			
		}
		jue.jugadores.at(1).recibeCarta(dar2);
		system("pause");
		system("cls");
		
		
		// MOSTRANDO JUGADORES LUEGO DE REPARTIR CARTA 1

		//cout<<jue.mostrarJugadores()<<"\n";
		cout<<"Su puntaje actual es de: "<<jue.jugadores.at(0).getPuntaje()<<endl;
		cout<<"El puntaje actual de la maquina es de: "<<jue.jugadores.at(1).getPuntaje()<<endl;
		system("pause");
		system("cls");
		
		if(jue.jugadores.at(0).getMonedas() >= apuesta*2){

			
			do{
				
				cout<<"Desea doblar su apuesta?\n";
				cout<<"1. SI	2. NO\n";
				cin>>apu;
				
				try{
					
					if(apu != 1 && apu != 2){
						
						throw apu;
						
					}else if(apu == 1){
						
						cout<<"Apuesta doblada a: "<<jue.jugadores.at(0).getApuesta()*2<<"\n";
						jue.jugadores.at(0).DoblarApuesta();
						apu = 2;
						
					}
					
					
				}catch(int apu){
					
					cout<<"Opcion invalida, intente una de las sugeridas\n";
					system("pause");
					system("cls");
					
				}
				
			} while(apu != 2);
			
		}
		
		// SEGUNDA RONDA DE CARTAS
		system("pause");
		system("cls");
		cout<<"Repartiendo Cartas\n";
		cout<<"Carta para "<<jue.jugadores.at(0).getNombre()<<"\n";
		
		carta dar3 = jue.reparteCarta();
		if(dar3.getValor() == "A"){
			
			bool fin1 = false;
			
			do{
				
				try{
					
					cout<<"Cuanto quiere que valga el As\n";
					cout<<"1. Uno 		2. Once\n";
					cin>>as2;
					
					if(as2 != 1 && as2!=2){
						
						throw as2;
						
					}else{
						
						if(as2==2){
							
							as2 = 11;
							
						}
						
						jue.jugadores.at(0).setPuntaje(jue.jugadores.at(0).getPuntaje() + as2);
						fin1 = true;
						
					}
					
					
				}catch(int as2){
					
					cout<<"Opcion invalida\n";
					system("pause");
					system("cls");
					
				}
				
			} while(!fin1);
			
			
		}
		jue.jugadores.at(0).recibeCarta(dar3);
		system("pause");
		system("cls");
		cout<<"Su puntaje actual es de: "<<jue.jugadores.at(0).getPuntaje()<<endl;
		cout<<"El puntaje actual de la maquina es de: "<<jue.jugadores.at(1).getPuntaje()<<endl;
		system("pause");
		system("cls");
		if(jue.jugadores.at(0).getPuntaje() < 21){
			
			do{
				
				cout<<"Desea pedir otra carta?\n";
				cout<<"1. SI	2. NO\n";
				cin>>op1;	
				system("pause");
				system("cls");
				
				try{
					
					if(op1 != 1 && op1 != 2){
						
						throw op1;
						
					}else{
						
						if(op1 == 2) break;
						
						carta dar4 = jue.reparteCarta();
						
						if(dar4.getValor() == "A"){
							
							bool fin3 = false;
							
							do{
								
								try{
									
									cout<<"Cuanto quiere que valga el As\n";
									cout<<"1. Uno 		2. Once\n";
									cin>>as3;
									
									if(as3 != 1 && as3!=2){
										
										throw as3;
										
									}else{
										
										if(as3==2){
											
											as3 = 11;
											
										}
										
										jue.jugadores.at(0).setPuntaje(jue.jugadores.at(0).getPuntaje() + as3);
										fin3 = true;
										
									}
									
									
								}catch(int as3){
									
									cout<<"Opcion invalida\n";
									system("pause");
									system("cls");
									
								}
								
							} while(!fin3);
							
							
						}
						jue.jugadores.at(0).recibeCarta(dar4);
						
						cout<<"Su puntaje actual es de: "<<jue.jugadores.at(0).getPuntaje()<<endl;
						
						if(jue.jugadores.at(0).getPuntaje()==21){
							
							op1=2;
							system("pause");
							system("cls");
							
						}
						
						if(jue.jugadores.at(0).getPuntaje()>21){
							
							cout<<"\n\nExidio el puntaje posible\n\n";
							op1=2;
							system("pause");
							system("cls");
							
						}
						
						
					}
					
					
				}catch(int op1){
					
					cout<<"Opcion invalida, intente una de las sugeridas\n";
					system("pause");
					system("cls");
					
				}
				
			} while(op1!=2);
			
		}
		
		
		cout<<"Carta para la maquina\n";
		carta dar5 = jue.reparteCarta();
		if(dar5.getValor() == "A"){
			
			jue.jugadores.at(1).setPuntaje(jue.jugadores.at(1).getPuntaje() + 1);
			
		}
		jue.jugadores.at(1).recibeCarta(dar5);
		system("pause");
		system("cls");
		
		cout<<jue.decidirGanadorRonda();
		system("pause");
		system("cls");
		cout<<"Jugadores de la partida en esta ronda: \n\n";
		cout<<jue.mostrarJugadores();
		system("pause");
		system("cls");
		jue.resetRonda();
		
		bool yu = false;
		do{
			
			
			try{
				
				cout<<"Desea continuar jugando?\n";
				cout<<"1. SI		2. NO\n";
				cin>>op;
				system("pause");
				system("cls");
				
				if(op!=1 && op!=2){
					
					throw op;
					
				}else{
					
					if(op == 2){
						
						finale = false;
						jue.jugadores.clear();
					}
					if(op == 1 && jue.jugadores.at(0).getMonedas() < 50){
						
						finale = false;
						jue.jugadores.clear();
						
					}
					yu = true;
					
				}
				
			}catch(int op){
				
				cout<<"Opcion invalida\n";
				system("pause");
				system("cls");
			}
			
		} while(!yu);
		
		jue.mazito.vaciarMazo();
		
	} while(jue.checkeaMonedas() && finale);
	
}

void control::menu2ply(){
	
	
	

	
	
}

void control::menu3play(){
	
	
	
	
	
	
}
