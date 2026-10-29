// Answer 1: We write 0 for SMS in blank (c) because we want to provide the
// third argument (data = 1.5). In C++, we cannot skip a middle argument when 
// calling a function. So we must write mobileBill(60, 0, 1.5)
// Answer 2: The call mobileBill(60, , 1.5) gives a syntax error because C++ 
// does not allow an argument to be left empty between commas.
 
#include <iostream>
using namespace std;

double mobileBill(int minutes, int sms=0 , double data=0.0);   // (a)
void printLine(char ch = '-', int n = 30);                   // (b)

int main() {
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);
    cout << "Bill 4: " << mobileBill(60,0,1.5) << endl;   // (c)
    printLine('=');
    return 0;
}

double mobileBill(int minutes, int sms , double data) {    // (d)
    return 2*minutes+1*sms+150*data;                                      // (e)
}

void printLine(char ch,int n) {                   // (f)
    for (int i = 0;i < n;i++)                   // (g)
    cout << ch;                           
    cout << endl;
}


