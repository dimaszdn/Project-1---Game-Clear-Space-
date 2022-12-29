#include <Game.hpp>

namespace ch
{
    Game::~Game()
    {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::SetCaption(const std::string& caption)
    {
        m_caption = caption;
    }

    void Game::SetResolution(int width, int height)
    {
        m_width = width;
        m_height = height;
    }

    void Game::Setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
        
        fontTex.loadFromFile("Images/font.png");
        for (int i = 0; i < 2; ++i)
        {
            font[i].setTexture(fontTex);
            font[i].setPosition(0, m_width * i - m_width);
        }
        font[1].setTextureRect(sf::IntRect(0, m_width, m_height, -m_width));
    }

    sf::Sprite Game::Get()
    {
        for (int i = 0; i < 2; ++i)
            return font[i];
    }

    void Game::fontAnim()
    {
        for (int i = 0; i < 2; ++i)
        {
            font[i].move(0, 0.1);

            fon[i] = font[i].getPosition();
            if (fon[i].y > m_width)
            {
                font[i].setPosition(0, -m_width);
            }
        }
    }

    void Game::SetupPause()
    {
        ssPause << "PAUSE";

        strPause.setCharacterSize(60);
        strPause.setPosition(m_x, m_y);
        strPause.setColor(sf::Color::White);
        textFont.loadFromFile("Images/CASTELAR.TTF");
        strPause.setFont(textFont);
        strPause.setString(ssPause.str());
    }

    void Game::SetStop(bool decision)
    {
        stop = decision;
    }

    bool Game::GetStop()
    {
        return stop;
    }

    sf::Text Game::GetPause()
    {
        return strPause;
    }

    void Game::Run()
    {
        srand(time(0));
        
        Ship player;
        Bullet bul;
        Meteor meteor[7];
        Score score;
        score.SetupScore();
        score.SetupBestScore();
        SetupPause();

        int count = 0;
        int maxCount = 0;
        int takeOff = 0;

        for (int i = 0; i < 7; ++i)
        {
            meteor[i].Setup();
        }

        player.Setup();
        bul.Setup();
        
        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::F1)
                        m_window->close();
                    
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        if (!bul.GetNotBullet() && !GetStop())
                        {
                            float x = player.GetPosX() + (231 / 2);
                            float y = player.GetPosY() - (161 / 2);
                            bul.SetPos(x, y);
                            bul.SetNotBullet(true);
                        }
                    }
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        takeOff += 1;
                        if (takeOff % 2 == 0)
                            SetStop(false);
                        else
                            SetStop(true);
                    }
                }
            }
            
            if (!GetStop())
            {
                fontAnim();

                for (int i = 0; i < 7; ++i)
                {
                    meteor[i].Anim();
                    meteor[i].Move();
                    if (bul.Get().getGlobalBounds().intersects(meteor[i].Get().getGlobalBounds()))
                    {
                        meteor[i].Collision();
                        bul.SetPos(-100, -100);
                        count += 5;
                        score.SetScore(count);
                    }

                    if (player.Get().getGlobalBounds().intersects(meteor[i].Get().getGlobalBounds()))
                    {
                        meteor[i].Collision();
                        if (count > maxCount)
                        {
                            score.SetScore(count);
                            score.SetBestScore();
                            maxCount = count;
                            count = 0;
                        }
                        count = 0;
                        score.SetScore(count);

                    }
                }


                bul.Move();
                player.Move();
                player.ShipAnim();
            }
            m_window->setFramerateLimit(500);
            m_window->clear();

            //m_window->draw(Get());
            if (!GetStop())
            {
                for (int i = 0; i < 2; ++i)
                    m_window->draw(font[i]);

                m_window->draw(player.Get());

                for (int i = 0; i < 7; ++i)
                    m_window->draw(meteor[i].Get());

                m_window->draw(bul.Get());

                m_window->draw(score.Get());

                m_window->draw(score.GetBestScore());
            }
            if (GetStop())
                m_window->draw(GetPause());

            m_window->display();
        }
    }   
}

