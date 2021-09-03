#include <stdio.h>
#include <stdlib.h>


void merge(int* array, int beginning, int middle, int end){
  int left[middle - beginning];
  int right[end - middle];
  int i;
  int j = 0; int x = 0;
  for(i = beginning; i < middle; i++){
    left[j] = array[i];
    j++;
  }
  for(; i < end; i++){
    right[x] = array[i];
    x++;
  }

  j = 0; x = 0;
  for(i = beginning; i < end; i++){
    if(j >= middle - beginning) { array[i] = right[x]; x++; continue; }
    if(x >= end - middle) { array[i] = left[j]; j++; continue; }
    if(left[j] < right[x]){
      array[i] = left[j];
      j++;
    } else {
      array[i] = right[x];
      x++;
    }
  }
}


void mergeSort(int* array, int beginning, int end){

  if(end - beginning > 1){
    int middle = (end + beginning)/2;
    mergeSort(array, beginning, middle);
    mergeSort(array, middle, end);

    merge(array, beginning, middle, end);

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
