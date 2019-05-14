
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   void addFront(Tile* newTile);
   void insertAt(int pos, Tile* newTile);
   void addBack(Tile* newTile);
   Node* get(int pos);
   boolean search(Tile* currentTile);
   void remove(int pos)
   void removeHead()
   void removeTail();

private:
   Node* head;
   Node* tail;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
