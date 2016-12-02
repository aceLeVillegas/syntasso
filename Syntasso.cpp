#include "Syntasso.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

Syntasso::Syntasso(){

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



    numPar[0].first = "&Sum";
    numPar[0].second = 1;
    numPar[1].first = "+Add";
    numPar[1].second = "011111";
    numPar[2].first = "-Sub";
    numPar[2].second = "011110";
    numPar[3].first = "*Mult";
    numPar[3].second = "011101";
    numPar[4].first = "/Div";
    numPar[4].second = "011100";
    numPar[5].first = "%Mod";
    numPar[5].second = "011011";
    numPar[6].first = "^Pow";
    numPar[6].second = "011010";
    numPar[7].first = "~Fortono";
    numPar[7].second = "011001";
    numPar[8].first = "#Kryvo";
    numPar[8].second = "011000";
    numPar[9].first = "@Kyklo";
    numPar[9].second = "010111";
    numPar[10].first = ">Ako";
    numPar[10].second = "010110";
    numPar[11].first = "<Lego";
    numPar[11].second = "010101";
    numPar[12].first = "?Lykis";
    numPar[12].second = "010100";
    numPar[13].first = "$Alma";
    numPar[13].second = "010011";
    numPar[14].first = "|Exa";
    numPar[14].second = "010010";
    numPar[15].first = "!Stasi";
    numPar[15].second = "000000";
    numPar[16].first = "alpha";
    numPar[16].second = 0;
    numPar[17].first = "beta";
    numPar[17].second = 0;
    numPar[18].first = "gamma";
    numPar[18].second = 0;
    numPar[19].first = "delta";
    numPar[19].second = "0100";
    numPar[20].first = "epsilon";
    numPar[20].second = "0101";
    numPar[21].first = "zeta";
    numPar[21].second = "0110";
    numPar[22].first = "eta";
    numPar[22].second = "0111";
    numPar[23].first = "theta";
    numPar[23].second = "1000";
    numPar[24].first = "iota";
    numPar[24].second = "1001";
    numPar[25].first = "kappa";
    numPar[25].second = "1010";
    numPar[26].first = "lambda";
    numPar[26].second = "1011";
    numPar[27].first = "mu";
    numPar[27].second = "1100";
    numPar[28].first = "sigma";
    numPar[28].second = "1101";
    numPar[29].first = "omicron";
    numPar[29].second = "1110";
    numPar[30].first = "omega";
    numPar[30].second = "1111";


}

bool Syntasso::checkSyntax(std::string word, int whiteSpace){

    if(whiteSpace == 0){

        return checkPar(word);
    }
    if(whiteSpace == 1 && parameters >= whiteSpace){

        if(searchBin(word)){

            return true;
        }
        else if((word[0] >= '0' && word[0] <= '9') || (word[0] >= 'a' && word[0] <= 'z')){

            return true
        }
        else{

            return false;
        }// end else
    }// end if
    else{

        return false; 
    }


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

string Syntasso::asciiToBin(int& number)
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

void Syntasso::readMnemonic(ifstream& inFile)
{
  int whiteSpace = 0;
  string line;
  if(inFile.is_open())
  {
    cout << "Successfully opened file!" << endl;
    while(getline(inFile, line, '\n'))
    {
      std::stringstream   linestream(line);
      std::string         value;
      // Ignore if the line is a comment or dummy variables
      if(line.find("(") == 0)
        continue;
      else
      {
        while(getline(linestream,value, " " ))
        {
          cout << "test" << endl;
        }

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
>>>>>>> 612c23125574b22df34949887040c890adeaa591
