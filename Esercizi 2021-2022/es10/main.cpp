#include<iostream>

using namespace std;


const int n=3;

int main() {

  int i;

  struct str1
  {
    char c[80];
    int h;
  } T[n];

  for(i=0; i < n; i++)
  {
    cout << "nome:";
    cin >> T[i].c;
    cout << "numero:";
    cin >> T[i].h;
    cout << "\n\n";
  }

  for(i=0; i < n; i++)
    cout << T[i].c << "\t" << T[i].h << endl;
}
