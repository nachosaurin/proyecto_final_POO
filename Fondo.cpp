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
	
	s.setTexture(t);
	s.setScale(escalaX, escalaY);
	s.setPosition(0,0);
	
	
	
	
}
	void Fondo::mostrar(RenderWindow &w){
		w.draw(s);
	}

