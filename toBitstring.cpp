#include <iostream>
#include <string>

std::string toBin(int input); // Obsolete

std::string toSys(int input, int sys);


int main(){
    int input_num;
    int input_sys;
    std::cout << "Geben sie eine nicht-negative Zahl ein: ";
    std::cin >> input_num;
    std::cout << "In welches Zahlensystem soll umgerechnet werden?(2-16): ";
    std::cin >> input_sys;

    std::cout << "Die " << input_sys << "-Darstellung der " << input_num << " ist: " << toSys(input_num, input_sys) << "\n";

    return 0;
}

std::string toBin(int input){
    std::string res;
    while(input > 0){
        res.insert(0, std::to_string(input%2));
        input /= 2;
    }
    return res;
}

std::string toSys(int input, int sys){
    std::string res;
    char avail_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(input > 0){
        res.insert(0, std::string(1, avail_chars[input%sys]));
        input /= sys;
    }
    return res;
}

// Beispiele:

// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Geben sie eine nicht-negative Zahl ein: 12
// In welches Zahlensystem soll umgerechnet werden?(2-16): 2
// Die 2-Darstellung der 12 ist: 1100
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Geben sie eine nicht-negative Zahl ein: 12
// In welches Zahlensystem soll umgerechnet werden?(2-16): 16
// Die 16-Darstellung der 12 ist: C
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Geben sie eine nicht-negative Zahl ein: 16
// In welches Zahlensystem soll umgerechnet werden?(2-16): 2
// Die 2-Darstellung der 16 ist: 10000
// emilio@emilios-pc:~/code/InfoB$ ./a.out
// Geben sie eine nicht-negative Zahl ein: 16
// In welches Zahlensystem soll umgerechnet werden?(2-16): 10
// Die 10-Darstellung der 16 ist: 16
