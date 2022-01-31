// by AC, 12.2021

#include <stdio.h>
#include <math.h>

#define _TASK_NAME "tablicuj funkcje pow((1 + x), 2)"
#define _TASK_DESCRIPTION "Dla wybranej ilosci podprzedzialow i wartosci potegi funkcji 1 + x, program wydrukuje wartosci z wybranego takze przedzialu"

#define workaround_static_def 0

typedef enum { false, true } bool;

double szereg(double x, int * mnozniki, int m);
int zwroc_liste_mnoznikow_funkcji(int m);

int main() {
    int sub_count, i, m;
    double start_value, end_value, x, diff;

    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);

    printf("\nPodaj wartosc m w funkcji (x + 1)^m (liczbe naturalna)\n");
    scanf("%d", &m);
    if(m < 0) {
        printf("\nZle dane wejsciowe; %d nie jest liczbą naturalną", m);
        return 0;
    }
    
    printf("Podaj przedzial (start koniec)\n");
    scanf("%lf %lf", &start_value, &end_value);
    printf("Podaj liczbe podrozdzialow\n");
    scanf("%d", &sub_count);
    // loop over all sub chapter values and print results
    printf("\n\t|    argument x  |    wartosc f(x)  | wartosc szeregu |");
    diff = (end_value - start_value)/sub_count;
    x = start_value;
    int *wskaznik_mnoznikow = zwroc_liste_mnoznikow_funkcji(m);
    for(i = 0; i < sub_count; i++) {
        printf("\n\t|      %.2lf     |      %.5lf     |      %.5lf     |", x, pow((1 + x), m), szereg(x, wskaznik_mnoznikow, m));
        x += diff;
    }
    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}


double szereg(double x, int * mnozniki, int m) {
    double result = 1;
    int j;
    if(m <= 0)
        return 1;
    
    for(j = 1; j < m; j++) {
        result += x * (*(mnozniki + j));
        x = x*x;
    }

    return result;
}

int zwroc_liste_mnoznikow_funkcji(int m) {
    int nr_of_args, numerator = 1, denominator, i, lista_wykrzyknikow[m]; //lista_wykrzyknikow to kolejne rozwiniecia liczby m!
    static int lista_zwrotna[workaround_static_def +m-1];
    nr_of_args = m/2;
    if(m % 2 == 0) // ✔️
        nr_of_args += 1;

    lista_wykrzyknikow[0] = 1; // 0! = 1
    for(i = 1; i <= m; i++) { // ✔️
        numerator *= i;
        lista_wykrzyknikow[i] = numerator;
    }

    for(i = 0; i < nr_of_args; i++) {
        denominator = lista_wykrzyknikow[i] * lista_wykrzyknikow[m-i];
        lista_zwrotna[i] = numerator / denominator;
        lista_zwrotna[m-1-i] = lista_zwrotna[i];
    }

    return lista_zwrotna;
}
