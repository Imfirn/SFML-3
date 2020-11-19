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
#include"Item.h"
#include"Item2.h"
#include<time.h>
#include"Boss.h"
#include"Bullet_boss.h"


using namespace sf;
int player_di;

static const float VIEW_HIGHT = 1080.0f;

void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HIGHT * aspectRatio, VIEW_HIGHT);
}

int main()
{

    RenderWindow window(VideoMode(1080, 720), "little red riding hood", Style::Close | Style::Resize);
    View view(Vector2f(0.0f, 0.0f), Vector2f(1080.0f, 720.0f));

    RectangleShape background(Vector2f(8300.0f, 720.0f));
    background.setPosition(0.0f, 0.0f);
    Texture ace;
    ace.loadFromFile("pic/bg-2.png");
    background.setTexture(&ace);

    RectangleShape background2(Vector2f(8300.0f, 720.0f));
    background2.setPosition(17000.0f, 0.0f);
    Texture ace2;
    ace2.loadFromFile("pic/bgp2.png");
    background2.setTexture(&ace2);

    ///Menu_bg////

    RectangleShape Menu(Vector2f(1080.0f, 720.0f));
    Menu.setPosition(0.0f, 0.0f);
    Texture Menu_0;
    Menu_0.loadFromFile("pic/menu1.png");
    Menu.setTexture(&Menu_0);


    ///Menu_b1-3////
    RectangleShape Menu1(Vector2f(1080.0f, 720.0f));
    Menu1.setPosition(0.0f, 0.0f);
    Texture Menu_1;
    Menu_1.loadFromFile("pic/m/button-1.png");
    Menu1.setTexture(&Menu_1);

    ///Menu_b1////
    RectangleShape Menu2(Vector2f(1080.0f, 720.0f));
    Menu2.setPosition(0.0f, 0.0f);
    Texture Menu_2;
    Menu_2.loadFromFile("pic/m/b1.png");
    Menu2.setTexture(&Menu_2);


    ///Menu_b2////
    RectangleShape Menu3(Vector2f(1080.0f, 720.0f));
    Menu3.setPosition(0.0f, 0.0f);
    Texture Menu_3;
    Menu_3.loadFromFile("pic/m/b2.png");
    Menu3.setTexture(&Menu_3);

    ///Menu_b2////
    RectangleShape Menu4(Vector2f(1080.0f, 720.0f));
    Menu4.setPosition(0.0f, 0.0f);
    Texture Menu_4;
    Menu_4.loadFromFile("pic/m/b3.png");
    Menu4.setTexture(&Menu_4);


    RectangleShape Hi(Vector2f(1080.0f, 720.0f));
   // Hi.setPosition(0.0f, 0.0f);
    Texture hello;
    hello.loadFromFile("pic/menu1.png");
    Hi.setTexture(&hello);




    ///PLayer///
    Texture playtexture;
    playtexture.loadFromFile("pic/LR3.png");
    Player player(&playtexture, Vector2u(6, 4), 0.2f, 150.0f, 200.0f);

    float playerHP = 80000;
    RectangleShape HP(Vector2f(playerHP / 250.0f, 30));
    HP.setPosition(Vector2f(450, 46));
    HP.setFillColor(Color::Red);
    HP.setSize(Vector2f(playerHP / 320.f, 15));

    Texture BULLET;
    BULLET.loadFromFile("pic/gun-1.png");
    Bullet bullet1(&BULLET, sf::Vector2u(4, 2), 0.15f, 600.0f, player.getPosition());


    ///stair///
    RectangleShape st(Vector2f(100.0f, 230.0f));
    st.setPosition(899.0f, 400.0f);
    Texture sts;
    sts.loadFromFile("pic/pla-2.png");
    st.setTexture(&sts);

    RectangleShape door(Vector2f(300.0f, 500.0f));
    door.setPosition(7340.0f, 175.0f);
    Texture doors;
    doors.loadFromFile("pic/d.png");
    door.setTexture(&doors);

    srand(time(NULL));




    ///monster1///
    Texture MONSTER;
    MONSTER.loadFromFile("pic/m3.png");
    std::vector<monster> monsterVector;
    //monsterVector.push_back (monster (&MONSTER, sf::Vector2u(6, 2), 0.2f, 200.0f, 545.0f));
  /*  monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 3500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 4500, 575.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 5500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 2500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 6000, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 7500, 615.0f));
    monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 7000, 615.0f));*/
    // monsterVector.push_back(monster(&MONSTER, sf::Vector2u(6, 2), 0.2f, 100.0f, 545.0f));
     //monsterVector.push_back(monster(&MONSTER, sf::Vector2u(6, 2), 0.2f, 800.0f, 545.0f));

     ///monster2
    Texture MONSTER2;
    MONSTER2.loadFromFile("pic/mo3-1.png");
    std::vector<monster> monsterVector2;
   


    //moving platform
    Texture MOVPLAT;
    MOVPLAT.loadFromFile("pic/test.png");

    Texture MOVPLAT2;
    MOVPLAT2.loadFromFile("pic/test.png");
    std::vector<Platform2>platVector2;

    platVector2.push_back(Platform2(&MOVPLAT, sf::Vector2u(1, 1), 0.2f, 1000.0f, 400.0f));
    platVector2.push_back(Platform2(&MOVPLAT2, sf::Vector2u(1, 1), 0.2f, 2000.0f, 400.0f));

    std::vector<Platform2>platVector_3;
    Texture MOVPLAT3;
    MOVPLAT3.loadFromFile("pic/pm2.png");
    platVector_3.push_back(Platform2(&MOVPLAT3, sf::Vector2u(5, 2), 0.2f, 18705.0f, 250.0f));




    ///Boss//
    Texture BOSS;
    BOSS.loadFromFile("pic/m3.png");
    // std::vector<Boss> bossVector;
     //bossVector.push_back(Boss(&BOSS, sf::Vector2u(2, 2), 0.2f,23430.0f, 600.0f));
   
    ///Boss HP///
    float bossHP = 80000;
    RectangleShape HPb(Vector2f(bossHP / 250.0f, 50));
    HPb.setPosition(Vector2f(450, 46));
    HPb.setFillColor(Color::Magenta);
    HPb.setSize(Vector2f(bossHP / 23430.f, 15));


    ///ITEM 1///
    Texture itemHPup;
    itemHPup.loadFromFile("pic/t-1.png");
    std::vector<Item> itemHPupVector;
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 2000, 540.0f));
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 3000, 540.0f));
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 4000, 540.0f));
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 5500, 615.0f));
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 6500, 615.0f));
    itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 6000, 615.0f));


    //ITEM 2///
    Texture itemslow;
    itemslow.loadFromFile("pic/t-2.png");
    std::vector<Item2> itemslowVector;
    itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 2000.0f, 480.0f));
    itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 3000.0f, 530.0f));
    itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 4000.0f, 540.0f));
    itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 5000.0f, 540.0f));
    // itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(6, 2), 0.2f, rand() % 500 + 3000, 615.0f));


    std::vector<Platform>platforms;
    ////Part 1/////
    platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3057.0f, 500.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3050.0f, 550.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3815.0f, 550.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(342.0f, 32.0f), sf::Vector2f(3449.0f, 450.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(274.0f, 80.0f), sf::Vector2f(4415.0f, 630.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(316.0f, 40.0f), sf::Vector2f(4710.0f, 640.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(274.0f, 80.0f), sf::Vector2f(5000.0f, 630.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(296.0f, 50.0f), sf::Vector2f(5800.0f, 510.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(296.0f, 50.0f), sf::Vector2f(6138.0f, 400.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(592.0f, 50.0f), sf::Vector2f(6859.0f, 400.0f)));




    Texture Floor;
    Floor.loadFromFile("pic/f-2.png");
    platforms.push_back(Platform(&Floor, Vector2f(16000.0f, 68.0f), Vector2f(1000.0f, 700.0f)));
    ///Part 2//////
    Texture Floor2;
    Floor2.loadFromFile("pic/f2-2.png");
    platforms.push_back(Platform(&Floor2, Vector2f(16000.0f, 75.0f), Vector2f(17000.0f, 650.0f)));

    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(18705.0f, 250.0f)));//
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(21756.0f, 250.0f)));//
    platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 50.0f), sf::Vector2f(19518.0f, 460.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 50.0f), sf::Vector2f(20947.0f, 460.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 50.0f), sf::Vector2f(19972.0f, 380.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 50.0f), sf::Vector2f(20493.0f, 380.0f)));

    std::vector<Platform>platforms_2;
    Texture Statue;
    Statue.loadFromFile("pic/stat.png");
    platforms_2.push_back(Platform(&Statue, sf::Vector2f(500.0f,500.0f), sf::Vector2f(17335.0f, 350.0f)));

    std::vector<Platform>platforms_1;
    Texture Top;
    Top.loadFromFile("pic/test.png");

    platforms_1.push_back(Platform(&Top, sf::Vector2f(400.0f, 100.0f), Vector2f(1000.0f, 400.0f)));
    platforms_1.push_back(Platform(&Top, sf::Vector2f(400.0f, 100.0f), Vector2f(1600.0f, 400.0f)));
    // platforms.push_back(Platform(nullptr, sf::Vector2f(1080.0f, 100.0f), sf::Vector2f(500.0f, -50.0f)));
     //  platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(150.0f, 400.0f)));
    //   platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(900.0f, 100.0f)));



      ///Boss bullet//

    Bullet_boss b1;
    std::vector<Bullet_boss> bullet;
  





    Vector2f bossCenter;
    Vector2f mouse;
    Vector2f aimDir;
    Vector2f aimDirNorm;



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
    float deltaTime = 0.0f;
    sf::Clock clock;
    //int b = 0;
    bool end = false;
    bool start = false;
    bool menu = true;

    while (window.isOpen())
    {
        
        while (menu == true)
        {   

            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }
            sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
            mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;

            deltaTime = clock.restart().asSeconds();
            
                window.draw(Menu);
                window.draw(Menu1);
               
           if (sf::Mouse::getPosition(window).x >= 596&&
                sf::Mouse::getPosition(window).y >= 203 &&
                sf::Mouse::getPosition(window).x <= 980&&
                sf::Mouse::getPosition(window).y <= 322)
            {
                window.draw(Menu2);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //Soundch.play();
                   menu = false;
                    start = true;
                    Menu.setPosition(view.getCenter().x - 540, 0);
                    Menu1.setPosition(view.getCenter().x - 540, 0);
                    Menu2.setPosition(view.getCenter().x - 540, 0);
                    Menu3.setPosition(view.getCenter().x - 540, 0);
                    Menu4.setPosition(view.getCenter().x - 540, 0);
                  //  MemScore = true;
                }
            }
            else if (Mouse::getPosition(window).x >= 596 &&
                Mouse::getPosition(window).y >= 366 &&
                Mouse::getPosition(window).x <= 980 &&
                Mouse::getPosition(window).y <= 480)
            {
                window.draw(Menu3);
                if (Mouse::isButtonPressed(Mouse::Left) )
                {
                    /*Soundch.play();
                    MENU = false;
                    START = false;
                    Rank = true;*/
                }
            }
            else if (sf::Mouse::getPosition(window).x >= 596 &&
                sf::Mouse::getPosition(window).y >= 529 &&
                sf::Mouse::getPosition(window).x <= 980&&
                sf::Mouse::getPosition(window).y <= 653)
            {
                window.draw(Menu4);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                   // Soundch.play();
                    window.close();
                    break;
                }
            }
           window.display();
        }
        
        playerHP = 80000;
        HP.setSize(Vector2f(playerHP / 320.f, 15));
        scoreup = 0;

        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 3500, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 4500, 575.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 5500, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 2500, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 6000, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 5000, 615.0f));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 6500, 615.0f));


        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 615.0f));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 615.0f));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 3500, 545.0f));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 4500, 545.0f));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 5500, 615.0f));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 4500, 615.0f));


        Boss  bossVector(&BOSS, Vector2u(2, 2), 0.2f, 23430.0f, 600.0f);
        bullet.push_back(Bullet_boss(b1));







       while (start == true) {

            deltaTime = clock.restart().asSeconds();
            Vector2f pos = player.getPosition();
           std::cout << pos.x << ' ' << pos.y << '\n';
          // cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
           //std::cout << "............................";
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
            ////Boss//


            
            player.Update(deltaTime, itemslowVector);
            HP.setPosition(Vector2f(view.getCenter().x - 520, 46));
            HPb.setPosition(Vector2f(bossVector.getposix(), 46));////////----


            Score.setPosition({ view.getCenter().x - 100 ,view.getCenter().y - 300 });
            if (pos.x > 30000) {
                Score.setPosition(view.getCenter().x - 540, 300);
            }

            point.str(" ");
            point << "SCORE: " << scoreup;
            Score.setString(point.str());

            for (int i = 0; i < monsterVector.size(); i++) {
                if (monsterVector[i].check() == 1) {
                    //std::cout << "............................";
                    playerHP -= 50;
                    HP.setSize(Vector2f(playerHP / 320.f, 15));
                    
                }
            }


            /// เรายิงบอส

            if (bossVector.GetCollider().CheckCollision(bullet1.GetCollider())) {

                bossHP -= 10;
                HPb.setSize(Vector2f(bossHP / 320.f, 15));
                bullet1.del();
                if (bossHP < 0) {
                    bossHP = 0;
                    HPb.setSize(Vector2f(bossHP / 320.f, 15));
                    bossVector.delelet();
                }
            }




            for (int i = 0; i < monsterVector2.size(); i++) {
                if (monsterVector2[i].check() == 1) {
                    //std::cout << "............................";
                    playerHP -= 100;
                    HP.setSize(Vector2f(playerHP / 320.f, 15));
                   
                }
            }


            //ชน boss
            if (bossVector.check() == 1) {
                //std::cout << "............................";
                playerHP -= 100;
                HP.setSize(Vector2f(playerHP / 320.f, 15));
                
            }    


            /// ถูก boss ยิง
            for (int i = 0; i < bullet.size(); i++) {
                if (player.GetCollider().CheckCollision(bullet[i].GetCollider())) {
                    std::cout << "............................";
                    playerHP -= 100;
                    HP.setSize(Vector2f(playerHP / 320.f, 15));
                    bullet.erase(bullet.begin() + i);
                }
            }
            if (playerHP < 0) {
                playerHP = 0;
                end = true;
            }
           


            for (int i = 0; i < itemHPupVector.size(); i++) {
                if (itemHPupVector[i].check() == 1) {
                    //std::cout << "............................";
                    playerHP += 1000;
                    HP.setSize(Vector2f(playerHP / 300.f, 15));
                }
            }


            for (int i = 0; i < monsterVector.size(); i++) {

                monsterVector[i].updatemon(deltaTime, bullet1);
                monsterVector[i].updatemon2(deltaTime, player);

            }

            //bossVector

            bossVector.updateboss(deltaTime, bullet1);
            bossVector.updateboss2(deltaTime, player);







            //Boss shoting

            if (player.getPosition().x < 23030 && player.getPosition().x>23000 && bossVector.getposix() == 23430)
            {

                b1.shape.setPosition(23430, 570);
                b1.currVelocity.x = -b1.maxSpeed;
                bullet.push_back(Bullet_boss(b1));

                if (abs(b1.getposix() - bossVector.getposix()) == 40) {
                    
                    for (size_t i = 0; i < bullet.size(); i++)
                    {
                        bullet.erase(bullet.begin() + i);
                    }

                }

            }

            if (player.getPosition().x < 23690 && player.getPosition().x>23660 && bossVector.getposix() == 23430)
            {

                b1.shape.setPosition(23430, 570);
                b1.currVelocity.x = b1.maxSpeed;
                bullet.push_back(Bullet_boss(b1));

            }
            for (size_t i = 0; i < bullet.size(); i++)
            {
                bullet[i].shape.move(bullet[i].currVelocity);
            }

            //Draw

            window.clear();
            for (size_t i = 0; i < bullet.size(); i++)
            {
                window.draw(bullet[i].shape);
            }

            for (int i = 0; i < monsterVector2.size(); i++) {

                monsterVector2[i].updatemon(deltaTime, bullet1);
                monsterVector2[i].updatemon2(deltaTime, player);

            }

            for (int i = 0; i < platVector2.size(); i++) {
                platVector2[i].updateX(deltaTime);
            }

            for (int i = 0; i < platVector_3.size(); i++) {
                platVector_3[i].updateY(deltaTime);
            }


            for (int i = 0; i < itemHPupVector.size(); i++) {
                itemHPupVector[i].updateitem(deltaTime, player);
            }

            for (int i = 0; i < itemslowVector.size(); i++) {
                itemslowVector[i].update(deltaTime);
            }

            Vector2f direction;
            Collider playerCollision = player.GetCollider();
            for (Platform& platform : platforms)
                if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);

            for (Platform& platform_1 : platforms_1)
                if (platform_1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);

            for (Platform& platforms_2 : platforms_2)
                if (platforms_2.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);



            for (Platform2& platVector : platVector2)
                if (platVector.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);


            for (Platform2& platVector3 : platVector_3)
                if (platVector3.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);


            for (Platform& platform : platforms)
                platform.Draw(window);

            window.clear();
            window.draw(background2);

           window.draw(background);



           

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
            {
                player_di = player.Direction();

                if (player_di == 1) {

                    bullet1.attackR(pos);
                    std::cout << "............................";
                }
                else if (player_di == -1) {
                    bullet1.attackL(pos);
                    std::cout << "--------------------------";
                }

                Bul = 1;
            }


            if (Bul == 1)
            {
                if (player_di == 1) {

                    bullet1.UpdateR(deltaTime);
                    bullet1.Draw(window);

                }
                else if (player_di == -1) {

                    bullet1.UpdateL(deltaTime);
                    bullet1.Draw(window);

                }



                for (int i = 0; i < 6; i++) {
                    if (monsterVector2[i].hit() == 1)
                    {
                        scoreup += 200;
                        bullet1.del();
                    }
                }
                for (int i = 0; i < 9; i++) {
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


            view.setCenter(player.getPosition().x, 360);

            if (view.getCenter().x - 540 <= 0.0f) {
                view.setCenter(540, 360);
                
            }
          
           if (view.getCenter().x + 540 >= 25158) {
            
                view.setCenter(24618, 360);
            
            }
           
            window.setView(view);
            window.draw(door);
            player.Draw(window);
            window.draw(Score);
            for (int i = 0; i < monsterVector.size(); i++) {
                monsterVector[i].Draw(window);
            }

            bossVector.Draw(window);
            

            for (size_t i = 0; i < bullet.size(); i++)
            {
                window.draw(bullet[i].shape);
            }

            if (scoreup > 10) {
                for (int i = 0; i < monsterVector2.size(); i++) {
                    monsterVector2[i].Draw(window);
                }
            }
            for (int i = 0; i < platVector2.size(); i++) {
                platVector2[i].draw(window);
            }

            for (int i = 0; i < platVector_3.size(); i++) {
                platVector_3[i].draw(window);
            }

            for (int i = 0; i < itemHPupVector.size(); i++) {
                itemHPupVector[i].Draw(window);
            }
            for (int i = 0; i < itemslowVector.size(); i++) {
                itemslowVector[i].draw(window);
            }


            for (Platform& platforms_2 : platforms_2)
                platforms_2.Draw(window);

            for (Platform& platform_1 : platforms_1)
                platform_1.Draw(window);

            window.draw(HP);
            window.draw(HPb);
            window.draw(st);
            //window.draw(Menu);
            Hi.setPosition(view.getCenter().x - 540, 0);

            if (end == true) {
                std::cout << "............................";
                window.draw(Hi);
                //window.draw(Hi);
                if (Mouse::getPosition(window).x >= 0 &&
                    Mouse::getPosition(window).y >= 540 &&
                    Mouse::getPosition(window).x <= 1080 &&
                    Mouse::getPosition(window).y <= 720)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                        start = false;
                       // end = false;
                        menu = true;

                        
                        Menu.setPosition(view.getCenter().x - 540, 0);
                        Menu1.setPosition(view.getCenter().x - 540, 0);
                        Menu2.setPosition(view.getCenter().x - 540, 0);
                        Menu3.setPosition(view.getCenter().x - 540, 0);
                        Menu4.setPosition(view.getCenter().x - 540, 0);
                    }
                }


            }
            window.display();
            }
            player.setPosition(626.0f, 360.0f);
            end = false;
            for (int i = 0; i < monsterVector.size(); i++) {
                monsterVector.erase(monsterVector.begin() + i);
            }
            monsterVector.clear();

            for (int i = 0; i < monsterVector2.size(); i++) {
                monsterVector2.erase(monsterVector2.begin() + i);
            }
           
            monsterVector2.clear();


            for (int i = 0; i < bullet.size(); i++) {
                bullet.erase(bullet.begin() + i);
            }
              bullet.clear();

    }
   
    return 0;

    }