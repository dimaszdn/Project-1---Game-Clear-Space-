#include <Meteor.hpp>

Meteor::~Meteor()
{

}

void Meteor::Setup()
{
    meteorTx.loadFromFile("Images/meteor.png");
    for (int i = 0; i < 7; ++i)
    {
        meteor[i].setTexture(meteorTx);
        meteor[i].setTextureRect(sf::IntRect(0, 0, 112, 161));
        m_x[i] = rand() % 8;
        m_y[i] = rand() % 8;
        meteor[i].setPosition(161 * m_x[i], -112 - 100 * m_y[i]);
    }
}

void Meteor::Anim()
{
    frame += 0.01;
    for (int i = 0; i < 10; ++i)
    {
        if (frame < 1)
        {
            meteor[i].setTextureRect(sf::IntRect(0, 0, 112, 161));
        }
        else if (frame > 1 && frame < 2)
        {
            meteor[i].setTextureRect(sf::IntRect(124, 0, 112, 161));
        }
        else
        {
            frame = 0;
        }
    }
}

void Meteor::Move()
{
    sf::Vector2f met[7];
    unsigned int under_side = 800 - 161;
    for (int i = 0; i < 7; ++i)
    {
        meteor[i].move(0, m_speed);

        met[i] = meteor[i].getPosition();
        if (met[i].y > under_side + 162)
        {
            m_x[i] = rand() % 8;
            m_y[i] = rand() % 8;
            meteor[i].setPosition(161 * m_x[i], -112 - 100 * m_y[i]);
        }
    }
}

void Meteor::Collision()
{
    for (int i = 0; i < 7; ++i)
    {
        m_y[i] = rand() % 5;
        meteor[i].setPosition(161 * i, -112 - 100 * m_y[i]);
    }
}

sf::Sprite Meteor::Get()
{
    for (int i = 0; i < 7; ++i)
        return meteor[i];
}

