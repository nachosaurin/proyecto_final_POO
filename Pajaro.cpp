#include "Pajaro.h"
#include <SFML/Window/Keyboard.hpp>

Pajaro::Pajaro(){ 
		t.loadFromFile("pngwing.com.png");
		s.setTexture(t); 
		//seteo de su posicion inicial. sirve para trabajar despues cuando reinicie
		posicionInicial = Vector2f(250,450);
		s.setPosition(posicionInicial); 
		
		//escalado del pajaro
		s.setScale(0.15,0.15);
	}


//estas funciones podrian estar todas en una sola
bool Pajaro::fueraDePantalla(RenderWindow &w) { 
	return s.getPosition().y < 0 || s.getPosition().y > w.getSize().y  ;
}


void Pajaro::reiniciarPosicion() { 
	s.setPosition(posicionInicial);
}

void Pajaro::mover(RenderWindow &w) {
		
	if(Keyboard::isKeyPressed(Keyboard::Up)){ 
		velocidadY = impulso;
		teclaPresionada = true;
		enMovimiento = true;
	}
	if(teclaPresionada && enMovimiento){ 
		s.move(0,velocidadY);
		velocidadY += gravedad;
	}
	if(fueraDePantalla(w)) { 
		reiniciarPosicion();
		enMovimiento = false;
	}
}

	void Pajaro::mostrar(RenderWindow &w) { 
		w.draw(s);
	}






