#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Objeto {
public:
	Objeto(std::string nombre);
	void Draw(RenderWindow &window);
	bool Colision(Sprite o);
protected:
	Texture m_texture;
	Sprite m_spr;
};

#endif

