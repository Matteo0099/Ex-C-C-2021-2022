#include <iostream>
#include <cstring>

using namespace std;

void input(string s1, string s2, string s3) {
  string pos;
  string root;
  string dominio_root;
  string domain;
  int utente;
  
  cout<<"inserisci nome: ";
  getline(cin, s1);
  cout<<"inserisci cognome: ";
  getline(cin, s2);
  cout<<"inserisci la mail: ";
  getline(cin, s3);

  utente = s3.find("@");
  root = s3.substr(0, utente);

  dominio_root = s3.substr(utente+1, s3.size());
  utente = dominio_root.find(".");
  cout<<"\n"<<utente<<endl;
  
  domain = dominio_root.substr(0, utente);
  root = dominio_root.substr(utente+1, 3);

  cout<<"numero utente = "<<utente<<endl;
  cout<<"dominio = "<<domain<<endl;
  cout<<"root = "<<root;
}

int main() {
  string s1, s2, s3;
  string pos, root;

  input(s1, s2, s3);
  
  return 0;
}
