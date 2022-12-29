#include <Game.hpp>

int main()
{
    ch::Game game;

    game.SetResolution(1300, 800);
    game.SetCaption("Clear space");
    game.Setup();
    
    game.Run();

    return 0;
}