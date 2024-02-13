#include "Board.h"

#include <optional>

using Color = Piece::Color;
using Type =  Piece::Type;

Board::Board() = default;

Square& Board::getSquare(sf::Vector2i coord) {
    return board[coord.x][coord.y];
}

void Board::initSquares() {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            board[i][j].m_piece.loadSprite();
            board[i][j].setCoordinates(i * 60, j * 60);
            board[i][j].setColor((i + j) % 2 ? sf::Color(118, 150, 86) : sf::Color(238, 238, 210));
        }
    }
}

void Board::drawPieces(sf::RenderWindow& window) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            int x = 60 * i;
            int y = 60 * j;

            if (board[i][j].m_piece.getPieceType() != Piece::Type::NoType) {
                board[i][j].m_piece.pieceSprite.setPosition(x, y);
                window.draw(board[i][j].m_piece.pieceSprite);
            }
        }
    }
}

void Board::setPieces() {
    for (int i = 0; i < board.size(); ++i) {
        board[i][1].setPiece(Color::White, Type::Pawn);
        board[i][6].setPiece(Color::Black, Type::Pawn);
    }

    const Type pieceTypes[] = {Type::Rook, Type::Knight, Type::Bishop};
    for (int i = 0; i < 3; ++i) {
        board[i][0].setPiece(Color::White, pieceTypes[i]);
        board[i][7].setPiece(Color::Black, pieceTypes[i]);
        board[7 - i][0].setPiece(Color::White, pieceTypes[i]);
        board[7 - i][7].setPiece(Color::Black, pieceTypes[i]);
    }

    board[3][0].setPiece(Color::White, Type::Queen);
    board[4][0].setPiece(Color::White, Type::King);
    board[3][7].setPiece(Color::Black, Type::King);
    board[4][7].setPiece(Color::Black, Type::Queen);
}

void Board::drawSquares(sf::RenderWindow& window) {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j){
            board[i][j].draw(window);
            if (board[i][j].m_piece.getPieceType() != Piece::Type::NoType) {
                board[i][j].m_piece.pieceSprite.setPosition(60 * i, 60 * j);
                window.draw(board[i][j].m_piece.pieceSprite);
            }
        }
}

void Board::setSquare(int row, int col, Square &square) {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        board[row][col] = square;
    }
}
