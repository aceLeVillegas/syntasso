#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>
#include <string>
#include <algorithm>


class Syntasso{

public:

  Syntasso();
  bool checkSyntax(std::string word, int parameters); // Sarah has Sudo Code

  int stringtoAscii(std::string& word); //completed
  // Summary: Function will take a string that will be converted to its ascii value.

  std::string asciiToBin(int& number); // completed
  // Summary: Function will take an integer and return a string equvalent to its binary value.

  void readBin(std::ifstream& fin);
  // Summary: Function will read a text file with binary values to be passed into the assembly simulator.

  void readMnemonic(std::ifstream& inFile); // TODO: waiting for checkSyntax Function
  // Summary: Function will read a text file with mnemonic code to be converted into binary
  // code and write out into a new text file.

private:
  int accumulator; // accumulator register
  int counter;
  int numberOfInstructions;
  int opCode; // current operation being performed
  int operand; // memory location of opCode being acted on
  int instructionRegister; // next instruction to be split and run
  int memory[1000];
  int parameters;


};
#endif
