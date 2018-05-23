#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void quicksort(vector<int> &inpList);
void quicksort_helper(vector<int> &inpList, int lo, int hi);
int qs_partition(vector<int> &inpList, int lo, int hi);

void swap(vector<int> &inpList, int ind1, int ind2){
    int temp = inpList[ind1];
    inpList[ind1] = inpList[ind2];
    inpList[ind2] = temp;
}

void quicksort(vector<int> &inpList){
    quicksort_helper(inpList, 0, inpList.size()-1);
}

void quicksort_helper(vector<int> &inpList, int lo, int hi){
    int p = qs_partition(inpList, lo, hi);
    quicksort_helper(inpList, lo, p-1);
    quicksort_helper(inpList, p+1, hi);
}


int qs_partition(vector<int> &inpList, int lo, int hi){
    int pivot = inpList[hi];
    int i = lo - 1;
    for(int j = lo; j<hi; ++j){
        if(inpList[j]<pivot){
            ++i;
            swap(inpList, i, j);
        }
    }
    swap(inpList, i+1, hi);
    return i+1;

}

int main(){
    string inp;
    getline(cin, inp);
    vector<int> myvec;
    string temp;
    for(auto c: inp){
        if(!isspace(c)){
            temp.push_back(c);
        } else {
            myvec.push_back(std::stoi(temp));
            temp.clear();
        }
    }


    quicksort(myvec);

    for(auto item: myvec) { cout << item << " "; }
    cout << endl;


    return 0;
}