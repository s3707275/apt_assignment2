
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList() {
}

void LinkedList::addFront(Tile* newTile){
  // places tile at front of linked LinkedList
  // moves head pointer to the new tile and head next pointer to old head
  // if list is empty, new node becomes head and tail
  // constant time complexity
  Node *newNode = new Node();
  newNode->tile = newTile;
  newNode->head = head;
  this->head = newNode;
  if(length == 0){
    this->tail = newNode;
  }
  legnth++;
}

void LinkedList::insertAt(int pos, Tile* newTile){
  // checks length of LinkedList, find position in LinkedList
  // changes prvious node's pointer to the new node and points new node to the pointer of the current node
  // linear time complexity
  if(length < pos){
    Node *previousNode = nullptr;
    Node *currentNode = this->head;

    for(int i = 1; i < pos; i++){
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

    Node *newNode = nullptr;
    previousNode->next = newNode;
    newNode->tile = newTile;
    newNode->next = currentNode;
    length++;
  }
}

void LinkedList::addBack(Tile* newTile){
  // uses the tail pointer to allow for constant time complexity
  // attempts to place tile at end of the LinkedList
  // if list is empty, tile is head and tail
  Node *newNode = new Node();
  newNode->tile = newTile;
  if(length == 0){
    this->head = newNode;
    this->tail = newNode;
  }
  else {
    this->tail->next = newNode;
    this->tail = newNode;
  }
  length--;
}

Node* LinkedList::get(int pos){
  Node *currentNode = head;
  if (pos < 0 || pos > length){
    return nullptr;
  }
  for(int i = 0; i < pos; i++){
    currentNode = currentNode->next;
  }
  return currentNode;
}

boolean LinkedList::search(Tile* currentTile){
  Node* currentNode = head;
  for (int i = 0; i < length; i++){
    if (currentNode->tile == currentTile){
      return true;
    }
    currentNode = currentNode->next;
  }
  return false;
}

void LinkedList::remove(){

}
