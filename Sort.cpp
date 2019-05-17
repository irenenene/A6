#include "Sort.h"

Sort::Sort() {
  copy1 = NULL;
  copy2 = NULL;
  copy3 = NULL;
  copy4 = NULL;
  arraySize = 0;
  fileOK = true;
}

Sort::~Sort() {
  delete[] copy1;
  delete[] copy2;
  delete[] copy3;
  delete[] copy4;
  cout << "Destructor" << endl;
}

void Sort::initialize(string fName) {
  ifstream infile;
  infile.open(fName);

  if(infile.is_open()) {
    string fileString = "";
    int lines;

    try {
      getline(infile, fileString); //get the first line, which should be the # of items
      lines = stoi(fileString);
      arraySize = lines;

      //dynamically allocate the arrays
      copy1 = new double[arraySize];
      copy2 = new double[arraySize];
      copy3 = new double[arraySize];
      copy4 = new double[arraySize];

      for(int i = 0; i < arraySize; i++) {
        //read the data
        getline(infile, fileString);
        double currLine = stod(fileString);

        copy1[i] = currLine;
        copy2[i] = currLine;
        copy3[i] = currLine;
        copy4[i] = currLine;
      }
    }
    catch (const invalid_argument &e) {
      cout << "Error reading from file." << endl;
      fileOK = false;

    }
    catch (ifstream::failure& e) {
      cout << "Tried to read past EOF." << endl;
      fileOK = false;
    }

    infile.close();
  }
}

void Sort::bubbleSort(double* arr, int arrSize) {
  for (int i = 0; i < arrSize-1; i++) {
    bool swapped = false;

    for (int j = 0; j < arrSize-1; j++) {
      if (arr[j] > arr[j+1]) {
        double temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = arr[j];
        swapped = true;
      }
    }

    if(!swapped)
      break;
  }
}

void Sort::printAll() {
  cout << "Array 1: ";
  printArray(copy1);
  cout << endl;
  cout << "Array 2: ";
  printArray(copy2);
  cout << endl;
}

void Sort::printArray(double* dArray) {
  for (int i = 0; i < arraySize; i++) {
    cout << dArray[i] << " ";
  }
}
