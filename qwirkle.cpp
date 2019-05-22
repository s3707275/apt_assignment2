
#include "LinkedList.h"
#include "Player.h"
// #include "Tile.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>

#define EXIT_SUCCESS          0
#define COL_INDEX             "    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25\n"
#define HASH_ROW              "   -------------------------------------------------------------------------------\n"
#define BOARD_SIZE            26
#define TOTAL_TILES           6
#define TWO_OF_EACH_IN_BAG    2

/* game variables */
std::vector<Player*> players;
Tile* board[BOARD_SIZE][BOARD_SIZE] = {{nullptr}};
LinkedList* bag;
Player* currentPlayer;

void printMainMenu(char* input);
void runMenu(char* input);
void newPlayers();
void printBoard();
void newGame();
void firstMove();

// saving function = Will
void saveGame();
// loading game functions - Will
bool boardCreation(std::vector<std::string> gameData, int playing, int counter);
bool playerCreation(std::vector<std::string> playerData, int playing);

int main(void) {

  std::cout << "Welcome to Quirkle!" << std::endl;
  std::cout << "-------------------" << std::endl;
  char* input = new char(' ');
  printMainMenu(input);

  return EXIT_SUCCESS;
}

void printMainMenu(char* input){
  std::cout << "Menu\n----\n";
  do{
    std::cout << "1. New Game\n" << "2. Load Game\n"
    << "3. Display Student Information\n" << "4. Quit\n" << "> ";
    std::cin >> input;
  } while (*input != '1' && *input != '2' && *input != '3' && *input != '4');
  runMenu(input);
}

void runMenu(char* input){
  if(*input == '1'){
    std::cout << "Starting a New Game\n" << std::endl;
    newPlayers();
    std::cout << "Let's Play!\n\n";
    newGame();
    firstMove();
  }
  else if(*input == '2'){

// User enters relative path
std::string input;
std::cout << "Enter file path" << std::endl;

std::cin >> input; // "saveFile.txt"

// Information from saveFile.txt is stored into data vector
std::ifstream file(input);
int counter = 0;
std::vector<std::string> gameData;
std::string line;

if(file.is_open()){
  while(getline(file, line)){
    gameData.push_back(line);
    counter++;
  }

  // Player information is separated into its own vector
  std::vector<std::string> playerData;
  int playing = counter - 30; // The board + last 2 lines (bag and current player)
  for(int x = 0; x < playing; x++){
    playerData.push_back(gameData.at(x));
  }

  // Each vector is used to re-create the game
  // If successful both functions will return true
  bool playerSuccess = playerCreation(playerData, playing);
  bool boardSuccess = boardCreation(gameData, playing, counter);

  // current player is always last line in file
  std::string currentplayer = gameData.at(gameData.size() - 1);
  std::cout << "Current Player: " << currentplayer << std::endl;

  // If game has successfully been re-created
  if(playerSuccess == true && boardSuccess == true){
    std::cout << "Qwirkle game successfully loaded" << std::endl;
  }
  else{
    std::cerr << "Game load failed" << std::endl;
  }
}
else{
  std::cerr << "Unable to open file" << std::endl;
}
file.close();

// Use to test accuracy of load in
// std::cout << "CURRENT BOARD" << std::endl;
// printBoard();

}
  else if(*input == '3'){
    std::cout << "\n\n------------------------------\n" << std::endl;
    std::cout << "Name: Jonathan Diver" << std::endl;
    std::cout << "Student ID: s3707275"  << std::endl;
    std::cout << "Email: s3707275@student.rmit.edu.au\n\n" << std::endl;

    std::cout << "Name: William Guida" << std::endl;
    std::cout << "Student ID: s3707064"  << std::endl;
    std::cout << "Email: s3707064@student.rmit.edu.au\n\n" << std::endl;

    std::cout << "Name: Daniel Ong" << std::endl;
    std::cout << "Student ID: s3676400"  << std::endl;
    std::cout << "Email: s3676400@student.rmit.edu.au" << std::endl;
    std::cout << "------------------------------\n\n" << std::endl;
    printMainMenu(input);
  }
  else {
    std::cout << "Goodbye!" << std::endl;
    //saveGame();
    exit(0);
  }
}

void newPlayers(){
  int numPlayers = 0;
  /* magic numbers remove these */
  while(numPlayers != 2 && numPlayers != 3 && numPlayers != 4){
    std::cout << "Enter number of players in game (2-4)\n> ";
    std::cin >> numPlayers;
  }
  std::string name = "";
  std::regex nameRegex("[A-Z]+");
  for(int i = 1; i <= numPlayers; i++){
    while(!std::regex_match(name, nameRegex)){
      std::cout << "Enter name for player " << i << " (uppercase characters only)\n> ";
      std::cin >> name;
    }
    players.push_back(new Player(name));
    /* resets name for next regex check */
    name = "";
  }
}

