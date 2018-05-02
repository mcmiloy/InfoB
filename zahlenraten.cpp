#include <iostream>
#include <stdlib.h> // Hier befindet sich die Funktion srand
#include <time.h>   // Hier befindet sich die Funktion time


int main(){
    srand(time(NULL));
    int randomnum = random() % 100;

    std::cout << "Herzlich Wiklommen beim Zahlenraten. :-)\n";

    int guesses;

    for(int i=0; true; i++){
        std::cout << "Geben sie eine Zahl ein: ";
        int user_input;
        std::cin >> user_input;
        if(user_input == randomnum){
            guesses = i + 1;
            break;
        } else if(user_input < randomnum){
            std::cout << "Die gesuchte Zahl ist groesser\n";
        } else {
            std::cout << "Die gesuchte Zahl ist kleiner\n";
        }
    }
    std::cout << "Sie haben nur " << guesses << " Versuche benoetigt. Das ist Super!\n";

    return 0;
}