
#include "Tile.h"
#include "TileCodes.h"


private Colour colour;
private Shape shape;

public Tile::Tile(Colour colour, Shape shape){
    this->colour = colour;
    this->shape = shape;
}

public Colour Tile::getColour(){
    return colour;
}

public Shape Tile::getShape(){
    return shape;
}




