/*
    Matteo Manià, CL 3IA

    -Carica la matrice 4x5 con numeri casuali che vanno da 1 a 100, e poi visualizzala.
    -fai la somma delle righe
    -fai la somma delle colonne
    -fai la media di tutti i numeri
    -trova la chiave

*/

#include <iostream>
#include <ctime>

using namespace std;


const int DIM_R = 4;
const int DIM_C = 5;

void riempi(int m[DIM_R][DIM_C]) {
    for (int i = 0; i<DIM_R; i++) {
        for (int j = 0; j<DIM_C; j++) {
            m[i][j] = rand()%100+1;
        }
    }
}

void visualizza(int m[DIM_R][DIM_C]) {
    for (int i = 0; i<DIM_R; i++) {
        for (int j = 0; j<DIM_C; j++) {
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}

void somma_righe(int m[DIM_R][DIM_C]) {
    int somma;
    for (int i = 0; i<DIM_R; i++) {
        for (int j = 0; j<DIM_C; j++) {
            somma += m[i][j];
        }
    }
    cout << "\nla somma delle righe e\' "<< somma;
}

void somma_colonne(int m[DIM_R][DIM_C]) {
    int somma = 0;
    for (int i = 0; i<DIM_C; i++) {
        for (int j = 0; j<DIM_R; j++) {
            somma += m[j][i];
        }
    }
    cout << "\nla somma delle colonne e\' "<< somma<<"\n\n";
}

void media_colonne(int m[DIM_R][DIM_C]) {
    int somma = 0, conta = 0;
    float media = 0;

    for (int i = 0; i<DIM_C; i++) {
        somma=0;
        for (int j = 0; j<DIM_R; j++) {
            somma = somma + m[j][i];
            conta++;
        }
        media = somma/conta;
        cout << "media colonna "<<i << media <<endl;
    }
    cout<<endl;
}

void media_righe(int m[DIM_R][DIM_C]) {
    int somma, conta = 0;
    float media = 0;

    for (int i = 0; i<DIM_R; i++) {
        somma=0;
        for (int j = 0; j<DIM_C; j++) {
            somma = somma + m[i][j];
            conta++;
        }
        media = somma/conta;
        cout << "media riga "<<i << media <<endl;
    }
}

int main()
{
    int m[DIM_R][DIM_C];
    srand(time(NULL));
    riempi(m);
    visualizza(m);
    somma_righe(m);
    somma_colonne(m);
    media_colonne(m);
    media_righe(m);

    return 0;
}
