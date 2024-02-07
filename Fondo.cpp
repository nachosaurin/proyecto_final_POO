#include "Fondo.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
using namespace std;
using namespace sf;
Fondo::Fondo() {
	if(!t.loadFromFile("fondorecortado.png")){
		cout << "No cargo el fondo" << endl;
	}
	escalaX = static_cast<float>(VideoMode::getDesktopMode().width) / t.getSize().x;
	escalaY = static_cast<float>(VideoMode::getDesktopMode().height) / t.getSize().y;
//	escalaX = 100; 
//	escalaY = 100;
	s.setTexture(t);
	s.setScale(escalaX, escalaY);
	s.setPosition(0,0);
	
	//iniciamos pos x del fondo
	velMov = 5;
	posX=0;
	transicion =((0 -s.getGlobalBounds().width) + 1000) ;
	
}
//void Fondo::moverFondo() {
//	// Disminuir la posici�n en x del fondo por unidades de velMovimiento
//	posX -= velMov;
//	
//	// Establecer la nueva posici�n del sprite del fondo
//	s.setPosition(posX, 0);
//	
//	// Si el fondo ha pasado el umbral de transici�n
//	if (posX <= transicion) { 
//		// Reiniciar la posici�n del fondo a la posici�n inicial
//		posX = 0;
//		
//		// Mover el sprite a la nueva posici�n reiniciada
//		s.setPosition(posX, 0);
//	}
//}

	

	
	
	void Fondo::mostrar(RenderWindow &w){
		w.draw(s);
	}

