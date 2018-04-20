#include <iostream>
using namespace std;

int main() {
  int my_input;
  cout << "Bitte int angeben: ";
  
  cin >> my_input;

  if(!(my_input % 2)){
    cout << "gerade" << endl;
  } else {
    cout << "ungerade" << endl;
  }

  return 0;
}






