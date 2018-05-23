#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;


// a)
int ind_of_max_recursive(int a[], int size){
    if(size==1) return 0;
    
    int index = ind_of_max_recursive(a, size-1);
    if(a[size-1] >= a[index]) {
        return size-1;
    } else {
        return index;
    }
}

void selectsort_recursive(int a[], int size){
    if(size>=2){
        int max_in_a = ind_of_max_recursive(a, size);
        int temp = a[max_in_a];
        a[max_in_a] = a[size-1];
        a[size-1] = temp;
        selectsort_recursive(a, size-1);
    }
}


// b)
double sprod_rec(double a[], double b[], int size){
    if(size==0){
        return 0;
    } else {
        return a[size-1] * b[size-1] + sprod_rec(a, b, size-1);
    }
}


double sprod_it(double a[], double b[], int size){
    double res = 0;
    for(int i=0; i<size; ++i){
        res += (a[i] * b[i]);
    }
    return res;
}



int main(){
    int ary[10] = {9,10,8,7,6,5,4,3,2,1};
    selectsort_recursive(ary, 10);
    for(auto item: ary) cout << item << " ";
    cout << endl;


    double ary1[3] = {1,2,3};
    double ary2[3] = {1,2,3};
    cout << sprod_rec(ary1, ary2, 3) << endl;
    cout << sprod_it(ary1, ary2, 3) << endl;
    
    return 0;
}