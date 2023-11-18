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
}