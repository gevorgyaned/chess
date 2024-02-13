#include "Game.h"

Game::Game(sf::RenderWindow &window, Board& board) : mWindow(window), mBoard(board) {
    playingTurn = 1;
    squareSelected = false;
}

void Game::run() {
    while (mWindow.isOpen()) {
        sf::Event event{};

        while (mWindow.pollEvent(event)) {
            handleInput();

            if (event.type == sf::Event::Closed)
                mWindow.close();
        }

        mWindow.setFramerateLimit(30);
        mWindow.clear();
        mBoard.drawSquares(mWindow);
        mWindow.display();
    }
}

void Game::move() {
    mBoard.getSquare(to).m_piece = mBoard.getSquare(from).m_piece;
    mBoard.getSquare(from).setPiece(Piece::Color::NoColor, Piece::Type::NoType);
}

void Game::handleInput() {
    sf::Vector2i squareCoords;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i coordinates = sf::Mouse::getPosition(mWindow);
        sf::Vector2f boardPixels = mWindow.mapPixelToCoords(coordinates);

        squareCoords = {(int)boardPixels.x / 60, (int)boardPixels.y / 60};

        if (squareSelected) {
            to = squareCoords;
            squareSelected = false;
            move();
        }
        else {
            from = squareCoords;
            squareSelected = true;
        }
    }
}