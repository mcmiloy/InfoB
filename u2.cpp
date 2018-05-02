#include <iostream>
#include <stdlib.h> // Hier befindet sich die Funktion srand
#include <time.h>   // Hier befindet sich die Funktion time

using namespace std;

int main(){
    srand(time(NULL));
    int a;
    int b=random() % 100;

    for (int i=1;true;i++){
        cout <<"Schreiben Sie eine Zahl: ";
        cin >> a;
        if(a<b){
            cout <<"Zu niedrig\n";
        }else if(a>b) {
            cout <<"Zu hoch" << endl;
        }else{
            cout << "Richtig. Versuche: "<< i << endl;  
            break; 
        }
    }

    return 0;
}