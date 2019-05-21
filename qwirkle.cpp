#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS     0
#define NUM_PLAYER       2

<<<<<<< HEAD
void getInput(char& input);
=======
#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <algorithm>

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
>>>>>>> dan

int main(void) {

  //LinkedList* list = new LinkedList();
  //delete list;

  bool quit = false;
  bool newGame = true;
  char input = '\0';
  Menu* menu = new Menu();
  std::string player[NUM_PLAYER];


  /* Student Infomation (save elsewhere?) */
  std::string name[] = {
    "JONO DIVER",
    "WILL GUIDA",
    "DANIEL ONG"
  };
  std::string id[] = {
    "sXXXXXXX",
    "sXXXXXXX",
    "s3676400"
  };
  std::string email[] = {
    "sXXXXXXX@student.rmit.edu.au",
    "sXXXXXXX@student.rmit.edu.au",
    "s3676400@student.rmit.edu.au"
  };

  /* Welcome Message */
  std::cout << "Welcome to Quirkle!" << std::endl;
  std::cout << "-------------------" << std::endl;

  /* Qwirkle Program Runs Here */
  menu->printMenu();
  do {
    // menu->printMenu();
    getInput(input);
    std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );

    if (input == '1') {

<<<<<<< HEAD
      if (!newGame) {
        std::cout << "Continuing Game..\n" << std::endl;
      }
      else {
        std::cout << "Starting a New Game\n" << std::endl;
        newGame = false;
      }
      /* Reading in Player names if its a New Game */
      for (int i = 0; i < NUM_PLAYER; ++i) {
        if (player[i] != "") {
          std::cout << "Current Player "
          << (i+1)
          << ": "
          << player[i]
          << std::endl;
        }
        else{
          player[i] = menu->getPlayerName(i+1);
        }
      }
      std::cout << "\nLets Play!\n" << std::endl;


      //RUN GAME
      // 1. Create the ordering for the tile bag
      // 2. Set up the initial player hands
      // 3. Start with an empty board, with player 1 as the starting player

      /* To exit or return to Main Menu */
      std::string exit = "";
      std::cout << "Input 'q' to exit or press 'Enter' to return to Main Menu" << std::endl;
      std::cout << "> ";
      std::getline(std::cin, exit);

      if (exit == "q") {
        quit = true;
      }
      else {
        quit = false;
        menu->printMenu();
      }
    }
    else if (input == '2') {
      std::cout << "Enter the filename from which load a game" << std::endl;
      // User enters relative path

      // 1. Check that the file exists.
      // 2. Check that the format of the file is correct

      // If validation checks out
      std::cout << "Qwirkle game successfully loaded" << std::endl;
      //gameplay continue from here
      quit = true; // to call exit when needed
    }
    else if (input == '3') {
      menu->printStudentInfo(name, id, email);
    }
    else if (input == '4') {
      quit = true;
    }
    else {
      std::cout << "Invalid Input" << std::endl;
=======
void runMenu(char* input){
  if(*input == '1'){
    std::cout << "Starting a New Game\n" << std::endl;
    newPlayers();
    std::cout << "Let's Play!\n\n";
    newGame();
    firstMove();
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
>>>>>>> dan
    }
  }
  while (!quit);
  std::cout << "Goodbye!" << '\n';
  return EXIT_SUCCESS; // EXIT POINT
}

<<<<<<< HEAD
void getInput(char& input) {
  std::cout << "> ";
  std::cin >> input;
  // std::cout << '\n';
}

//Might Wanna add a Save Method
=======
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
  std::string tileToPlace = " ";
  std::regex tileRegex("place [ROYGBP]{1}[1-6]{1}");
  while(!std::regex_match(tileToPlace, tileRegex)){
    std::cout << "Choose tile to place at N13\n> ";
    std::cin >> tileToPlace;
  }
  // printBoard();
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
>>>>>>> dan
