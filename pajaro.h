#ifndef PAJARO_H
#define PAJARO_H
#include "Objeto.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class pajaro : public Objeto {
public:
	pajaro();
	void Update();
	void Stop();
	float GetPos_y();
	void InMove();
	void Back();
	bool GetMoving();
	float GetPos_x ();
private:
	float m_vel=0;
	Vector2f m_posPrinc={80,300};
	const float m_grav=.9;
	const float m_impuslso=-8;
	bool m_moving=false;
};

#endif

