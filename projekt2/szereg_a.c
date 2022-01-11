// by AC, 12.2021

#include <stdio.h>
#include <math.h>
#include <conio.h>

#define _TASK_NAME "tablicuj funkcje pow((1 + x), 2)"
#define _TASK_DESCRIPTION "Dla wybranej ilosci podprzedzialow i wartosci potegi funkcji 1 + x, program wydrukuje wartosci z wybranego takze przedzialu"

#define M_VALUE 2

typedef enum { false, true } bool; // for compatibility

// function declarations
double szereg(double x);
//

int main() {
    int sub_count, i;
    double start_value, end_value, x, diff;

    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);
    // get data
    printf("Podaj przedzial (start koniec)\n");
    scanf("%lf %lf", &start_value, &end_value);
    printf("Podaj liczbe podrozdzialow\n");
    scanf("%d", &sub_count);
    // loop over all sub chapter values and print results
    printf("\n\t|    argument x  |    wartosc f(x)  | wartosc szeregu |");
    diff = (end_value - start_value)/sub_count;
    x = start_value;
    for(i = 0; i < sub_count; i++) {
        printf("\n\t|      %.2lf     |      %.5lf     |      %.5lf     |", x, pow((1 + x), M_VALUE), szereg(x));
        x += diff;
    }
    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}


double szereg(double x) {
    return 1 + 2*x + x*x;
}
