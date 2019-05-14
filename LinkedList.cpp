
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList()
{
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
  // linear time
  // finds the value of the tile at a given position
  // checks position is a legal value
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

void LinkedList::remove(int pos){
  Node *currentNode = head;
  Node *previousNode = nullptr;

  for(int i = 1; i < pos; i++) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
  previousNode->next = currentNode->next;
  delete currentNode;
}

void LinkedList::removeHead(){
  // constant time
  Node *temp = head;
  head = head->next;
  delete temp;
}

void LinkedList::removeTail(){
  Node *currentNode = head;
  Node *previousNode = nullptr;

  while(currentNode->next!=nullptr) {
    currentNode=current;
    currentNode=currentNode->next;
  }
  tail = previousNode;
  previousNode->next = nullptr;
  delete currentNode;
}

Tile* LinkedList::removeFromBag(){
  // shuffle method
  // chooses a random value in the LinkedList, between 0 and
  int min = 0;
  int max = length;
  int seed = 1234;
  std::default_random_engine engine(seed);
  std::uniform_int_distribution<int> uniform_dist(min, max);
  int pos = uniform_dist(engine);
  std::cout << "Randomly-chosen position: " << pos << std::endl;
  return this->get(pos);
}
