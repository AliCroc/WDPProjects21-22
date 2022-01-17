#include <stdio.h>
#include <string.h>

#define _TASK_NAME "palindrom"
#define _TASK_DESCRIPTION "Wpisz slowo by otrzymac liczbe uzytych znakow i sprawdzic, czy jest to palindrom"

typedef enum { false, true } bool; // for compatibility

int main() {
    char word_chain[200], final_chain[200];
    int c = 0, d = 0, i, len, is_palindrome = true;
    printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);
    printf("\nPodaj dowolne zdanie\n");
    scanf("%[^\t\n]", word_chain);

    while (word_chain[c] != '\0')
    {
        printf("%c", word_chain[c]);
        if (word_chain[c] != ' ') {
        final_chain[d] = word_chain[c];
        d++;
        }
        c++;
    }

    len = strlen(final_chain);
    for(i = 0; i < len; i++) {
        if(final_chain[i] != final_chain[len-i-1]) {
            is_palindrome = false;
            break;
        }
    }
    printf("\nZdanie %s ma w sobie %d znakow i %sjest palindromem", word_chain, len, is_palindrome ? "" : " NIE");
    printf("\nDziekuje za skorzystanie z mojego programu!\n");
    return 0;
}