#ifndef SFML_PROJ_BOARD_H
#define SFML_PROJ_BOARD_H

#include <array>

#include "Square.h"

class Board {
public:
    Board();
    Square& getSquare(sf::Vector2i coord);
    void setSquare(int row, int col, Square& square);
    void drawSquares(sf::RenderWindow& window);
    void initSquares();
    void setPieces();
    void drawPieces(sf::RenderWindow& window);

private:
    std::array<std::array<Square, 8>, 8> board;
};

#endif //SFML_PROJ_BOARD_H
