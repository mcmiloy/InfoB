#include <iostream>
using namespace std;


int mega = 2;
int ultra = 4;

int f(int ultra) {
    cout << mega << endl;
    cout << ultra << endl;
    return ultra*ultra;
}
int main() {
    int mega = 7;
    int ultra = f(::mega);
    int iiih;
    for (int iiih = 0; iiih<ultra; iiih++) {
        int ultra = mega-1;
        {ultra = f(iiih);
        ::ultra = 0;
        ::mega++;
        mega = mega*::mega*::mega*::mega*::mega*::mega;
        int mega = ultra;}
        cout << mega << endl;
        cout << ultra << endl;
    }
    cout << iiih << endl;
}
