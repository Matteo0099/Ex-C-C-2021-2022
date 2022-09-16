#include <iostream>
#include <cmath>

using namespace std;

float cateto1, cateto2, ipotenusa, perimetro;

void inserimentoDati () {
    do {

    } while(cateto1 <= 0 || cateto2 <= 0);
}

float calcolaPerimetro() {
    ipotenusa = sqrt(cateto1*cateto2 + cateto2*cateto2);
    return (cateto1+cateto2+ipotenusa);
}

void stampaPerimetro () {
    cout << "il valore del perimetro e\': " << perimetro;
}

int main()
{
    cout << "inserisci il valore dei cateti del triangolo: \n";
    cin >> cateto1 >> cateto2;
    inserimentoDati;
    perimetro = calcolaPerimetro();
    stampaPerimetro();

    return 0;

}
