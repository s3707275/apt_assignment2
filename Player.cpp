#include "Player.h"
#include "Node.h"
#include "Tile.h"

#include <iostream>

using std::string;

#define HAND_SIZE   6

 
string name;
Node* head;
int score;

Player::Player(string name){
    this->name = name;
    this->score = 0;
    head = nullptr;
}

string Player::getName(){
    return name;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int score){
    if(score >= 0){
        this->score += score;
    }
    else{
         std::cerr << "Error: " << score << " is an invalid score to set to a player" << std::endl;
    }
}

void Player::display(){
    if(head->next != nullptr){
        Node* curr = head;
        while(curr->next != nullptr){
            Tile tile = curr->tile;
            cout << tile->shape <<", "<< tile->colour << " ";
            curr = curr->next;
      }
    }
    else{
        std::cerr << "Error: " << name << "'s hand is empty" << std::endl;
    }
}

void Player::add(Tile toAdd){
    if(handSize() != HAND_SIZE){
        Node* curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        Node* newNode = new Node(nullptr, toAdd);
        curr->next = newNode;
    }
    else{
         std::cerr << "Error: " << name << "'s hand already contains 6 tiles" << std::endl;
    }          
}

void Player::replace(Tile takeOut, Tile putIn){
    boolean exists = false;
    Node* curr = head;
    while(curr->next != nullptr){
        Tile tile = curr->tile;
        if(tile->shape == takeOut->shape && tile->colour == takeOut->colour){
            tile->shape = putIn->shape;
            tile->colour = putIn->colour;
            exists = true;
        }
        curr = curr->next;
    }
    if(!exists){
         std::cerr << "Error: (" << takeOut->shape << ", " << takeOut->colour << ") doesn't exist in " << name << "'s hand" << std::endl;
    }
}

void Player::remove(Tile toRemove){
    boolean exists = false;
    Node* curr = head;
    Node* prev = nullptr;
    while(curr->next != nullptr){
        Tile tile = curr->tile;
        if(tile->shape == toRemove->shape && tile->colour == toRemove->colour){
            prev->next = curr->next;
            exists = true;
            delete curr;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!exists){
          std::cerr << "Error: (" << toRemove->shape << ", " << toRemove->colour << ") doesn't exist in " << name << "'s hand" << std::endl;
    }
}

int Player::handSize(){
    int counter = 0;
    Node* curr = head;
    while(curr->next != nullptr){
        counter++;
        curr = curr->next;
    }
    return counter;
}

