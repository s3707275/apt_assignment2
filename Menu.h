#include <iostream>

#define PROJECT_GROUPSIZE     3
class Menu {
public:
  void printMenu();
  std::string getPlayerName(int player);
  void printStudentInfo(std::string name[], std::string id[], std::string email[]);
};
