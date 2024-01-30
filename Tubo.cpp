#include "Tubo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf; 
Tubo::Tubo(float posX) {
	int alturaMax =500;
	int alturaMin = 100;
	int aperturaMax = 400; 
	int aperturaMin = 200; 
	
	int alturaTubo = rand()%(alturaMax - alturaMin + 1) + alturaMin;
	int aperturaTubo = rand()%(aperturaMax - aperturaMin + 1) + aperturaMin;
	
	
	tuboSuperior.setSize(Vector2f(50,alturaTubo)); 
	tuboSuperior.setPosition(posX, 0);
	tuboSuperior.setFillColor(Color::Green);

	//Inferior
	tuboInferior.setSize(Vector2f(50,alturaTubo)); 
	tuboInferior.setPosition(posX, alturaTubo + aperturaTubo);
	tuboInferior.setFillColor(Color::Green);
	
	velocidad = 4.0;
//	separacion = rand()% (300-100 + 1) + 100;
//	
	
}
	void Tubo::mover() { 
		// Mover tubos a la derecha
		tuboSuperior.move(-velocidad,0);
		tuboInferior.move(-velocidad,0);
		
		//Verificar si salen de la pantalla para reiniciar posicion
		if(tuboSuperior.getPosition().x < -50) {
			
			int alturaTubo = rand()%(500 - 100 + 1) + 100;
			int aperturaTubo = rand()%(300- 100+ 1) + 100;	
				
				
			float nuevaPosX = 900; 
			tuboSuperior.setSize(Vector2f(50,alturaTubo));
			tuboSuperior.setPosition(nuevaPosX,650);
			
			tuboInferior.setSize(Vector2f(50,alturaTubo));
			tuboSuperior.setPosition(nuevaPosX,alturaTubo + aperturaTubo);
		}
	}
	
	
	void Tubo::mostrar(RenderWindow &w) { 
		w.draw(tuboSuperior); 
		w.draw(tuboInferior); 
	}
	

