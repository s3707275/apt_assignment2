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

void Menu::printStudentInfo(std::string name[], std::string id[], std::string email[]) {
  for (int i = 0; i < 3; ++i) {
    std::cout << "Name: " << name[i] << std::endl;
    std::cout << "Student ID: " << id[i] << std::endl;
    std::cout << "Email: " << email[i] << std::endl;
    std::cout << std::endl;
  }
}
