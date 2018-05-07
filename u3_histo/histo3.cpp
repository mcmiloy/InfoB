#include <iostream>
using namespace std;

struct eintrag {
	char symbol; // ein Zeichen
	unsigned int amount; // Häufigkeit des Zeichens
};

int main() {
	
	int size = 23; // Beispiel-Größe!
	char text[size] = "diesisteinbeispieltext"; // Beispiel-Text!
	int differentChars = 10; // Beispiel-Anzahl!
	
	// Hier muss das Programm geschrieben werden
	
	// eintrag * histogramm = new eintrag[...]; ?
	// ODER
	// eintrag histogramm[...]; ?
	
	cout << differentChars << endl;
} 
