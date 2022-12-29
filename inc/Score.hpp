#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<sstream>

class Score
{
private:
	float m_x = 30, m_y = 30;
	sf::Text strScore;
	sf::Text strBestScore;
	int m_bestScore;
	sf::Font font;
	int m_score = 0;
	std::ostringstream ssScore;	
	std::ostringstream ssBestScore;

public:
	~Score();

	void SetupScore();

	void SetupBestScore();

	void SetScore(int score);

	void SetBestScore();

	sf::Text Get();

	sf::Text GetBestScore();

};