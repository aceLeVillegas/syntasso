#include "Syntasso.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cassert>
using namespace std;


// TODO: make the loop inception
// TODO: Display in binary
// TODO: finish switch for find

Syntasso::Syntasso(){
    commandCounter = 15;
    // Binary representation for each command
    binCode[0].first = "&Sum";
    binCode[0].second = "100000";
    binCode[1].first = "+Add";
    binCode[1].second = "011111";
    binCode[2].first = "-Sub";
    binCode[2].second = "011110";
    binCode[3].first = "*Mult";
    binCode[3].second = "011101";
    binCode[4].first = "/Div";
    binCode[4].second = "011100";
    binCode[5].first = "%Mod";
    binCode[5].second = "011011";
    binCode[6].first = "^Pow";
    binCode[6].second = "011010";
    binCode[7].first = "Edo";
    binCode[7].second = "011001";
    binCode[8].first = "#Evrima";
    binCode[8].second = "011000";
    binCode[9].first = "@Kyklo";
    binCode[9].second = "010111";
    binCode[10].first = ">Ako";
    binCode[10].second = "010110";
    binCode[11].first = "<Lego";
    binCode[11].second = "010101";
    binCode[12].first = "?Lykis";
    binCode[12].second = "010100";
    binCode[13].first = "$Alma";
    binCode[13].second = "010011";
    binCode[14].first = "|Exa";
    binCode[14].second = "010010";
    binCode[15].first = "!Stasi";
    binCode[15].second = "000000";
    binCode[16].first = "alpha";
    binCode[16].second = "0001";
    binCode[17].first = "beta";
    binCode[17].second = "0010";
    binCode[18].first = "gamma";
    binCode[18].second = "0011";
    binCode[19].first = "delta";
    binCode[19].second = "0100";
    binCode[20].first = "epsilon";
    binCode[20].second = "0101";
    binCode[21].first = "zeta";
    binCode[21].second = "0110";
    binCode[22].first = "eta";
    binCode[22].second = "0111";
    binCode[23].first = "theta";
    binCode[23].second = "1000";
    binCode[24].first = "iota";
    binCode[24].second = "1001";
    binCode[25].first = "kappa";
    binCode[25].second = "1010";
    binCode[26].first = "lambda";
    binCode[26].second = "1011";
    binCode[27].first = "mu";
    binCode[27].second = "1100";
    binCode[28].first = "sigma";
    binCode[28].second = "1101";
    binCode[29].first = "omicron";
    binCode[29].second = "1110";
    binCode[30].first = "omega";
    binCode[30].second = "1111";


    // How many parameters are allowed for each command
    numPar[0].first = "&Sum";
    numPar[0].second = 1;
    numPar[1].first = "+Add";
    numPar[1].second = 3;
    numPar[2].first = "-Sub";
    numPar[2].second = 3;
    numPar[3].first = "*Mult";
    numPar[3].second = 3;
    numPar[4].first = "/Div";
    numPar[4].second = 3;
    numPar[5].first = "%Mod";
    numPar[5].second = 3;
    numPar[6].first = "^Pow";
    numPar[6].second = 3;
    numPar[7].first = "Edo";
    numPar[7].second = -1;
    numPar[8].first = "#Evrima";
    numPar[8].second = 1;
    numPar[9].first = "@Kyklo";
    numPar[9].second = 2;
    numPar[10].first = ">Ako";
    numPar[10].second = 1;
    numPar[11].first = "<Lego";
    numPar[11].second = 1;
    numPar[12].first = "?Lykis";
    numPar[12].second = 1;
    numPar[13].first = "$Alma";
    numPar[13].second = 1;
    numPar[14].first = "|Exa";
    numPar[14].second = 0;
    numPar[15].first = "!Stasi";
    numPar[15].second = 0;
    // The following registers are going to be assigned an index in memory array
    // starting at index 2 - 14  alpha and beta will be pointers pointing to index 50
    numPar[16].first = "alpha";
    numPar[16].second = 50;
    numPar[17].first = "beta";
    numPar[17].second = 50;
    numPar[18].first = "gamma";
    numPar[18].second = 3;
    numPar[19].first = "delta";
    numPar[19].second = 4;
    numPar[20].first = "epsilon";
    numPar[20].second = 5;
    numPar[21].first = "zeta";
    numPar[21].second = 6;
    numPar[22].first = "eta";
    numPar[22].second = 7;
    numPar[23].first = "theta";
    numPar[23].second = 8;
    numPar[24].first = "iota";
    numPar[24].second = 9;
    numPar[25].first = "kappa";
    numPar[25].second = 10;
    numPar[26].first = "lambda";
    numPar[26].second = 11;
    numPar[27].first = "mu";
    numPar[27].second = 12;
    numPar[28].first = "sigma";
    numPar[28].second = 13;
    numPar[29].first = "omicron";
    numPar[29].second = 14;
    numPar[30].first = "omega";
    numPar[30].second = 15;

    // This is when Edo is stated first it needs to still find how many
    // parameters it need since it hasnt seen the command yet
    parameters = -1;
    usedC = 0;

    for(size_t i = 0; i < CAPACITY; i++){

        commandOrder[i].first = -10;
        commandOrder[i].second = -10;
    }

    // initialize the array elements to 0 to get rid of trash values.
    memory[0] = 50; // set alpha to point to index 50
    memory[1] = 50; // set alpha to point to index 50
    for(int i = 2; i < 1000; i++)
    {
      memory[i] = 0;
    }

}
  std::string Syntasso::stringToBin(std::string word)
  {
    std::string transToBin;
    for(unsigned int i = 0; i < CAPACITY; i++)
    {
      if(word == binCode[i].first)
      {
        transToBin = binCode[i].second;
        //cout << transToBin << endl;
      }
    }

    return transToBin;
  } // end stringToBin

