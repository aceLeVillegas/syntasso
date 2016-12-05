#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>
#include <string>
#include <algorithm>


class Syntasso{

    public:

        static const std::size_t CAPACITY = 30;
        Syntasso();
        bool checkSyntax(std::string word, int &whiteSpace);
        bool searchPar(std::string key);
        bool searchBin(std::string key);

        int stringtoAscii(std::string& word); //completed
        // Summary: Function will take a string that will be converted to its ascii value.

        std::string asciiToBin(int& decimal); // completed
        // Summary: Function will take an integer and return a string equvalent to its binary value.

        std::string stringToBin(std::string word); // completed
        // Summary: Functions takes a command or register name and returns its predetermined value in binary code
        // found in the binCode table.

        void readBin(std::ifstream& fin);
        // Summary: Function will read a text file with binary values to be passed into the assembly simulator.

        void readMnemonic(std::ifstream& inFile);
        // Summary: Function will read a text file with mnemonic code to be converted into binary
        // code and write out into a new text file.

        void fillCommandOrder(string command);
        // Summary: Function will take in the binary representation of the command and store the commands in commandOrder[]

        void performCommand(int decimal, string line);
        // Summary: Takes in the binary representation of the command and the lne read in from the binary file then performs the specific operation.

        void clearRegisters();
        // Summary 



    private:
      int accumulator; // accumulator register
      int counter;
      int numberOfInstructions;
      int opCode; // current operation being performed
      int operand; // memory location of opCode being acted on
      int instructionRegister; // next instruction to be split and run
      int memory[1000];
      int parameters; // Holds how many parameter(s) command can have
      std::pair<std::string, std::string> binCode[CAPACITY]; // Holds what the binary representation is
      std::pair<std::string, int> numPar[CAPACITY];// holds the number of parameter are allowed
      int commandOrder[CAPACITY];
      size_t usedC; // Counter for commandOrder[]



};
#endif
