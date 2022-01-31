// by AC, 12.2021

#include <stdio.h>
#include <math.h>

#define _TASK_NAME "srednia geometryczna liczb dodatnich"
#define _TASK_DESCRIPTION "Podaj pojedynczo kazdy element ktory chcesz, by byl brany pod uwage przy obliczaniu."

typedef enum { false, true } bool; // for compatibility

// function declarations

//
// polecenie A z projektu 1

int main()
{
double whole_value, temp_value, stop_value;
int element_count;
whole_value = 1, element_count = 0;

printf("\nWitaj w moim programie: %s\n%s", _TASK_NAME, _TASK_DESCRIPTION);
printf("\nPodaj wartosc STOP (po ktorej wpisaniu otrzymamy wynik)\n");
scanf("%lf", &stop_value);

do {
printf("\nPodaj prosze wartosc elementu nr %d\n", element_count + 1);
scanf("%lf", &temp_value);
if(temp_value <= 0)
continue;
element_count++;
whole_value *= temp_value;
}
while(temp_value != stop_value);
printf("\tWynik sredniej geometrycznej z podanych wartosci wynosi:\n%lf\n\n", pow(whole_value, 1./element_count));
printf("Dziekuje za skorzystanie z mojego programu!\n");
return 0;
}
