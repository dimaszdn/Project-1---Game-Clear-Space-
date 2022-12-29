#include<Score.hpp>


Score::~Score()
{

}

void Score::SetupScore()
{
	ssScore << "Score: ";

	strScore.setCharacterSize(30);
	strScore.setPosition(m_x, m_y);
	strScore.setColor(sf::Color::White);
	font.loadFromFile("Images/CASTELAR.TTF");
	strScore.setFont(font);
	strScore.setString(ssScore.str());
}

void Score::SetScore(int score)
{
	m_score = score;
	ssScore.str("");
	ssScore << "Score: " << m_score;
	strScore.setString(ssScore.str());
}

void Score::SetupBestScore()
{
	ssBestScore << "Best: ";
	
	strBestScore.setCharacterSize(30);
	strBestScore.setPosition(m_x + 1100, m_y);
	strBestScore.setColor(sf::Color::White);
	strBestScore.setFont(font);
	strBestScore.setString(ssBestScore.str());
}

void Score::SetBestScore()
{
	m_bestScore = m_score;
	ssBestScore.str("");
	ssBestScore << "Best: " << m_bestScore;
	strBestScore.setString(ssBestScore.str());
}

sf::Text Score::GetBestScore()
{
	return strBestScore;
}

sf::Text Score::Get()
{
	return strScore;
}