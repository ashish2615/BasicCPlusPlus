//
//  Created by Ashish Sharma on 18/11/23.
//

#include <iostream>
#include <list>
using namespace std;


// Class in c++
class ObjectOrientedProgramming {
    // Access modifier for a class: public, private or protected.
private:
    // Encapsulation: these variables should be private.
    // Such they can only be accessed inside the class
    string name;
    int userCounter;
    list<string> totalUsers;
protected:
    string userName;
    int learningPercentage;
public:
    // Constructor in c++
    // Method which invoke when an object of a class is created
    ObjectOrientedProgramming(const string& name1, const string& userName1){
        name = name1;
        userName = userName1;
        userCounter = 0;
        learningPercentage = 0;
    }
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "User: " << userName << endl;
        cout << "User counter: " << userCounter << endl;
        for (string userCount : totalUsers) {
            cout << userCount << endl;
        }
       cout << endl;
    }
    void subUserCounts(){
        userCounter++;
    }
    void unSubUserCounts(){
        if (userCounter > 0)
            userCounter--;
    }
    void addUser(const string& title){
        totalUsers.push_back(title);
    }
    void checkLearningPercent(){
        if (learningPercentage < 70)
            cout << userName << " has not reached the satisfactory level of learning. " << endl;
        else
            cout << userName << " has reached a satisfactory level. " << endl;
    }
};

// class inheriting from another class
class PracticeOOP: public ObjectOrientedProgramming {
public:
    // Access the constructor of base class.
    PracticeOOP(const string& name, const string& userName): ObjectOrientedProgramming(name, userName) {

    }
    void practiceProgramming() {
        cout << userName << " is Practicing the fundamentals of C++" << endl;
        learningPercentage ++;
        cout << endl;
    }
};

class ImplementOOP: public ObjectOrientedProgramming {
public:
    ImplementOOP(const string& name, const string& userName): ObjectOrientedProgramming(name, userName){
    }
    // Overriding the method in PracticeOOP class.
    void practiceProgramming() {
        cout << userName << " is Implementing the fundamentals of C++" << endl;
        learningPercentage ++;
        cout << endl;
    }
};


int main() {

    PracticeOOP useOOP("c++", "Ashish");
    useOOP.subUserCounts();
    useOOP.addUser("DSA");
    useOOP.addUser("Functions");
    useOOP.addUser("OOP");
    useOOP.getInfo();
    useOOP.practiceProgramming();

    ImplementOOP implementOop("c++", "Sharma");
    implementOop.practiceProgramming();

    // Pointer of base class to the object of derived class.
    ObjectOrientedProgramming * ooPPtr = &useOOP;
    ObjectOrientedProgramming * oopPtr2 = &implementOop;
    ooPPtr->checkLearningPercent();
    oopPtr2->checkLearningPercent();

    ObjectOrientedProgramming ooP("objectName", "userName");
    ooP.subUserCounts();
    ooP.subUserCounts();
    ooP.subUserCounts();
    ooP.addUser("first");
    ooP.addUser("second");
    ooP.addUser("third");
    ooP.getInfo();
}
