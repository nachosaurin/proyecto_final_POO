#ifndef PAJARO_H
#define PAJARO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Pajaro {
private:
	Texture t; 
	Sprite s;
	float velocidadY = 10; // velocidad vertical del pajaro
	float gravedad = 0.5; // fuerza para abajo
	float impulso = -5; // fuerza de impulso, negativa porque asi va para arriba	
	Vector2f posicionInicial;
	bool teclaPresionada = false; // Indicador de si la tecla se apreto o no
	bool enMovimiento = false; //Indicador de estado del pajaro (quieto/moviendose)
public:
	Pajaro();
	void mover();
	void mostrar(RenderWindow &w);
	bool fueraDePantalla();
	void reiniciarPosicion();
};

#endif

