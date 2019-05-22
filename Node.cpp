
#include "Node.h"

Tile* tile;
Node* next;

Node::Node(Tile* tile, Node* next)
{
  this->tile = tile;
  this->next = next;
}

Node::Node(Node& other) :
  tile(other.tile),
  next(other.next)
{
   // TODO
};

Node::~Node() {
}
