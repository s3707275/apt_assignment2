
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {

  bool quit = false;
  char input ='\0';
  Menu* menu = new Menu();
  LinkedList* list = new LinkedList();
  //delete list;

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
      std::cout << "NEW GAME" << '\n';
      //RUN GAME
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
