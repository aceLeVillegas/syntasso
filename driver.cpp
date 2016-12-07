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
  //string line;
  Syntasso test;

  test.readMnemonic(inFile);
  test.readBin(fin);

  return EXIT_SUCCESS;
}// end main
