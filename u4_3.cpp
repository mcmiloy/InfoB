#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort
#include <exception> // std::logic_error
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// a)
// greedy algorithm:

// given: a list of available coins,
//        an amount which should be represented with the available coins.

// 0. check available coins is not empty, else throw error
// 1. sort the list of coins from larger to smaller
// 2. iterate through list of coins until you find the first coin which is smaller than amount
// 3. append said coin into a vector storing the result
// 4. subtract the amount you stored in result from the previous amount to obtain new amount
// 5. repeat steps 2-4 until amount smaller or equal to zero
// 6. if amount is smaller than zero, it was not possible to represent amount with available coins: throw error
// 7. else return vector result

// help function for b)

int find_largest_smaller(vector<int> vec, int num){
    int i = 0;
    while(vec[i] > num){
        ++i;
    }
    return vec[i];
}

// help function for c)

int find_largest_smaller_recursive(vector<int> vec, int num){
    if(vec[0] <= num){
        return vec[0];
    } else {
        vec.erase( vec.begin() );
        return find_largest_smaller_recursive(vec, num);
    }
}

// b)

vector<int> change(vector<int> coin_types_v, int amount){
    if(coin_types_v.empty()) throw std::logic_error("invalid coin list");    
    std::sort(coin_types_v.begin(), coin_types_v.end(), [](int i, int j){return j<i;});

    vector<int> res;
    while(amount > 0){
        int next_coin = find_largest_smaller(coin_types_v, amount);
        res.push_back(next_coin);
        amount -= next_coin; // amount = amount - next_coin
    }
    return res;
}

// c)

vector<int> change_recursive(vector<int> coin_types_v, int amount){
    if(coin_types_v.empty()) throw std::logic_error("invalid coin list");        
    std::sort(coin_types_v.begin(), coin_types_v.end(), [](int i, int j){return j<i;});

    if(amount == 0){
        return vector<int> {};
    } else {
        int next_coin = find_largest_smaller_recursive(coin_types_v, amount);
        vector<int> pass = change_recursive(coin_types_v, amount - next_coin);
        pass.insert(pass.begin(), next_coin);
        return pass;
    }
}

// d)
// greedy ist nicht optimal:
// Muenzen: {1,15,25}, Geld: 30
// greedy: 25,1,1,1,1,1; optimal: 15, 15


int main(){
    cout << "Wie viel Geld brauchst du: ";
    int amount;
    cin >> amount;
    vector<int> coin_types = {1,2,5,10,20,50,100};
    cout << "Moechtest du dein Geld rekursiv bekommen(y/n): ";
    char yes_no;
    cin >> yes_no;
    vector<int> mychange;
    if(yes_no=='y'){
        mychange = change_recursive(coin_types, amount);
    } else {
            mychange = change(coin_types, amount);
    }

    for(auto item: mychange) cout << item << ", ";
        cout << endl;
    

    return 0;
}

// Beispiele: 

// emilio@emilios-pc:~/code/InfoB$ g++ -std=c++14 -Wall -Wextra -pedantic -Werror u4_3.cpp
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Wie viel Geld brauchst du: 42
// Moechtest du dein Geld rekursiv bekommen(y/n): n
// 20, 20, 2,
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Wie viel Geld brauchst du: 42
// Moechtest du dein Geld rekursiv bekommen(y/n): y
// 20, 20, 2,
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Wie viel Geld brauchst du: 99
// Moechtest du dein Geld rekursiv bekommen(y/n): n
// 50, 20, 20, 5, 2, 2,
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Wie viel Geld brauchst du: 99
// Moechtest du dein Geld rekursiv bekommen(y/n): y
// 50, 20, 20, 5, 2, 2,
// emilio@emilios-pc:~/code/InfoB$