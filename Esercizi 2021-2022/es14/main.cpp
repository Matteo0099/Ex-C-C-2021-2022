/*
    struct nei sottoprogrammi/e non;
*/

#include <iostream>

using namespace std;


const int MAX = 3;   //valore che si può cambiare

 struct tabella_analisi {
    string nome;
    string indirizzo;
    int eta;
    float voti;
  }MarioRossi;

float sottpr1 (struct tabella_analisi *tabella) {
  float media=0; float somma=0; int temp;
    cout<<"inserisci 3 voti per Mario Rossi: \n";
    for (int i=0; i<MAX; i++) {
      cin >> MarioRossi.voti;
      somma=somma+MarioRossi.voti;
      temp++;
    }
    media=somma/MAX;
    cout<<"media = "<<media<<endl;

  return media;
}


int main (){
  struct tabella_analisi tabella[4][4];
  float mediavoti;

  cout << "inserisci il nome: ";
  getline(cin, MarioRossi.nome);  //ignora gli spazi(con più nomi);
  cout << "inserisci l'indirizzo: ";
  getline(cin, MarioRossi.indirizzo);
  cout << "inserisci l'eta\': ";
  cin >> MarioRossi.eta;

  mediavoti = sottpr1(&tabella[3][3]);

  return 0;
}
