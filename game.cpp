#include "game.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;

game::game() :m_win(VideoMode(900,900),"tw bird"){
m_win.setFramerateLimit(60);
m_win.clear(Color(0,0,0,255));
m_fondo.loadFromFile("fondorecortado.png");
m_spritef.setTexture(m_fondo);
m_spritef.setScale(1,1);
t_piso.loadFromFile("piso.png");
s_piso.setTexture(t_piso);
s_piso.setScale(3,3);
s_piso.setPosition(-10,350);

}

void game::Run(){
	while(m_win.isOpen()){
		ProcesEvent();
		Update();
		Draw();
	}
}

void game::Update(){
//	
//	cout << c.getElapsedTime().asSeconds() << endl;
	if(c.getElapsedTime().asSeconds()>=1.5){
		if(m_pajaro.GetPos_x() >= m_tubo.GetPos_x()) { 
			contador ++;
			c.restart();
			cout << contador << endl;
		}
		
	}
	
	
	
	if(m_pajaro.Colision(m_tubo.GetSpriteDw()) or
						(m_pajaro.Colision(m_tubo.GetSpriteUp())) or
						(m_pajaro.GetPos_y()>=m_win.getSize().y-71
						or m_pajaro.GetPos_y()<=0.0f) or m_pajaro.Colision(s_piso))
	GameOver();
	
	
	m_pajaro.Update();
	m_tubo.Update();
	if(Keyboard::isKeyPressed(Keyboard::Key::Space) and !m_pajaro.GetMoving() and 
	   !m_tubo.GetMoving()){
		Play();
		
	}
}

void game::ProcesEvent(){
	Event e;
	while(m_win.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_win.close();	
	}
}

void game::Draw(){
	m_win.clear(Color(0,0,0));
	m_win.draw(m_spritef);
	
	m_tubo.Draw(m_win);
	m_win.draw(s_piso);
	m_pajaro.Draw(m_win);
	m_win.display();
	
}

void game::GameOver(){
	m_tubo.TuboStop();
	m_pajaro.Stop();
	contador = 0;
}

void game::Play(){
	m_pajaro.Back();
	m_pajaro.InMove();
	m_tubo.Back();
	m_tubo.TuboInMove();
}
