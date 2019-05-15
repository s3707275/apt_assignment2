
#include "LinkedList.h"
#include "Player.h"

#include <iostream>

#define EXIT_SUCCESS    0

void printMainMenu(char* input);
void runMenu(char* input);

int main(void) {

  std::cout << "Welcome to Quirkle!" << std::endl;
  std::cout << "-------------------" << std::endl;
  char* input = new char(' ');
  printMainMenu(input);

  return EXIT_SUCCESS;
}

void printMainMenu(char* input){
  std::cout << "-------------------" << std::endl;
  std::cout << "=    Main Menu    =" << std::endl;
  std::cout << "-------------------" << std::endl;
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
    std::cout << "------------------------------\n" << std::endl;
    std::cout << "Name: Jonathan Diver" << std::endl;
    std::cout << "Student ID: s3707275"  << std::endl;
    std::cout << "Email: s3707275@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------\n" << std::endl;
    std::cout << "Name: William Guida" << std::endl;
    std::cout << "Student ID: s3707064"  << std::endl;
    std::cout << "Email: s3707064@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------\n" << std::endl;
    std::cout << "Name: Daniel Ong" << std::endl;
    std::cout << "Student ID: s3676400"  << std::endl;
    std::cout << "Email: s3676400@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------\n" << std::endl;
    printMainMenu(input);
  }
  else {
    std::cout << "Goodbye!" << std::endl;
    exit(0);
  }
}
