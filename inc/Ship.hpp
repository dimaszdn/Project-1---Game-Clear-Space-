#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<Game.hpp>
#include<Bullet.hpp>

class Ship
{
private:
	sf::Texture shipTx;
	sf::Sprite player;
	double m_speed = 1.5;
	float frame = 0;
	float m_x = 1300 / 2, m_y = 800 / 2;
	sf::Vector2f pl;

public:
	~Ship();

	void Setup();

	void ShipAnim();

	void Move();

	float GetPosX();

	float GetPosY();

	sf::Sprite Get();
};