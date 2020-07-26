#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "Board.h"
#include "Helpers.h"
using namespace std;

int main()
{
    // ======== INITIAILIZATION ========================================== /
    cout << "Testing! Testing! If you see me, that's good.\n" << endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper Clone", 
        sf::Style::Close | sf::Style::Titlebar); // No resize!

    // Create sprites

    // Background
    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(200, 200, 200));

    // Create Board:
    Board board = Board(25, 16);
    board.InitializeRandom();      // THIS NEEDS TO BE THE REAL WAY TO START

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

    // Counter
    sf::Texture digitTexture = TextureManager::GetTexture("digits");
    vector<sf::IntRect> digitRects;
    for (int i = 0; i < 211; i += 21)
        digitRects.push_back(sf::IntRect(i, 0, 21, 32));
    vector<int> nums = Helpers::digitizer(board.GetMineCount());
    vector<sf::Sprite> digitDisplay;
    for (int i = 0, j = 50; i < 3; i++) {
        digitDisplay.push_back(sf::Sprite(digitTexture));
        digitDisplay.at(i).setPosition(j, 512);
        j += 21;
        digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
    }

    // ======== PROGRAM EXECUTION ========================================== /
    
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
                        board.RevealTile(currentSpot);
                        board.GetGameOver();
                        if (board.GetVictory())
                            smiley.setTexture(TextureManager::GetTexture("face_win"));
                        if (board.GetGameOver())
                            smiley.setTexture(TextureManager::GetTexture("face_lose"));
                    }

                    // Debug Button Logic
                    else if ((position.x > 499 && position.x < 564) && 
                        (position.y > 512 && position.y < 576))
                        board.ToggleDebug();


                    // New Board Buttons Logic
                    // Load Board 1
                    else if ((position.x > 563 && position.x < 628) 
                        && (position.y > 512 && position.y < 576)) {
                        board.Initialize(1);
                        smiley.setTexture(TextureManager::GetTexture("face_happy"));
                        nums = Helpers::digitizer(board.GetMineCount() - board.GetFlagCount());
                        for (int i = 0; i < 3; i++)
                            digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
                    }
                    // Load Board 2
                    else if ((position.x > 627 && position.x < 692) 
                        && (position.y > 512 && position.y < 576)) {
                        board.Initialize(2);
                        smiley.setTexture(TextureManager::GetTexture("face_happy"));
                        nums = Helpers::digitizer(board.GetMineCount() - board.GetFlagCount());
                        for (int i = 0; i < 3; i++)
                            digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
                    }
                    // Load Board 3
                    else if ((position.x > 691 && position.x < 756) 
                        && (position.y > 512 && position.y < 576)) {
                        board.Initialize(3);
                        smiley.setTexture(TextureManager::GetTexture("face_happy"));
                        nums = Helpers::digitizer(board.GetMineCount() - board.GetFlagCount());
                        for (int i = 0; i < 3; i++)
                            digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
                    }

                    // Smiley Button Logic
                    else if ((position.x > 349 && position.x < 414) 
                        && (position.y > 512 && position.y < 576)) {
                        board.InitializeRandom();    // THIS NEEDS TO BE THE REAL WAY TO START
                        smiley.setTexture(TextureManager::GetTexture("face_happy"));
                        nums = Helpers::digitizer(board.GetMineCount() - board.GetFlagCount());
                        for (int i = 0; i < 3; i++)
                            digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
                    }
                }

                // Right Button
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);

                    // Flag Logic
                    if (position.y < 512) {
                        Tile* currentSpot = &board.GetTile(25 * (position.y / 32) + (position.x / 32));
                        currentSpot->ToggleFlag();
                        nums = Helpers::digitizer(board.GetMineCount() - board.GetFlagCount());
                        for (int i = 0; i < 3; i++)
                            digitDisplay.at(i).setTextureRect(digitRects.at(nums.at(i)));
                    }
                }
            }
        }

        // ======== Draw ========================================== /

        
        // 1. Clear -- ONLY CALL ONCE!
        window.clear();

        // 2. Draw

        window.draw(background);
        window.draw(debugButton);
        window.draw(test1Button);
        window.draw(test2Button);
        window.draw(test3Button);
        window.draw(smiley);
        for (int i = 0; i < 3; i++)
            window.draw(digitDisplay.at(i));

        for (unsigned int i = 0; i < board.GetSize(); i++) {
            window.draw(board.GetTile(i).GetSprite());
        }
        
        // 3. Display -- ONLY CALL ONCE!
        window.display();
    }

    // ======== Clean Up ========================================== /
    TextureManager::Clear();
    

    return 0;
}