#include<Ship.hpp>

Ship::~Ship()
{

}

void Ship::Setup()
{
	shipTx.loadFromFile("Images/ship.png");
	player.setTexture(shipTx);
	player.setTextureRect(sf::IntRect(0, 0, 231, 161));
	player.setPosition(m_x, m_y);
}

void Ship::ShipAnim()
{
    frame += 0.01;
    if (frame < 1)
    {
        player.setTextureRect(sf::IntRect(0, 0, 231, 161));
    }
    else if (frame > 1 && frame < 2)
    {
        player.setTextureRect(sf::IntRect(234, 0, 231, 161));
    }
    else
        frame = 0;
}

void Ship::Move()
{
    pl = player.getPosition();
    unsigned int right_side = 1300 - 234;
    unsigned int under_side = 800 - 161;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (pl.x < right_side)
        {
            player.move(m_speed, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (pl.x > 0)
        {
            player.move(-m_speed, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (pl.y > 0)
        {
            player.move(0, -m_speed);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (pl.y < under_side)
        {
            player.move(0, m_speed);
        }
    }
}

float Ship::GetPosX()
{
    return pl.x;
}

float Ship::GetPosY()
{
    return pl.y;
}

sf::Sprite Ship::Get()
{
    return player;
}