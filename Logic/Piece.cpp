#include "Piece.h"

Piece::Piece() {
    m_pieceType = Type::NoType;
    m_color = Color::NoColor;
}

bool Piece::isValidMove() {
    return false;
}

void Piece::setPieceType(Piece::Type pieceType) {
    m_pieceType = pieceType;
}

Piece::Type Piece::getPieceType() {
    return m_pieceType;
}

void Piece::setColor(Piece::Color color) {
    m_color = color;
}

void Piece::loadSprite() {
    if (m_pieceType == Type::NoType) {
        return;
    }

    std::string filename = m_color == Color::White ? "W_" : "B_";

    switch(m_pieceType) {
        case Type::Pawn:
            filename += "P.png";
            break;
        case Type::King:
            filename += "K.png";
            break;
        case Type::Knight:
            filename += "Kn.png";
            break;
        case Type::Bishop:
            filename += "B.png";
            break;
        case Type::Queen:
            filename += "Q.png";
            break;
        case Type::Rook:
            filename += "R.png";
            break;
        default:
            filename = "Not found";
            break;
    }

    texture.loadFromFile("/Users/picsartacademy/CLionProjects/chess/Sprites/" + filename);
    pieceSprite.setTexture(texture);
}

