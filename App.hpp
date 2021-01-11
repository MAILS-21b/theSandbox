#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
class App
{
public:
    App();
    void start(int w,int h,const char* title);
    void init();
    void update();
    void render();
    void handleEvent(sf::Event ev);
    ~App();

    //functions
    int getNeighbor(int i);
private:
    sf::RenderWindow* renderWindow;
    bool running = false;

    int* currentState;
    int* outputState;

    int windowWidth = 600, windowHeight = 600, pixelSize = 4;
    int arrLen = 0;
    int x=0;
    bool stateRenderVertex = false;
    bool paused = false;
    sf::CircleShape bruh;
};