void printBoard(){
  char rowLetter = 'A';
  std::cout << "\n" << COL_INDEX << HASH_ROW;
  for(int i = 0; i < BOARD_SIZE; i++){
    std::cout << rowLetter << "  |";
    rowLetter++;
    for(int j = 0; j < BOARD_SIZE; j++){
      if(board[i][j] == nullptr){
        std::cout << "  |";
      }
      else{
        std::cout << board[i][j]->colour << board[i][j]->shape << "|";
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void newGame(){
  // create bag of 72 tiles, 2 of each tile
  bag = new LinkedList();
  for(int i = 1; i <= TOTAL_TILES;  i++){
    for(int j = 0; j < TWO_OF_EACH_IN_BAG;  j++){
      bag->addFront(new Tile('R', i));
      bag->addFront(new Tile('O', i));
      bag->addFront(new Tile('Y', i));
      bag->addFront(new Tile('G', i));
      bag->addFront(new Tile('B', i));
      bag->addFront(new Tile('P', i));
    }
  }
  // bag->display();
  // std::cout << "number of tiles in bag : " << bag->size() << std::endl;
  // std::cout << "player vector contains:";

  /* gives each player a new random hand */
  for (std::vector<Player*>::iterator it = players.begin(); it != players.end(); ++it){
    // std::cout << ' ' << (*it)->name << "'s hand: ";
    (*it)->giveNewHand(*bag);
    // (*it)->displayHand();
  }
  // std::cout << "number of tiles in bag : " << bag->size() << std::endl;
}

void firstMove(){
  currentPlayer = players.front();
  std::cout << currentPlayer->name << ", it's your turn\n";
  for (std::vector<Player*>::iterator it = players.begin(); it != players.end(); ++it){
    std::cout << "Score for " << (*it)->name << ": " << (*it)->score << std::endl;
  }
  printBoard();
  std::cout << "Your hand is\n";
  currentPlayer->displayHand();
  std::string playerPlace = "";
  // std::regex place("(place )[ROYGBP][1-6]( at )[A-Z](2[0-5]|1[0-9]|0?[0-9])");
  std::regex firstPlace("(place )[ROYGBP][1-6]");
  int posOfTile;
  do {
    std::cout << "Choose tile to place at N13\n> ";
    std::getline(std::cin, playerPlace);
    // check if tile is in players hand
    if(std::regex_match(playerPlace, firstPlace)){
      // get tile index in hand
      char tileColour = playerPlace.at(6);
      char charTileShape = playerPlace.at(7);
      // 48 is ASCII where numbers begin, minusing it yields result
      int tileShape = charTileShape - 48;
      std::cout << tileColour << tileShape << std::endl;
      if(currentPlayer->hand->search(tileColour, tileShape)){
        std::cout << "if" << std::endl;
        posOfTile = currentPlayer->hand->positionSearch(tileColour, tileShape);
      }
      else {
        std::cout << "else" << std::endl;
        std::cout << "Please enter a tile from your hand" << std::endl;
        playerPlace = "";
      }
    }
  } while(!std::regex_match(playerPlace, firstPlace));
  //place tile at N13 (center of board)
  board[13][13] = currentPlayer->hand->get(posOfTile)->tile;
  int tileInBag = bag->removeFromBag();
  currentPlayer->hand->remove(posOfTile);
  currentPlayer->hand->addBack(bag->get(tileInBag)->tile);
  bag->remove(tileInBag);
  currentPlayer->displayHand();
  printBoard();
  // printBoard();
}

bool playerCreation(std::vector<std::string> playerData, int playing){
  bool success = true;
  std::string name;
  int score;
  std::string playerHand;

  // Regex checks
  std::regex nameRegex("[A-Z]+");
  std::regex scoreRegex("[0-9]+");
  Player* player;
  // For each player: find name, score, hand and re-create
    for(int x = 0; x < playing; x++){
      player = nullptr;

        // find Name
        if(std::regex_match(playerData.at(x), nameRegex) && success == true){
          name = playerData.at(x);
          std::cout <<"Player Name: "<< name << std::endl;

          // find Score
          if(std::regex_match(playerData.at(x + 1), scoreRegex)){
            score = std::stoi(playerData.at(x + 1));
            std::cout <<"Player Score: "<< score << std::endl;
            player = new Player(name);
            player->score = score;
            players.push_back(player);

            // Breaks up and adds each tile individually
            playerHand = playerData.at(x + 2);
            std::cout << "Player Hand: ";
            for(int y = 0; y < playerHand.length(); y++){
              if(playerHand.substr(y,1) != ","){
                std::string letter = playerHand.substr(y,1);
                char colour = letter.at(0);
                int shape = std::stoi(playerHand.substr((y + 1),1));
                std::cout << colour << "" << shape << ", ";
                Tile* tile = new Tile(colour,shape);
                player->addTile(tile);
                y += 2; // go to next tile
              }
            }
          }
        }
        else{
          // regex found error, stop making players and eventually return false
          success = false;
        }
        std::cout << std::endl;
        x += 2; // Move to next player
      }
  return success;
}

bool boardCreation(std::vector<std::string> gameData, int playing, int counter){
  bool success = true;
  std::string tileBag;
  std::string colour;
  std::string shape;

  std::string row;
  std::smatch matches;
  std::regex rowRegex("[A-Z]+");
  std::regex tileRegex("[A-Z][0-9]+");

  // uncomment to print the map from the file
  // for(int x = playing; x < counter; x++){
  //   std::cout << gameData.at(x) <<" index "<<x<< std::endl;
  // }

  // x begins at 1st line of board and continues until last value in gameData
  for(int x = playing; x < counter; x++){
    row = gameData.at(x);
    int colIndex = -1;
    if((x + 2) != counter){
      if(std::regex_search(row,matches,rowRegex)){ // Finds a row A,B,C,etc on the board
        if(std::regex_search(row,matches,tileRegex)){ // Finds any tiles in that row
          for(int z = 1; z < row.length(); z++){ // Start at 1 to skip row headings
            std::string letter = row.substr(z,1);
            char colour = letter.at(0);
            if(colour == '|'){
              colIndex++;
            }
            if(std::regex_match(letter, rowRegex)){ // Finds beginning of tile i.e. A
              int shape = std::stoi(row.substr((z + 1),1));
              int rowIndex = x - playing - 2;
              std::cout << "Tiles on board: ("<<rowIndex<<","<<colIndex<<") ";
              std::cout << colour << shape << std::endl;
              // using rowIndex and colIndex we can place each tile back into the 2D array
              Tile* tile = new Tile(colour, shape);
              board[rowIndex][colIndex] = tile;
            }
          }
        }
      }
    }
    else{
      tileBag = gameData.at(x);
      x += 2;
    }
  }

  // Breaks up and adds each tile individually
  bag = new LinkedList();
  for(int y = 0; y < tileBag.length(); y++){
    if(tileBag.substr(y,1) != ","){
      std::string letter = tileBag.substr(y,1);
      char colour = letter.at(0);
      int shape = std::stoi(tileBag.substr((y + 1),1));
      //std::cout << colour << "" << shape << ", ";
      Tile* tile = new Tile(colour,shape);
      bag->addFront(tile);
      y += 2; // move across string to next tile
    }
  }
  std::cout << std::endl;
  std::cout <<"Tile Bag: ";
  for(int x = 1; x <= bag->size(); x++){
    std::cout << bag->get(x)->tile->colour;
    std::cout << bag->get(x)->tile->shape << ", ";
  }
  std::cout << std::endl;
  return success;
}

void saveGame(){

// writing
std::ofstream file;
file.open("saveFile.txt");

if(file.is_open()){
  // Writes each player's name, score and hand to  saveFile.txt file
  for(Player* player : players){
    file << player->name;
    file << "\n";
    file << player->score;
    file << "\n";
    for(int x = 1; x <= TOTAL_TILES; x++){
      file << player->get(x)->tile->colour;
      file << player->get(x)->tile->shape;
      file << " ";
    }
    file << "\n";
  }

  // Writes board to saveFile.txt file
  char rowLetter = 'A';
  file << COL_INDEX;
  file << HASH_ROW;
  for(int i = 0; i < BOARD_SIZE; i++){
    file << rowLetter << "  |";
    rowLetter++;
    for(int j = 0; j < BOARD_SIZE; j++){
      if(board[i][j] == nullptr){
        file << "  |";
      }
      else{
        file << board[i][j]->colour;
        file << board[i][j]->shape;
        file << "|";
      }
    }
    file << "\n";
  }

  // Writes bag and current player to saveFile.txt file
  for(int x = 1; x <= bag->size(); x++){
    file << bag->get(x)->tile->colour;
    file << bag->get(x)->tile->shape;
    file << " ";
  }
  file << "\n";

  file << currentPlayer->name;
  file << "\n";

  std::cout << "Game successfully saved" << std::endl;
}
else{
  std::cerr << "Unable to open file" << std::endl;
}

file.close();
// back to gameplay
}

void gameplay(){
     // while !gameOver
     //   1. The name of the current player
     //   2. The scores of both players
     //   3. The state of the board
     //   4. The tiles in the current player’s hand
     //   5. The user prompt
     //   6. Execute user prompt
     //   7. gameplay()

}
