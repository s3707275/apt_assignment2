
#include "LinkedList.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

LinkedList::LinkedList() {
   head = nullptr;
}

LinkedList::~LinkedList() {
  Node* currentNode = head;
  Node* toDelete = nullptr;
  for(int i = 0; i < size(); i++){
    toDelete = currentNode;
    currentNode = currentNode->next;
    delete toDelete;
  }
  head = nullptr;
}

void LinkedList::addFront(Tile* newTile){
  // places tile at front of linked LinkedList
  // moves head pointer to the new tile and head next pointer to old head
  // if list is empty, new node becomes head and tail
  // constant time complexity
  Node* newNode = new Node(newTile, nullptr);
  if(head != nullptr){
    newNode->next = head;
    this->head = newNode;
  }
  else{
    this->head = newNode;
  }
}

void LinkedList::addBack(Tile* newTile){
  // linear time
  Node* newNode = new Node(newTile, nullptr);
  if(head == nullptr){
    this->head = newNode;
  }
  else{
    Node* currentNode = head;
    while(currentNode->next != nullptr){
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
  }
}

Node* LinkedList::get(int pos){
  // linear time
  // finds the value of the tile at a given position
  // checks position is a legal value
  // if returning a nullptr be mindful that will cause a seg fault
  pos--;
  if (pos < 0 || pos > size()){
    return nullptr;
  }
  Node *currentNode = head;
  for(int i = 0; i < pos; i++){
    currentNode = currentNode->next;
  }
  return currentNode;
}

// remove mehtods could be void??
Node* LinkedList::remove(int pos){
  pos--;
  Node* currentNode = head;
  Node* previousNode = nullptr;
  if (pos < 0 || pos > size()){
    return nullptr;
  }
  if(pos == 0){
    return removeHead();
  }
  else{
    for(int i = 0; i < pos; i++){
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
    previousNode->next = currentNode->next;
  }
  return currentNode;
}

Node* LinkedList::removeHead(){
  if(head == nullptr){
    return nullptr;
  }
  else {
    Node* newHead = head->next;
    Node* temp = head;
    head = newHead;
    return temp;
  }
}

void LinkedList::display(){
  if(head != nullptr){
    Node* currentNode = head;
    while(currentNode != nullptr){
      Tile* tile = currentNode->tile;
      if(currentNode->next != nullptr){
        std::cout << tile->colour << tile->shape << ",";
      }
      else {
        std::cout << tile->colour << tile->shape;
      }
      currentNode = currentNode->next;
    }
    std::cout << std::endl;
  }
}

bool LinkedList::search(char searchColour, int searchShape){
  Node* currentNode = head;
  while(currentNode->next != nullptr){
    Tile* tile = currentNode->tile;
    if(tile->colour == searchColour && tile->shape == searchShape){
      return true;
    }
  }
  return false;
}

int LinkedList::positionSearch(char searchColour, int searchShape){
  Node* currentNode = head;
  int index = 0;
  while(currentNode->next != nullptr){
    Tile* tile = currentNode->tile;
    index++;
    if(tile->colour == searchColour && tile->shape == searchShape){
      return index;
    }
    currentNode = currentNode->next;
  }
  return -1;
}

int LinkedList::size(){
  int size = 0;
  if(head != nullptr){
    Node* currentNode = head;
    while(currentNode != nullptr){
        size++;
        currentNode = currentNode->next;
    }
  }
  return size;
}

int LinkedList::removeFromBag(){
  if(this->size() == EMPTY_BAG){
    return -1;
  }
  else {
    int minIndex = 1;
    int maxIndex = this->size();
    srand(time(NULL));
    std::default_random_engine engine(rand()%this->size());
    std::uniform_int_distribution<int> uniformDist(minIndex, maxIndex);

    int pos = uniformDist(engine);
    return pos;
  }
}
