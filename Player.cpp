#include "Player.h"
#include "Tile.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#define HAND_SIZE   6

private string name;
private vector<Tile> hand;
private int score;

public Player::Player(string name){
    this->name = name;
    this->score = 0;
}

public string Player::getName(){
    return name;
}

public int Player::getScore(){
    return score;
}

public void Player::setScore(int score){
    this->score += score;
}

public void Player::display(){
   if(!hand.empty()){
        for(int x = 0; x < HAND_SIZE; x++){
           cout << hand[x].getShape() << hand[x].getColour() << ", ";
        }
   }
   else{
       cout << "Error: " << name << "'s hand is empty" << endl;
   }
}

public void Player::populate(){
    // may need to pass in reference or pointer to bag as a param
    if(!hand.empty()){
    for(int x = 0; x < HAND_SIZE; x++){
        // RNG randomly picks a Tile from the bag
        // Tile random = param->grabTile();
        hand.push_back(random);
    }
    }
    else{
        cout << "Error: " << name << "'s hand has already been dealt" << endl;
        cout << "No changes made" << endl;
    }
}

public void Player::add(Tile putIn){
    // may need to apss in rference or pointer to bag as a param
    if(!hand.empty()){
        // RNG randomly picks a Tile from the bag
        // Tile random = pararm->grabTile();
        hand.push_back(random);
    }
    else{
        cout << "Error: " << name << "'s hand is empty" << endl;
        cout << "No changes made" << endl;
    }
}

public void Player::replace(Tile takeOut, Tile putIn){
    if(!hand.empty()){
        boolean exists = false;
        for(int x = 0; x < HAND_SIZE; x++){
           if(hand[x] == takeOut){
               hand[x] = putIn;
               exists = true;
           }
        }
        if(!exists){
             printf("Error: (%c,%d) doesn't exist in %s's hand\n", takeOut.getShape(), takeOut.getColour(), name.c_str());
             cout << "No changes made" << endl;
        }
    }
    else{
        cout << "Error: " << name << "'s hand is empty" << endl;
        cout << "No changes made" << endl;

    }
}


public void Player::remove(Tile toRemove){
    if(!hand.empty()){
        boolean exists = false;
        for(int x = 0; x < HAND_SIZE; x++){
            if(hand[x] == toRemove){
                // removes desired tile and resizes vector (hand)
                hand.erase(hand.begin()+x);
                exists = true;
            }
        }
        if(!exists){
            printf("Error: (%c,%d) doesn't exist in %s's hand\n", toRemove.getShape(), toRemove.getColour(), name.c_str());
        }
    }
    else{
        cout << "Error: " << name << "'s hand is empty" << endl;
    }
}