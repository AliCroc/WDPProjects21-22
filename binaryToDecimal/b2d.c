// by AC, 12.2021

#include <stdio.h>
#include <math.h>
#include <conio.h>

#define _TASK_NAME "zamiana liczby z dziesiatkowej na binarna"
#define _TASK_DESCRIPTION "Wpisz liczbe w systemie dziesiatkowym, a otrzymasz ta sama liczbe zapisana w systemie binarnym"

typedef enum { false, true } bool; // for compatibility

// function declarations

//

int main() {
    int binary_number[10], dec_number, i;
    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);
    printf("\nPodaj liczbe w systemie dziesiatkowym\n");
    scanf("%d", &dec_number);
    for(i = 0; dec_number > 0; i++) {
        binary_number[i] = dec_number%2;
        dec_number = dec_number/2;
    }
    printf("\nForma binarna podanej liczby to ");
    for(i--; i >= 0; i--)
        printf("%d",binary_number[i]);
    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}
