#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "Utility\TimeUtility.h"
#include "Utility\InputSystem.h"
#include "Core\ObjectBase.h"
#include "Core\Component.h"
#include "Components\SpriteComponent.h"

int main()
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SpaceInvaders!");
    //window->setVerticalSyncEnabled(true);
    //sf::CircleShape shape(300.f, 32);
    //shape.setFillColor(sf::Color::Green);

    std::unique_ptr<Game> game = std::make_unique<Game>();
    std::unique_ptr<Utility::InputSystem> inputSystem = std::make_unique<Utility::InputSystem>();

    auto obj = Core::CreateObject<ObjectBase>();
    obj->AddComponent(new SpriteComponent(window));


    if (window && game)
    {
        game->Start();
    }

    while (window->isOpen())
    {
        window->clear();
        auto currentTime = Utility::TimeUtility::GetUnixNow();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        
        inputSystem->Tick();
        game->Update((Utility::TimeUtility::GetUnixNow() - currentTime) / 1000.f);
        obj->Update(game->deltaTime);

        //window->draw(shape);
        window->display();
    }

    return 0;
}
