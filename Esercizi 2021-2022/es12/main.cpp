/*
        Classe 3IA
        Maggio 2022

        Esercizio struct
        Per lo sportello di accettazione di un ospedale si desidera avere un programma che registri tutti i ricoveri dei pazienti.
        I dati relativi a tali pazienti sono memorizzati in una tabella contenente per ogni elemento:
        cognome
        nome
        data di accettazione
        data di dimissioni
        scrivi un programma che esegua queste operazioni:
        a.	leggere e stampare i dati dei pazienti da un file di testo
        b.	stampa l'elenco di tutti i pazienti dimessi in una determinata data fornita in input;
        c.	registrazione di una dimissione avendo in input il cognome del paziente da dimettere e la data attuale (se il paziente non è presente segnalare l'errore);
        d.	registrazione di un'accettazione di un paziente con immissione dei dati relativi nella prima posizione vuota.
*/
#include <iostream>
#include <fstream>

using namespace std;


const int DIM = 4;
ifstream fs;

struct s_data {
    int gg, mm, aa;
};

struct s_paziente {
    string cognome;
    string nome;
    s_data dataAccettazione;
    s_data dataDimissioni;
};

void popolaArrayPazienti(s_paziente p[]) {
    for (int i = 0; i < DIM; i++) {
        fs >> p[i].nome;
        fs >> p[i].cognome;
        fs >> p[i].dataAccettazione.gg;
        fs >> p[i].dataAccettazione.mm;
        fs >> p[i].dataAccettazione.aa;
        fs >> p[i].dataDimissioni.gg;
        fs >> p[i].dataDimissioni.mm;
        fs >> p[i].dataDimissioni.aa;
    }
}

void stampaArrayPazienti(s_paziente p[]) {
    for(int i = 0; i < DIM; i++) {
        cout << p[i].nome <<"\t"<< p[i].cognome <<"\t";
        cout << p[i].dataAccettazione.gg << "\/" << p[i].dataAccettazione.mm << "\/" << p[i].dataAccettazione.aa << "\t";
        cout << p[i].dataDimissioni.gg << "\/" << p[i].dataDimissioni.mm << "\/" << p[i].dataDimissioni.aa << endl;
    }
}

void stampaPazientiDimessi(s_paziente p[], int gg, int mm, int aa) {
    for (int i = 0; i < DIM; i++)
        if (p[i].dataDimissioni.gg == gg && p[i].dataDimissioni.mm == mm && p[i].dataDimissioni.aa == aa)
            cout << p[i].cognome << " " << p[i].nome << endl;
}

int main() {
    s_paziente pazienti[DIM];
    int ggDimissioni, mmDimissioni, aaDimissioni;

    fs.open("pazienti.txt");  //FILE TESTO DA CREARE CON I NOMI;
    if (!fs)
        cout << "FILE NON TROVATO";
    else {
        popolaArrayPazienti(pazienti);
        stampaArrayPazienti(pazienti);
        cout << "Inserisci una data di dimissioni: giorno,mese, anno: ";
        cin >> ggDimissioni >> mmDimissioni >> aaDimissioni;
        stampaPazientiDimessi(pazienti, ggDimissioni, mmDimissioni, aaDimissioni);
    }
    fs.close();
    //commentino
    return 0;
}
