#include <SFML/Graphics.hpp>
#include "Pajaro.h"
#include "Fondo.h"
#include <vector>
#include "Tubo.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(900,900),"Ejemplo de SFML");
	w.setFramerateLimit(60);
	Tubo tubo(500);
	vector<Tubo> t; 
	t.emplace_back(tubo);
	Fondo f;
	Pajaro p; 
	
	while(w.isOpen()) {
		//Evento de cerrar ventana
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		/*	w.clear(Color(20,20,20,20));*/
		f.mostrar(w);
	
		p.mover();
		
		for(auto& tubo: t) {
			tubo.mover(); 
			tubo.mostrar(w);
		}
		
		p.mostrar(w);
		w.display();
	}
	return 0;
	}

