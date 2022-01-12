#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Vector;

void czytaj_kolumnami(int n, int m, int a[n][m]) {
  int i,j;
  for (i=0; i<m; i++)
     {
      printf("\n");
      for (j=0; j<n; j++)
          scanf("%d",&a[j][i]);
     }
}

void initVector(Vector *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertVector(Vector *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeVector(Vector *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}