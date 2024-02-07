#include <SFML/Graphics.hpp>
#include "Pajaro.h"
#include "Fondo.h"
#include <vector>
#include "Tubo.h"
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow window(VideoMode(900, 900), "Ejemplo de SFML");
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

		if (clock.getElapsedTime().asSeconds() > tubo.verFrecuencia()) { 
			tubo.mostrarTuboInf(tubo);
			tubo.mostrarTuboSup(tubo);
			clock.restart();
		}
		
		fondo.mostrar(window);
		tubo.mover(0.1); // la velocidad de movimiento se multiplica con esto, podemos dejar fija la velocidad y regular desde aca
		
		
		// Mostrar los tubos
		tubo.mostrar(window);
		
		// Mover el pájaro
		pajaro.mover();
		
		// Mostrar el pájaro
		pajaro.mostrar(window);
		
		window.display();
	}
	tubo.borrarTubos();
	return 0;
}
//	
//int main() {
//	RenderWindow window(VideoMode(900, 900), "Ejemplo de SFML");
//	window.setFramerateLimit(60);
//	
//	Fondo fondo;
//	Pajaro pajaro;
//	vector<Tubo> tubos; // Vector para contener múltiples instancias de Tubo
//	Clock clock;
//	
//	while (window.isOpen()) {
//		Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		
//		window.clear();
//		
//		if (clock.getElapsedTime().asSeconds() > 2.0f) { // Generar un nuevo tubo cada 2 segundos
//			Tubo nuevoTubo;
//			tubos.push_back(nuevoTubo); // Agregar un nuevo tubo al vector
//			clock.restart(); // Reiniciar el reloj
//		}
//		
//		fondo.mostrar(window);
//		
//		for (auto& tubo : tubos) {
//			tubo.mover(0.016f); // Mover los tubos con un delta de tiempo de 0.016 segundos (aprox. 60 FPS)
//			tubo.mostrar(window); // Mostrar los tubos
//		}
//		
//		pajaro.mover();
//		pajaro.mostrar(window);
//		
//		window.display();
//	}
//	
//	return 0;
//}
