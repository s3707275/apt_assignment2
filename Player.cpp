
#include "Player.h"

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
void Player::giveNewHand(){

}

// Method to print the players hand
void Player::displayHand(){

}

// Adds a new tile to the head of the hand
void Player::addTile(){

}

// removes specified tile from hand if it exists
void Player::removeTile(){

}

// removes specified tile from hand if it exists
// and replaces it with a new random tile from the bag
void Player::replaceTile(){

}

// returns the current amount of tiles in player's hand
int Player::handSize(){
  return HAND_SIZE;
}
