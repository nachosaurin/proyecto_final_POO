#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "pajaro.h"
#include "tubo.h"
#include <tuple>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;
class game {
public:
	game();
	void Run();
	void ProcesEvent();
	void Update();
	void Draw();
	void GameOver();
	void Play();
	
private	:
	Clock c;
	bool pasoTubo = false;
	int contador = 0;
	Texture t_piso;
	Sprite s_piso;
	Texture m_fondo;
	Sprite m_spritef;
	RenderWindow m_win;
	pajaro m_pajaro;
	tubo m_tubo;
	bool m_Gameover=false;
};

#endif

