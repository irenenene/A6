//Sort.h contains implementations of 4 sorting algorithms
//Bubble sort
//Selection sort
//Quick sort
//Radix sort

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Sort {
public:
  Sort();
  //Sort(int arrSize);
  ~Sort();

  double* copy1;
  double* copy2;
  double* copy3;
  double* copy4;
  int arraySize;
  bool fileOK; //will be false if there is an error with file processing.

  void initialize(string fName); //reads from file
  void bubbleSort(double* arr, int arrSize);
  void insertionSort(double* arr, int arrSize);
  void quickSort(double* arr, int left, int right);
  void gnomeSort(double*arr, int arrSize);
  void runSorts();

  void printArray(double* dArray); //for testing
  void printAll();
};

#endif
