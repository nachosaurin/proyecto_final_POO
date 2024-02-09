#ifndef TUBO_H
#define TUBO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf; 

class Tubo {
private:
	vector<Sprite> pipeSprites;
	Texture t_up; 
	Sprite s_up;
	
	Texture t_down ;
	Sprite s_down;
	float velMov;
	float movimiento;
	float frecuencia;
	int spawnY;
	bool enMovimiento;
	

public:
	Tubo();

	Sprite& getSpriteInf(){return s_down;}
	Sprite& getSpriteUp(){return s_up;}
	Texture& getTextureInf(){return t_down;}
	Texture& getTextureUp(){return t_up;}
	Sprite& getSpriteInv() {return s_down;}
	
	
	void randomizarPosicionY(RenderWindow &w);
	void guardarSprite(Sprite &s); 
	
	
	void mostrar(RenderWindow &w);
	void alturasAleatorias();
	void mostrarTuboInf(Tubo &tubo, const RenderWindow &w);
	void mostrarTuboSup (Tubo &tubo, const RenderWindow &w);
	void mostrarTuboInv(Tubo &tubo);
	void mover(float dt);
	float verFrecuencia();
	void borrarTubos();
	

};

#endif

