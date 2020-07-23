#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Random.h"
#include "TextureManager.h"
#include "Board.h"
#include "Helpers.h"
using namespace std;

int main()
{
    // ======== 1. INITIAILIZATION ======== /
    cout << "Testing! Testing! If you see me, that's good.\n" << endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // 1. Create sprites

    // Initial board
    int boardChoice = 2;

    // Background
    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(200, 200, 200));

    // Create Board:
    Board board = Board(25, 16);
    board.Initialize(boardChoice);

    // Buttons
    sf::Sprite debugButton(TextureManager::GetTexture("debug"));
    debugButton.setPosition(500, 512);
    sf::Sprite test1Button(TextureManager::GetTexture("test_1"));
    test1Button.setPosition(564, 512);
    sf::Sprite test2Button(TextureManager::GetTexture("test_2"));
    test2Button.setPosition(628, 512);
    sf::Sprite test3Button(TextureManager::GetTexture("test_3"));
    test3Button.setPosition(692, 512);

    // Smiley
    sf::Sprite smiley(TextureManager::GetTexture("face_happy"));
    smiley.setPosition(350, 512);

    // ======== 2. PROGRAM EXECUTION ======== /
    
    while (window.isOpen())
    {
        // ======== Startup ======== /
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window Close Logic
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse Button Press Capture
            else if (event.type == sf::Event::MouseButtonPressed) {

                // Left Button
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);

                    // Reveal Tile Logic
                    if (position.y < 512) {
                        Tile* currentSpot = &board.GetTile(25 * (position.y / 32) + (position.x / 32));
                        // Reveal returns true if mine, false if anything else
                        bool gameOver = currentSpot->Reveal();
                        // Check if mine. If so, game over, tiles become unclickable
                        if (gameOver) {
                            board.SetGameOver();
                            smiley.setTexture(TextureManager::GetTexture("face_lose"));
                        }
                    }

                    // Debug Button Logic
                    else if ((position.x > 499 && position.x < 564) && (position.y > 512 && position.y < 576))
                        board.ToggleDebug();


                    // New Board Buttons Logic
                    // Load Board 1
                    else if ((position.x > 563 && position.x < 628) && (position.y > 512 && position.y < 576))
                        boardChoice = 1;
                    // Load Board 2
                    else if ((position.x > 627 && position.x < 692) && (position.y > 512 && position.y < 576))
                        boardChoice = 2;
                    // Load Board 3
                    else if ((position.x > 691 && position.x < 756) && (position.y > 512 && position.y < 576))
                        boardChoice = 3;

                    // Smiley Button Logic
                    else if ((position.x > 349 && position.x < 414) && (position.y > 512 && position.y < 576)) {
                        board.Initialize(boardChoice);
                        smiley.setTexture(TextureManager::GetTexture("face_happy"));
                    }
                }

                // Right Button
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);

                    // Flag Logic
                    if (position.y < 512) {
                        Tile* currentSpot = &board.GetTile(25 * (position.y / 32) + (position.x / 32));
                        currentSpot->ToggleFlag();
                    }

                }
            }
        }

        // ======== Draw ======== /

        
        // 1. Clear -- ONLY CALL ONCE!
        window.clear();

        // 2. Draw

        window.draw(background);
        window.draw(debugButton);
        window.draw(test1Button);
        window.draw(test2Button);
        window.draw(test3Button);
        window.draw(smiley);

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