#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

auto iparent = [](int i){ return std::floor((i-1)/2); };
auto iLeftChild = [](int i){ return 2*i + 1; };
auto iRightChild = [](int i){ return 2*i + 2; };

void swap(vector<int> &inpList, int val1, int val2){
    int temp = inpList[val1];
    inpList[val1] = inpList[val2];
    inpList[val2] = temp;
}


void heapify(vector<int> inpList){}

vector<int> heapsort(vector<int> inpList){
    heapify(inpList);
    int end = inpList.size() - 1;
    while(end>0){

    }
}




int main(){


    return 0;
}