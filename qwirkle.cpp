
#include "LinkedList.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>

#define EXIT_SUCCESS    0
#define COL_INDEX       "    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25\n"
#define HASH_ROW        "   -------------------------------------------------------------------------------\n"
#define BOARD_SIZE      26

/* game variables */
std::vector<Player*> players = {nullptr};
Tile* board[BOARD_SIZE][BOARD_SIZE] = {{nullptr}};

void printMainMenu(char* input);
void runMenu(char* input);
void newPlayers();
void newGame();
void printBoard();

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
    // newGame();
    // while !gameOver
    // 1. The name of the current player
    // 2. The scores of both players
    // 3. The state of the board
    // 4. The tiles in the current player’s hand
    // 5. The user prompt
    // printBoard();
    std::cout << "Let's Play!" << std::endl;
  }
  else if(*input == '2'){
    std::cout << "Enter the filename from which load a game" << std::endl;
    // User enters relative path
    std::cin >> input;
    ifstream myFile (input);
    int count = = 0;
    std::string line;
    std::vector<std::string> playerdetails;
    if (myFile.is_open()) {
      while (getline (myFile.line) {
        playerdetails.push_back(line);
        count++;
      }
    }
    else {
      std::cout << "File does not exist"
    }
    // std::string name = "";
    std::regex nameRegex("[A-Z]+");
    std::regex intRegex("^\d+$")
    std::regex handRegex("[A-Z](\d)(1,1)")
    if (std::regex_match(playerdetails(0), nameRegex) {}
    if (std::regex_match(playerdetails(1), intRegex) {}
    for (int i = 0; i < playerdetails(2).length(); ++i) {
    }
    for (int i = 0; i < n; ++i) {
      if
    }
    if (std::regex_match(playerdetails(3), nameRegex) {}
    if (std::regex_match(playerdetails(4), intRegex) {}
    // Check hand
    // Check BOARD
    // Check Bag
    // Current Player Name

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
  std::cout << COL_INDEX << HASH_ROW;
  for(int i = 0; i < BOARD_SIZE; i++){
    std::cout << rowLetter << "  |";
    rowLetter++;
    for(int j = 0; j < BOARD_SIZE; j++){
      if(board[i][j] == nullptr){
        std::cout << "  |";
      }
      else{
        std::cout << board[i][j] << "|";
      }
    }
    std::cout << std::endl;
  }
}

void newGame(){
  // create bag
  // give each player 6 tiles
  //
}
