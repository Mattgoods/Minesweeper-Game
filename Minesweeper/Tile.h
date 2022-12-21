#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
using namespace std;

class Tile {
private:
    sf::Sprite noSP;
    sf::Sprite nowSP;
    sf::Sprite markSP;
    sf::Vector2f tilePos;
    bool shown;
    bool bomb;
    bool marker;
    int num;
public:
    Tile(bool bomb, int xPos, int yPos);
    sf::Sprite getNoSP();
    sf::Sprite getNowSP();
    sf::Sprite getMarkSP();
    vector<Tile*> adjacentTiles;
    bool setMark();
    bool Marker();
    int getNumber();
    bool Shown();
    bool Bomb();
    void setToShow(bool bug);
    void setNumber(int num);
    void setToBomb();
    void RevealSquares();
    void setSP(string textureName);
    void Draw(sf::RenderWindow& window);
};

