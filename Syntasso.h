#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>


class Syntasso{

    public:
      

    private:
      int accumulator; // accumulator register
      int counter;
      int numberOfInstructions;
      int opCode; // current operation being performed
      int operand; // memory location of opCode being acted on
      int instructionRegister; // next instruction to be split and run
      int memory[1000];
      char code[8];
      char com[8];
      bool hex;

};
#endif
