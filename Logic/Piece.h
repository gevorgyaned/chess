#ifndef SFML_PROJ_PIECE_H
#define SFML_PROJ_PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Piece {
public:
    enum class Type { Pawn, Knight, Bishop, Rook, Queen, King, NoType };
    enum class Color { Black, White, NoColor };

    Piece();
    sf::Texture texture;
    sf::Sprite pieceSprite;
    Type getPieceType();
    void loadSprite();
    void setPieceType(Type pieceType);
    void setColor(Color color);

protected:
    /* TODO */
    virtual bool isValidMove();

private:
    Type m_pieceType;
    Color m_color;
};

#endif //SFML_PROJ_PIECE_H
