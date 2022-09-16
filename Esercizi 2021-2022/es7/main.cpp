//Matteo Manià, CL 3IA
#include <iostream>

using namespace std;


int main()
{
    //stringhe
    /*
    string s1;
    getline(cin, s1);
    cout << s1;
    */

    /*----------------------------------------------------------------------------------------*/

    //struttura record
    /* tabella per  gestire la teballea anagrafica; */
    /* ogni singola riga, si chiama record; è questo il motivo per il quale si chiama così; */
    struct tab1 {
        int id;
        string nome;
        string indirizzo;
        int eta;
    }RossiMario, verdiGiovanni, stud;

    //notazione puntata per cin>> per richiamare il campo che vogliamo popolare ex: Rossimario.eta ;
    RossiMario.id = 1;

    //input;
    cout << "inserisci il nome: ";
    cin >> RossiMario.nome;  //si può anche assegnare dei valori ...
    cout << "inserisci la tua eta\': ";
    cin >> RossiMario.eta;
    cout << "inserisci il tuo indirizzo: ";
    cin >> RossiMario.indirizzo;

    cout << "\n\n";

    //visualizzazione struttura
    cout << RossiMario.id << "\t";
    cout << RossiMario.nome << "\t";
    cout << RossiMario.eta << "\t";
    cout << RossiMario.indirizzo << "\t";

    /*----------------------------------------------------------------------------------------*/

    cout << "\n\n";

    //popolare i campi di verdiGiovanni;
    verdiGiovanni.id = 2;
    cin >> verdiGiovanni.nome;
    cin >> verdiGiovanni.eta;
    cin >> verdiGiovanni.indirizzo;

    cout << "\n\n";

    //visualizzare a video verdiGiovanni;
    cout << verdiGiovanni.id  << "\t";
    cout << verdiGiovanni.nome << "\t";
    cout << verdiGiovanni.eta << "\t";
    cout << verdiGiovanni.indirizzo << "\t";

    /*----------------------------------------------------------------------------------------*/

    cout << "inserisci l'identificativo dello studente: \n";
    cin >> stud.id;
    cout << "inserisci il nome dello studente: \n";
    cin.ignore();              //ignora gli spazi vuoti
    getline(cin, stud.nome);   //serve per gestire;
    getline(cin, stud.indirizzo);
    cin >> stud.eta;


    /*
    struct tabella {
     string nome;
     string ind;
    }a1,a2,a3;
    cin >> (a1.nome);
    cout << (a1.nome);
    */


    return 0;
}
