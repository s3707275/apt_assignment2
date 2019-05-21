
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

#define HAND_SIZE          6

class Player {

  public:
    Player(std::string name);
    ~Player();

    void giveNewHand(LinkedList& bag);
    void displayHand();
    void addTile(Tile* newTile); // added arg - Will
    void removeTile(int pos); // added arg - Will
    void replaceTile(int pos, Tile* tile); // added args - Will
    int handSize();

  // private:
    std::string name;
    int score;
    LinkedList* hand;
    // LinkedList hand;
};

#endif // ASSIGN2_PLAYER_H
