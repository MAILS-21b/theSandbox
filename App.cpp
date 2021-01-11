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
    
}

void App::update()
{

}

void App::render()
{
    renderWindow->clear(sf::Color(30,30,30,255));

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

App::~App()
{
    delete renderWindow;
}
