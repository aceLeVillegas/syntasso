#include "Syntasso.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

  // ifstream inFile("benchmark1.vilo");
  // ifstream fin("binCode.vilo");
  // ifstream read("binCode.vilo");
  //
  // //string line;
   Syntasso test;
  //
  // test.readMnemonic(inFile);
  // test.fillCommandOrder(read);
  // test.readBin(fin);

  cout << test.binaryConversion("0011") << endl;

  return EXIT_SUCCESS;
}// end main
