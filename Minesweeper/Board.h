#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Tile.h"
#include "TextureManager.h"
#include "SFML/Graphics.hpp"
using namespace std;

class Board {
private:
    int numMarkers;
    vector<int> board;
public:
    vector<vector<Tile>> tileField;
    int colsX;
    int rowsY;
    bool end;
    int numBombs;
    int smile = 0;
    Board(string file);
    static void drawSP(sf::RenderWindow& wind, sf::Sprite spr);
    void checkLC(sf::Vector2f mPos);
    void checkRC(sf::Vector2f mPos);
    void readTest(string title);
    void readConfig(string title);
    void boardDebug(sf::RenderWindow& display);
    void adjacentTiles(int xPos, int yPos);
    void pushTile(int xP, int yP, int a, int b);
    void checkLoss(bool L);
    void clearBoard();
    bool checkWin();

};



