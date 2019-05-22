
#include "LinkedList.h"
#include "Player.h"

#include <iostream>
#include <regex>
#include <vector>
#include <string>

#define EXIT_SUCCESS          0
#define COL_INDEX             "    00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25\n"
#define HASH_ROW              "   -------------------------------------------------------------------------------\n"
#define BOARD_SIZE            26
#define TOTAL_TILES           6
#define TWO_OF_EACH_IN_BAG    2
#define COLOUR_REGEX_INDEX    6
#define SHAPE_REGEX_INDEX     7
#define ROW_CHAR_REGEX_INDEX  12
#define COL_INT_REGEX_INDEX   13
#define ASCII_TO_INT          48
#define ASCII_A               'A'
#define INDEX_ZERO            0

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
void gameplay();
bool validMove(char tileColour, int tileShape, int row, int col);

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
    gameplay();
  }
  else if(*input == '2'){
    std::cout << "Enter the filename from which load a game" << std::endl;
      // User enters relative path

      // 1. Check that the file exists.
      // 2. Check that the format of the file is correct

      // If validation checks out
      std::cout << "Qwirkle game successfully loaded" << std::endl;
      //gameplay continue from here
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
    for (std::vector<Player*>::iterator it = players.begin(); it != players.end(); ++it){
      delete (*it);
    }
    for(int i = 0; i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
        delete board[i][j];
      }
    }
    delete bag;
    std::cout << "Goodbye!" << std::endl;
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

  std::string playerPlace;
  std::regex firstPlace("(place )[ROYGBP][1-6]");
  int posOfTile;
  do {
    std::cout << "Choose tile to place at N13\n> ";
    std::getline(std::cin, playerPlace);
    // check input matches regexß
    if(std::regex_match(playerPlace, firstPlace)){
      // get tile index in hand
      char tileColour = playerPlace.at(COLOUR_REGEX_INDEX);
      char charTileShape = playerPlace.at(SHAPE_REGEX_INDEX);
      // 48 is ASCII where numbers begin, minusing it yields result
      int tileShape = charTileShape - ASCII_TO_INT;
      if(currentPlayer->hand->search(tileColour, tileShape)){
        posOfTile = currentPlayer->hand->getPosition(tileColour, tileShape);
      }
      else {
        std::cout << "INVALID INPUT - Please enter a tile from your hand" << std::endl;
        playerPlace = "";
      }
    }
  } while(!std::regex_match(playerPlace, firstPlace) && playerPlace.compare("save") != 0);
  //place tile at N13 (center of board), remove tile from hand
  if(playerPlace.compare("save") == 0){
    //saveGame();
    char* input = new char(' ');
    printMainMenu(input);
  }
  board[13][13] = currentPlayer->hand->get(posOfTile)->tile;
  currentPlayer->hand->remove(posOfTile);
  // remove a tile from bag and place in hand
  int tileInBag = bag->removeFromBag();
  currentPlayer->hand->addBack(bag->get(tileInBag)->tile);
  bag->remove(tileInBag);
  // increment score, on first turn can only place 1 tile so score must be 1
  currentPlayer->score++;


  // current player is ready for next players move
  currentPlayer = players.at(1);
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
     std::string playerPlace;
     int rowIndex;
     int colIndex;

     while(playerPlace.compare("save") != 0){
       std::cout << "\n" << currentPlayer->name << ", it's your turn\n";
       for (std::vector<Player*>::iterator it = players.begin(); it != players.end(); ++it){
         std::cout << "Score for " << (*it)->name << ": " << (*it)->score << std::endl;
       }
       printBoard();
       std::cout << "Your hand is\n";
       currentPlayer->displayHand();
       std::regex place("(place )[ROYGBP][1-6]( at )[A-Z](2[0-5]|1[0-9]|0?[0-9])");
       std::regex replace("(replace )[ROYGBP][1-6]");
       int posOfTile;
       do {
         std::cout << "Choose tile to place at [ROW LETTER][COL NUMBER]\n> ";
         std::getline(std::cin, playerPlace);
         // check input matches regex
         if(std::regex_match(playerPlace, place)){
           // get tile index in hand and coordinates position
           char tileColour = playerPlace.at(COLOUR_REGEX_INDEX);
           char charTileShape = playerPlace.at(SHAPE_REGEX_INDEX);
           char rowChar = playerPlace.at(ROW_CHAR_REGEX_INDEX);
           std::string colString = playerPlace.substr(COL_INT_REGEX_INDEX);
           // 48 is ASCII where numbers begin, minusing it yields result
           int tileShape = charTileShape - ASCII_TO_INT;
           // each row will have the index of its ascii value minus the ascii value of 'A'
           rowIndex = rowChar - ASCII_A;
           colIndex = std::stoi(colString);

           // std::cout << "Tile : " << tileColour << tileShape << "\nPOS : row = " << rowIndex << " col = " << colIndex << std::endl;
           // valid tile selection and board bounds check
           if(currentPlayer->hand->search(tileColour, tileShape)){
             posOfTile = currentPlayer->hand->getPosition(tileColour, tileShape);
             if(rowIndex >= INDEX_ZERO && rowIndex < BOARD_SIZE && colIndex >= INDEX_ZERO && colIndex < BOARD_SIZE ){
               // move legality check
               if(validMove(tileColour, tileShape, rowIndex, colIndex)){
                 // happy to place tile there
                 std::cout << "VALID MOVE\n";
               }
               else {
                 std::cout << "INVALID INPUT - Not a valid move" << std::endl;
                 playerPlace = "";
               }
             }
             else{
               std::cout << "INVALID INPUT - Please enter a valid coordinate" << std::endl;
               playerPlace = "";
             }
          }
          else if (std::regex_match(playerPlace, replace)) {
            posOfTile = currentPlayer->hand->getPosition(tileColour, tileShape);
            if(rowIndex >= INDEX_ZERO && rowIndex < BOARD_SIZE && colIndex >= INDEX_ZERO && colIndex < BOARD_SIZE ){
            //  currentPlayer->hand->replaceTileFunctions();
            }

          }
           else {
             std::cout << "INVALID INPUT - Please enter a tile from your hand" << std::endl;
             playerPlace = "";
           }
         }
       } while(!std::regex_match(playerPlace, place) && playerPlace.compare("save") != 0 && !std::regex_match(playerPlace, replace));
       //
       if(playerPlace.compare("save") == 0){
         //saveGame();
         char* input = new char(' ');
         printMainMenu(input);
       }
       std::regex_match(playerPlace, replace){

       }
       board[rowIndex][colIndex] = currentPlayer->hand->get(posOfTile)->tile;
       currentPlayer->hand->remove(posOfTile);
       // remove a tile from bag and place in hand
       int tileInBag = bag->removeFromBag();
       currentPlayer->hand->addBack(bag->get(tileInBag)->tile);
       bag->remove(tileInBag);
       // increment score
       currentPlayer->score++;


       // current player is ready for next players move
       currentPlayer = players.at(1);
     }
}

