#include "Tubo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
using namespace std;
using namespace sf; 
Tubo::Tubo() {
	
	//Carga de textura (img)
	t_down.loadFromFile("pipe.png");
	s_down.setTexture(t_down);
	// Establenciendo la textura
	t_up.loadFromFile("pipe.png");
	s_up.setTexture(t_up);
	
	
	
	velMov = 60.0f;//velocidad de movimineto de los tubos
	frecuencia = 2;//cada 2 segundos spawnea otro tubo
}
	
	float Tubo::verFrecuencia(){ return frecuencia;}
	void Tubo::guardarSprite( Sprite &s){
		pipeSprites.push_back(s);
	}
		
		
	void Tubo::mostrarTuboInf(Tubo &tubo){
	
		Sprite& spriteInf = tubo.getSpriteInf();
		spriteInf.setPosition(900, -1200);
		guardarSprite(spriteInf);
	}
	void Tubo::mostrarTuboSup (Tubo &tubo){
		
		Sprite& spriteSup = tubo.getSpriteUp(); 
		spriteSup.setPosition(900, 600);
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
	
	

//	void Tubo::mostrarTuboInv(Tubo &tubo){
//
//		Sprite& spriteInv = tubo.getSpriteInv(); 
//		spriteInv.setPosition(400, 300);
//		spriteInv.setColor(sf::Color(0,0,0,0));
//		guardarSprite(spriteInv);
//}


