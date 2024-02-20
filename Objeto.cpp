#include "Objeto.h"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include "Collision.h"

using namespace std;

Objeto::Objeto(std::string nombre){	
	m_texture.loadFromFile(nombre);
	m_spr.setTexture(m_texture);
}

void Objeto::Draw(RenderWindow &window){
	window.draw(m_spr);
}

bool Objeto::Colision(Sprite o){
	return Collision::PixelPerfectTest(m_spr, o);	
}
