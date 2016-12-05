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
  //string line;
  Syntasso test;

  test.readMnemonic(inFile);

  return EXIT_SUCCESS;
}// end main