bool Syntasso::checkSyntax(std::string word, int &whiteSpace){

    //cout << "Command Order: " <<  commandOrder[usedC].first << endl;
    // If the line were reading in is a line within the loop
    if(word == "Edo" && whiteSpace == 0){


        return true;
    }
    // Command is the first value for the line being read in
    else if(whiteSpace == 0 && word != "Edo" ){

        return searchPar(word);
    }

    // to search and see if the parameters are registers, numbers, or words IF IT the line starts with a command
    else if(whiteSpace >= 1 && parameters >= whiteSpace){


        if(whiteSpace == 1 && searchCom(word)){

            //cout << "whiteSpace == 1" << word <<endl;
            whiteSpace--;
            parameters++;

            return true;
        }// end else if

        if(searchReg(word)){

            return true;
        }
        // checks to see if the first and onward parameters are either words or numbers
        else if( whiteSpace == 1 && word[0] >= '0' && word[0] <= '9'){

            return true;
        }
        // Condition for ?Lykis
        else if(//commandOrder[usedC].first == 20 &&
        (whiteSpace == 2) &&
        (word == "N" || word == "P" || word == "Z")){

            return true;
        }
        // Condition for @Kyklo
        else if(//commandOrder[usedC].first == 23 &&
        (whiteSpace == 2) &&
         (word[0] >= '0' && word[0] <= '9')){

             return true;
        }
        else{

            return false;
        }// end else

    }// end if




    return false;

  //}
}
bool Syntasso::searchPar(std::string key){

    string holder;
    for(unsigned int i = 0; i < CAPACITY; i++){

        if(key == numPar[i].first){

            parameters = numPar[i].second;
            return true;
        }
    }
    return false;


}
bool Syntasso::searchCom(std::string key){

    string holder;
    for(unsigned int i = 0; i <= 15; i++){

        if(key == binCode[i].first){

            return true;
        }
    }
    return false;

}

bool Syntasso::searchReg(std::string key){

    for(unsigned int i = 16; i < CAPACITY; i++){

        if(key == binCode[i].first){

            return true;
        }
    }
    return false;

}


int Syntasso::stringtoAscii(string& word)
{
  int length = word.length();
  int ascii = 0;
  for(int i = 0; i < length; ++i)
  {
    ascii += (int)word[i];
  }
  return ascii;
} // end stringtoAscii

