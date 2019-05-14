#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS     0
#define NUM_PLAYER       2

void getInput(char& input);

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
    }
  }
  while (!quit);
  std::cout << "Goodbye!" << '\n';
  return EXIT_SUCCESS; // EXIT POINT
}

void getInput(char& input) {
  std::cout << "> ";
  std::cin >> input;
  // std::cout << '\n';
}

//Might Wanna add a Save Method
