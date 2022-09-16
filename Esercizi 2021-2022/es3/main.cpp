/*
Matteo Manià, CL 3IA
I prodotti trattati da una parafarmacia sono memorizzati in 5 vettori paralleli di 5 elementi:
-	codice, codice numerico di ciascun prodotto;
-	nome, nome del prodotto;
-	casa, casa produttrice;
-	classe, tipologia di prodotto (medicinale “M”, cosmetico “C”, prodotto dietetico “D”, ecc.)
-	prezzo, prezzo dei prodotti.

Facendo uso di sottoprogrammi, sviluppare le seguenti richieste:
-	popolare i vettori da tastiera e visualizzarli in questo modo:
        codice1 nome1 casa1 classe1 prezzo1
        codice2 nome2 casa2 classe2 prezzo2 ...
-	aggiornare i prezzi, che hanno subito un aumento del 5%;
-	stampare il nome del prodotto che ha prezzo massimo;
-	calcolare la media dei prezzi di una certa categoria fornita in input;
-	cercare il prezzo e la classe di un prodotto dato il codice in input (ricerca sequenziale);
-	ordinare il vettore prezzi in modo decrescente.
*/

#include <cstdlib>
#include <iostream>

using namespace std;


const int DIM = 3;  //costante, che si può cambiare in base al numero di prodotti che si vuole inserire

void input(int codice[], string casa[], string classe[], string nome[], float prezzo[]) {

    for (int i = 0; i<DIM; i++) {
        cin >> codice[i] >> casa[i] >> classe[i] >> nome[i] >> prezzo[i];
        cout << endl;
    }
    cout << "\n\n";
}

void visualizza(int codice[], string casa[], string classe[], string nome[], float prezzo[]) {
    cout << "codice casa classe nome prezzo\n";
    for (int i = 0; i<DIM; i++) {
        cout << codice[i] <<"  "<< casa[i] <<"  "<< classe[i] <<"  "<< nome[i] <<"  "<< prezzo[i];
        cout << endl;
    }
}

void aumento(float prezzo[]) {
    for (int i = 0; i<DIM; i++) {
        prezzo[i] = prezzo[i] + prezzo[i]*5/100;
    }
}

float prezzo_max_nome(float prezzo[]) {
    int indice_massimo = 0;
    float prezzo_max;

    for (int i = 0; i<DIM; i++) {
        if (i == 0) {
            prezzo_max = 0;
            indice_massimo = 0;
        }
        if (prezzo[i] > prezzo_max) {
            indice_massimo = i;
        }
    }

    return indice_massimo;
}

float calcolaSommaPrezziCategoria(float prezzo, float somma) {
  somma = somma + prezzo;

  return somma;
}

void mostraPrezzoEClasse(int codice[], float prezzo[], string classe[], int cod) {
  bool trovato = false;
  for (int i = 0; i < DIM; i++) {
    if (codice[i] == cod) {
      cout << prezzo[i] << " " << classe[i];
      trovato = true;
    }
  }
  if (trovato == false)
    cout << "\nCategoria non trovata!";
}

void ordinamento(float prezzo[]) {
    int temp;

	for (int j = 0;j < DIM-1; j++) {
		for(int i = 0; i < DIM-1; i++) {
			if (prezzo[i] < prezzo[i+1]) {
				temp = prezzo[i];
				prezzo[i] = prezzo[i+1];
				prezzo[i+1] = temp;
			}
        }
    }
}

void prezzi_ordinati(float prezzo[]) {
    for (int i = 0; i<DIM; i++) {
        cout << " " << prezzo[i] << endl;
    }
}

int main() {
    int codice[DIM];
    string casa[DIM];
    string classe[DIM];
    string nome[DIM];
    float prezzo[DIM];
    int indice_massimo, contaProd, cod;
    string categoria = "";
    float sommaPrezziCat, mediaPrezziCat = 0;

    cout << "popola di dati con: codice prodotto, la casa prodruttrice, la classe (iniziale), il nome, e il suo prezzo: \n";
    input(codice, casa, classe, nome, prezzo);
    visualizza(codice, casa, classe, nome, prezzo);

    prezzo_max_nome(prezzo);
    cout << "il prodotto con il prezzo massimo e\' " << nome[indice_massimo];

    cout << "\n\nInserisci una categoria e ti forniro\' il prezzo medio di tutti i prodotti di quella categoria: ";
    cin >> categoria;

    for (int i = 0; i < DIM; i++) {
        if (classe[i] == categoria) {
            sommaPrezziCat = calcolaSommaPrezziCategoria(prezzo[i], sommaPrezziCat);
            contaProd++;
        }
    }
    if (contaProd != 0) {
        mediaPrezziCat = (float) sommaPrezziCat/contaProd;
        cout << "\nLa media dei prezzi dei prodotti della categoria " << categoria << " e\': " << mediaPrezziCat ;
    } else
        cout << "\nCategoria non trovata!";

    //(ricerca sequenziale)
    cout << "\n\nInserisci il codice e visualizzero\' il prezzo e la classe del relativo prodotto: ";
    cin >> cod;
    mostraPrezzoEClasse(codice, prezzo, classe, cod);

    cout << "\n\n prezzi ordinati in modo decrescente : \n";
    ordinamento(prezzo);
    prezzi_ordinati(prezzo);

    return 0;
}
