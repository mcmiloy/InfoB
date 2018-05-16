#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    // cout << char(65) << endl; //This is an 'A'
    // cout << char(122) << endl; //This is a 'Z'
    // cout << char(97) << endl; //This is an 'a'
    // cout << char(122) << endl; //This is a 'z'

    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
    "Vivamus in ultricies erat, nec volutpat lacus.";

    std::map<char, int> chars;
    for(char c=65; c<91; ++c) // I did the capital letters as well...
        chars[c] = 0;
    for(char c=97; c<123; ++c)
        chars[c] = 0;

    for(auto textit = text.begin(); textit != text.end(); ++textit){
        auto it = chars.find(*textit);
        if(it != chars.end())
            ++(it->second);
    }

    for(auto it = chars.begin(); it != chars.end(); ++it)
        cout << it->first << ": " << it->second << endl;

    std::cout << char(90) << std::endl;
    
}