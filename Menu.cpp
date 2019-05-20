#include "Menu.h"

void Menu::printMenu() {
  /* Printing Main Menu */
  std::cout
  << "1. New Game" << '\n'
  << "2. Load Game" << '\n'
  << "3. Show Student Infomation" << '\n'
  << "4. Quit" << '\n'
  << '\n';
}

std::string Menu::getPlayerName(int player) {
  std::string name = "";
  printf("Enter a name for player %d (uppercase characters only)\n", player);
  std::cout << "> ";
  std::getline(std::cin, name);

  while (name == "") {
    std::cout << "Invalid Input" << '\n';
    std::cout << "> ";
    std::getline(std::cin, name);
  }

  /* Validate Name using ASCII Values */
  for (int i = 0; i < name.length(); ++i) {
    if (name[i] == 32) {
      // Allows for space in Names
    }
    while (name[i] < 65 || name[i] > 90) { //32 is ASCII for space
      std::cout << "Invalid Input" << '\n';
      std::cout << "> ";
      std::getline(std::cin, name);
    }
  }
  return name;
}

void Menu::printStudentInfo(std::string name[], std::string id[], std::string email[]) {
  std::cout << "------------------------------\n" << std::endl;
  for (int i = 0; i < PROJECT_GROUPSIZE; ++i) {
    std::cout << "Name: " << name[i] << std::endl;
    std::cout << "Student ID: " << id[i] << std::endl;
    std::cout << "Email: " << email[i] << std::endl;
    std::cout << std::endl;
  }
  std::cout << "------------------------------\n" << std::endl;
}
