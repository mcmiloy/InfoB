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

auto iparent = [](int i){ return std::floor((i-1)/2); };
auto iLeftChild = [](int i){ return 2*i + 1; };

void swap(vector<int> &inpList, int ind1, int ind2){
    int temp = inpList[ind1];
    inpList[ind1] = inpList[ind2];
    inpList[ind2] = temp;
}

void siftDown(vector<int> &inpList, int start, int end) {
    int root = start;
    while(iLeftChild(root) <= end){
        int child = iLeftChild(root);
        int swap_ind = root;
        if(inpList[root] < inpList[child]){
            swap_ind = child;
        }
        if(inpList[swap_ind] < inpList[child+1] && child+1 <= end){
            swap_ind = child + 1;
        }
        if (swap_ind == root){
            return;
        }
        swap(inpList, root, swap_ind);
        root = swap_ind;
    }
}

void heapify(vector<int> &inpList){
    int start = iparent(inpList.size() -1);
    while(start >= 0){
        siftDown(inpList, start, inpList.size()-1);
        --start;
    }
}

void heapsort(vector<int> &inpList){
    // create max heap
    heapify(inpList);
    // end = last index that isn't sorted yet
    int end = inpList.size() - 1;
    while(end>0){
        swap(inpList, 0, end);
        --end;
        // restore max-heap property
        siftDown(inpList, 0, end);
    }
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


    heapsort(myvec);

    for(auto item: myvec) { cout << item << " "; }
    cout << endl;


    return 0;
}