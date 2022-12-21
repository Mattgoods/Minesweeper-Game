#include "Board.h"

Board::Board(string file)
{
    end = false;
    readConfig(file);
}

void Board::drawSP(sf::RenderWindow& wind, sf::Sprite spr) {
    wind.draw(spr);
}

void Board::adjacentTiles(int xP, int yP)
{
    int c = -1;

    if ((xP != tileField.size() - 1 && xP != 0) && (yP != tileField[xP].size() - 1 && yP != 0))
    {
        pushTile(xP, yP, 0, -1);
        pushTile(xP, yP, 1, 0);
        pushTile(xP, yP, -1, 0);
        pushTile(xP, yP, 0, 1);
        pushTile(xP, yP, -1, 1);
        pushTile(xP, yP, -1, -1);
        pushTile(xP, yP, 1, 1);
        pushTile(xP, yP, 1, -1);


        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }

        }
    }
    else if (xP == 0 && yP == tileField[xP].size() - 1)
    {
        pushTile(xP, yP, 1, 0);
        pushTile(xP, yP, 0, -1);
        pushTile(xP, yP, 1, -1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    }
    else if (xP == tileField.size() - 1)
    {
        pushTile(xP, yP, -1, 1);
        pushTile(xP, yP, -1, 0);
        pushTile(xP, yP, -1, -1);
        pushTile(xP, yP, 0, 1);
        pushTile(xP, yP, 0, -1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    }
    else if (xP == 0 && yP == 0)
    {
        pushTile(xP, yP, 0, 1);
        pushTile(xP, yP, 1, 0);
        pushTile(xP, yP, 1, 1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    }

    else if (yP == 0 && xP == tileField.size() - 1)
    {
        pushTile(xP, yP, -1, 0);
        pushTile(xP, yP, 0, 1);
        pushTile(xP, yP, -1, 1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }

    } else if (xP == tileField.size() - 1 && yP == tileField[xP].size() - 1) {
        pushTile(xP, yP, 0, -1);
        pushTile(xP, yP, -1, 0);
        pushTile(xP, yP, -1, -1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++) {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    }
        else if (yP == tileField[xP].size() - 1)
        {
            pushTile(xP, yP, 0, -1);
            pushTile(xP, yP, 1, 0);
            pushTile(xP, yP, -1, 0);
            pushTile(xP, yP, 1, -1);
            pushTile(xP, yP, -1, -1);

            for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
            {
                switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                    case (true) :
                        c++;
                        break;
                }
            }
    } else if (xP == 0) {
        pushTile(xP, yP, 1, -1);
        pushTile(xP, yP, 1, 0);
        pushTile(xP, yP, 1, 1);
        pushTile(xP, yP, 0, 1);
        pushTile(xP, yP, 0, -1);

        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++)
        {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    } else if (yP == 0) {

        pushTile(xP, yP, 1, 1);
        pushTile(xP, yP, -1, 1);
        pushTile(xP, yP, 1, 0);
        pushTile(xP, yP, -1, 0);
        pushTile(xP, yP, 0, 1);


        for (int i = 0; i < tileField[xP][yP].adjacentTiles.size(); i++) {
            switch (tileField[xP][yP].adjacentTiles.at(i)->Bomb()) {
                case (true) :
                    c++;
                    break;
            }
        }
    }

    switch (c) {
        case (-1) :
            break;
        default:
            c++;
            break;
    }

    tileField[xP][yP].setNumber(c);
}

void Board::pushTile(int x, int y, int a, int b) {
    if (a == 0 && b == 1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x][y + 1]);
    }
    else if (a == 1 && b == 0) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x + 1][y]);
    }
    else if (a == 0 && b == -1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x][y - 1]);
    }
    else if (a == -1 && b == 0) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x - 1][y]);
    }
    else if (a == 1 && b == 1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x + 1][y + 1]);
    }
    else if (a == -1 && b == -1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x - 1][y - 1]);
    }
    else if (a == -1 && b == 1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x - 1][y + 1]);
    }
    else if (a == 1 && b == -1) {
        tileField[x][y].adjacentTiles.push_back(&tileField[x + 1][y - 1]);
    }
}

void Board::readConfig(string filename)
{
    smile = 0;
    end = false;
    clearBoard();
    numBombs = 0;

    colsX = 0;
    rowsY = 0;

    for (int i = 0; i < colsX; i++){
        vector <Tile> r;
        for (int j = 0; j < rowsY; j++){
            r.push_back(Tile(false, i, j));
        }
        tileField.push_back(r);
    }
    string path = "boards/";
    path += filename + ".cfg";
    ifstream file(path);


    switch (file.is_open()) {
        case (true) :
            string intData;
            getline(file, intData);
            colsX = stoi(intData);
            getline(file, intData);
            rowsY = stoi(intData);
            getline(file, intData);
            numBombs = stoi(intData);
            break;
    }

    for (int i = 0; i < colsX; i++)
    {
        vector <Tile> rowVector;
        for (int j = 0; j < rowsY; j++)
        {
            rowVector.push_back(Tile(false, i, j));
        }
        tileField.push_back(rowVector);
    }

    int count = numBombs;
    while (count != 0){
        int randY = rand() % (rowsY - 1) + 0;
        int randX = rand() % (colsX - 1) + 0;

        switch (tileField[randX][randY].Bomb()) {
            case (false) :
                tileField[randX][randY].setToBomb();
                count--;
                break;
        }

    }

    for (int j = 0; j < rowsY; j++) {
        for (int i = 0; i < colsX; i++) {
            adjacentTiles(i, j);
        }
    }
}

