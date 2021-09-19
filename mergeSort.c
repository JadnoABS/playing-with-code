#include <stdio.h>
#include <stdlib.h>


// c + c(n/2) + c * ((n/2)-1) + c * n + c * (n-1) + c * (n-2)
// c + cn/2 + cn/2 - c + cn + cn - c + cn - 2c
// 4cn - 3c
// cn


void merge(int* array, int beginning, int middle, int end){     // M(n)
  int left[middle - beginning];                                 // c4
  int right[end - middle];                                      // c5
  int i;                                                        // c6
  int j = 0; int x = 0;                                         // c7
  for(i = beginning; i < middle; i++){                          // c8 * n/2
    left[j] = array[i];                                         // c9 * ((n/2)-1)
    j++;                                                        // c10 * ((n/2)-1)
  }
  for(; i < end; i++){                                          // c11 * n/2
    right[x] = array[i];                                        // c12 * ((n/2)-1)
    x++;                                                        // c13 * ((n/2)-1)
  }

  j = 0; x = 0;                                                 // c14
  for(i = beginning; i < end; i++){                             // c15 * n
    if(j >= middle - beginning) { array[i] = right[x]; x++; continue; } // c16 * (n-1)
    if(x >= end - middle) { array[i] = left[j]; j++; continue; }        // c17 * (n-1)
    if(left[j] < right[x]){                                             // c18 * (n-2)
      array[i] = left[j];                                               // c19 * (n-2)
      j++;                                                              // c20 * (n-2)
    } else {
      array[i] = right[x];
      x++;
    }
  }
}

// T(n) = 2 * T(n/2) + c * n
// T(1) = c
// T(2) = 2 * c + 2 * c = 4c
// T(3) = 3 * c + 3 * c = 6c
// T(4) = 4c + 4c = 8c
//
// T(n) = n*2 * c

void mergeSort(int* array, int beginning, int end){ // T(n)

  if(end - beginning > 1){                // c1
    int middle = (end + beginning)/2;     // c2
    mergeSort(array, beginning, middle);  // T(n/2)
    mergeSort(array, middle, end);        // T(n/2)

    merge(array, beginning, middle, end); // M(n) = c * n

    return;
  }

}



int main() {

  int arrayLength;

  printf("#### Merge sort algorithm ####\n");

  printf("Array length: \n");
  scanf("%d", &arrayLength);

  int* array = (int*) malloc(sizeof(int) * arrayLength);

  int i;
  printf("Insert each item from array: \n");
  for(i = 0; i < arrayLength; i++){
    scanf("%d", &array[i]);
  }

  printf("Original array:\n");
  printf("{");
  for(i = 0; i < arrayLength; i++){
    printf("%d ", array[i]);
  }
  printf("}\n");

  mergeSort(array, 0, arrayLength);

  printf("Sorted array:\n");
  printf("{");
  for(i = 0; i < arrayLength; i++){
    printf("%d ", array[i]);
  }
  printf("}\n");

  free(array);

  return 0;

}






/* Merge sort attempt before seeing any other merge sort implementation
void merge(int* array, int* L, int* R, int Lsize, int Rsize){
  int j = 0; int x = 0;
  for(int i = 0; i < Lsize + Rsize; i++){
    if(x >= Rsize || L[j] < R[x]){
      array[i] = L[j];
      j++;
    }
    if(j >= Lsize){
      array[i] = R[x];
      x++;
    }
  }

}
// This one was written before seeing any other merge sort implementation
void mergeSort(int* array, int length){

  int i; int j; int x;
  int tmp;

  if(length > 2){
    int* R; int* L;
    int leftArraySize;

    if(length % 2 != 0) leftArraySize = length/2 + 1;
    else leftArraySize = length/2;

    L = (int*) malloc(sizeof(int) * leftArraySize);
    R = (int*) malloc(sizeof(int) * length/2);

    for(i = 0; i < leftArraySize; i++) L[i] = array[i];
    for(; i < length; i++) R[i] = array[i];

    printf("a\n");
    mergeSort(L, leftArraySize);
    mergeSort(R, length/2);

    merge(array, L, R, leftArraySize, length/2);
    return;
  }

  if(array[0] > array[1]){
    tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
    return;
  }

  return;

}
*/
