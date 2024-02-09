#include "Fondo.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
using namespace std;
using namespace sf;
Fondo::Fondo() {
	if(!t.loadFromFile("fondorecortado.png") or !t_piso.loadFromFile("piso.png")){
		cout << "No cargo el fondo" << endl;
		
	}
	escalaX = static_cast<float>(VideoMode::getDesktopMode().width) / t.getSize().x;
	escalaY = static_cast<float>(VideoMode::getDesktopMode().height) / t.getSize().y;
//	escalaX = 0.5; 
//	escalaY = 0.5;
	s.setTexture(t);
	s.setScale(escalaX, escalaY);
	s.setPosition(0,0);
	
	


	posX=0;
	
}


	


	void Fondo::mostrar(RenderWindow &w){
		w.draw(s);
	}


	void Fondo:: mostrarPiso(RenderWindow &w){ 
		float alturaPiso = w.getSize().y - 450; // Establecer la posición y del piso un medio más arriba que la altura de la pantalla
		s_piso.setTexture(t_piso);
	// Configurar la posición del sprite del piso
		s_piso.setPosition(-100, 400);
		s_piso.setScale(3.5,3);
	// Dibujar el sprite del piso en la ventana
	w.draw(s_piso);
}

