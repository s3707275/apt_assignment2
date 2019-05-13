#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS     0
#define NUM_PLAYER       2

void getInput(char& input);

int main(void) {

  bool quit = false;
  char input ='\0';
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
  do {
    menu->printMenu();
    getInput(input);
    if (input == '1') {
      std::cout << "Starting a New Game\n" << std::endl;
      player[0] = menu->getPlayerName(1);

      player[1] = menu->getPlayerName(2);

      std::cout << player[0] << '\n';
      std::cout << player[1] << '\n';

      std::cout << "Lets Play!" << std::endl;

      //RUN GAME
      // 1. Create the ordering for the tile bag
      // 2. Set up the initial player hands
      // 3. Start with an empty board, with player 1 as the starting player
      quit = true;
    }
    else if (input == '2') {
      std::cout << "LOAD GAME" << '\n';
      //LOAD FROM SAVE./
    }
    else if (input == '3') {
      menu->printStudentInfo(name, id, email);
    }
    else if (input == '4') {
      std::cout << "Goodbye!" << '\n';
      quit = true;
    }
    else {
      std::cout << "INVALID INPUT, TRY AGAIN." << '\n' << std::endl;
    }
  }
  while (!quit);
  return EXIT_SUCCESS; // EXIT POINT
}

void getInput(char& input) {
  std::cout << "> ";
  std::cin >> input;
  std::cout << '\n';
}
