#include "pajaro.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

pajaro::pajaro():Objeto("pngwing.com.png"){
	m_spr.setScale(0.2,0.2);
	m_spr.setPosition(m_posPrinc);
}
void pajaro::Update(){
	if(m_moving==true){
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		m_vel=m_impuslso;
		m_spr.move(0,m_vel);
	}
		else{
		m_vel+=m_grav;m_spr.move(0,m_vel);
	}
	}
}


void pajaro::Stop(){
	m_vel=0;m_moving=false;
}

float pajaro::GetPos_x (){ 
	return m_spr.getPosition().x;
}
float pajaro::GetPos_y(){return m_spr.getPosition().y;}

void pajaro::InMove(){
	m_moving=true;
}
void pajaro::Back(){m_spr.setPosition(m_posPrinc);}

bool pajaro::GetMoving(){return m_moving;}
