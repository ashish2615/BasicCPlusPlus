//
// Created by Ashish Sharma on 18/11/23.
//

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <numeric>

using namespace std;


class Pointers {
public:
    void IntPointer(int* numberPointer) {
        cout << "IntPointer: " << *numberPointer << endl;
    }
    void CharPointer(char* charPointer) {
        cout << "CharPointer: " << *charPointer << endl;
    }
    // A void pointer can point to any data type pointer.
    void VoidPointer(void* ptr, char type){
        switch (type) {
            case 'i':
                cout << "IntPointer: " << *((int*)ptr) <<  endl;
                break;
            case 'f':
                cout << "FloatPointer: " << *((float*)ptr) <<  endl;
                break;
            case 'c':
                cout << "CharPointer: "<<  *((char*)ptr) <<  endl;
                break;
            default:
                break;
        }
    }
    void Pointer() {
        // Pointers : stores address of a variable.
        int n = 5;
        cout << "Int value: " << n <<  endl;
        cout << "Address of Int value " << n << " is: " << &n << endl; // & operator gives the address of the variable with value.

        // Reference a pointer
        int * ptr = &n; // *  Assign address of variable to a pointer.
        cout << "Reference address to the Pointer " << ptr <<  endl; // Gives the address of pointer where value is stored.

        // Dereference a pointer
        cout << "Dereference the Pointer " << *ptr <<  endl; // Dereference or Gives the value stored in pointer.

        // Replace the value stored in the pointer.
        *ptr = 10;
        cout << "Replace the value stored in pointer " <<*ptr <<  endl; // Gives the value stored in pointer.
        cout << "Int value would be that of pointer: " << n <<  endl; // n holds the same value as that of pointer.
        cout << "Pointer value : " << ptr <<  endl;

        int v;
        int *ptr2 = &v;
        *ptr2 = 7;
        cout << ptr2 <<  endl;
        cout << v <<  endl;

        // Void Pointers
        int number = 15;
        char letter = 'a';
        float floatValue = 2.0f;
        IntPointer(&number);
        CharPointer(&letter);
        VoidPointer(&number, 'i');
        VoidPointer(&letter, 'c');
        VoidPointer(&floatValue, 'f');
    }

    // Creating pointers for an array.
    void pointerFromArray(int sizeOfArray) {
        int array[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++) {
            cout << "Number : " ;
            cin >> array[i];
        }
        for (int i = 0; i < sizeOfArray; i++) {
            cout << (array + i) << " " << *(array + i) << endl;
        }
        //    int luckyNumber[] = {1, 3, 5, 7, 9};
        //    cout << luckyNumber <<  endl; // This gives the address of first element of the array.
        //    cout << &luckyNumber[0] << endl; // Cross-check if previous line is True.
        //    cout << luckyNumber[0] <<  endl;
        //    cout << *(luckyNumber + 2) << endl; //  Use the address of first and add 2 spaces to access the element.
        //    cout << *(luckyNumber + 4) << endl; //  Use the address of first and add 4 spaces to access the element.
    }

};

int functionPointer() {
    return 5;
}

int funcPointer(int a, int b) {
    return a + b;
}

bool ascendingCompare(int a, int b){
    return a > b;
}

bool descendingCompare(int a, int b){
    return a < b;
}

void customSort(vector<int>& vectorNumbers, bool(*compareFuncPtr)(int, int)){
    for (int start = 0; start < vectorNumbers.size(); start++) {
        int elementIndex = start;
        for (int currentIndex = 0; currentIndex < vectorNumbers.size(); currentIndex++) {
            if (compareFuncPtr(vectorNumbers[currentIndex], vectorNumbers[elementIndex])){
                elementIndex = currentIndex;
            }
            swap(vectorNumbers[start], vectorNumbers[elementIndex]);
        }
    }
}

void printNumbers(vector<int>& numbers){
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
    cout << endl;
}

int getMinValue(int inputArray[], int sizeOfArray){
    int minValue = inputArray[0];
    for (int i=1; i < sizeOfArray; i++) {
        if (inputArray[i] < minValue)
            minValue = inputArray[i];
    }
    return minValue;
}

int getMaxValue(int inputArray[], int sizeOfArray){
    int maxValue = inputArray[0];
    for (int i=1; i < sizeOfArray; i++) {
        if (inputArray[i] > maxValue)
            maxValue = inputArray[i];
    }
    return maxValue;
}

void getMinMaxValues(int inputArray[], int sizeOfArray, int* min, int* max) {
    for (int i=1; i < sizeOfArray; i++) {
        if (inputArray[i] > *max)
            *max = inputArray[i];
        if (inputArray[i] < *min)
            *min = inputArray[i];
    }
}

void dynamicArray(int size) {
    // Create an array of the dynamic size
    int* newArray = new int[size]; // Allocate memory to newArray.

    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "]";
        cin >> newArray[i];
    }

    for (int i = 0; i < size; i++) {
        cout << *(newArray + i) << endl;
    }
    // De-allocate memory from newArray once it is not required any more.
    delete []newArray;
    newArray = NULL;
}

void multiDimDynamicArray(int rows, int column) {
    // Create a array of number of rows
    int** table = new int*[rows];
    // Create a new array for each row.
    // How many column a row have
    for (int i = 0; i < rows; i++) {
        table[i] = new int[column];
        // Create an array for each row i.e. how many element each array have.
        for (int j = 0; j < column; j++) {
            cout << "Array[" << i << "][" << j << "]" ;
            cin >> table[i][j];
        }
    }

    // De-allocate the memory
    // We have to de-allocated each row first rather than whole table.
    for (int i = 0; i < rows; i++) {
        delete[] table[i];
    }
    delete[] table;
    table = NULL;
}


int main() {
    Pointers pointer;
    pointer.Pointer();
    pointer.pointerFromArray(5);

    vector<int> vectorNumbers = { 5, 29, 53, 2, 40, 11, 28 };
    bool(*funcPtr)(int, int) = ascendingCompare;
    customSort(vectorNumbers, funcPtr);
    printNumbers(vectorNumbers);

    vector<int> vectorNumbers1 = {5, 29, 53, 2, 40, 11, 28};
    bool(*funcPtr1)(int, int) = descendingCompare;
    customSort(vectorNumbers1, funcPtr1);
    printNumbers(vectorNumbers1);

    int(*functionPtr)() = functionPointer;
    cout << functionPtr() << endl;
    int(*functPtr1)(int, int) = funcPointer;
    cout << functPtr1(4, 8) << endl;

    int inputArray[] = {2,6,-7,9,4};
    int inputArraySize = *(&inputArray + 1) - inputArray;
    int minValue = getMinValue(inputArray, inputArraySize);
    int maxValue = getMaxValue(inputArray, inputArraySize);
    cout << "Minimun value in array is: " << minValue << endl;
    cout << "Max value in array is: " << maxValue << endl;

    // Passing the addressed to the functions.
    int min = inputArray[0];
    int max = inputArray[0];
    getMinMaxValues(inputArray, inputArraySize, &min, &max);
    cout << "Min value is: " << min << endl;
    cout << "Max value is: " << max << endl;

    dynamicArray(5);
    multiDimDynamicArray(3, 4);
}