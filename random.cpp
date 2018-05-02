#include <iostream>
#include <stdlib.h> // Hier befindet sich die Funktion srand
#include <time.h>   // Hier befindet sich die Funktion time

using namespace std;

int main() {
    
    srand(time(NULL));
    
    cout << "Dies ist eine Zufallszahl aus dem Intervall [0,9]: ";
    cout << random() % 10 << endl;
    
}
