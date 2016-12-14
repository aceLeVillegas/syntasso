#ifndef SYNTASSO_H
#define SYNTASSO_H

#include <cstdlib>
#include <string>
#include <algorithm>


class Syntasso{

    public:

        static const std::size_t CAPACITY = 30;
        Syntasso();
        // Summary: Sets up binCode[], numPar[], commandOrder[], and registers.
        bool checkSyntax(std::string word, int &whiteSpace);
        // Summary: Takes in the word read in by a file and shecks if it is a Command , register, number and word.
        bool searchPar(std::string key);
        // Summary: Goes through numPar[] and checks if the key is present and sets parameters to the value at the key
        bool searchCom(std::string key);
        // Summary: Goes through binCode[] and checks if the key is present

        bool searchReg(std::string key);
        // Summary: Goes through binCode[] and checks if the key is present

        int stringtoAscii(std::string& word); //completed
        // Summary: Function will take a string that will be converted to its ascii value.

        int binaryConversion(std::string binary);
        // Summary: Function will take a binary string that will be converted to its decimal value.

        std::string asciiToBin(int& decimal); // completed
        // Summary: Function will take an integer and return a string equvalent to its binary value.

        std::string stringToBin(std::string word); // completed
        // Summary: Functions takes a command or register name and returns its predetermined value in binary code
        // found in the binCode table.

        void readBin(std::ifstream& fin); //completed
        // Summary: Function will read a text file with binary values to be passed into the assembly simulator.

        void readMnemonic(std::ifstream& inFile); // completed TODO: @Kyklos command does not pass checkSyntax
        // Summary: Function will read a text file with mnemonic code to be converted into binary
        // code and write out into a new text file.

        void fillCommandOrder(std::string command);
        // Summary: Function will take in the binary representation of the command and store the commands in commandOrder[]

        void performCommand(int decimal, std::string line); // completed
        // Summary: Takes in the binary representation of the command and the lne read in from the binary file then performs the specific operation.

        void clearRegisters();
        // Summary: Sets all registers to null or 0

        int findReg(std::string& line); // completed
        // Takes a line with binary code representing a register and converts it to an int that indicates the value of index in memory array.

        void displayMemory(); //completed
        // Function will display a visual representation of the Syntasso memory.

        void skip(int value, char state);

        bool find(int headPtr, int tailPtr, int target);
        // Function will iterate beginning at the head of array and compare values at every index until
        // it reaches the end of the the array at tailPtr.  Will return true if value is found or false if not found.




    private:
      int counter;
      int instructionRegister; // next instruction to be split and run
      int memory[1000];
      int parameters; // Holds how many parameter(s) command can have
      std::pair<std::string, std::string> binCode[CAPACITY]; // Holds what the binary representation is
      std::pair<std::string, int> numPar[CAPACITY];// holds the number of parameter are allowed
      std::pair< int, int>  commandOrder[CAPACITY];
      size_t usedC; // Counter for commandOrder[]
      size_t commandCounter;
      bool canSkip;



};
#endif
