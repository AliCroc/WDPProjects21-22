// by AC, 12.2021

#include <stdio.h>
#include <math.h>

#define _TASK_NAME "zamiana liczby z dziesiatkowej na binarna"
#define _TASK_DESCRIPTION "Wpisz liczbe w systemie dziesiatkowym, a otrzymasz ta sama liczbe zapisana w systemie binarnym"

typedef enum { false, true } bool;

int main() {
float a;
double c;
int b, l = 0, primary_list[20], floating_list[7], sorted_list[7], i, n, count = 0;

printf("\nWitaj w moim programie: %s\n%s\n", _TASK_NAME, _TASK_DESCRIPTION);
printf("\nPodaj liczbe w systemie dziesiatkowym\n");
scanf("%lf", &c);
b = c;
a = c - b;
printf("\n");
while(b != 0) {
n = b % 2;
b /= 2;
primary_list[count] = n;
count += 1;
}

if(count <= 1)
printf("%d",  primary_list[0]);
else
for(count--; count >= 0; count--)
printf("%d", primary_list[count]);

if(a > 0) {
printf(".");
for(i = 1; i <= 8; i++) {
a = a*2;
l = a;
floating_list[i-1] = a;
if(l == 1)
a -= l;
}

bool flag = false;
count = 0;

for(i = 8; i >= 0; i--) {

if(floating_list[i] != 0) {
flag = true;
}

if(flag == true) {
sorted_list[count] = floating_list[i];
count++;
}
}

for(i = count-1; i >= 0; i--)
printf("%d", sorted_list[i]);
}
printf("\n");
}
