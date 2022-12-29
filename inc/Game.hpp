#pragma once
#include <SFML/Graphics.hpp>
#include <Ship.hpp>
#include<Meteor.hpp>
#include<time.h>
#include<Score.hpp>
#include<sstream>

namespace ch
{
    class Game
    {
    private:
        int m_width, m_height;
        std::string m_caption;
        sf::RenderWindow* m_window;
        sf::Texture fontTex;
        sf::Sprite font[2];
        double m_speed = 0.01;
        sf::Vector2f fon[2];

        sf::Text strPause;
        sf::Font textFont;
        std::ostringstream ssPause;
        float m_x = 1100 / 2, m_y = 800 / 2;
        bool stop = false;

    public:

        ~Game();

        void SetCaption(const std::string& caption);

        void SetResolution(int width, int height);

        void Setup();

        void fontAnim();

        void SetStop(bool decision);

        void SetupPause();

        void Run();

        sf::Sprite Get();

        bool GetStop();

        sf::Text GetPause();
    };
}
