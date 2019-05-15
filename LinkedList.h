
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   void addFront(Tile* newTile);
   // void insertAt(int pos, Tile* newTile);
   void addBack(Tile* newTile);
   Node* get(int pos);
   // bool search(Tile* currentTile);
   Node* remove(int pos);
   Node* removeHead();
   void display();
   int size();

   // Tile* removeFromBag();

// private:
   Node* head;
   Node* tail;
};

#endif // ASSIGN2_LINKEDLIST_H
