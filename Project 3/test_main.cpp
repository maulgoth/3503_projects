//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "Random.h"
//using namespace std;
//
//int main()
//{
//    cout << "Testing! Testing! If you see me, that's good." << endl;
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Red);
//    shape.setOrigin(shape.getRadius(), shape.getRadius());
//
//    sf::Font arial;
//    arial.loadFromFile("fonts/arial.ttf");
//    sf::Text textTest("Hi there, do I work?", arial, 42U);
//    textTest.setFillColor(sf::Color::Green);
//    textTest.setOrigin(50, 50);
//
//    int randomX = Random::Int(100, 500);
//    int randomY = Random::Int(100, 500);
//
//    textTest.setPosition(randomX, randomY);
//    
//  
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        if (event.type == sf::Event::MouseButtonPressed) {
//            if (event.mouseButton.button == sf::Mouse::Left) {
//                /*int x = Random::Int(0, 500);
//                int y = Random::Int(0, 500);
//                textTest.setPosition(x, y);*/
//                sf::Vector2i position = sf::Mouse::getPosition(window);
//                textTest.setPosition(position.x, position.y);
//            }
//        }
//
//        if (event.MouseMoved) {
//            sf::Vector2i position = sf::Mouse::getPosition(window);
//            shape.setPosition(position.x, position.y);
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.draw(textTest);
//        window.display();
//    }
//
//
//
//    return 0;
//}