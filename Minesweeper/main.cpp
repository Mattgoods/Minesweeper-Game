#include "Board.h"
#include "Tile.h"
#include "TextureManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    Board gameBoard("config");
    sf::RenderWindow display(sf::VideoMode(1000, 1000), "Minesweeper");

    sf::Sprite smile;
    sf::Sprite sprite;
    sf::Sprite markerAmt;

    sf::Sprite amount1;
    sf::Sprite amount2;
    sf::Sprite amount3;

    sf::Sprite test1;
    sf::Sprite test2;
    sf::Sprite test3;

    sprite.setTexture(TextureManager::GetTexture("debug"));
    sprite.setPosition(((sprite.getGlobalBounds().width * 2) + (gameBoard.colsX * (16))  - 16), 32 * gameBoard.rowsY);
    test1.setTexture(TextureManager::GetTexture("test_1"));
    test1.setPosition(((sprite.getGlobalBounds().width * 3) + (gameBoard.colsX * (16)) - 16), (32 * gameBoard.rowsY));
    test2.setTexture(TextureManager::GetTexture("test_2"));
    test2.setPosition(((sprite.getGlobalBounds().width * 4) + (gameBoard.colsX * (16)) - 16), (32 * gameBoard.rowsY));
    test3.setTexture(TextureManager::GetTexture("test_3"));
    test3.setPosition((((5) * sprite.getGlobalBounds().width) + (gameBoard.colsX * (16)) - 16), (32 * gameBoard.rowsY));
    amount1.setPosition(21, ((32) * gameBoard.rowsY));
    amount2.setPosition(42, ((32) * gameBoard.rowsY));
    amount3.setPosition(63, ((32) * gameBoard.rowsY));
    smile.setTexture(TextureManager::GetTexture("face_happy"));
    smile.setPosition(((16 * gameBoard.colsX) - 16), (32 * gameBoard.rowsY));
    markerAmt.setPosition(0, gameBoard.rowsY * 32);
    bool debug = false;

    while (display.isOpen()) {
        sf::Event event;

        while (display.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed) :
                    display.close();
                case (sf::Event::MouseButtonPressed) :
                    sf::Vector2f mPos = display.mapPixelToCoords(sf::Mouse::getPosition(display));
                    switch (event.mouseButton.button) {
                        case (sf::Mouse::Left) :
                            gameBoard.checkLC(mPos);
                            switch (sprite.getGlobalBounds().contains(mPos)) {
                                case (true) :
                                    switch (debug) {
                                        case (true) :
                                            debug = false;
                                            break;
                                        case (false) :
                                            debug = true;
                                            break;
                                    }
                                    break;
                            }
                            switch (test3.getGlobalBounds().contains(mPos)) {
                                case (true) :
                                    gameBoard.readTest("testboard3");
                                    break;
                            }

                            switch (smile.getGlobalBounds().contains(mPos)) {
                                case (true) :
                                    gameBoard.readConfig("config");
                                    break;
                            }

                            switch (test1.getGlobalBounds().contains(mPos)) {
                                case (true) :
                                    gameBoard.readTest("testboard1");
                                    break;
                            }

                            switch (test2.getGlobalBounds().contains(mPos)) {
                                case (true) :
                                    gameBoard.readTest("testboard2");
                                    break;
                            }

                            break;
                    }

                    switch (event.mouseButton.button) {
                        case (sf::Mouse::Right) :
                            gameBoard.checkRC(mPos);
                            break;
                    }
                    break;
            }
        }

        display.clear();

        for (int j = 0; j < gameBoard.rowsY; j++) {
            for (int i = 0; i < gameBoard.colsX; i++) {
                gameBoard.tileField[i][j].Draw(display);
            }
        }

        switch (debug) {
            case (true) :
                gameBoard.boardDebug(display);
        }

        if (gameBoard.smile == 1) {
            smile.setTexture(TextureManager::GetTexture("face_win"));
        }
        else if (gameBoard.smile == 2) {
            smile.setTexture(TextureManager::GetTexture("face_lose"));
        }
        else {
            smile.setTexture(TextureManager::GetTexture("face_happy"));
        }

        int nb = gameBoard.numBombs;
        if (nb > 0) {
            markerAmt.setTextureRect(sf::IntRect(0, 0, 0, 32));
        } else {
            markerAmt.setTextureRect(sf::IntRect(210, 0, 21, 32));
            markerAmt.setTexture(TextureManager::GetTexture("digits"));
        }

        for (int i = 0; i < 10; i++) {

            if (nb < 0) {
                nb = nb * -1;
            }

            int nb1 = (nb % 10);
            int nb2 = (nb % 100 / 10);
            int nb3 = (nb % 1000 / 100);

            if (nb1 == i) {
                amount3.setTexture(TextureManager::GetTexture("digits"));
                amount3.setTextureRect(sf::IntRect(i * 21, 0, 21, 32));
            }
            if (nb2 == i) {
                amount2.setTexture(TextureManager::GetTexture("digits"));
                amount2.setTextureRect(sf::IntRect(i * 21, 0, 21, 32));
            }
            if (nb3 == i) {
                amount1.setTexture(TextureManager::GetTexture("digits"));
                amount1.setTextureRect(sf::IntRect(i * 21, 0, 21, 32));
            }
        }

        Board::drawSP(display, amount1);
        Board::drawSP(display, amount2);
        Board::drawSP(display, amount3);
        Board::drawSP(display, test1);
        Board::drawSP(display, test2);
        Board::drawSP(display, test3);
        Board::drawSP(display, smile);
        Board::drawSP(display, sprite);
        Board::drawSP(display, markerAmt);

        display.display();
    }

    TextureManager::Clear();

    return 0;
}