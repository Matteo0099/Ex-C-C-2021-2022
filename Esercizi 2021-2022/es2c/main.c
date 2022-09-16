/*Matteo Manià Cl 3IA
data: 11/02/2022
Es 1:
Misurando 5 volte la lunghezza in input di un chiodo palmer, si ottengono 5 valori espressi in millimetri; con i sottoprorammi, scrivere un programma che calcoli la media e la semidispersione dei valori misurati;
*/

#include <stdio.h>                                 //librerie standard;
#include <stdlib.h>

int calcoloMisura(int valori) {      //funzione che calcola la media;
  printf("inserisci 5 valori della lunghezza del chiodo palmer : \n");
  int i, somma;
  int temp, semi_disp, Min, Max;
  float media, lunghezza_chiodo;

  for (i = 1; i <= 5; i++) {
    scanf("%f", &lunghezza_chiodo);
    printf("lunghezza chiodo inserita: %f\n", lunghezza_chiodo);
    somma = somma + lunghezza_chiodo;
    if (lunghezza_chiodo > temp) {
        Max = lunghezza_chiodo;                 //trovare il massimo;
    } else {
        Min = lunghezza_chiodo;                 //trovare il minimo;
    }
  }
  media = somma / i;                           //calcolo media;
  printf("media misure chiodo = %2.f", media);

  semi_disp = (Max - Min)/2;                  //formula semidispersione;
  printf("\n La semidispersione dei chiodi e\' pari a : %d", semi_disp);   //output;

  return media;
}


int main (void) {                        //main, programma di partenza;
  int lunghezza_chiodo, strum;          //valori di prova (valori, strum)
  float media, valori;              //qs.2 parametri sono float perché sono medie;

  calcoloMisura(valori);    //chiamante;
}
