#include "Tubo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <algorithm>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf; 
Tubo::Tubo() {
	
	//Carga de textura (img)
	t_down.loadFromFile("pipe2l.png");
	s_down.setTexture(t_down);
	s_down.setScale(0.4,0.4);
	// Establenciendo la textura
	t_up.loadFromFile("pipe2inv.png");
	s_up.setTexture(t_up);
	s_up.setScale(0.4,0.4);
	
	
	
	velMov = 60.0f;//velocidad de movimineto de los tubos
	frecuencia = 1;//cada 2 segundos spawnea otro tubo
	spawnY = 100; 
	enMovimiento = false;
}
	
	float Tubo::verFrecuencia(){ return frecuencia;}
	void Tubo::guardarSprite( Sprite &s){
		pipeSprites.push_back(s);
	}
		
		
	void Tubo::mostrarTuboInf(Tubo &tubo , const RenderWindow &w){
	
		Sprite& spriteInf = tubo.getSpriteInf();
		spriteInf.setPosition(w.getSize().x,w.getSize().y -spriteInf.getGlobalBounds().height- spawnY +175  );
		guardarSprite(spriteInf);
	}



	void Tubo::mostrarTuboSup (Tubo &tubo, const RenderWindow &w){
		
		Sprite& spriteSup = tubo.getSpriteUp(); 
		spriteSup.setPosition(w.getSize().x, - spawnY );
		guardarSprite(spriteSup);
	}

	void Tubo::mover(float dt){
		for(unsigned short int i = 0; i<pipeSprites.size(); i++) { 
			Vector2f position = pipeSprites.at(i).getPosition();
			float movimiento = velMov * dt;
			pipeSprites.at(i).move(-movimiento, 0);
		}
	}

	
void Tubo::mostrar(RenderWindow &w) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			w.draw(pipeSprites.at(i));
	}
}

void Tubo::borrarTubos(){ 
	pipeSprites.clear();
}
void Tubo::randomizarPosicionY(RenderWindow &w) { 
	spawnY = rand()%( 350 + 1);
}
	



