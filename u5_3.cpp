#include <iostream>
#include <vector>
#include <cmath>
using std::floor;
using std::ceil;
using std::pow;
using std::sqrt;

using std::vector;
using std::cout;
using std::cin;
using std::endl;


int bin_search(vector<double> array, int k, int left, int right){
	if (left >= right)
        throw std::logic_error("wrong bounds");
	int mitte = left + (right-left) / 2;
	if (array[mitte] <= k && k < array[mitte + 1])
		return mitte;
	else if (k < array[mitte]) 
		return bin_search(array, k, left, mitte);
	else
		return bin_search(array, k, mitte+1, right);
}

int binary_search(vector<double> array, int k, int size) {
	return bin_search(array, k, 0, size);
}

double not_so_effective_sqrt(double x, double accuracy = 0.001){ // 3(a) & 3(b)
    if(x <= 1) throw std::logic_error("Input must be larger than one!");
    const int size = floor((x-1)/accuracy - 1);
    vector<double> options; // I tried using arrays but -pedantic flag kept screwing me over...
    for(int i=0; i<size; ++i){
        options.push_back(pow(1 + (i+1) * accuracy, 2));
    }

    int index = binary_search(options, x, size);

    return 1 + (index + 1) * accuracy;
}


double rough_estimation_sqrt(double n){
    int i = 0;
    while(n >= 100){
        i += 2;
        n /= 100;
    }
    if(n < 10){
        return 2*pow(10, i/2);
    } else {
        return 6*pow(10,i/2);
    }
}

double baybylonian_method(double n, double accuracy = 0.001){
    double x = rough_estimation_sqrt(n);
    double last;
    do{
        last = x;
        x = 0.5 * (x + n/x);
    } while(floor(last*1/accuracy) != floor(x*1/accuracy));

    return x;
}


int main(){

    cout << "sqrt of 2 is: \n";
    cout << "my algorithm: " << not_so_effective_sqrt(2) << endl;
    cout << "std library algorithm: " << std::sqrt(2) << endl;
    cout << "babylonain method: " << baybylonian_method(2) << endl;

    cout << "\nsqrt of 49 is: \n";
    cout << "my algorithm: " << not_so_effective_sqrt(49) << endl;
    cout << "std library algorithm: " << std::sqrt(49) << endl;
    cout << "babylonain method: " << baybylonian_method(49) << endl;

    cout << "\nenter accuracy (if you choose a very high accuracy be prepared to suffer a stack overflow...): ";
    double accuracy;
    cin >> accuracy;
    cout << "number you want to know the sqaure root of: ";
    double number;
    cin >> number;

    cout << "sqrt of " << number << " is: \n";
    cout << "my algorithm: " << not_so_effective_sqrt(number, accuracy) << endl;
    cout << "std library algorithm: " << std::sqrt(number) << endl;
    cout << "babylonain method: " << baybylonian_method(number, accuracy) << endl;

}

// Example: 

// emilio@emilios-XPS-13:~/code/InfoB$ g++ -std=c++14 -Wall -Wextra -Werror -pedantic u5_3.cpp
// emilio@emilios-XPS-13:~/code/InfoB$ ./a.out
// sqrt of 2 is:
// my algorithm: 1.414
// std library algorithm: 1.41421
// babylonain method: 1.41421

// sqrt of 49 is:
// my algorithm: 7
// std library algorithm: 7
// babylonain method: 7

// enter accuracy (if you choose a very high accuracy be prepared to suffer a stack overflow...): 0.05
// number you want to know the sqaure root of: 12
// sqrt of 12 is:
// my algorithm: 3.45
// std library algorithm: 3.4641
// babylonain method: 3.4641
// emilio@emilios-XPS-13:~/code/InfoB$