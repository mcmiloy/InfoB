#include <iostream>
#include <stdlib.h> // Hier befindet sich die Funktion srand
#include <time.h>   // Hier befindet sich die Funktion time
using namespace std;

int main(){
    int a;
    cout <<"Schreiben Sie eine Zahl: ";
    cin >> a;
    int b=1;
    int c=0;
 


    for(;true;){
        c=a-b;
        b=b*2;
        if(c<0){
            b=b/2;
            a=a-b;
            cout <<"1";
            break;
        }
    }
    for(;true;){
        b=b/2;                
        if(b<1){ 
            break;
        }
        if(b<=a){
            cout <<"1";
            a=a-b;
        }else if(b>a){
            cout <<"0";
        }
    }

    return 10;
}