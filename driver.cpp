#include "Syntasso.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
  ifstream inFile("Commands.vilo");
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
  return EXIT_SUCCESS;
}// end main
