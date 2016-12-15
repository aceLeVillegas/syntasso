#include "Syntasso.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

  ifstream inFile("benchmark1.vilo");
  ifstream fin("binCode.vilo");
  ifstream read("binCode.vilo");

  // //string line;
   Syntasso test;
  //
  test.readMnemonic(inFile);
  test.fillCommandOrder(read);
  test.readBin(fin);

  // cout << test.binaryConversion("0011") << endl;

  // string bin = "101101";
  // long int binFinal;
  // binFinal = atoi(bin.c_str());
  // cout << "finalBin " << binFinal << endl;

  return EXIT_SUCCESS;
}// end main
