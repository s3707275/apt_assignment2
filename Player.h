
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

class Player {

    // Creates a Player object
    Player(String name);

    // Getters and Setters for class variables
    std::string getName();
    int getScore();
    void setScore(int score);

    // Prints player's hand to console
    void display();

    // Randomly populates player's hand relative to the bag of tiles
    void populate();

    // Add, replaces and removes tiles relative to player's actions during game
    void add(Tile putIn);
    void replace(Tile takeOut, Tile putIn);
    void remove(Tile toRemove);

    public:
    std::string name;
    std::vector<Tile> hand;
    int score;

};

#endif // ASSIGN2_TILE_H
