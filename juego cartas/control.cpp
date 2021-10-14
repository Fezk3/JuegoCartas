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
						menuUniversal(1);
						subF = true;
						system("pause");
						system("cls");
						break;
					case 2:
						menuUniversal(2);
						subF = true;
						system("pause");
						system("cls");
						break;
					case 3:
						menuUniversal(3);
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

void control::apostar(int i){
	
	bool sale=false;
	do{
		int apuesta;
		cout<<"\tjugador:	"<<jue.jugadores.at(i).getNombre()<<"\n";
		cout<<"Usted dispone de: "<<jue.jugadores.at(i).getMonedas()<<"\n";
		cout<<"Digite el numero de monedas que quiere apostar en esta ronda: \n";
		cin>>apuesta;
		system("pause");
		system("cls");
		
		try{
			
			if(apuesta < 50 || apuesta > jue.jugadores.at(i).getMonedas()){
				
				throw apuesta;
				
			}else{
				
				jue.jugadores.at(i).setApuesta(apuesta);
				jue.jugadores.at(i).setMonedas(jue.jugadores.at(i).getMonedas() - apuesta);
				sale=true;
				
			}
			
		}catch(int apuesta){
			
			cout<<"Apuesta invalida, el minimo es de 50 y no debe de exeder su numero de monedas\n";
			system("pause");
			system("cls");
			
		}
	
	} while(!sale);
}

void control::esAs(carta dar1, int i){
	
	if(dar1.getValor() == "A"){
		
		bool fin = false;
		
		do{
			int as1;
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
					
					jue.jugadores.at(i).setPuntaje(jue.jugadores.at(i).getPuntaje() + as1);
					fin = true;
					
				}
				
				
			}catch(int as1){
				
				cout<<"Opcion invalida\n";
				system("pause");
				system("cls");
				
			}
			
		} while(!fin);
		
		
	}
}

void control::doblarApuesta(int i){
	if( jue.jugadores.at(i).getMonedas()> jue.jugadores.at(i).getApuesta()*2){
		int apu;
		do{
			system("pause");
			system("cls");
			cout<<jue.jugadores.at(i).getNombre()<<"\n";
			cout<<"Desea doblar su apuesta?\n";
			cout<<"1. SI	2. NO\n";
			cin>>apu;
			
			try{
				
				if(apu != 1 && apu != 2){
					
					throw apu;
					
				}else if(apu == 1){
					
					cout<<"Apuesta doblada a: "<<jue.jugadores.at(i).getApuesta()*2<<"\n";
					jue.jugadores.at(i).DoblarApuesta();
					apu = 2;
					
				}
				
				
			}catch(int apu){
				
				cout<<"Opcion invalida, intente una de las sugeridas\n";
				system("pause");
				system("cls");
				
			}
			
		} while(apu != 2);
		
	}

}

void control::pidiendoSegundaCarta(int i){
	if(jue.jugadores.at(i).getPuntaje() < 21){
		int op1;
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
					
					esAs(dar4,i);
					
					jue.jugadores.at(i).recibeCarta(dar4);
					
					cout<<jue.jugadores.at(i).getNombre() <<" su puntaje actual es de: "<<jue.jugadores.at(i).getPuntaje()<<endl;
					
					if(jue.jugadores.at(i).getPuntaje()==21){
						
						op1=2;
						system("pause");
						system("cls");
						
					}
					
					if(jue.jugadores.at(i).getPuntaje()>21){
						
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
}

void control::continuar(bool finale){
	bool yu = false;
	int op;
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
}

void control::menuUniversal(int valor){
	
	bool finale = true;
	string nombre;
	jue.mazito.llenarMazo();
	jue.mazito.revolver();
	do{
		//ASIGNANDO JUGADORES Y PRIMERA APUESTA
		for(int i=0;i<valor;i++){
			cout<<"Digite su nombre: \n";
			cin>>nombre;
			
			jue.agregarJugador(new jugador(nombre));
			cout<<"\n\n";
			system("pause");
			system("cls");
			apostar(i);
		}
		
		jue.agregarJugador(new jugador("Maquina"));
		jue.jugadores.back().setMonedas(999);
		jue.jugadores.back().setApuesta(50);
		//---------------------------------------------------------------
		
		
		//REPARTIENDO CARTAS
		for(int i=0;i<valor;i++){
			cout<<"Repartiendo Cartas\n";
			cout<<"Carta para "<<jue.jugadores.at(i).getNombre()<<"\n";
			
			carta dar1 = jue.reparteCarta();
			
			//verifica si es un as o no
			esAs(dar1,i);
			
			jue.jugadores.at(i).recibeCarta(dar1);
			system("pause");
			system("cls");
			
		}
		
		cout<<"Carta para la maquina\n";
		carta dar2 = jue.reparteCarta();
		
		if(dar2.getValor() == "A"){
			
			jue.jugadores.back().setPuntaje(jue.jugadores.back().getPuntaje() + 1);
			
		}
		jue.jugadores.back().recibeCarta(dar2);
		
		//--------------------------------------------------------------
		
		
		//DOBLANDO APUESTA 
		for(int i=0;i<valor;i++){
			doblarApuesta(i);
			system("pause");
			system("cls");
		}
		//-------------------------------------------------------------
		
		// SEGUNDA RONDA DE CARTAS
		for(int i=0;i<valor;i++){
			cout<<"Repartiendo Cartas\n";
			cout<<"Carta para "<<jue.jugadores.at(i).getNombre()<<"\n";
			
			carta dar1 = jue.reparteCarta();
			
			//verifica si es un as o no
			esAs(dar1,i);
			
			jue.jugadores.at(i).recibeCarta(dar1);
			
			system("pause");
			system("cls");
			cout<<"Su puntaje actual es de: "<<jue.jugadores.at(i).getPuntaje()<<endl;
			cout<<"El puntaje actual de la maquina es de: "<<jue.jugadores.back().getPuntaje()<<endl;
			system("pause");
			system("cls");
			pidiendoSegundaCarta(i);
		}
		
		cout<<"Carta para la maquina\n";
		carta dar5 = jue.reparteCarta();
		if(dar5.getValor() == "A"){
			
			jue.jugadores.back().setPuntaje(jue.jugadores.back().getPuntaje() + 1);
			
		}
		jue.jugadores.back().recibeCarta(dar5);
		//------------------------------------------------------------
		
		//DECIDIENDO GANADOR, MOSTRANDO JUGADORES Y PREGUNTANDO CONTINUIDAD
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
		
		
		continuar(finale);
		//------------------------------------------------------------
	}while(jue.checkeaMonedas() && !finale);
}
