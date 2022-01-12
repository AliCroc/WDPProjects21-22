// by AC, 12.2021

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define _TASK_NAME "tablice 2d"
#define _TASK_DESCRIPTION "Program znajduje te komorki w liscie 2d gdzie znajduja sie liczby calkowite wieksze od wprowadzonej przez uzytkownika"


int main() {
    int row_count, col_count;
    double x;
    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);

    printf("Podaj ilosc wierszy i kolumn\n");
    scanf("%d %d",&row_count, &col_count);
    printf("\nPodaj liczbe x\n");
    scanf("%lf", &x);
    int list_A[row_count][col_count];
    printf("\nPodaj prosze dane do tablicy\n");
    czytaj_kolumnami(row_count, col_count, list_A);
    // init vector
    Vector wynik;
    initVector(&wynik, 2);

    int i,j, counter = 0;
    for (i = 0; i < row_count; i++) {
        for (j = 0; j < col_count; j++) 
            if(list_A[i][j] > x) {
                printf("\nadded %d at [%d, %d]\n", list_A[i][j], i, j); //debug
                insertVector(&wynik, i);
                insertVector(&wynik, j);
                counter += 2;
            }
    }

    printf("Indeksy komorek o wartosciach wiekszych niz %.1lf:\n", x);
    for(i = 0; i < counter; i += 2)
        printf("[%d][%d], ", wynik.array[i], wynik.array[i + 1]);

    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}
