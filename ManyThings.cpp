#include <iostream>
using namespace std;

int main() {
	
	int zahl = 29/2;
	
	cout << zahl << endl;
	
	cout << (3+5*7==zahl-2) << endl;
	
	zahl = 40;
	
	cout << (3+5*7==zahl-2) << endl;
	
	cout << "Inf B " << (50 * zahl + 18) << endl;
	
	cout << (true && (zahl <= 42)) << endl;
	
	cout << (true + 7) << endl;
	
	zahl++;
	
	if (zahl - 10 <= 30) {
		cout << "Korrekt" << endl;
	} else {
		cout << "Falsch" << endl;
	}
	
	cout << (zahl + true
	
	- 7) << endl;
	
	int anzahl;
	
	cout << "Geben Sie eine Zahl ein: ";
	
	cin >> anzahl;
	
	for (int i = 0; i < anzahl; i++) {
		cout << i*i << endl;
	}
	
	return 0;
}
