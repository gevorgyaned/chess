#ifndef SFML_PROJ_SQUARE_H
#define SFML_PROJ_SQUARE_H

#include "Piece.h"

#include <SFML/Graphics.hpp>

class Square {
public:
    Square();
    void setPiece(Piece::Color color, Piece::Type type);
    void setCoordinates(int x, int y);
    void draw(sf::RenderWindow& window);
    void setColor(sf::Color color);
    sf::Vector2i getCoordinates();
    Piece m_piece;
private:
    constexpr static const float size = 60;
    sf::Color m_color;
    sf::RectangleShape m_shape;
    sf::Vector2i coordinates;
};

#endif //SFML_PROJ_SQUARE_H
