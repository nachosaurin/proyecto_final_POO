#ifndef FONDO_H
#define FONDO_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;


class Fondo {
private:
	Texture t; 
	Sprite s; 
	float escalaX;
	float escalaY;
	float velX, velY, posX, velMov, transicion;
	
	
public:
	Fondo();
	void mostrar(RenderWindow &w);
	void moverFondo();

};

#endif

