#include <Bullet.hpp>

Bullet::~Bullet()
{

}

void Bullet::Setup()
{
	bulletTex.loadFromFile("Images/bullet.png");
	bullet.setTexture(bulletTex);
	bullet.setPosition(m_x, m_y);
}

void Bullet::Move()
{
    sf::Vector2f bul = bullet.getPosition();
    if (notBullet)
    {
        bullet.move(0, -m_speed);

        if (bul.y < -100)
            notBullet = false;
    }
}

void Bullet::SetNotBullet(bool decision)
{
    notBullet = decision;
}

void Bullet::SetPos(float x, float y)
{
    m_x = x;
    m_y = y;
    bullet.setPosition(m_x, m_y);
}

sf::Sprite Bullet::Get()
{
    return bullet;
}

bool Bullet::GetNotBullet()
{
    return notBullet;
}
