// Answer 1: version 2 will run, b will conver into number bcz this version have 
//           integer data type on 2nd arguments which converts the letter in number 
//           acc. to ASCII value of B.
// Answer 2: It gives a compile error because functions cannot be
//           overloaded by return type alone. compiler will not distinguish of these
//           two functions
// Answer 3: version 2 and 3

#include <iostream>
using namespace std;

void printInfo(string name) {
    cout << "Name: " << name << endl;
}
void printInfo(string name, int rollNo) {
    cout << "Name: " << name <<" | Roll No: "<<rollNo << endl;

}
void printInfo(int rollNo, string name) {
    cout << "Roll No: " << rollNo<<" | Name: " << name << endl;

}
void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;

}
void printInfo(char grade) {
    cout << "Grade: " << grade << endl;
}


int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}
