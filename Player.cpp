
#include "Player.h"

#define HAND_SIZE   6

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
  for(int x = 0; x < HAND_SIZE; x++){
    Tile* tile = bag.removeFromBag();
    hand->addFront(tile);
  }
}

// Method to print the players hand
void Player::displayHand(){
  hand->display();
}

// Adds a new tile to the head of the hand

/*
* Added the Tile* newTile arg for this function
* so that it can be passed to the LinkedList
* function addFront(Tile* newTile) - Will
*/
void Player::addTile(Tile* newTile){
  hand->addFront(newTile);
}

// removes specified tile from hand if it exists

/*
* Added the Tile* newTile arg for this function
* so that it can be passed to the LinkedList
* function remove(int pos) - Will
*/
void Player::removeTile(int pos){
  hand->remove(pos);
}

// removes specified tile from hand if it exists
// and replaces it with a new random tile from the bag

/*
* Added the args for this function:
* pos: The position of the tile that we want
* to remove.
* tile: The tile to replace the removed one.
* - Will
*/
void Player::replaceTile(int pos, Tile* tile){
  hand->remove(pos);
  hand->addBack(tile);
}

// returns the current amount of tiles in player's hand

/*
* Returning the int from the linkedList's size function
* - Will
*/
int Player::handSize(){
  return hand->size();
}
