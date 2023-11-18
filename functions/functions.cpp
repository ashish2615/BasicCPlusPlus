//
//  Created by Ashish Sharma on 14/10/23.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


void TriangleImages(int sideOne, int sideTwo, char symbol) {
    // Triangle and Reverse Triangle.
    for (int s1 = 0; s1 <= sideOne; s1++) {
        for (int s2 = 0; s2 < s1; s2++) {
            cout << setw(2) << symbol;
        }
        cout << endl;
    }
    cout << endl;
    // Reverse Triangle
    for (int s1 = sideOne; s1 >= 1; s1--) {
        for (int s2 = 0; s2 < s1; s2++) {
            cout << setw(2) << symbol;
        }
        cout << endl;
    }
}

void RectangleImage(int height, int width, char symbol){
    // Draw a rectangle
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            cout << setw(3) << symbol;
        }
        cout << endl;
    }
}

void CheckSizeOfvariablesInCPlusPlus() {
    cout << "Size of the short is "<< sizeof(short) << "  bytes." << endl; //2 bytes
    cout << "Size of the int is "<< sizeof(int) << "  bytes." << endl; // 4 bytes
    cout << "Size of the char is "<< sizeof(char) << "  bytes." << endl; // 1 bytes
    cout << "Size of the bool is "<< sizeof(bool) << "  bytes." << endl; // 1 bytes
    cout << "Size of the float is "<< sizeof(float) << "  bytes." << endl; // 4 bytes
    cout << "Size of the double is "<< sizeof(double) << "  bytes." << endl; // 8 bytes
    cout << "Size of the double is "<< sizeof(long) << "  bytes." << endl; // 8 bytes

    cout << "Int min value is:" << INT_MIN << endl; // -2147483648 , this inlcudes 0 hence has one value higer than Int_Max.
    cout << "Int max value is: "<< INT_MAX << endl; // 2147483647
    cout << "Char min value is:" << CHAR_MIN << endl;
    cout << "Char max value is: "<< CHAR_MAX << endl;
    cout << "Long min value is:" << LONG_MIN << endl;
    cout << "Long max value is: "<< LONG_MAX << endl;

}

void CheckAsciiOfCharacter(char givenCharacter){
    cout << "ASCII for character " << givenCharacter << " is " << int(givenCharacter) << endl;
}

void CheckAsciiOfInteger(int number){
    cout << "ASCII for integer " << number << " is " << char(number) << endl;
}

void CheckEvenOrOddNumber(int number) {
    if (number % 2 == 0) {
        cout << number <<" is an even number." << endl;
    } else {
        cout << number <<" is an odd number." << endl;
    }
}

void CheckTriangleType(float side1, float side2, float side3) {
    // Nested If-else statement.
    if (side1 == side2 && side2 == side3)
        cout << "Equilateral traingle" << endl;
    else {
        if (side1 != side2 && side1 != side3 && side2 != side3)
            cout << "Scalene traingle" << endl;
        else
            cout << "Isoceles traingle" << endl;
    }
}

int DaysInMonthApproachSecond(int year) {
    // Without % operator
    int x = year/4; int y= 4 * x;
    return (y == year) ? 29 : 28;
}

int DaysInMonthApproachFirst(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
}

