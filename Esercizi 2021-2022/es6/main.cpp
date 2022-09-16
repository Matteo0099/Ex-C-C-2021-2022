/*
    ES 1
    Caricare una matrice 4 x 4 con numeri interi random compresi tra 1 e 100. Visualizza la matrice, azzerala
    e poi visualizza nuovamente la matrice.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

/*
const int DIM = 4;

void riempiMatrice(int matr[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            matr[i][j]=rand()%100+1;
        }
    }
}

void visualizzaMatrice(int matr[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<"\t"<<matr[i][j];
        }
        cout<<endl;
    } cout<<endl;
}

void resetMatrice(int matr[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            matr[i][j]=0;
            cout<<"\t"<<matr[i][j];
        }
        cout<<endl;
    } cout<<endl;
}

int main() {
    int matr[DIM][DIM];
    srand(time(NULL));
    riempiMatrice(matr);
    visualizzaMatrice(matr);
    resetMatrice(matr);
    riempiMatrice(matr);
    visualizzaMatrice(matr);

    return 0;
}
*/


/*
    ES 2
    Memorizzare in un array bidimensionale 10 x 10 dei numeri casuali compresi tra zero e nove, stamparne
    il contenuto e dire quanti zeri sono memorizzati all’interno dell’array.
*/
/*
const int DIM = 10;

void riempiArray(int array[DIM][DIM]) {
    int s=1;
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            array[i][j]=rand()%9;
            if(array[i][j]==0) {
                s++;
            }
        }
    }
    cout<<"\nle volte che lo 0 e' uscito sono: "<<s<<"\n\n";
}

void visualizza(int array[DIM][DIM]) {
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++) {
            cout<<"\t"<<array[i][j];
        }
        cout<<endl;
    }
}

int main () {
    int array[DIM][DIM];
    srand(time(NULL));
    riempiArray(array);
    visualizza(array);
    return 0;
}
*/

/*
    ES 3
    Memorizzare in un array bidimensionale 5 x 5 tutti zeri tranne nelle celle della diagonale principale dove
    memorizzare uno (non usare l’inizializzazione con parentesi graffe!);
*/
/*
const int DIM = 5;

void riempi(int array[DIM][DIM]) {
    int s=0;
    int v=0;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            if(i!=j){            //perchè quando le righe corrispondono alle colonne trovi l'elemento.
                array[i][j]=0;
            } else
                array[i][j]=1;
        }
    }
}

void visualizza(int array[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<"\t"<<array[i][j];
        }
        cout<<endl;
    }
}

int main () {
    int array[DIM][DIM];
    riempi(array);
    visualizza(array);

    return 0;
}
*/

/*
    ES 4
    Data una matrice 4 x 4 caricata con interi inseriti da tastiera, trovare la riga o la colonna con somma più
    alta.
*/
/*
const int DIM = 4;

void riempi(int array[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cin>>array[i][j];
        }
    } cout<<endl;
}

int sommaRighe(int array[DIM][DIM]) {
    int s=0, sMAX, indiceMAX;
    for(int i=0;i<DIM;i++) {
        s=0;
        for(int j=0;j<DIM;j++) {
            s = s + array[i][j];
        }
        if(s>sMAX) {
            sMAX=s;
            indiceMAX=i;
        }
    }
    return indiceMAX;
}

int sommaColonne(int array[DIM][DIM]) {
    int s=0, sMAX, indiceMAX;
    for(int j=0;j<DIM;j++) {
        s=0;
        for(int i=0;i<DIM;i++) {
            s = s + array[i][j];
            if(s>sMAX) {
                sMAX=s;
                indiceMAX=i;
            }
        }
    }
    return indiceMAX;
}

int main() {
    int array[DIM][DIM], indiceSommaR, indiceSommaC;
    srand(time(NULL));
    cout<<"inserisci numeri nella matrice 4x4: \n";
    riempi(array);
    indiceSommaR=sommaRighe(array);
    indiceSommaC=sommaColonne(array);
    cout<<"la riga con la somma massima e': "<<indiceSommaR+1<<endl;
    cout<<"la colonna con la somma massima e': "<<indiceSommaC+1<<endl;

    return 0;
}
*/

/*
    ES5
    Es. 5. Data una matrice 4 x 4 caricata con interi inseriti da tastiera, trovare la riga e la colonna con somme più
    alte.
*/

