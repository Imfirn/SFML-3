#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include"Animation.h"
#include "Player.h"
#include"Platform.h"
#include "Bullet.h"
#include"monster.h"
#include"Platform2.h"
//#include"monsterbu.h"

using namespace sf;

static const float VIEW_HIGHT = 1080.0f;

void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HIGHT * aspectRatio, VIEW_HIGHT);
}
int main()
{

   RenderWindow window(VideoMode(1080, 720), "little red riding hood",Style::Close | Style::Resize);
   View view(Vector2f(0.0f, 0.0f), Vector2f(1080.0f, 720.0f));
    
    RectangleShape background(Vector2f(8000.0f, 720.0f));
    background.setPosition(0.0f, 0.0f);
    Texture space;
    space.loadFromFile("bg-2.png");
    background.setTexture(&space);

    Texture playtexture;
    playtexture.loadFromFile("LR3.png");
    Player player(&playtexture, Vector2u(6, 4), 0.2f, 150.0f, 200.0f);

    Texture BULLET;
    BULLET.loadFromFile("gun-1.png");
    Bullet bullet1(&BULLET, sf::Vector2u(4, 2), 0.15f, 600.0f, player.getPosition());

    

    RectangleShape st(Vector2f(100.0f, 230.0f));
    st.setPosition(899.0f,400.0f);
    Texture sts;
    sts.loadFromFile("pla-2.png");
    st.setTexture(&sts);


    Texture Floor;
    Floor.loadFromFile("F.png");

    Texture Top;
    Top.loadFromFile("test.png");


    //monster1
    Texture MONSTER;
    MONSTER.loadFromFile("P-1.png");
    std::vector<monster> monsterVector;
   //monsterVector.push_back (monster (&MONSTER, sf::Vector2u(6, 2), 0.2f, 200.0f, 545.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(6, 2), 0.2f,1500.0f, 545.0f));
   // monsterVector.push_back(monster(&MONSTER, sf::Vector2u(6, 2), 0.2f, 100.0f, 545.0f));
    //monsterVector.push_back(monster(&MONSTER, sf::Vector2u(6, 2), 0.2f, 800.0f, 545.0f));

    //monster2
    Texture MONSTER2;
    MONSTER2.loadFromFile("m2.png");
    std::vector<monster> monsterVector2;
    monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, 1200.0f, 545.0f));
    monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, 1300.0f, 300.0f));
       
    //movu=ing platform
    Texture MOVPLAT;
    MOVPLAT.loadFromFile("test.png");
    std::vector<Platform2>platVector2;
    platVector2.push_back(Platform2(&MOVPLAT, sf::Vector2u(5, 2), 0.2f, 1000.0f, 400.0f));

   /* Texture MONBULLET;
    MONBULLET.loadFromFile("gun-1.png");
    monsterbu BM(&MONBULLET, sf::Vector2u(4, 2), 0.15f, 600.0f, player.getPosition());*/


    std::vector<Platform>platforms;

     platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3057.0f, 500.0f)));
     platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3050.0f, 550.0f)));
     platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3815.0f, 550.0f)));
     platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3449.0f, 450.0f)));
     platforms.push_back(Platform(nullptr, sf::Vector2f(274.0f, 80.0f), sf::Vector2f(4415.0f, 630.0f)));

    platforms.push_back(Platform(&Floor, Vector2f(8000.0f,68.0f),Vector2f(500.0f, 700.0f)));
    platforms.push_back(Platform(&Top, sf::Vector2f(400.0f, 100.0f), Vector2f(1000.0f, 400.0f)));
    platforms.push_back(Platform(&Top, sf::Vector2f(400.0f, 100.0f), Vector2f(1600.0f, 400.0f)));
   // platforms.push_back(Platform(nullptr, sf::Vector2f(1080.0f, 100.0f), sf::Vector2f(500.0f, -50.0f)));
    //  platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(150.0f, 400.0f)));
   //   platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(900.0f, 100.0f)));

    int scoreup = 0;

    sf::Font font;
    font.loadFromFile("ABCD.ttf");
    std::ostringstream point;
    sf::Text Score;
    Score.setCharacterSize(50);
    Score.setString(point.str());
    Score.setFont(font);
    Score.setFillColor(sf::Color::Red);

    int Bul = 0;
    float deltatime = 0.0f;
    sf::Clock clock;
    //int b = 0;

    while (window.isOpen())
    {
        deltatime = clock.restart().asSeconds();
        Vector2f pos = player.getPosition();
        std::cout << pos.x << ' ' << pos.y << '\n';

        if (deltatime > 1.0 / 20.0f)
            deltatime = 1.0 / 20.0f;
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                break;

            }
        }

       
       

        player.Update(deltatime);
        Score.setPosition({ view.getCenter().x -100 ,view.getCenter().y - 300 });
        if (pos.x > 5000) {
            Score.setPosition(view.getCenter().x - 540, 300);
        }
        point.str(" ");
        point << "SCORE: " << scoreup;
        Score.setString(point.str());
       
        //monsterVector[i].updatemon(deltatime, bullet1);
       for (int i = 0; i < monsterVector.size(); i++) {

            monsterVector[i].updatemon(deltatime, bullet1);
            monsterVector[i].updatemon2(deltatime, player);
            
        }
       for (int i = 0; i < monsterVector2.size(); i++) {

           monsterVector2[i].updatemon(deltatime, bullet1);
           monsterVector2[i].updatemon2(deltatime, player);

       }
       for (int i = 0; i < platVector2.size(); i++) {

          platVector2[i].updateX(deltatime);
          

       }
        
       Vector2f direction;
        Collider playerCollision = player.GetCollider();
        for (Platform& platform : platforms)
            if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                player.OnCollision(direction);

        
        Collider playerCollision_2 = player.GetCollider();
        for (Platform2& platVector2 : platVector2)
            if (platVector2.GetCollider().CheckCollision(playerCollision_2, direction, 1.0f))
                player.OnCollision(direction);


        window.clear();
        window.draw(background);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
        {

            bullet1.attack(pos);
            Bul = 1;
        }
        if (Bul == 1)
        {
            float d = deltatime;
            bullet1.Update(d);

            bullet1.Draw(window);
            for (int i = 0; i < 2; i++) {
                if (monsterVector2[i].hit() == 1)
                {
                    scoreup += 200;
                    bullet1.del();
                }
            }
            for (int i = 0; i < 1; i++) {
                if (monsterVector[i].hit() == 1)
                {
                    scoreup += 100;
                    bullet1.del();
                }
            }




        }
        if (player.getPosition().x - bullet1.GetPosition().x <= -1000.0f)
        {
            Bul = 0;
            bullet1.isAvaliable();
        }


        view.setCenter(player.getPosition().x,360);

        //MONBULLET.draw(window);
        window.setView(view);
        player.Draw(window);     
        window.draw(Score);        
        for (int i = 0; i < monsterVector.size(); i++) {
            monsterVector[i].Draw(window);
        }
        if (scoreup > 10) {
            for (int i = 0; i < monsterVector2.size(); i++) {
                monsterVector2[i].Draw(window);
            }
        }
        for (int i = 0; i < platVector2.size(); i++) {
            platVector2[i].draw(window);
        }
        for (Platform& platform : platforms)
        platform.Draw(window);
        window.draw(st);
        window.display();
    }

    return 0;
}