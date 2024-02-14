#ifndef SFML_PROJ_GAME_H
#define SFML_PROJ_GAME_H

#include "Logic/Piece.h"
#include "Logic/Square.h"
#include "Logic/Board.h"

#include <SFML/Graphics.hpp>

class Game {
public:
    Game(sf::RenderWindow& window, Board& board);
    void run();

private:
    sf::RenderWindow& mWindow;
    Board& mBoard;

    bool squareSelected;
    Piece::Color currentPlayer;

    sf::Vector2i moveFrom;
    sf::Vector2i moveTo;

    void move();
    void handleInput();
    void changePlayer();
};


#endif //SFML_PROJ_GAME_H
