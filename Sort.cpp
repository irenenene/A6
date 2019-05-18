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
        arr[j+1] = temp;
        swapped = true;
      }
    }

    if(!swapped)
      break;
  }
}

void Sort::insertionSort(double* arr, int arrSize) {
  for (int i = 1; i < arrSize; i++) {
    double temp = arr[i];
    int j = i;

    while ((j > 0) && (arr[j-1] >= temp)) {
      arr[j] = arr[j-1];
      j--;
    }

    arr[j] = temp;
  }
}

void Sort::quickSort(double* arr, int left, int right) { //start and end are indexes
  double pivot = arr[right];
  int i = left;
  int j = right;
  double temp;

  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

void Sort::gnomeSort(double* arr, int arrSize) {
  int index = 0;

  while (index < arrSize) {
    if ((index == 0) || (arr[index] >= arr[index-1]))
      index++;
    else {
      double temp = arr[index];
      arr[index] = arr[index-1];
      arr[index-1] = temp;
      index--;
    }
  }
}

void Sort::printAll() {
  cout << "Array 1: ";
  printArray(copy1);
  cout << endl;
  cout << "Array 2: ";
  printArray(copy2);
  cout << endl;
  cout << "Array 3: ";
  printArray(copy3);
  cout << endl;
  cout << "Array 4: ";
  printArray(copy4);
  cout << endl;
}

void Sort::printArray(double* dArray) {
  for (int i = 0; i < 10; i++) {
    cout << dArray[i] << " ";
  }
}

void Sort::runSorts() {
  clock_t startTime;
  clock_t endTime;

  cout << "Running bubble sort. \n";
  startTime = clock(); //get startTime
  bubbleSort(copy1, arraySize);
  endTime = clock(); //get endTime

  double seconds;
  seconds = double(endTime-startTime)/CLOCKS_PER_SEC;
  cout << "Bubble Sort time: " << seconds << " seconds \n";

  cout << "Running insertion sort. \n";
  startTime = clock(); //get startTime
  insertionSort(copy2, arraySize);
  endTime = clock(); //get endTime

  seconds = double(endTime-startTime)/CLOCKS_PER_SEC;
  cout << "Insertion Sort time: " << seconds << " seconds \n";

  cout << "Running quick sort. \n";
  startTime = clock(); //get startTime
  quickSort(copy3, 0, arraySize-1);
  endTime = clock(); //get endTime

  seconds = double(endTime-startTime)/CLOCKS_PER_SEC;
  cout << "Quick Sort time: " << seconds << " seconds \n";

  cout << "Running Gnome sort. \n";
  startTime = clock(); //get startTime
  gnomeSort(copy4, arraySize);
  endTime = clock(); //get endTime

  seconds = double(endTime-startTime)/CLOCKS_PER_SEC;
  cout << "Gnome Sort time: " << seconds << " seconds \n";
}
