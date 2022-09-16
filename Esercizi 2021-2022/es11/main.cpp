/*
    Es. File di testo.
    Matteo Manià, CL 3IA, data: 20/05/2022
    a) stampa dei dati relattivi a un elettrodomestico di cui viene fornito il codice;
    b) stampa dei dati relativi all'elettrodomestico di prezzo massimo appartenente a una determinata categoria fornita in input.
    c) stampa del prezzo medio dei frigoriferi.

*/

#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;


const int DIM = 4;  //fase di testing del codice
 ifstream fs;

struct elettrodomestici {
    int codice;
    string categoria;
    string descrizione;
    float importo;
};

void riempi(elettrodomestici scheda[DIM]) {
    for (int i = 0; i < DIM; i++) {
        fs >> scheda[i].codice;
        fs >> scheda[i].categoria;
        fs >> scheda[i].descrizione;
        fs >> scheda[i].importo;
    }
}

void visualizza(elettrodomestici scheda[DIM]) {
    for (int i = 0; i < DIM; i++) {
        cout << scheda[i].codice <<endl;
        cout << scheda[i].categoria <<endl;
        cout << scheda[i].descrizione <<endl;
        cout << scheda[i].importo <<endl;
    }
}

int cerca(elettrodomestici scheda[DIM], string temp1) {
    int pos, chiave;
    for(int i = 0; i < DIM; i++) {
        if(temp1 == scheda[i].categoria) {
            pos = i;
        }
    }
    return pos;
}

void facciolamedia(elettrodomestici scheda[DIM]) {
    float media = 0,somma = 0;
    int conta = 0;
    for (int i = 0; i < DIM; i++) {
        if (scheda[i].categoria == "frigorifero" || scheda[i].categoria == "Frigorifero") {
            somma = somma + scheda[i].importo;
            conta++;
        }
    }
    if (somma != 0) {
        media=somma/conta;
        cout << "\n\nla media e\'" << media << "\n\n";
    } else {
        cout << "la media e\' 0 o negativa. \n";
    }
}

int sottoprCerc(elettrodomestici scheda[DIM], string categoria) {
    int massimo;
    for (int i = 0; i < DIM; i++) {
        if (scheda[i].categoria == categoria) {
            if (i == 0) {
                massimo = scheda[i].importo;
            }
            if (scheda[i].importo > massimo) {
                massimo = scheda[i].importo;
            }
        }
    }
    return massimo;
}

int main() {
    string vettore[DIM];  //===
    elettrodomestici scheda[DIM];
    string temp1, categoria;
    int pos, massimo;
    float media;

    fs.open("file.txt", ios::in);
    if (!fs) {
        cout<<"Foglio di testo non trovato.\n";
    }
    else {
        riempi(scheda);
        visualizza(scheda);
        }
        /*for (int i = 0; i < DIM; i++) {
            cout << scheda[i].codice <<endl;
            cout << scheda[i].categoria <<endl;
            cout << scheda[i].descrizione <<endl;
            cout << scheda[i].importo <<endl;
        }*/
    fs.close();

    /*ricerca*/
    cout << "scrivi un nome di un prodotto, e io ti stampero\' le sue caratteristiche: \n";
    cin >> temp1;
    pos = cerca(scheda, temp1);
    cout << "\nadesso cerco....\n";
        cout << scheda[pos].codice<<endl;
        cout << scheda[pos].descrizione<<endl;
        cout << scheda[pos].importo<<endl;

    /*prezzo massimo di una categoria in input;*/
    cout <<"\n\nInserisci una categoria e io ti diro\' il prezzo massimo del prodotto relativa ad essa:\n";
    cin >> categoria;
    massimo = sottoprCerc(scheda, categoria);
    cout << "Il prezzo massimo per la categoria e\' " << massimo;

    /*media frigoriferi*/
    facciolamedia(scheda);

    return 0;
}
