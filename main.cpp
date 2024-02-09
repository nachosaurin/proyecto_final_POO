#include <SFML/Graphics.hpp>
#include "Pajaro.h"
#include "Fondo.h"
#include <vector>
#include "Tubo.h"
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow window(VideoMode(900, 900), "Flappy bird");
	window.setFramerateLimit(60);
	
	Fondo fondo;
	Pajaro pajaro;
	Tubo tubo; // Crear una sola instancia de Tubo
	Clock clock;
	
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}       
		
		window.clear();
		if(Keyboard::isKeyPressed(Keyboard::Up)){
			if (clock.getElapsedTime().asSeconds() > tubo.verFrecuencia()) { 
				tubo.randomizarPosicionY(window);
				tubo.mostrarTuboInf(tubo,window);
				tubo.mostrarTuboSup(tubo,window);
				clock.restart();
			}	
		}
		
		
		
		
		
		fondo.mostrar(window);
		
		
		
		
		tubo.mover(0.1); // la velocidad de movimiento se multiplica con esto, podemos dejar fija la velocidad y regular desde aca
		
		
		// Mostrar los tubos
		tubo.mostrar(window);
		fondo.mostrarPiso(window);//mostramos piso 
		
		// Mover el pájaro
		pajaro.mover(window);
		
		// Mostrar el pájaro
		pajaro.mostrar(window);
		
		window.display();
	}
	tubo.borrarTubos();
	return 0;
}

