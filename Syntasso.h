#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>
#include <string>
#include <algothrim>


class Syntasso{

    public:
        Syntasso();
        bool checkSyntax(string word, int parameters); // Sarah has Sudo Code
        


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
