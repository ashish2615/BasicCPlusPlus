//
// Created by Ashish Sharma on 18/11/23.
//

#include <iostream>
using namespace std;


class Pointers {
public:
    void IntPointer(int* numberPointer) {
        cout << "IntPointer: " << *numberPointer << endl;
    }
    void CharPointer(char* charPointer) {
        cout << "CharPointer: " << *charPointer << endl;
    }
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
        *ptr = 10; // Replace the value stored in the pointer.
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

int main() {
    Pointers pointer;
    pointer.Pointer();
    pointer.pointerFromArray(5);
}