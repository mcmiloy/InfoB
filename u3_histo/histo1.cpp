#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "Wie lang darf der Text sein? ";
	cin >> size;
	char* text = new char[size];
	cin >> text;
	cout << size << endl;
}
