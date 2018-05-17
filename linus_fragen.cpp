#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_array(int *a, int size){
    for(int i=0; i<size; ++i) cout << *(a+i) << " ";
}

int factorial_iterativ(int n){
    int ret = 1;
    while(n>=2){
        ret *= n;
        n--;
    }
    return ret;
}

int factorial_rekursiv(int n){
    if(n <= 1) {
        return 1;
    } else {
        return n*factorial_rekursiv(n-1);
    }
}

int main(){
    int a = 42;
    int *ptr = &a;
    *ptr = 10;

    cout << a << endl;

    int myarray[5] = {1,2,3,4,5};
    print_array(myarray, 5);
    cout << endl;

    cout << factorial_iterativ(5) << endl;
    cout << factorial_rekursiv(5) << endl;

    return 0;
}