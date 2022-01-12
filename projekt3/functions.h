#ifndef __FUNCTIONS
#define __FUNCTIONS

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Vector;

void czytaj_kolumnami(int n, int m, int a[n][m]);
void initVector(Vector *a, size_t initialSize);
void insertVector(Vector *a, int element);
void freeVector(Vector *a);

#endif