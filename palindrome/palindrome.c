// by AC, 12.2021

#include <stdio.h>
#include <string.h>

#define _TASK_NAME "palindrom"
#define _TASK_DESCRIPTION "Wpisz slowo by otrzymac liczbe uzytych znakow i sprawdzic, czy jest to palindrom"

typedef enum { false, true } bool; // for compatibility

// function declarations

//

int main() {
    char word_chain[200];
    int i, len, is_palindrome = true;
    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);
    printf("\nPodaj dowolne slowo\n");
    scanf("%s", word_chain);
    len = strlen(word_chain);
    for(i = 0; i < len; i++) {
        if(word_chain[i] != word_chain[len-i-1]) {
            is_palindrome = false;
            break;
        }
    }
    printf("\nSlowo %s ma w sobie %d znakow i %sjest palindromem", word_chain, len, is_palindrome ? "" : " NIE");
    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}
