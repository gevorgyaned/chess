#include "Logic/Board.h"
#include "Game.h"

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(483, 480), "CHESS");
    Board board;

    board.setPieces();
    board.initSquares();

    Game game(mainWindow, board);

    game.run();
}
