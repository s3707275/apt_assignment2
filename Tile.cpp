
#include "Tile.h"
#include "TileCodes.h"

Colour colour;
Shape shape;

Tile::Tile(Colour colour, Shape shape){
    this->colour = colour;
    this->shape = shape;
}

Colour Tile::getColour(){
    return colour;
}

Shape Tile::getShape(){
    return shape;
}








