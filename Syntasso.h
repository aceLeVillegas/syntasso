#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>
#include <string>
#include <algorithm>

class Syntasso{

    public:
        Syntasso();
        bool checkSyntax(std::string word, int parameters); // Sarah has Sudo Code
        bool searchPar(std::string key);
        bool searchBin(std::string key);




    private:
      int accumulator; // accumulator register
      int counter;
      int numberOfInstructions;
      int opCode; // current operation being performed
      int operand; // memory location of opCode being acted on
      int instructionRegister; // next instruction to be split and run
      int memory[1000];
      int parameters;
      pair<std::string, std::string> binCode[31];
      pair<std::string, int> numPar[31];



};
#endif
