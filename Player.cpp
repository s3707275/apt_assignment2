
#include "Player.h"

std::string name;
int score;
LinkedList* hand;

Player::Player(std::string name){
  this->name = name;
  this->score = 0;
  this->hand = new LinkedList();
}

Player::~Player() {
  // destructor
  delete hand;
}

// Method called when game commences to
// give the player 6 tiles - maybe addTile only
void Player::giveNewHand(LinkedList& bag){
  for(int i = 0; i < HAND_SIZE; i ++){
    int pos = bag.removeFromBag();
    Tile* tile = bag.get(pos)->tile;
    hand->addFront(tile);
    bag.remove(pos);
  }
}

// Method to print the players hand
void Player::displayHand(){
  hand->display();
}

// Adds a new tile to the head (pos) of the hand
void Player::addTile(Tile* tile){
  hand->addFront(tile);
}

// Removes specified tile from hand if it exists
void Player::removeTile(int pos){
  hand->remove(pos);
}

Node* Player::get(int pos){
  return hand->get(pos);
}

// Removes specified tile from hand if it exists
// and replaces it with a new random tile from the bag
void Player::replaceTile(int pos, LinkedList& bag){

  // tile is removed from player's hand
  Tile* removed = hand->get(pos)->tile;
  hand->remove(pos);

  // random tile is placed into player's hand
  int random = bag.removeFromBag();
  Tile* newTile = bag.get(random)->tile;
  hand->addFront(newTile);

  // removed tile is placed back into bag
  bag.addFront(removed);
}

// returns the current amount of tiles in player's hand
int Player::handSize(){
  return hand->size();
}
