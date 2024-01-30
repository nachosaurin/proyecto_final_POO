#ifndef TUBO_H
#define TUBO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;
using namespace sf; 

class Tubo {
private:
	RectangleShape tuboSuperior; 
	RectangleShape tuboInferior;
	float velocidad; 
	float separacion; 
	int alturaMax ;
	int alturaMin;
	int aperturaMax; 
	int aperturaMin ; 
	int alturaTubo; 
	int aperturaTubo;
	
	
	
	
public:
	
	Tubo(float posX);
	void mover(); 
	void mostrar(RenderWindow &w);

};

#endif