/*
const int DIM = 4;

void popolaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cin >> mat[i][j];
        }
    }
}

void visualizzaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<mat[i][j] << "\t";
        }
        cout<<endl;
    }
}

int calcolaSommaRighe(int mat[DIM][DIM]) {
    int sommaR, sommaMax=0, indiceMax=0;
    for(int i=0;i<DIM;i++) {
        sommaR=0;
        for(int j=0;j<DIM;j++) {
            sommaR = sommaR + mat[i][j];
        }
        if(sommaR>sommaMax) {
            sommaMax=sommaR;
            indiceMax=i;
        }
    }
    return indiceMax;
}

int calcolaSommaColonne(int mat[DIM][DIM]) {
    int sommaC, sommaMax=0, indiceMax=0;
    for(int j=0;j<DIM;j++) {
        sommaC=0;
        for(int i=0;i<DIM;i++) {
            sommaC = sommaC + mat[i][j];
        }
        if(sommaC>sommaMax) {
            sommaMax=sommaC;
            indiceMax=j;
        }
    }
    return indiceMax;
}

int main() {
    int mat[DIM][DIM], indiceSommaR, indiceSommaC;

    cout<<"Indice gli elementi della matrice "<<DIM<<" x "<<DIM<<":\n";
    popolaMatrice(mat);
    visualizzaMatrice(mat);
    indiceSommaR = calcolaSommaRighe(mat);
    indiceSommaC = calcolaSommaColonne(mat);

    cout<<"\n la riga con la massima somma e' "<< indiceSommaR+1<<".\n";
    cout<<"\n La colonna con la massima somma e' "<< indiceSommaC+1<<".\n";
}
*/



/*
    ES6
    Data una matrice 4 x 5 di interi (random a piacere) calcolare e visualizzare la sua trasposta. La trasposta
    di una matrice si ottiene prendendo in ordine le righe della matrice originale e facendole diventare le colonne
    della matrice trasposta.
*/

/*
const int DIM_R = 4;
const int DIM_C = 5;

void popolaMatrice(int mat[DIM_R][DIM_C]) {
    for(int i=0;i<DIM_R;i++) {
        for(int j=0;j<DIM_C;j++) {
            mat[i][j] = rand()%50+1;
        }
        cout<<endl;
    }

}

void visualizzaMatrice(int mat[DIM_R][DIM_C]) {
    for(int i=0;i<DIM_R;i++) {
        for(int j=0;j<DIM_C;j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void calcolaTrasposta(int mat[DIM_R][DIM_C], int matT[DIM_C][DIM_R]) {
    for(int i=0;i<DIM_R;i++){
        for(int j=0;j<DIM_C;j++) {
            matT[j][i] = mat[i][j];
        }
    }
}

void visualizzaMatriceT(int matT[DIM_C][DIM_R]) {
    for(int i=0;i<DIM_C;i++) {
        for(int j=0;j<DIM_R;j++) {
            cout<<matT[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main () {
    int mat[DIM_R][DIM_C];
    int matT[DIM_C][DIM_R];
    srand(time(NULL));

    popolaMatrice(mat);
    visualizzaMatrice(mat);
    calcolaTrasposta(mat, matT);
    cout<<endl;
    visualizzaMatriceT(matT);

    return 0;
}
*/

/*
    ES7
    Data una matrice 3×3 verificare se è simmetrica rispetto alla diagonale principale.
    Una matrice si dice simmetrica rispetto alla diagonale principale se è uguale alla sua trasposta.
*/

/*
const int DIM = 3;

void popolaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cin >> mat[i][j];
        }
    }
}

void visualizzaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void calcolaTrasposta(int mat[DIM][DIM], int matT[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            matT[j][i] = mat[i][j];
        }
    }
}

bool verificaSimmetria(int matT[DIM][DIM]) {
    bool isSymmetric = false;
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            if(matT[i][j] != matT[j][i])
                isSymmetric = false;
            else
                isSymmetric = true;
            }
        }
    return isSymmetric;
}

int main () {
    int mat[DIM][DIM], matT[DIM][DIM];
    bool isSymmetric = false;

    cout<<"inserisci gli elementi della matrice "<<DIM<<" x "<<DIM<<":\n";
    popolaMatrice(mat);
    visualizzaMatrice(mat);
    calcolaTrasposta(mat, matT);
    cout<<endl;
    visualizzaMatrice(matT);

    isSymmetric = verificaSimmetria(matT);
    if(isSymmetric)
        cout<<"\nLa matrice e' simmetrica";
    else
        cout<<"\nLa matrice non e' simmetrica.";


    return 0;
}
*/


/*
    Es. 8. Verificare se una matrice 3 × 3 è la matrice identità (la matrice identità è formata da zeri su tutte le
    celle tranne quelle della diagonale dove ci sono uni).
*/

