#include "Square.h"

Square::Square() {
    m_shape.setSize({size, size});
}

void Square::setCoordinates(int x, int y) {
    coordinates = {x, y};
    m_shape.setPosition((sf::Vector2f)coordinates);
    m_piece.pieceSprite.setPosition((sf::Vector2f)coordinates);
}

sf::Vector2i Square::getCoordinates() {
    return coordinates;
}

void Square::setPiece(Piece::Color color, Piece::Type type) {
    m_piece.setColor(color);
    m_piece.setPieceType(type);
}

void Square::draw(sf::RenderWindow &window) {
    window.draw(m_shape);
}

void Square::setColor(sf::Color color) {
    m_shape.setFillColor(color);
}


