
#include "Tile.h"

Colour colour;
Shape shape;

Tile::Tile(Colour colour, Shape shape) {
  this->colour = colour;
  this->shape = shape;
}

Tile::~Tile() {
  // destructor
}
