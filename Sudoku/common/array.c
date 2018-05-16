#include <assert.h>
#include <stdio.h>
#include "array.h"

void print_array(const int a[], int len) {
  assert(len > 0);
  
  for (int i = 0; i <= len - 1; ++i) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", a[i]);
  }
  printf(".\n");
}
