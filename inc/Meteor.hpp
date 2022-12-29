#pragma once
#include <SFML/Graphics.hpp>
#include<Bullet.hpp>

class Meteor
{
private:
	sf::Texture meteorTx;
	sf::Sprite meteor[10];
	float m_x[7] = { 0 };
	float m_y[7] = { 0 };
	float frame = 0;
	double m_speed = 1;

public:
	~Meteor();
	
	void Setup();

	void Anim();

	void Move();

	void Collision();

	sf::Sprite Get();
};