string Syntasso::asciiToBin(int& decimal)
{
  int remainder = 0;
  int base = 2;
  std::string bin = "";
  std::string reverse = "";
  while(decimal > 0)
  {
    remainder = decimal % base;
    decimal = decimal / base;
    bin += '0' + remainder;

  } // end while
  for(int i = bin.length(); i >= 0; i--)
    reverse += bin[i];

  return reverse;
} // end asciiToBin

void Syntasso::readMnemonic(std::ifstream& inFile)
    {
  int whiteSpace = 0;
  string line;
  ofstream fout;
  int temp;
  string leadZero;
  fout.open("binCode.vilo",ios::out);
  if(inFile.is_open())
  {
    cout << "Successfully opened file!" << endl;
    while(getline(inFile, line, '\n'))
    {
      whiteSpace = 0;
      std::stringstream   linestream(line);
      std::string         value;
      // Ignore if the line is a comment or dummy variables
      if(line.find("(") == 0)
      {
        whiteSpace = 0;
        continue;
      }
      else
      {

        while(getline(linestream,value, ' ' ))

        {
            // /cout << "Current word: " << value << " T/F: " <<checkSyntax(value, whiteSpace) << " "
            //  << "whiteSpace: " << whiteSpace
            //  << "parameters: " << parameters << endl << endl ;
          if(value.length() <= 4 && isdigit(value[0]))
          {
            temp = stoi(value);//if it's a string number convert it to an int
            assert(temp <= 256 && temp >=0);
            value = decimalToBinary(temp); //convert the int into a string binary
            // for(int i = value.length(); i <= 4; ++i)
            // {
            //   //leadZero += '0';
            // }
            //value = leadZero + value;
            fout << value << " ";
          }
          else if(checkSyntax(value, whiteSpace))
          {
            value = stringToBin(value);
            fout << value << " ";
            whiteSpace++;
          }
          else
          {
            cout << "Koino : "  << line << endl;
            cout << "Program terminated abnormally." << endl;
            cout << value << " caused a syntax error." << endl;
            exit(1);
          }


        }
        fout << endl;

      }
    } // end while
    // close the file before exiting
    inFile.close();
  }
  else
  {
    cout << "Unable to open file.\n";
    exit(1);
  }
} // end readMnemonic


void Syntasso::readBin(std::ifstream& inFile)
{
    int binToDecimal;
    string line;
    string binary;
    long int binaryInt;
    int binCode;
    if(inFile.is_open())
    {
        cout << "Successfully opened  binary file!" << endl;
        while(getline(inFile, line))
        {
            // take the first binary code and convert to a decimal number
            binToDecimal = binaryConversion(line.substr(0,6)); //This number will be sent to switch
            binary = line.substr(0,6); //This is the string version of command
            binaryInt = atoi(binary.c_str()); //This is the REAL binary number that will be stored in memory
            memory[commandCounter] = binaryInt;
            commandCounter++;

            if(line.length() > 0)
                performCommand(binToDecimal, line);

        }// end of while

    // close the file before exiting
    inFile.close();
    }// end of if
    else
    {
        cout << "Unable to open file.\n";
        exit(1);
    }// end else

    // for(int i = 0; i < CAPACITY; i++ ){
    //
    //     cout << commandOrder[i].first << endl
    //     << commandOrder[i].second << endl;
    // }
    //
    // cout << endl << "usedC should == 7  " << usedC << endl;
} // end readBin