void Board::checkLoss(bool L)
{
    switch (L) {
        case (true) :
            smile = 2;
            for (int i = 0; i < colsX; i++)
            {
                for (int j = 0; j < rowsY; j++)
                {
                    switch (tileField[i][j].Bomb()) {
                        case (true) :
                            tileField[i][j].setSP("tile_revealed");
                            tileField[i][j].setToShow(false);
                            break;
                    }

                }
            }
            break;
    }

}

bool Board::checkWin()
{
    int c = 0;
    bool b = false;
    int numNotMines = colsX * rowsY - numBombs;

    for (int j = 0; j < rowsY; j++) {
        for (int i = 0; i < colsX; i++) {
            switch (tileField[i][j].Shown() || (tileField[i][j].Marker() && tileField[i][j].Bomb())) {
                case (true) :
                    c++;
                    break;
            }

        }
    }

    if (numNotMines == c)
    {
        smile = 1;
        end = true;

        for (int i = 0; i < colsX; i++)
        {
            for (int j = 0; j < rowsY; j++)
            {
                switch (tileField[i][j].Bomb() && !tileField[i][j].Marker()) {
                    case (true) :
                        tileField[i][j].setToBomb();
                        tileField[i][j].setToShow(false);
                        numBombs--;
                        break;
                }
            }
        }
    }
    return b;
}

void Board::checkLC(sf::Vector2f mPos)
{
    bool lc = false;
    for (int i = 0; i < colsX; i++)
    {
        for (int j = 0; j < rowsY; j++)
        {
            if (tileField[i][j].getNowSP().getGlobalBounds().contains(mPos) && !tileField[i][j].Marker() && tileField[i][j].Bomb() && !end)
            {
                end = true;
                lc = true;
            } else if (tileField[i][j].getNowSP().getGlobalBounds().contains(mPos)
                       && !tileField[i][j].Marker() && !end)
            {
                tileField[i][j].RevealSquares();
                tileField[i][j].setSP("tile_revealed");
                tileField[i][j].setToShow(false);
            }

        }
    }
    checkLoss(lc);
    checkWin();
}


void Board::checkRC(sf::Vector2f mPos)
{

    for (int j = 0; j < rowsY; j++)
    {
        for (int i = 0; i < colsX; i++)
        {
            switch (tileField[i][j].getNowSP().getGlobalBounds().contains(mPos) && !tileField[i][j].Shown()) {
                case (true) :
                    switch (tileField[i][j].setMark()) {
                        case (true) :
                            numBombs--;
                            break;
                        default:
                            numBombs++;
                            break;
                    }
                    break;
            }

        }
    }
}

void Board::readTest(string filename)
{
    rowsY = 0;
    colsX = 0;
    numBombs = 0;
    smile = 0;
    end = false;
    numMarkers = 0;
    clearBoard();

    string path = "boards/";
    path += filename + ".brd";
    ifstream file(path);

    int columnCount = 0;
    int rowCount = 0;

    switch (file.is_open()) {
        case (true) :
            string line;

            while (getline(file, line)){
                for (int i = 0; i < line.size(); i++){
                    int a = line[i] - 48;
                    board.push_back(a);
                }
                rowCount++;
            }
            columnCount = line.size();
            break;
    }

    colsX = rowCount;
    rowsY = columnCount;

    int count = 0;
    for (int i = 0; i < colsX; i++){
        vector <Tile> r;
        for (int j = 0; j < rowsY; j++){
            bool mine = false;
            switch (board.at(count)) {
                case (1) :
                    mine = true;
                    numBombs++;
                    break;
            }

            r.push_back(Tile(mine, j, i));
            count++;
        }
        tileField.push_back(r);
    }

    for (int j = 0; j < rowsY; j++) {
        for (int i = 0; i < colsX; i++) {
            adjacentTiles(i, j);
        }
    }

}

void Board::boardDebug(sf::RenderWindow& display){
    for (int i = 0; i < colsX; i++){
        for (int j = 0; j < rowsY; j++){
            switch (tileField[i][j].Bomb() && !end) {
                case (true) :
                    display.draw(tileField[i][j].getNoSP());
                    break;
            }

        }
    }
}

void Board::clearBoard() {
    board.clear();
    tileField.clear();
}

