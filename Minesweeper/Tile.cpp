#include "Tile.h"
#include "TextureManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Tile::setSP(string tex){
    nowSP.setPosition(tilePos.x, tilePos.y);
    nowSP.setTexture(TextureManager::GetTexture(tex));
}

bool Tile::Shown(){
    return shown;
}

Tile::Tile(bool bomb_, int xPos, int yPos){

    bomb = bomb_;
    num = -1;
    shown = false;
    marker = false;
    tilePos.x = 32 * xPos;
    tilePos.y = 32 * yPos;

    nowSP.setPosition(tilePos);
    nowSP.setTexture(TextureManager::GetTexture("tile_hidden"));

}

sf::Sprite Tile::getNowSP(){
    return nowSP;
}

sf::Sprite Tile::getMarkSP(){
    markSP.setPosition(tilePos);
    markSP.setTexture(TextureManager::GetTexture("flag"));


    return markSP;
}

void Tile::setToBomb(){
    noSP.setTexture(TextureManager::GetTexture("mine"));
    noSP.setPosition(tilePos);
    bomb = true;
}

bool Tile::Marker(){
    return marker;
}

sf::Sprite Tile::getNoSP(){
    switch (bomb) {
        case (true) :
            noSP.setTexture(TextureManager::GetTexture("mine"));
            noSP.setPosition(tilePos);
            break;
        case (false) :
            string textName = "number_";
            textName += to_string(num);
            noSP.setTexture(TextureManager::GetTexture(textName));
            noSP.setPosition(tilePos);
            break;
    }

    return noSP;
}

void Tile::setToShow(bool bug) {
    if (shown == false){
        shown = true;
    } else if ((shown && bug) == true){
        shown = false;
    }
}

void Tile::setNumber(int a){
    num = a;
}

int Tile::getNumber(){
    return num;
}

void Tile::RevealSquares(){
    for (int i = 0; adjacentTiles.size() > i; i++){
        if (adjacentTiles.at(i)->getNumber() >= 0 && !adjacentTiles.at(i)->Bomb() && !adjacentTiles.at(i)->Marker()){
            adjacentTiles.at(i)->setSP("tile_revealed");
            adjacentTiles.at(i)->setToShow(false);
        } else if (!adjacentTiles.at(i)->Shown() && adjacentTiles.at(i)->getNumber() == -1 && !adjacentTiles.at(i)->Shown() && !adjacentTiles.at(i)->Bomb()){
            adjacentTiles.at(i)->setSP("tile_revealed");
            adjacentTiles.at(i)->setToShow(false);
            adjacentTiles.at(i)->RevealSquares();
        }
    }
}

void Tile::Draw(sf::RenderWindow& window) {
    if (Marker() == true) {
        window.draw(getNowSP());
        window.draw(getMarkSP());

    } else if (Shown() == true) {
        window.draw(getNowSP());


        if ((num != -1 || Bomb()) == true) {
            window.draw(getNoSP());
        }
    }else {
        window.draw(getNowSP());
    }

    }


bool Tile::Bomb()
{
    return bomb;
}

bool Tile::setMark()
{
    switch (marker) {
        case (false) :
            marker = true;
            return marker;
            break;
        case (true) :
            marker = false;
            return marker;
            break;
    }

}