void Syntasso::performCommand(int decimal, string line){
    string binary;
    int location1 = 0,
        location2 = 0,
        location3 = 0;
    unsigned int finalBin;
        int value;
        int temp;

    bool isThere;

    switch (decimal) {

        case 0:
        // !Stasi (hault)
            displayMemory();
            break;

        case 32:
        // &Sum
            line = line.substr(7,4);
            location1 = binaryConversion(line); // 13

            cout << "Line is: " << line << endl
                << "Sigma is: " << location1 << endl;
             cout << "Enter a value: ";
             cin >> value;

             memory[location1] += value;
            break;

        case 31:
        //+Add
            line = line.substr(7);
            line = line.substr(0,2);
            location1 = binaryConversion(line);
            location2 = findReg(line);
            location3 = findReg(line);

            memory[numPar[location3].second] = memory[numPar[location1].second] + memory[numPar[location2].second];
            break;
        case 30:
        // -Sub
            line = line.substr(7);
            location1 = findReg(line);
            location2 = findReg(line);
            location3 = findReg(line);
            memory[numPar[location3].second] = memory[numPar[location1].second] - memory[numPar[location2].second];

            break;

        case 29:
        //*Mult
            line = line.substr(7);
            location1 = findReg(line);
            location2 = findReg(line);
            location3 = findReg(line);

            memory[numPar[location3].second] = memory[numPar[location1].second] * memory[numPar[location2].second];
            break;

        case 28:
        // /Div
            line = line.substr(7);
            location1 = findReg(line);
            location2 = findReg(line);
            location3 = findReg(line);

            memory[numPar[location3].second] = memory[numPar[location1].second] / memory[numPar[location2].second];
            break;

        case 27:
        //%Mod
            line = line.substr(7);
            location1 = findReg(line);
            location2 = findReg(line);
            location3 = findReg(line);

            memory[numPar[location3].second] = memory[numPar[location1].second] % memory[numPar[location2].second];

            break;

        case 26:
        // ^Pow
            line = line.substr(7);
            location1 = findReg(line);
            location2 = findReg(line);
            location3 = findReg(line);

            memory[numPar[location3].second] = pow(memory[numPar[location1].second], memory[numPar[location2].second]);
            break;

        case 25:
        //Edo (Load)

            break;

        case 24:
        // #Evrima (Find)
            line = line.substr(7);
            location1 = findReg(line);
            cout << find(numPar[16].second, iterator, memory[numPar[location1].second]);

            break;

        case 23:
        //@Kyklo (Loop)
        // Sarah

            line = line.substr(14,3); // we take away the command

             cout << "OG line: " << line << endl;
            //
            // cout << "location 1: " << location1 << endl
            //     << "LINE: " << line << "test" << endl;
            iterator = binaryConversion(line);
            cout << "iterator: " << iterator << endl;

            if(loopCommand()){

                cout << "Success !" << endl;
            }
            else{

                cout << "Try harder!" << endl;
            }


            find(numPar[16].second, numPar[17].second, memory[2]);

            break;

        case 22:
        //>Ako (Input)
            line = line.substr(7);
            location1 = findReg(line);
            cout << "Enter an integer: (0 - 256)";
            cin >> temp;
            binary = decimalToBinary(temp);
            //cout << "binary " << binary << endl;

            // finalBin = atoi(binary.c_str());
            // cout << "finalBin " << atoi(binary.c_str()) << endl;
            memory[numPar[location1].second] = temp;

            break;

        case 21:
        // <Lego (Output)
            line = line.substr(7, 4);
            location1 = binaryConversion(line);
            //cout << "Location 1: " << location1 << endl;
            cout << endl <<  memory[location1] << endl;

            break;

        case 20:
        // ?Lykis (SkipCond)
            line = line.substr(7);
            location1 = findReg(line);




            break;

        case 19:
        // $Alma (Jump)
        //Noe

            break;

        case 18:
        // |Exa (Clear)

            clearRegisters();
            break;

          // case 17:
          // // Deka
          //
          //     break;

          case 16:
          //Epis (chars)

              break;

        default:

            cout << "Invalid COmmand! What Happened?!" <<endl;

            break;
    }// end of switch
}// end of performCommand()


int Syntasso::binaryConversion(std::string binary)
{
  int length = binary.length();
  //cout << "Length: " << length <<endl;
  int decimal[length];
  int finalDecimal = 0;
  int power = length - 1; //initialize this value at the highest exponent

  for(int i = 0; i < length; i++)
  {
    if(binary[i] == '1')
    {
      finalDecimal += pow(2, power);
      power--;
    }
    else
      power--;
  }
  return finalDecimal;
} // end binary

void Syntasso::clearRegisters(){

    for(size_t i = 16; i < CAPACITY; i++){

        memory[i] = 0;

    }
    return;
}

int Syntasso::findReg(std::string& line)
{
  string binValue = line.substr(0, 4);

  for(int i = 0; i < CAPACITY; ++i)
  {
    if(binCode[i].second == binValue)
    {
      line = line.substr(5);
      return i;
    }
  }
  return -1;
} // end findReg

