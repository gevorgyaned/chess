//
// Created by Picsart Academy on 12.02.24.
//

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
    bool playingTurn;
    bool squareSelected;
    sf::RenderWindow& mWindow;
    Board& mBoard;

    sf::Vector2i from;
    sf::Vector2i to;

    void move();
    void handleInput();
};


#endif //SFML_PROJ_GAME_H
