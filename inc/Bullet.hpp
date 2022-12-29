#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float m_x = -100;
	float m_y = -100;
	double m_speed = 2;
	sf::Texture bulletTex;
	sf::Sprite bullet;
	bool notBullet = false;

public:
	~Bullet();

	void Setup();

	void Move();

	void SetNotBullet(bool decision);

	void SetPos(float x, float y);

	sf::Sprite Get();

	bool GetNotBullet();

};