void Syntasso::displayMemory()
{

  // cout << "REGISTERS:\n";
  // cout.width(25); cout << left << "accumulator " << right << showpos << setfill('0') << left << setw(5) << setfill(' ') << endl;
  // cout.width(25); cout << left << "instructionCounter " << right << noshowpos << setw(5) << endl;
  // cout.width(25); cout << left << "instructionRegister  " << right << showpos << setw(5) << endl;
  // cout.width(25); cout << left << "operationCode " <<  right << noshowpos << setw(5) << endl;
  // cout.width(25); cout << left << "operand  " << right << noshowpos << setw(5) << endl;
  cout << "\nMEMORY:" << endl << noshowpos;



  cout << "  ";
  for(int i = 0; i < 10; i++)
  {
    cout << setw(6) << right << noshowpos << i;
  }
  cout << endl;
  int count = 0;
  for(int ix = 0; ix < 100; ix++)
  {
    cout << noshowpos << setw(3) << right << ix * 10 << " ";
    for(int j = 0; j < 10; j++)
    {
      cout << noshowpos << setfill('0') << right << setw(6) << memory[count] << " ";
      count++;
    }
    cout << setfill(' ') << endl;
  }
  cout << endl;

} // end displayMemory


void Syntasso::skip(int value, char state){
    canSkip = false;
    switch (state) {

        case 'N':
            if(value < 0){
                canSkip = true;
            }
            break;

        case 'P':
            if(value > 0){
                canSkip = true;
            }
            break;

        case 'Z':
            if(value == 0){
                canSkip = true;
            }
            break;



    }

}// end of skip()

bool Syntasso::find(int& headPtr, int& tailPtr, int& target)
{
  bool isFound = false;
  for(int i = headPtr; i < tailPtr; ++i)
  {
    if(memory[i] == target)
      isFound = true;
  }
  return isFound;
}


void Syntasso::fillCommandOrder(std::ifstream& fin){

    int decimal;
    string line;
    if(fin.is_open())
    {

        while(getline(fin, line)){
        // take the first binary code and convert to a decimal number
        decimal = binaryConversion(line.substr(0,6)); //This number will be sent to switch
        if(line.length() > 0){

            commandOrder[usedC].first = decimal;
            //cout << "usedC " << usedC << endl;
            //cout << "sentence" << sentence << endl;
            //cout << "Line: " << line  << endl;

            line = line.substr(7); // gets rid of EDO when Passed into performCommand()


            //cout << "usedC " << usedC << endl;
            commandOrder[usedC].second = line;

            usedC++;
        }


        }// end of while
        fin.close();
    }// end of if
    else{
        cout << "You Done Messed Up.\n";
        exit(1);
    }

    //
    // for(int i = 0; i < CAPACITY; i++ ){
    //
    //     cout << commandOrder[i].first << endl
    //     << commandOrder[i].second << endl;
    // }


    return;

}


bool Syntasso::loopCommand(){

    int start = -1,
            end = -1;
    bool isfirst = true;
    string command;
    int decCom;

    for(size_t i = 0; i < usedC; i++){

        if(isfirst && commandOrder[i].first == 25){

            start = i;
            isfirst = false;
        }

        else if(commandOrder[i].first == 25 && commandOrder[i + 1].first != 25){
            end = i;

        }





    }// end of for


    if(start == -1 && end == -1){
        return false;
    }
    if(end == -1)
        end = start;

    // cout << "start " << start << endl
    //         << "end " << end << endl ;
    for(size_t j = 0; j < iterator; j++){

        for(size_t k = start; k <= end; k++ ){

            command = commandOrder[k].second.substr(0,6);

            decCom = binaryConversion(command);
            //cout << "I'm on top" << endl;
            performCommand(decCom, commandOrder[k].second);
        }
    }
    return true;
}

string Syntasso::decimalToBinary(int decimal)
{
  int remainder = 0;
  int base = 2;
  std::string bin = "";
  int i = 0;
  std::string reverse = "";
  while(decimal > 0)
  {
    remainder = decimal % 2;
    decimal = decimal / 2;

    bin += '0' + remainder;
    i++;
  } // end while
  for(int i = bin.length(); i >= 0; i--)
    reverse += bin[i];

  return reverse;
} // end decimalToBinary
