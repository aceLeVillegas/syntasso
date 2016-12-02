#include "Syntasso.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
Syntasso::Syntasso(){

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
  string line;
  if(inFile.is_open())
  {
    cout << "Successfully opened file!" << endl;
    while(getline(inFile, line, '\n'))
    {
      std::stringstream   linestream(line);
      std::string         value;
      // Ignore if the line is a comment or dummy variables
      if(line.find("#") == 0 || line.find("rowid") == 0)
        continue;
      else
      {
        while(getline(linestream,value,','))
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
