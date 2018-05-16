#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// a)
// call (pass) by reference: Die Argumente werden per Referenz uebergeben,
// d.h. die Funktion bekommt die Objekte selbst. Beispiel:

vector<int> first_to_zero(vector<int> &vec){
    vec[0] = 0; // das eingegebene Objekt selbst wird veraendert. 
    return vec;
}

// call (pass) by value: Die Funktion bekommt eine Kopie der Argumente,
// nicht die Objekte selbst. Beispiel:
string unchanged_string(string str){
    str = "Ich veraendere eine Kopie des eingegebenen Objekts,\
           nicht das Objekt selbst.";
    return str;
}

// call (pass) by name: Wird in C++ nicht unterstuetzt.
// Es wird nur der Name eines Objekts als Argument angeben.

// b)
// call by value
// void f(int x, int y)

// main cout 1: a = 2, b = 4
// f cout 1: x = 2, y = 4
// f cout 2: x = 6, y = 12 | Die Berechn. von y erfolgt mit bereits geandertem x
// main cout 2: a = 2, b = 4 | call by value: urspruenglichen Objekte unberuhert

// call by reference
// void f(int &x, int &y)

// ... alles gleich
// main cout 2: a = 6, b = 12 | call by reference: y ist ein Alias fuer b.
//                              Wenn man y aendert, dann auch b.

// c)
// call by value
// f cout 1: Hier ist f
// main cout 1: z = 15 | f() -> 5; g(5) = 5 + 10 = 15; z = g(5) = 15;

// call by name: ???

int main(){
    vector<int> myvec = {1,2,3,4,5};
    first_to_zero(myvec);
    cout << myvec[0] << endl; // -> 0

    string mystring = "mystring";
    unchanged_string(mystring);
    cout << mystring << endl; // -> "mystring"

    return 0;
}