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

    ///score
    RectangleShape Hi(Vector2f(1080.0f, 720.0f));
   // Hi.setPosition(0.0f, 0.0f);
    Texture hello;
    hello.loadFromFile("pic/score.png");
    Hi.setTexture(&hello);

    RectangleShape Hi2(Vector2f(1080.0f, 720.0f));
    // Hi.setPosition(0.0f, 0.0f);
    Texture hello2;
    hello2.loadFromFile("pic/s1.png");
    Hi2.setTexture(&hello2);




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




    ///monster1-mud///
    Texture MONSTER;
    MONSTER.loadFromFile("pic/m3.png");
    std::vector<monster> monsterVector;
   
    ///monster2-bat///
    Texture MONSTER2;
    MONSTER2.loadFromFile("pic/mo3-1.png");
    std::vector<monster> monsterVector2;
   
    ///monster3-ghost///
    Texture MONSTER3;
    MONSTER3.loadFromFile("pic/g1.png");
    std::vector<monster> monsterVector3;

    //moving platform//
    
    Texture MOVPLAT2;
   
    std::vector<Platform2>platVector2;
    MOVPLAT2.loadFromFile("pic/test-1.png");
    platVector2.push_back(Platform2(&MOVPLAT2, sf::Vector2u(4, 0), 0.2f, 1000.0f, 400.0f));
    platVector2.push_back(Platform2(&MOVPLAT2, sf::Vector2u(4, 0), 0.2f, 2000.0f, 400.0f));


    //moving platform - part2//
    std::vector<Platform2>platVector_3;
    Texture MOVPLAT3;
    MOVPLAT3.loadFromFile("pic/pm2.png");
    platVector_3.push_back(Platform2(&MOVPLAT3, sf::Vector2u(5, 2), 0.2f, 18705.0f, 250.0f));
    platVector_3.push_back(Platform2(&MOVPLAT3, sf::Vector2u(5, 2), 0.2f, 21830.0f, 250.0f));




    ///Boss//
    Texture BOSS;
    BOSS.loadFromFile("pic/boss.png");
   


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
   



    //ITEM 2///
    Texture itemslow;
    itemslow.loadFromFile("pic/t-2.png");
    std::vector<Item2> itemslowVector;
   



    std::vector<Platform>platforms;
    ////Part 1/////
    platforms.push_back(Platform(nullptr,Vector2f(50.0f, 50.0f),Vector2f(3057.0f, 500.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(342.0f, 32.0f),Vector2f(3050.0f, 550.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(342.0f, 32.0f),Vector2f(3815.0f, 550.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(342.0f, 32.0f),Vector2f(3449.0f, 450.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(274.0f, 80.0f),Vector2f(4415.0f, 630.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(316.0f, 40.0f),Vector2f(4710.0f, 640.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(274.0f, 80.0f),Vector2f(5000.0f, 630.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(296.0f, 50.0f),Vector2f(5800.0f, 510.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(296.0f, 50.0f),Vector2f(6138.0f, 400.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(592.0f, 50.0f),Vector2f(6859.0f, 400.0f)));

    ///Exit part1///
    std::vector<Platform>Door_1;
   
    Texture Floor;
    Floor.loadFromFile("pic/f-2.png");
    platforms.push_back(Platform(&Floor, Vector2f(16000.0f, 68.0f), Vector2f(1000.0f, 700.0f)));



    ///Part 2//////
    Texture Floor2;
    Floor2.loadFromFile("pic/f2-2.png");
    platforms.push_back(Platform(&Floor2, Vector2f(16000.0f, 75.0f), Vector2f(17000.0f, 650.0f)));

    platforms.push_back(Platform(nullptr,Vector2f(400.0f, 350.0f),Vector2f(18705.0f, 250.0f)));//
    platforms.push_back(Platform(nullptr,Vector2f(400.0f, 350.0f),Vector2f(21756.0f, 250.0f)));//
    platforms.push_back(Platform(nullptr,Vector2f(260.0f, 50.0f),Vector2f(19518.0f, 460.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(260.0f, 50.0f),Vector2f(20947.0f, 460.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(260.0f, 50.0f), Vector2f(19972.0f, 380.0f)));
    platforms.push_back(Platform(nullptr,Vector2f(260.0f, 50.0f),Vector2f(20493.0f, 380.0f)));

    std::vector<Platform>platforms_1;
    Texture Top;
    Top.loadFromFile("pic/test-1.png");

    platforms_1.push_back(Platform(&Top, Vector2f(400.0f, 100.0f), Vector2f(1000.0f, 400.0f)));
    platforms_1.push_back(Platform(&Top, Vector2f(400.0f, 100.0f), Vector2f(1600.0f, 400.0f)));


    std::vector<Platform>platforms_2;
    Texture Statue;
    Statue.loadFromFile("pic/stat.png");
    platforms_2.push_back(Platform(&Statue,Vector2f(500.0f,500.0f),Vector2f(17335.0f, 350.0f)));

    
   


     ///Boss bullet//
    Bullet_boss b1;
    std::vector<Bullet_boss> bullet;
    Vector2f bossCenter;
    Vector2f mouse;
    Vector2f aimDir;
    Vector2f aimDirNorm;



   
    ///Score////
    Font font;
    font.loadFromFile("ABCD.ttf");
    std::ostringstream point;
    Text Score;
    Score.setCharacterSize(50);
    Score.setString(point.str());
    Score.setFont(font);
    Score.setFillColor(Color::Red);

    ///Score when end////
    Font font1;
    font1.loadFromFile("ABCD.ttf");
    ostringstream point1;
    Text LastScore;
    LastScore.setCharacterSize(50);
    LastScore.setString(point1.str());
    LastScore.setFont(font1);
    LastScore.setFillColor(Color::Black);




    int Bul = 0;
    int scoreup = 0;
    float counTime=0;
    float deltaTime = 0.0f;
    int Loop = 0;
    Clock clock;
   
    bool end = false;
    bool start = false;
    bool SCore_li = false;
    bool menu = true;
    bool MemScore = false;

    
    // Adding name///
    String playerInput;
    std::ofstream fileWriter;
    std::ostringstream keyname;
    Text Keyname;
    std::string userName;
    fstream adminFile;
    Keyname.setCharacterSize(40);
    Keyname.setString(" ");
    Keyname.setFont(font);
    Keyname.setFillColor(sf::Color::White);    
    char last_char = ' ';
    RectangleShape cursor;
    cursor.setSize(Vector2f(5.0f, 30.0f));
    cursor.setOrigin(Vector2f(2.5f, 15.0f));
    cursor.setFillColor(Color::White);
    Text text("", font);

    Keyname.setPosition(300, 500);
    text.setFillColor(Color::White);
    text.setPosition(545, 535);
    cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
    float totalTime_cursor = 0;
    Clock clock_cursor;
    bool state_cursor = false;
    
    std::map<int, std::string> save_score;
    std::ifstream Opentext;
    std::string list;

    while (window.isOpen())
    {
        
        while (menu == true)
        {   

            Event event;
            while (window.pollEvent(event)) {
                switch (event.type)
                {
                case Event::Closed:
                     window.close();
                     break;
                }
            }
            Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
            mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
           // cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;

            deltaTime = clock.restart().asSeconds();
            
                window.draw(Menu);
                window.draw(Menu1);
               
           if (Mouse::getPosition(window).x >= 596&&
                Mouse::getPosition(window).y >= 203 &&
                Mouse::getPosition(window).x <= 980&&
                Mouse::getPosition(window).y <= 322)
            {
                window.draw(Menu2);
                if (Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //Soundch.play();
                    Menu.setPosition(view.getCenter().x - 540, 0);
                    Menu1.setPosition(view.getCenter().x - 540, 0);
                    Menu2.setPosition(view.getCenter().x - 540, 0);
                    Menu3.setPosition(view.getCenter().x - 540, 0);
                    Menu4.setPosition(view.getCenter().x - 540, 0);
                  //  MemScore = true;
                    menu = false;
                    start = false;
                    MemScore = true;
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
                   
                    menu = false;
                    start = false;
                    SCore_li = true;
                }
            }
            else if (Mouse::getPosition(window).x >= 596 &&
                    Mouse::getPosition(window).y >= 529 &&
                    Mouse::getPosition(window).x <= 980&&
                    Mouse::getPosition(window).y <= 653)
            {
                window.draw(Menu4);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                  
                    window.close();
                    break;
                }
            }
           window.display();
        }
        
        /////////////////////////////
        while (MemScore == true) {
            
            counTime += deltaTime;
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }

            if (event.type == sf::Event::TextEntered && last_char != event.text.unicode)
            {
                if (event.text.unicode == 13) { //enter
                    userName = playerInput;
                    playerInput.clear();
                    menu = true;
                }
                else if (event.text.unicode == 8 && playerInput.getSize() > 0) { // backspace delete
                    playerInput = playerInput.substring(0, playerInput.getSize() - 1);
                }
                else {
                    if (playerInput.getSize() < 10) {
                        if (counTime > 0.2) {
                            playerInput += event.text.unicode;
                            counTime = 0;
                        }
                    }
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    menu = false;
                    SCore_li = false;
                    MemScore = false;
                    start = true;
                }

                last_char = event.text.unicode;
                text.setString(playerInput);
                cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
            }
            else if (event.type == Event::EventType::KeyReleased && last_char != ' ') {
                last_char = ' ';
            }
            window.clear();
            //window.draw(key);
            window.draw(Keyname);

            totalTime_cursor += clock_cursor.restart().asSeconds();
            if (totalTime_cursor >= 0.5) {
                totalTime_cursor = 0;
                state_cursor = !state_cursor;
            }
            if (state_cursor == true) {
                window.draw(cursor);
            }
            window.draw(text);

            window.display();
        }
        ////////////////////////
        while (SCore_li == true) {

            if (Loop == 0) {
                view.setCenter(540, 360);
            }
           
            sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
            mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;

            window.clear();
            //window.draw(hh);
            sf::Text text1("", font);
            text1.setCharacterSize(30);
            text1.setFillColor(sf::Color::White);
            Opentext.open("text/high_s.txt");
            do {
                Opentext >> list;
                std::string first_token = list.substr(0, list.find(','));
                int second_token = std::stoi(list.substr(list.find(',') + 1, list.length()));
                save_score[second_token] = first_token;
            } while (Opentext.good());
            Opentext.close();
            std::map<int, std::string>::iterator end = save_score.end();
            std::map<int, std::string>::iterator beg = save_score.begin();
            end--;
            beg--;
            int currentDisplay = 0;
            for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
                text1.setString(it->second);
                text1.setPosition(view.getCenter().x - 170, 210 + 80 * currentDisplay);
                window.draw(text1);
                text1.setString(std::to_string(it->first));
                text1.setPosition(view.getCenter().x + 95, 210 + 80 * currentDisplay);
                window.draw(text1);
                currentDisplay++;
                if (currentDisplay == 5)
                {
                    break;
                }
            }

                if (Keyboard::isKeyPressed(sf::Keyboard::E))
                {
                    //Soundch.play();
                    SCore_li = false;
                    menu = true;
                }
           
            window.display();
        }

        deltaTime = 0;
        clock.restart();
        playerHP = 80000;
        HP.setSize(Vector2f(playerHP / 320.f, 15));
        scoreup = 0;

        Door_1.push_back(Platform(nullptr, Vector2f(300.0f, 900.0f), Vector2f(7430.0f, 500.0f)));


        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f, 140));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 100 + 1500, 300.0f, 130));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 200 + 1700, 300.0f, 130));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 1500, 615.0f, 80));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 3500, 615.0f, 130));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 3500, 615.0f, 80));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 3300, 380.0f, 80));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 4500, 575.0f, 150));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 5500, 615.0f, 150));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 2500, 615.0f, 80));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 6000, 615.0f, 50));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 5000, 615.0f, 50));
        monsterVector.push_back(monster(&MONSTER, sf::Vector2u(2, 2), 0.2f, rand() % 500 + 6500, 615.0f, 100));


        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 615.0f, 250));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 615.0f, 250));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 5500, 615.0f, 250));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 4000, 545.0f, 150));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 5000, 615.0f, 150));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 4500, 545.0f, 150));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 5500, 615.0f, 150));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 4500, 615.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6000, 615.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6000, 320.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 320.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.2f, rand() % 500 + 6500, 320.0f, 200));


        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 2000, 600.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 2200, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 2100, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 3000, 380.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 4000, 600.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 5500, 600.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 6500, 600.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 6000, 600.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 4300, 510.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 6100, 380.0f));

        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 5700, 380.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 5800, 380.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 5900, 380.0f));



        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 6700, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 6800, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 6900, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 7000, 300.0f));


        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 19500, 305.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 20000, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 20000, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 20200, 300.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 19500, 550.0f));

        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 17645, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 17745, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 17845, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 17945, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, 18045, 550.0f));

        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 21000, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 21300, 550.0f));
        itemHPupVector.push_back(Item(&itemHPup, sf::Vector2u(3, 1), 0.2f, rand() % 500 + 22000, 550.0f));

        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 2000.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 2500.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 3400.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 3500.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 3300.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 3600.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 6000.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 6300.0f, 600.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 6500.0f, 600.0f));


        //p2
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 19905.0f, 305.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 20200.0f, 305.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 22370.0f, 550.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 21406.0f, 550.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 21606.0f, 550.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 21806.0f, 550.0f));
        itemslowVector.push_back(Item2(&itemslow, sf::Vector2u(3, 1), 0.2f, 22006.0f, 550.0f));

        //part 2//

        Boss  bossVector(&BOSS, Vector2u(3, 2), 0.4f, 23430.0f, 450.0f);
        bullet.push_back(Bullet_boss(b1));

        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 17500, 530.0f, 200));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 17500, 500.0f, 250));

        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 19000, 300.0f, 250));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 18000, 300.0f, 200));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 18500, 300.0f, 200));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 200 + 20000, 530.0f, 250));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 200 + 21000, 530.0f, 200));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 200 + 21200, 530.0f, 250));
        monsterVector3.push_back(monster(&MONSTER3, sf::Vector2u(4, 2), 0.5f, rand() % 500 + 21100, 530.0f, 200));

        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.5f, rand() % 500 + 21000, 300.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.5f, rand() % 500 + 17500, 615.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.5f, rand() % 500 + 17500, 615.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.5f, rand() % 500 + 18500, 615.0f, 200));
        monsterVector2.push_back(monster(&MONSTER2, sf::Vector2u(5, 2), 0.5f, rand() % 500 + 6500, 615.0f, 200));


        


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

            if (end == false) {

                player.Update(deltaTime, itemslowVector);

            } 
          
           

            

            point.str(" ");
            point << "SCORE: " << scoreup;
            Score.setString(point.str());

            for (int i = 0; i < monsterVector.size(); i++) {
                if (monsterVector[i].check() == 1) {
                   
                    playerHP -= 50;
                    HP.setSize(Vector2f(playerHP / 320.f, 15));
                    
                }
            }


            /// เรายิงบอส

            if (bossVector.GetCollider().CheckCollision(bullet1.GetCollider())) {

                bossHP -= 10000;
                HPb.setSize(Vector2f(bossHP / 320.f, 15));
                bullet1.del();
              
            }
            if (bossHP < 0) {
                bossHP = 0;
                HPb.setSize(Vector2f(bossHP / 320.f, 15));
                bossVector.delelet();
                end = true;

            }

            if (bossHP == 0) { 
            
                point1.str(" ");
                point1 << "  " << scoreup;
                LastScore.setString(point1.str());
                      
            
            }


            for (int i = 0; i < monsterVector2.size(); i++) {
                if (monsterVector2[i].check() == 1) {
                    //std::cout << "............................";
                 //   playerHP -= 100;
                    HP.setSize(Vector2f(playerHP / 320.f, 15));
                   
                }
            }

            for (int i = 0; i < monsterVector3.size(); i++) {
                if (monsterVector3[i].check() == 1) {
                    //std::cout << "............................";
                   // playerHP -= 200;
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
           
            if (playerHP == 0) {
            
                point1.str(" ");
                point1 << "  " << scoreup;
                LastScore.setString(point1.str());
                window.draw(LastScore);
            
            }


            for (int i = 0; i < itemHPupVector.size(); i++) {
                if (itemHPupVector[i].check() == 1) {
                    //std::cout << "............................";
                    playerHP += 2500;
                    HP.setSize(Vector2f(playerHP / 300.f, 15));
                    if (playerHP > 80000) {
                            
                        playerHP = 80000;
                    
                    }
                }
            }


            for (int i = 0; i < monsterVector.size(); i++) {

                monsterVector[i].updatemon(deltaTime, bullet1);
                monsterVector[i].updatemon2(deltaTime, player);

            }

            for (int i = 0; i < monsterVector3.size(); i++) {

                monsterVector3[i].updatemon(deltaTime, bullet1);
                monsterVector3[i].updatemon2(deltaTime, player);

            }

            //bossVector

            bossVector.updateboss(deltaTime, bullet1);
            bossVector.updateboss2(deltaTime, player);







            //Boss shoting

            if (player.getPosition().x < 23030 && player.getPosition().x>23000 && bossVector.getposix() == 23430)
            {

                b1.shape.setPosition(23430, 470);
                b1.currVelocity.x = -b1.maxSpeed;
                bullet.push_back(Bullet_boss(b1));

               

            }

            if (player.getPosition().x < 23690 && player.getPosition().x>23660 && bossVector.getposix() == 23430)
            {

                b1.shape.setPosition(23430, 470);
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

            for (Platform& DoorVector : Door_1)
                if (DoorVector.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                    player.OnCollision(direction);

            for (int i = 0; i < monsterVector.size(); i++) {

                Collider monster_1 = monsterVector[i].GetCollider();

                for (Platform& platform : platforms)
                    if (platform.GetCollider().CheckCollision(monster_1, direction, 1.0f))
                        monsterVector[i].OnCollision(direction,deltaTime);
                                                                         

            }

            for (int i = 0; i < monsterVector.size(); i++) {

                Collider monster_1 = monsterVector[i].GetCollider();

                for (Platform& platform : platforms)
                    if (platform.GetCollider().CheckCollision(monster_1, direction, 1.0f))
                        monsterVector[i].OnCollision(direction, deltaTime);


            }

            for (int i = 0; i < monsterVector3.size(); i++) {

                Collider monster_3 = monsterVector3[i].GetCollider();

                for (Platform& platform : platforms)
                    if (platform.GetCollider().CheckCollision(monster_3, direction, 1.0f))
                        monsterVector3[i].OnCollision(direction, deltaTime);


            }

            

            for (Platform& platform : platforms)
                platform.Draw(window);

            window.clear();
            window.draw(background2);

            if (scoreup > 700) {

                for (int i = 0; i < Door_1.size(); i++) {
                    Door_1.erase(Door_1.begin()+i);
                }
               
            
            }
           

            for (size_t i = 0; i < bullet.size(); i++)
            {
                window.draw(bullet[i].shape);
            }

           window.draw(background);

          

           

            if (Keyboard::isKeyPressed(sf::Keyboard::Key::G))
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



                for (int i = 0; i < monsterVector2.size(); i++) {
                    if (monsterVector2[i].hit() == 1)
                    {
                        scoreup += 200;
                        bullet1.del();
                    }
                }
                for (int i = 0; i < monsterVector.size(); i++) {
                    if (monsterVector[i].hit() == 1)
                    {
                        scoreup += 100;
                        bullet1.del();
                    }
                }

                for (int i = 0; i < monsterVector3.size(); i++) {
                    if (monsterVector3[i].hit() == 1)
                    {
                        scoreup += 250;
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
              HP.setPosition(Vector2f(view.getCenter().x - 520, 46));
              HPb.setPosition(Vector2f(bossVector.getposix(), 46));////////----
              LastScore.setPosition({ view.getCenter().x - 20 ,view.getCenter().y - 170 });
              Score.setPosition({ view.getCenter().x - 130 ,view.getCenter().y - 300 });

              if (pos.x > 30000) {

                  Score.setPosition(view.getCenter().x - 540, 300);
              }

             


            window.setView(view);
            window.draw(door);
            player.Draw(window);
            window.draw(Score);

            if (scoreup > 500) {

                for (int i = 0; i < monsterVector2.size(); i++) {

                    monsterVector2[i].updatemon(deltaTime, bullet1);
                    monsterVector2[i].updatemon2(deltaTime, player);

                }

                for (int i = 0; i < monsterVector2.size(); i++) {

                    monsterVector2[i].Draw(window);
                }
            }

            for (int i = 0; i < monsterVector.size(); i++) {
                monsterVector[i].Draw(window);
            }

            bossVector.Draw(window);
            

           
            
            for (int i = 0; i < monsterVector3.size(); i++) {
                monsterVector3[i].Draw(window);
            }
           
          

            for (int i = 0; i < platVector_3.size(); i++) {
                platVector_3[i].draw(window);
            }
            for (int i = 0; i < platVector2.size(); i++) {
                platVector2[i].draw(window);
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

            for (Platform& DoorVector :Door_1)
                DoorVector.Draw(window);

            window.draw(HP);
            window.draw(HPb);
            window.draw(st);
            //window.draw(Menu);
            Hi.setPosition(view.getCenter().x - 540, 0);
            Hi2.setPosition(view.getCenter().x - 540, 0);


            if (end == true) {

                //std::cout << "............................";
                cout << Mouse::getPosition(window).x << " " <<Mouse::getPosition(window).y << endl;
                window.draw(Hi);
                if (bossHP == 0) { window.draw(Hi2); }
                window.draw(LastScore);
                //window.draw(Hi);
                if (Mouse::getPosition(window).x >= 525 &&
                    Mouse::getPosition(window).y >= 475 &&
                    Mouse::getPosition(window).x <= 845 &&
                    Mouse::getPosition(window).y <= 565)
                {
                    if (Mouse::isButtonPressed(sf::Mouse::Left)) {
                        vector<pair<int, string> > score;
                        string temp, tempString;
                        int tempInt = 0, X = 1;
                        while (window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                                window.close();
                            fileWriter.open("text/high_s.txt", std::ios::out | std::ios::app);
                            fileWriter << "\n" << userName << "," << scoreup;
                            fileWriter.close();
                            playerInput.clear();
                        }
                        adminFile.close();
                        start = false;
                        MemScore = false;
                        end = false;
                        menu = true;
                       
                        
                        Menu.setPosition(view.getCenter().x - 540, 0);
                        Menu1.setPosition(view.getCenter().x - 540, 0);
                        Menu2.setPosition(view.getCenter().x - 540, 0);
                        Menu3.setPosition(view.getCenter().x - 540, 0);
                        Menu4.setPosition(view.getCenter().x - 540, 0);
                        cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
                        last_char = event.text.unicode;
                        text.setString(playerInput);
                        cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
                        Keyname.setPosition(view.getCenter().x - 240, 500);
                        text.setPosition(view.getCenter().x - 15, 535.0f);
                    }
                }


            }
            window.display();
            }
            
            Loop++;
            end = false;
            player.setPosition(700.0f, 360.0f);
            player.Reset();
            
            for (int i = 0; i < monsterVector.size(); i++) {
                monsterVector.erase(monsterVector.begin() + i);
            }
            monsterVector.clear();

            for (int i = 0; i < monsterVector2.size(); i++) {
                monsterVector2.erase(monsterVector2.begin() + i);
            }
           
            monsterVector2.clear();

            for (int i = 0; i < monsterVector3.size(); i++) {
                monsterVector3.erase(monsterVector3.begin() + i);
            }

            monsterVector3.clear();

            for (int i = 0; i < bullet.size(); i++) {
                bullet.erase(bullet.begin() + i);
            }
              bullet.clear();


              for (int i = 0; i <itemHPupVector.size(); i++) {
                  itemHPupVector.erase(itemHPupVector.begin() + i);
              }
              itemHPupVector.clear();

              for (int i = 0; i < itemslowVector.size(); i++) {
                  itemslowVector.erase(itemslowVector.begin() + i);
              }
            itemslowVector.clear();

    }
   
    return 0;

    }