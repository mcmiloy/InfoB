#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;


bool ex_1_1(vector<int> li){
    std::sort(li.begin(), li.end());
    for(auto it = li.begin(); it != (li.end()-1); ++it){
        if(*it - *(it + 1) >= -10) return true;
    }
    return false;
}

bool ex_1_2(vector<int> l1, vector<int> l2, vector<int> l3){
    std::sort(l1.begin(), l1.end());
    std::sort(l2.begin(), l2.end());
    std::sort(l3.begin(), l3.end());
    for(auto it1 = l1.begin(); it1 != l1.end(); ++it1){
        for(auto it2 = l2.begin(); it2 != l2.end(); ++it2){
            if((*l3.begin()) + (*it2) > -(*it1)){
                cout << "broke out: " << *it2 << " + " << *(l3.begin()) << " > " << -(*it1) << endl;
                return false;
            }

            for(auto it3 = l3.begin(); it3 != l3.end(); ++it3){
                if((*it3) + (*it2) == -(*it1)) return true;
                else if((*it3) + (*it2) > -(*it1)) break;
            }
        }
    }
    return false;
}


int main(){
    vector<int> vec = {2,14,15};
    cout << (ex_1_1(vec) ? "true" : "false") << endl;
    vec = {2, 14, 35};
    cout << (ex_1_1(vec) ? "true" : "false") << endl;
    


    vector<int> vec1 = {0,2};
    vector<int> vec2 = {2, 5};
    vector<int> vec3 = {1, 5};
    cout << ex_1_2(vec1, vec2, vec3) << endl;
}