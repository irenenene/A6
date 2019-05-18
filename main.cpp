/*
Irene Liu
irliu@chapman.edu
2313260
CPSC 350-02
Assignment 6

Used to run the sort class, also contains file IO
*/

#include "Sort.h"
#include <iostream>

using namespace std;

int main(int argc, char**args) {
  Sort sorter;

  if(argc > 1) {
    string fileName = args[1];

    sorter.initialize(fileName);
    if(sorter.fileOK) {
      sorter.runSorts();
      sorter.printAll();
    }

  }
  else
    cout << "Did not pass a filename in as an argument." << endl;

  return 0;
}
