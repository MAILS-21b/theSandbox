#include "App.hpp"

App::App()
{

}

void App::start(int w,int h,const char* title)
{
    renderWindow = new sf::RenderWindow(sf::VideoMode(w,h),title);
    windowWidth = w; windowHeight = h;

    renderWindow->setFramerateLimit(60);
    init();
    running = true;
    while (running && renderWindow->isOpen())
    {
        sf::Event sfEvent;
        handleEvent(sfEvent);
        update();
        render();
    }

}

void App::init()
{
    bruh.setRadius(5);
}

void App::update()
{
     bruh.setPosition(x,0);
     x++;
}

void App::render()
{
    renderWindow->clear(sf::Color(30,30,30,255));

        renderWindow->draw(bruh);


    renderWindow->display();
}

void App::handleEvent(sf::Event ev)
{
    while(renderWindow->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed)
        {
            renderWindow->close();
            running = false;
        }
    }
}

int App::getNeighbor(int index)
{
    int res = 0;
    int x = index % (windowWidth / pixelSize);
    int y = index / (windowWidth / pixelSize);
    for(int i = y - 1; i <= y + 1; i++)
    {
        for(int j = x - 1; j <= x + 1; j++)
        {
            if(i >= 0 && i < windowHeight / pixelSize && j >= 0 && j < windowWidth / pixelSize)
            {
                res += currentState[i * (windowWidth / pixelSize) + j];
            }

        }
    }
    return res - currentState[index];
}

App::~App()
{
    delete currentState;
    delete outputState;
    delete renderWindow;
}
