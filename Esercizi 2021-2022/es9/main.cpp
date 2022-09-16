/*
    Matteo Manià, CL 3IA.
    Le matrici M1 e M2 contengono l'incasso mensile degli alberghi della riviera romagnola per gli anni 2016 e 2017.
    IL vettore "Albergo" contiene il nome degli alberghi.
    Utilizzando i sottoprogrammi, prevedi:

    -Caricamento strutture dati;
    -La visualizzazione dell'incasso peer il 2016 e per il 2017;
    -La visualizzazione dell'albergo in cui si è verificato l'incasso totale maggiore sia per il 2016 che per il 2017;
    -Inserito da input il nome di un albergo, visualizza il suo incasso per il 2016 e per il 2017(richiama 2 volte la funzione INCASSO che restituisce l'incasso totale per l'albergo)
        segnala se l'albergo non esiste.

*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int D1 = 2;


void input(float M1[D1][D1], string Albergo[])
{
    for (int i = 0; i<D1; i++)
    {
        for (int j = 0; j<D1; j++)
        {
            cout << "nome: ";
            cin >> Albergo[i];
            cout << "incasso: ";
            cin >> M1[i][j];
        }
    }
}

void input2(float M2[D1][D1], string Albergo[])
{
    for (int i = 0; i<D1; i++)
    {
        for (int j = 0; j<D1; j++)
        {
            cout << "nome: ";
            cin >> Albergo[i];
            cout << "incasso: ";
            cin >> M2[i][j];
        }
    }
}

int main()
{
    float M1[D1][D1];
    float M2[D1][D1];
    string Albergo[D1];
    string chiave = "";
    int anno;
    float incasso;

    //input
    cout << "immetti il nome degli alberghi e i loro incassi per l'anno 2016: \n";
    input(M1, Albergo);
    cout << "\ninserisci il nome e l'incasso per gli alberghi dell'anno 2017: \n";
    input2(M2, Albergo);

    //ricerca
    cout << "inserisci il nome dell'albergo che stai cercando e io ti diro\' il suo incasso: \n";
    cout << "pero\' prima scrivi di quale anno e\' : ";
    cin >> anno;
    if (anno == 2016)
    {
        cout << "inserisci un nome dell'albergo per l'anno 2016: ";
        cin >> chiave;
        for (int i = 0; i<D1; i++)
        {
            for (int j = 0; j<D1; j++)
            {
                if (Albergo[i] == chiave)
                {
                    incasso = M1[i][j];
                }
                cout << "l'incasso totale per l'albergo e\' di "<< M1[i][j];
                system("PAUSE");
            }
            cout << endl;
        }
    }
    else
    {
        if (anno == 2017)
        {
            cout << "insersci un nome dell'albergo per l'anno 2017: ";
            cin >> chiave;
            for (int i = 0; i<D1; i++)
            {
                for (int j = 0; j<D1; j++)
                {
                    if (Albergo[i] == chiave)
                    {
                        incasso = M2[i][j];
                    }
                    cout << "l'incasso totale per l'albergo e\' di "<< M2[i][j];
                    system("PAUSE");
                }
                cout << endl;
            }
        }
        else
        {
            cout << "non trovato; ";
        }
    }

    return 0;

}
