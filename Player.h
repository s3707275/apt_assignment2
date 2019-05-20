
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

#define HAND_SIZE          6

class Player {

  public:
    Player(std::string name);
    ~Player();

    void giveNewHand();
    void displayHand();
    void addTile();
    void removeTile();
    void replaceTile();
    int handSize();

  // private:
    std::string name;
    int score;
    LinkedList* hand;
    // LinkedList hand;
};

#endif // ASSIGN2_PLAYER_H
