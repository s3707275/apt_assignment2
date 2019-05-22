
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
    void addTile(Tile* tile);
    void removeTile(int pos);
    void replaceTile(int pos, LinkedList& bag);
    Node* get(int pos);
    int handSize();

  // private:
    std::string name;
    int score;
    LinkedList* hand;
};

#endif // ASSIGN2_PLAYER_H
