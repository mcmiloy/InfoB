#include <iostream>
using namespace std;

int fibo_rekursiv(int eingabe);

int main(){
    int zahl;
    cout<<"Geben Sie eine Zahl ein: ";
    cin >>zahl;
    long a=0;
    long b=1;

    for(int i=zahl;i>0;i--){
        b=a+b;
        cout<<a<< endl;
        a=b-a;
    }


    cout << "\n" << fibo_rekursiv(5) << endl;

    return 0;
}

int fibo_rekursiv(int eingabe){
    if(eingabe==0){
        return 0;
    }
    if(eingabe==1){
        return 1;
    }
    return fibo_rekursiv(eingabe-1) + fibo_rekursiv(eingabe-2);
}

// ein neues commentar