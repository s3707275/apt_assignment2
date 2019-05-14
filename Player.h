
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

class Player {

  public:
    // Creates a Player object
    Player(String name);

    // Getters and Setters for class variables
    std::string getName();
    int getScore();
    void setScore(int score);

    // Prints player's hand to console
    void display();

    // Add, replaces and removes tiles relative to player's actions during game
    void add(Tile toAdd);
    void replace(Tile takeOut, Tile putIn);
    void remove(Tile toRemove);

    // Returns amount of tiles in current player's hand
    int handSize();

  private:
    std::string name;
    Node* head;
    int score;

};

#endif // ASSIGN2_TILE_H