bool validMove(char tileColour, int tileShape, int row, int col){
  //check surrounding location
  LinkedList* vertical = new LinkedList();
  LinkedList* horizontal = new LinkedList();
  // vetical check
  if(board[row+1][col] != nullptr || board[row-1][col] != nullptr){
    // put new tile as head of linked list
    vertical->addFront(new Tile(tileColour, tileShape));
    int temp = row;
    // check positions below the placed tile
    while(board[temp+1][col] != nullptr){
      vertical->addBack(board[temp+1][col]);
      temp++;
    }
    temp = row;
    // check positions above the placed tile
    while(board[temp-1][col] != nullptr){
      vertical->addFront(board[temp+1][col]);
      temp++;
    }
    vertical->display();
  }
  //horizontal check
  if(board[row][col+1] != nullptr || board[row][col-1] != nullptr){
    // put new tile as head of linked list
    horizontal->addFront(new Tile(tileColour, tileShape));
    int temp = col;
    // check positions below the placed tile
    while(board[temp][temp+1] != nullptr){
      horizontal->addBack(board[temp+1][col]);
      temp++;
    }
    temp = row;
    // check positions above the placed tile
    while(board[temp][temp-1] != nullptr){
      horizontal->addFront(board[row][temp-1]);
      temp++;
    }
    horizontal->display();
  }
  if(horizontal->size() > 1 || vertical->size() > 1){
    return true;
  }
  //      - duplicate valid move
  //      - same type/colour valid move
  return false;
}
