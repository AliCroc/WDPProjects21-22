// by AC, 12.2021

#include <stdio.h>
#include <math.h>

#define _TASK_NAME "srednia geometryczna liczb dodatnich"
#define _TASK_DESCRIPTION "Podaj pojedynczo kazdy element ktory chcesz, by byl brany pod uwage przy obliczaniu. By zakonczyc dodawanie elementow i uzyskac wynik sredniej, wpisz symbol rownosci \"=\"."

typedef enum { false, true } bool; // for compatibility

// function declarations

//
// polecenie A z projektu 1

int main()
{
    double whole_value, temp_value;
    int element_count, scanf_check;
    whole_value = 1, element_count = 0;

    printf("\nWitaj w moim programie: %s\n%s", _TASK_NAME, _TASK_DESCRIPTION);
    while(true) {
        printf("\nPodaj prosze wartosc elementu\n");
        scanf_check = scanf("%lf", &temp_value);
        if(scanf_check == 0) break;
        element_count++;
        whole_value*=temp_value;
    }
    printf("\tWynik sredniej geometrycznej z podanych wartosci wynosi:\n%lf\n\n", pow(whole_value, 1./element_count));
    printf("Dziekuje za skorzystanie z mojego programu!\n");
}
