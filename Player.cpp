#include "Player.h"
#include "Node.h"

#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

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
    this->score += score;
}

void Player::display(){
    Node* currNode = head;
    while(currNode->next != nullptr){
        Tile currTile = currNode->tile;
        cout <<"("<< currTile->shape <<", "<< currTile->colour << ")";
        currNode = currNode->next;
    }
}

void Player::add(Tile toAdd){
    Node* currNode = head;
    while(currNode->next != nullptr){
        currNode = currNode->next;
    }
    Node* newNode = new Node(nullptr, toAdd);
    currNode->next = newNode;
}

void Player::replace(Tile takeOut, Tile putIn){
    Node* currNode = head;
    while(currNode->next != nullptr){
        Tile currTile = currNode->tile;
        if(currTile->shape == takeOut->shape && currTile->colour == takeOut->colour){
            currTile->shape = putIn->shape;
            currTile->colour = putIn->colour;
        }
        currNode = currNode->next;
    }
}

void Player::remove(Tile toRemove){
    Node* currNode = head;
    Node* prevNode = nullptr;
    while(currNode->next != nullptr){
        Tile currTile = currNode->tile;
        if(currTile->shape == toRemove->shape && currTile->colour == toRemove->colour){
            prevNode->next = currNode->next;
            delete currNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

