#include <assert.h>
#include <stdlib.h>
#include "sort.h"

// merge(dest, src1, len1, src2, len2) modifies dest to contain
//   the elements from both src1 and src2 in sorted order
// requires: length of dest is at least (len1 + len2)
//           src1 and src2 are sorted
// effects:  modifies dest
// time:     O(n), where n is len1 + len2
static void merge(int dest[], 
                  const int src1[], int len1, 
                  const int src2[], int len2) {
  int pos1 = 0;
  int pos2 = 0;
  for (int i=0; i < len1 + len2; ++i) {
    if (pos1 == len1 || (pos2 < len2 && src2[pos2] < src1[pos1])) {
      dest[i] = src2[pos2];
      ++pos2;
    } else {
      dest[i] = src1[pos1];
      ++pos1;
    }
  }
}


// see sort.h for doucmentation

void merge_sort(int a[], int len) {
  assert(a);
  if (len <= 1) return;
  
  int llen = len / 2;
  int rlen = len - llen;
  
  int *left = malloc(llen * sizeof(int));
  int *right = malloc(rlen * sizeof(int));
  
  for (int i=0; i < llen; ++i) {
    left[i] = a[i];
  }
  
  for (int i=0; i < rlen; ++i) {
    right[i] = a[i + llen];
  }
  
  merge_sort(left, llen);
  merge_sort(right, rlen);
  
  merge(a, left, llen, right, rlen);
  
  free(left);
  free(right);
}
