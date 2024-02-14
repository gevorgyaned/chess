#include "Game.h"

Game::Game(sf::RenderWindow &window, Board& board) : mWindow(window), mBoard(board) {
    currentPlayer = Piece::Color::White;
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
    if (currentPlayer != mBoard.getSquare(moveFrom).m_piece.getColor()) {
        squareSelected = false;
        return;
    }

    mBoard.getSquare(moveTo).m_piece = mBoard.getSquare(moveFrom).m_piece;
    mBoard.getSquare(moveFrom).setPiece(Piece::Color::NoColor, Piece::Type::NoType);

    changePlayer();
}

void Game::handleInput() {
    sf::Vector2i squareCoords;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i coordinates = sf::Mouse::getPosition(mWindow);
        sf::Vector2f boardPixels = mWindow.mapPixelToCoords(coordinates);

        squareCoords = {(int)boardPixels.x / 60, (int)boardPixels.y / 60};

        if (squareSelected) {
            moveTo = squareCoords;

            if (moveTo == moveFrom) {
                return;
            }

            squareSelected = false;
            move();
        }
        else {
            moveFrom = squareCoords;

            if (moveTo == moveFrom) {
                return;
            }

            squareSelected = true;
        }
    }
}

void Game::changePlayer() {
    currentPlayer = currentPlayer == Piece::Color::White ? Piece::Color::Black : Piece::Color::White;
}
