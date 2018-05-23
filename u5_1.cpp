#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;


int myabs(int num){
    return num >= 0 ? num : -num;
}

bool ex_1_1_naive(vector<int> li){
    std::sort(li.begin(), li.end());
    for(auto it = li.begin(); it != li.end(); ++it){
        cout << *it << " " << *(it + 1) << endl;
        if(*it - *(it + 1) < -10) continue;
        else return true;
    }
}

bool ex_1_2_naive(vector<int> l1, vector<int> l2, vector<int> l3){
    for(auto it1 = l1.begin(); it1 != l1.end(); ++it1){
        for(auto it2 = l2.begin(); it2 != l2.end(); ++it2){
            for(auto it3 = l3.begin(); it3 != l3.end(); ++it3){
                if(*it1 + *it2 + *it3 == 0) return true;
            }
        }
    }
}


int main(){
    vector<int> vec1_1 = {-20,-2,0,6,25,121};
    cout << ex_1_1_naive(vec1_1) << endl;
}