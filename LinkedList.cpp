
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList() {
}

void addFront(Tile* newTile){
  Node *new_node = new Node();
  new_node->tile = newTile;
  new_node->head = head;
  this->head = new_node;
  if(length == 0){
    this->tail = new_node;
  }
  legnth++;
}

void addBack(Tile* newTile){
  Node *new_node = new Node();
  new_node->tile = newTile;
  if(length == 0){
    this->head = new_node;
    this->tail = new_node;
  }
  else {
    this->tail->next = new_node;
    this->tail = new_node;
  }
  length--;
}

Node* get(int searchInt){
  Node *currentNode = head;
  int i = 0;
  if (searchInt < 0 || searchInt > length){
    return nullptr;
  }
  while(i < searchInt) {
    currentNode = currentNode->next;
    i++;
  }
  return currentNode;
}

boolean search(Tile* currentTile){
  Node* currentNode = head;
  for (int i = 0; i < this->length; i++){
    if (currentNode->tile == currentTile){
      return true;
    }
    currentNode = currentNode->next;
  }
  return false;
}

void remove(){

}
