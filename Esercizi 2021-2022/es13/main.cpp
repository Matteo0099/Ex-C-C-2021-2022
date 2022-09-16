  /*
Matteo Manià, CL 3IA, 25.05.2022
    Consegna:
        Di un prodotto sono forniti i quantitativi venduti a n(5) clienti:
        in una tabella sono presenti:
        -il codice del cliente;
        -il cognome del cliente;
        -la quantità venduta;
        -la data della vendita;
    Scrivere un programma che:
        -legge i dati da un file di testo e li visualizza a video;
        -calcola e stampa la media delle quantità vendute;
        -trova il cliente a cui è stata venduta la quantità massima-->stampa il suo cognome;
        -dato un cognome, stampa codice e quantità venduta;
        -data la data di vendita, visualizza i cognomi dei clienti;
        -memorizza le quantità vendute in un array di n elementi e lo ordina in modo crescente;
    --------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#define DIM 5   //Dimensione vettore/struct;

using namespace std;


//Dichiarazione dell'input file stream
ifstream fs;

//Struct per le date:
struct m_data {
    int gg, mm, aa;
};

//Tabella per il cliente:
struct tabella {
    int codice;
    string cognome;
    int quantita;
    m_data scheda;
};

void input(tabella prodotti[]) {
    for (int i = 0; i < DIM; i++) {
        //leggo i dati del file:
        fs >> prodotti[i].codice;
        fs >> prodotti[i].cognome;
        fs >> prodotti[i].quantita;
        fs >> prodotti[i].scheda.gg;
        fs >> prodotti[i].scheda.mm;
        fs >> prodotti[i].scheda.aa;
    }
}

void output(tabella prodotti[]) {
    for (int i = 0; i < DIM; i++) {
        //stampo i dati del file:
        cout << "codice cliente: " << prodotti[i].codice << "\t";
        cout << "cognome:" << prodotti[i].cognome << "\t";
        cout << "quantita\':" << prodotti[i].quantita << "\t";
        cout << "data: " << prodotti[i].scheda.gg << "\/" << prodotti[i].scheda.mm << "\/" << prodotti[i].scheda.aa << endl;
    }
}
float calcoloMedia(tabella prodotti[]) {
    int c;         //contatore;
    int somma = 0;  //per la media;
    float media = 0; //media
    for (int i = 0; i < DIM; i++) {
        //controllo preciso;
        if (prodotti[i].quantita != 0) {
            somma = somma + prodotti[i].quantita;
            c++;
        }
    }
    //Media
    media = somma / c;

    return media; //Stampo nel main()
}

int ricerca (tabella prodotti[]) {
    int massimo, pos;  //ricerca massimo;
    for (int i = 0; i < DIM; i++) {
        //prima iterazione
        if (i == 0)
            massimo = prodotti[i].quantita;
        //se l'elemento successivo è maggiore:
        if (prodotti[i].quantita > massimo) {
            massimo = prodotti[i].quantita;
            pos = i; //posizione, quindi posso trovare tutti i dati.
        }
    }

    return pos;  //Posizione
}

int ricercaDati(tabella prodotti[], string cognome) {
    int iPos = 0;
    for (int i = 0; i < DIM; i++) {
        //Se corrisponde, ritorna la posizione;
        if (prodotti[i].cognome == cognome)
            iPos = i;
    }
    return iPos;  //Posizione
}

int ricercaCognome(tabella prodotti[], int gg, int mm, int aa) {
    int dataC;
    for (int i = 0; i < DIM; i++) {
        //Controllo
        if (gg == prodotti[i].scheda.gg && mm == prodotti[i].scheda.mm && aa == prodotti[i].scheda.aa)
            dataC = i;  //Pos
    }
    return dataC;  //Posizione
}

void memorizza(tabella prodotti[], int vettore[]) {
    for (int i = 0; i < DIM; i++)
        //Memorizzo nel vettore le quantità presenti:
        vettore[i] = prodotti[i].quantita;
}

void ordinamento(tabella prodotti[], int vettore[]) {
    int temp;
    bool scambio = false;
    do {
        scambio = false;
        //ordinamento crescente
        for (int i = 0; i < DIM-1; i++) {
            if(vettore[i] > vettore[i+1]) {
                temp = vettore[i];
                vettore[i] = vettore[i+1];
                vettore[i+1] = temp;
                scambio = true;
            }
        }
    } while (scambio == true);
}

void stampaOrdinato(int vettore[]) {
    for (int i = 0; i < DIM; i++)
        cout << " " << vettore[i];
}

int main() {
    tabella prodotti[DIM];  //Struct (dichiarazione);
    float media;            //Media
    int pos, iPos;          //Ricerca massimo;
    string cognome;         //Ricerca dati in base al cognome;
    int gg, mm, aa, dataC;  //Ricerca data la vendita;
    int vettore[DIM];       //Ordinamento

    //Lettura del file;
    cout << "Leggo i dati da un file di testo: \n";
    fs.open("file.txt");
    if(!fs)  //controllo per il file.txt:
        cout << "file non trovato.\n";
    //se è presente lo esegue:
    else {
        input(prodotti);
        output(prodotti);
    }

    //calcolo media;
    media = calcoloMedia(prodotti);
    //output media:
    cout << "\nla media delle quantita\' vendute e\': " << media << "\n";

    //ricerca del cliente;
    cout << "\nRicerchero\' la quantita\' massima a cui e\' stata venduta al cliente corrispettivo:";
    pos = ricerca(prodotti);
    //stampo il cognome corrispettivo alla quantità massima:
    cout << "\nil cognome del cliente con la quantita\' massima e\': ";
    cout << prodotti[pos].cognome;

    //ricerca
    cout << "\n\nInserisci il cognome, e ti diro\' il suo codice e la quantita\' corrispettiva: ";
    cin >> cognome;
    iPos = ricercaDati(prodotti, cognome);
    //Stampo il codice/quantità:
    cout << "stampo codice e quantita\': \n";
    cout << " " << prodotti[iPos].codice <<"\t";
    cout << prodotti[iPos].quantita;

    //ricerca cognomi, data la vendita;
    cout << "\n\nInserisci la data della vendita, e ti mostrero\' il cognome del compratore:\n";
    cin >> gg >> mm >> aa;
    dataC = ricercaCognome(prodotti, gg, mm, aa);
    //Stampo il cognome del cliente:
    cout << "stampo cognome del cliente:  ";
    cout << prodotti[dataC].cognome;

    //Ordinamento
    cout << "\n\nAdesso ordino l'elenco delle quantita\' vendute in ordine crescente: \n";
    memorizza(prodotti, vettore);
    ordinamento(prodotti, vettore);
    cout << "stampo in ordine crescente: \n";
    stampaOrdinato(vettore);
    cout << "\n";

    fs.close();  //chiudo il file di testo;

    return 0;
}
