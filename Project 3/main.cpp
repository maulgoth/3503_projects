#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include "Random.h"
#include "TextureManager.h"
#include "Board.h"
#include "Helpers.h"
using namespace std;

int main()
{
    // ======== 1. INITIAILIZATION ======== /
    cout << "Testing! Testing! If you see me, that's good." << endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // 1. Create sprites

    // Background
    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(250, 250, 250));

    // Create Board:
    Board board = Board(25, 16);
    board.Initialize();

    // Load Map -------------------------------------------------------- << REPLACE THIS WITH LOADER LATER


    // ======== 2. PROGRAM EXECUTION ======== /
    
    while (window.isOpen())
    {
        // ======== Startup ======== /
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
        }

        // ======== Update ======== /
        
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                //sf::Vector2f gamePos = window.mapPixelToCoords(position);
                //cout << position.x << " " << position.y << " " << gamePos.x << " " << gamePos.y << endl;
                //cout << position.y / 32 << " " << position.x / 32 << endl;
                //cout << 25 * (position.y / 32) + (position.x / 32) << endl;
                Tile* currentSpot = &board.GetTile(25 * (position.y / 32) + (position.x / 32));
                currentSpot->GetState();
                currentSpot->SetSprite("tile_revealed");
                currentSpot->Reveal();
            }
        }
        
        


        // ======== Draw ======== /
        
        // 1. Clear -- ONLY CALL ONCE!
        window.clear();

        // 2. Draw

        window.draw(background);

        for (int i = 0; i < board.GetSize(); i++) {
            window.draw(board.GetTile(i).GetSprite());
        }

        // 3. Display -- ONLY CALL ONCE!
        window.display();
    }

    // ======== Clean Up ======== /
    TextureManager::Clear();


    return 0;
}