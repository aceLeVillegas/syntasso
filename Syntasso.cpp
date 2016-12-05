#include "Syntasso.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

Syntasso::Syntasso(){

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
    binCode[7].first = "~Fortono";
    binCode[7].second = "011001";
    binCode[8].first = "#Kryvo";
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
    numPar[7].first = "~Fortono";
    numPar[7].second = 1;
    numPar[8].first = "#Kryvo";
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
    // starting at index 900 to 914
    numPar[16].first = "alpha";
    numPar[16].second = 900;
    numPar[17].first = "beta";
    numPar[17].second = 901;
    numPar[18].first = "gamma";
    numPar[18].second = 902;
    numPar[19].first = "delta";
    numPar[19].second = 903;
    numPar[20].first = "epsilon";
    numPar[20].second = 904;
    numPar[21].first = "zeta";
    numPar[21].second = 905;
    numPar[22].first = "eta";
    numPar[22].second = 906;
    numPar[23].first = "theta";
    numPar[23].second = 907;
    numPar[24].first = "iota";
    numPar[24].second = 908;
    numPar[25].first = "kappa";
    numPar[25].second = 909;
    numPar[26].first = "lambda";
    numPar[26].second = 910;
    numPar[27].first = "mu";
    numPar[27].second = 911;
    numPar[28].first = "sigma";
    numPar[28].second = 912;
    numPar[29].first = "omicron";
    numPar[29].second = 913;
    numPar[30].first = "omega";
    numPar[30].second = 914;


    for(size_t i = 0; i < CAPACITY; i++){

        commandOrder[i] = -1;
    }
    usedC = 0;

    alpha = NULL;
    beta = NULL;
    gamma = "";
    delta = "";
    epsilon = "";
    zeta = '';
    eta = '';
    theta = '';
    iota = 0;
    kappa = 0;
    lambda = 0;
    mu = 0;
    sigma = 0;
    omicron = 0;
    omega = 0;



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

    if(whiteSpace == 0){

        return searchPar(word);
    }
    // to search and see if the parameters are registers, numbers, or words
    else if(whiteSpace >= 1 && parameters >= whiteSpace){

        if(searchBin(word)){

            return true;
        }/*
        // work on if we have time
        // checks to see if the first and onward parameters are either words or numbers
        else if((word[0] >= "0" && word[0] <= "9") || (word[0] >= "a" && word[0] <= "z")){

            return true;
        }
        else{

            return false;
        }// end else
        */
    }// end if

    else{

        return false;
    }
    //return false;

}
bool Syntasso::searchPar(std::string key){

    for(unsigned int i = 0; i < CAPACITY; i++){

        if(key == numPar[i].first){

            parameters = numPar[i].second;

            return true;
        }
    }
    return false;


}
bool Syntasso::searchBin(std::string key){

    for(unsigned int i = 0; i < CAPACITY; i++){

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
          // cout << "Current word: " << value << " T/F: " <<checkSyntax(value, whiteSpace) << " "
          //   << "whiteSpace: " << whiteSpace << endl;
          if(checkSyntax(value, whiteSpace))
          {
            value = stringToBin(value);
            fout << value << " ";
            whiteSpace++;
          }
          else
          {
            cout << "Koino : "  << line << endl;
            cout << "Program terminated abnormally." << endl;
            cout << value << endl;
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
  string line;
  if(inFile.is_open())
  {
    cout << "Successfully opened  binary file!" << endl;
    while(getline(inFile, line, '\n'))
    {
      std::stringstream   linestream(line);
      std::string         value;
      int binToDecimal;
      while(getline(linestream,value, ' ' ))
      {
        binToDecimal = binaryConversion(value);




      }

    }

    // close the file before exiting
    inFile.close();
  }
  else
  {
    cout << "Unable to open file.\n";
    exit(1);
  }
} // end readBin


void Syntasso::fillCommandOrder(string command){

    for(size_t i = 0; i < CAPACITY; i++){

        if(command == binCode[i].first){

            commandOrder[usedC] = i;
            usedC++;
        }
    }
    return;

}

void Syntasso::performCommand(int decimal, string line){

    switch (decimal) {

        case 0:
        // !Stasi (hault)
        //Noe

            break;

        case 32:
        // &Sum
        //Sarah

            break;

        case 31:
        //+Add
        //Noe

            break;

        case 30:
        // -Sub
        //Noe

            break;

        case 29:
        //*Mult
        //Sarah

            break;

        case 28:
        // /Div
        //Sarah

            break;

        case 27:
        //%Mod
        // Noe

            break;

        case 26:
        // ^Pow
        //Noe

            break;

        case 25:
        //~Fortono (Load)
        // Sarah

            break;

        case 24:
        // #Kyklo (Store)
        // Sarah

            break;

        case 23:
        //@Kyklo (Loop)
        // Sarah

            break;

        case 22:
        //>Ako (Input)
        //Noe

            break;

        case 21:
        // <Lego (Output)
        //Noe

            break;

        case 20:
        // ?Lykis (SkipCond)
        //Sarah

            break;

        case 19:
        // $Alma (Jump)
        //Noe

            break;

        case 18:
        // |Exa (Clear)

            clearRegisters();
            break;

        case 17:
        // Deka

            break;

        case 16:
        //Epis

            break;

        default:

            cout << "Invalid COmmand! What Happened?!" <<endl;

            break;
    }// end of switch
}// end of performCommand()


int Syntasso::binaryConversion(std::string binary)
{
  int length = binary.length();
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

    alpha = NULL;
    beta = NULL;
    gamma = "";
    delta = "";
    epsilon = "";
    zeta = '';
    eta = '';
    theta = '';
    iota = 0;
    kappa = 0;
    lambda = 0;
    mu = 0;
    sigma = 0;
    omicron = 0;
    omega = 0;
}