void DayInMonthOfGivenYear(int year, int month) {

    switch (month) {
        case 2:{
            int numberOfDays = DaysInMonthApproachSecond(year);
            cout << "Number of days: " << numberOfDays << endl;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Number of days: " << 30 << endl;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Number of days: " << 31 << endl;
            break;

        default:
            cout << "Not a valid month." << endl;
            break;
    }
}

void CountDigitsOfNumber(int number) {

    int givenNumber = number;
    if (number == 0)
        cout << "Entered Number is 0." << endl;
    else {
        // If number is negative convert to positive.
        if (number < 0){
            number = -1 * number;
            givenNumber = number;
        }
        int counter = 0;
        while (number > 0) {
            number /= 10;
            counter++;
        }
        cout << "Number " << givenNumber << " contains " << counter << " digits." << endl;
    }
}

void ReverseNumber(int number) {

    int reveredNumber = 0;
    while (number != 0) {
        reveredNumber *= 10;
        reveredNumber += number % 10;
        number /= 10;
    }
    cout << "Reversed Number is: " << reveredNumber << endl;
}

void PinValidation(int pin) {
    // PIN validation.
    int userPin = 2615, errorCount = 0, maxNumberOfTrails = 3;;
    do {
        cout << "Enter the PIN: ";
        cin >> pin;
        if (pin != userPin){
            cout << "Incorrect PIN, enter again." << endl;
            errorCount ++;
        }
    } while (errorCount < maxNumberOfTrails && pin != userPin);

    if (errorCount < maxNumberOfTrails && pin == userPin)
        cout << "Loading..." << endl;
    else
        cout << "Blocked..." << endl;
}

void FactorialOfNumber(int number){
    // First Apporach.
    int factorial = 1;
    for (int i = 1; i <= number; i++) {
        factorial *= i;
    }
    cout << "Factorial of " << number << " is " << factorial << endl;

    // Second Appraoch.
    int factorial1 = 1;
    for(int i = number; i >= 1; i--){
        factorial1 *= i;
    }
    cout << "Factorial of " << number << " is " << factorial1 << endl;
}

void AverageOfGrades() {
    // Calculate the average of grades.
    int totalNumberOfGrades, grade, sum = 0, minGrade = 1, maxGrade = 5;

    cout << "Total Number of grades:" << endl;
    cin >> totalNumberOfGrades;

    for (int i=0; i < totalNumberOfGrades; i++) {
        do {
            cout << "Enter grade " << i + 1 << " : ";
            cin >> grade;
        } while (grade < minGrade || grade > maxGrade);
        cout << "Grade is : " << grade << endl;
        sum += grade;
    }

    cout << "Sum of Grade is : " << sum << endl;
    float avergaeGrade = sum/totalNumberOfGrades;
    cout << "Average grade is : " << avergaeGrade << endl;
}

void MultiplicationTableOfNumber(int startNumber, int maxNumber) {
    // Calculate the multiplication table between two given numbers.
    for (int i = startNumber; i <= maxNumber; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i *j << endl;
        }
        cout << endl;
    }
}

bool IsPrimeNumber(int number) {

    bool isPrimeNumber = true;
    for (int i = 2; i < number; i++) {
        if (number % i == 0){
            isPrimeNumber = false;
            break;
        }
    }

    if (isPrimeNumber)
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    return isPrimeNumber;
}

void CheckPrimeNumber(int number) {

    int counter = 0;
    for (int i = 1; i <= number; i++) {
        bool isPrimeNumber = IsPrimeNumber(i);
        if (isPrimeNumber)
            counter++;
    }
    cout << "Prime Number Between 1 to " << number << " are: " << counter << endl;
}

void showMenu() {
    cout << "******MENU******" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "************" << endl;

}

void AtmApp() {

    int option;
    double balance = 5000;

    do {
        showMenu();
        cout << "Enter Option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Balance: " << balance << " $." << endl;
                break;
            case 2:
                double depositeAmount;
                cout << "Deposite Amount: ";
                cin >> depositeAmount;
                balance += depositeAmount;
                break;
            case 3:
                double withDrawAmount;
                cout << "WihtDraw Amount: ";
                cin >> withDrawAmount;
                if (withDrawAmount <= balance)
                    balance -= withDrawAmount;
                else
                    cout << "Insufficient Balance." << endl;
                break;
            case 4:
                cout << "Exit" << endl;
        }
    } while (option!=4);

}

// Using generics to reduce the above two functions.
// Generic provide ease to use different data type in same function and redundancy.
template<typename T>
void swapWithGeneric(T &a , T & b){
    T temp = a;
    a = b;
    b = temp;
}

int recursiveSum(int a, int b) {
    if (a == b)
        return a;

    return a + recursiveSum(a + 1, b);
}

void sumUsingRecursion(int a, int b){
    // Sum of all numbers between two numbers. a < b.
    int sum = recursiveSum(a , b);
    cout << "Sum = " << sum << endl;
}


int main() {

    TriangleImages(5, 4, '*');

    RectangleImage(4, 4, '*');

    DayInMonthOfGivenYear(2036, 2);

    CheckPrimeNumber(3);

    AtmApp();

    sumUsingRecursion(3, 7);

    int a = 5;
    int b = 9;
    swapWithGeneric<int>(a, b);
    cout << "After swapping, a = " << a << " and b = " << b << endl;

    char c = 'c';
    char d = 'd';
    swapWithGeneric<char>(c, d);
    cout << "After swapping, c = " << c << " and d = " << d << endl;

}