/*
const int DIM = 3;

void popolaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cin>>mat[i][j];
        }
    }
}

void visualizzaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<mat[i][j]<<"\t";
        }
         cout<<endl;
    }
}

bool verificaIdentita(int mat[DIM][DIM]) {
    bool isIdentity = false;
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            if ((i != j && mat[i][j] == 0) || (i==j && mat[i][j] == 1))
                isIdentity = true;
            else
                isIdentity = false;
        }
    }
    return isIdentity;
}

int main () {
    int mat[DIM][DIM];
    bool isIdentity = false;

    cout<<"inserisci gli elementi della matrice "<<DIM<<" x "<<DIM << ": \n";
    popolaMatrice(mat);
    visualizzaMatrice(mat);

    isIdentity = verificaIdentita(mat);

    if(isIdentity)
        cout<<"\n la matrice e' una matrice che ha un'identità, a differenza tua stupidino.";
    else
        cout<<"non ha nemmeno la casa";

    return 0;
}
*/

/*  Es. 9. Date due matrici 4 x 4 calcolarne la somma (la somma tra matrici si calcola commando i contenuti delle
    celle nella stessa posizione).
*/

/*
const int DIM = 4;

void popolaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++) {
            mat[i][j] = rand()%100;
        }
    }
}

void visualizzaMatrice(int mat[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void calcolaSomma(int mat1[DIM][DIM], int mat2[DIM][DIM], int matSomma[DIM][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++) {
            matSomma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main() {
    int mat1[DIM][DIM], mat2[DIM][DIM], matSomma[DIM][DIM];
    srand(time(NULL));

    popolaMatrice(mat1);
    popolaMatrice(mat2);
    cout<<"Matrice 1: \n";
    visualizzaMatrice(mat1);
    cout<<endl;
    cout<<"Matrice 2:\n";
    visualizzaMatrice(mat2);
    calcolaSomma(mat1, mat2, matSomma);
    cout<<endl;
    cout<<"Matrice somma: \n";
    visualizzaMatrice(matSomma);
}
*/

/*
-Es. 10. Scrivere un programma in C++ che accetti una serie di date nella forma:
    gg-mm-aaaa
    gg-mm-aa
    gg/mm/aaaa
    gg/mm/aa
    Output:
    Giorno = gg
    Mese = mm
    Anno = aa
*/

/*
void splitData(string &data, string &giorno, string &mese, string &anno) {
    giorno = data.substr(0, 2);
    mese = data.substr(3, 2);
    anno = data.substr(6, 4);
}

int main () {
    string data, giorno = "", mese = "", anno = "";
    int numeroDataInput = 0;


    do {
        cout << "Quante date vuoi inserire (5 al massimo): ";
        cin >> numeroDataInput;
    } while (numeroDataInput < 1 || numeroDataInput > 5);

    for (int i = 0; i<numeroDataInput; i++) {
        cout << "\n Inserisci data "<<i+1<< "in uno di questi formati: gg-mm-aaaa \n";
        cin >> data;
        splitData(data, giorno, mese, anno);
        cout << "\nGiorno = "<<giorno;
        cout << "\nMese = "<< mese;
        cout << "\nAnno = "<< anno;
        cout << endl;
    }

    return 0;
}
*/

/* ES 11;
    -Scrivere un programma che accetti un’e-mail di lunghezza variabile (nome@dominio.it,
     mario.rossi@yahoo.com, ...) e visualizzi l’output in questo modo:
        Utente = nome (quello prima della @)
        Domain = domino
        Root = it (quello dopo il punto)
    -Visualizzare la lunghezza dell’intera stringa, compresi i caratteri @ e .
        Esempio:
        Utente = mario.rossi
        Domain = yahoo
        Root = com
*/
/*
void splitEmail(string &email, string &utente, string &domain, string &root) {
    string dominio_e_root = "";
    int posChiocciola = 0;
    int posPunto = 0;

    posChiocciola = email.find("@");
    utente = email.substr(0, posChiocciola);

    dominio_e_root = email.substr(posChiocciola+1, email.size());

    posPunto = dominio_e_root.find(".");
    cout<< "\n"<<posPunto;
    domain = dominio_e_root.substr(0, posPunto);

    root = dominio_e_root.substr(posPunto+1, 3);
}


int main () {
    string email, utente = "", domain = "", root = "";

    //input
    cout << "inserisci un indirizzo e-mail valido: ";
    cin >> email;

    splitEmail(email, utente, domain, root);

    //output
    cout << "\nUtente = "<<utente;
    cout << "\nDomain = "<<domain;
    cout << "\nRoot = "<<root;
    cout << endl;
    cout << "la lunghezza dell'intera stringa e': "<< email.size();

    return 0;
}
*/
