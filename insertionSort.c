#include <stdio.h>
#include <stdlib.h>


void insertionSort(int* array, int length){

  int i;
  int j;
  int key;
  int tmp;
  for(i = 1; i < length; i++){
    key = array[i];
    j = i-1;
    while(j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }

  return;
}

// Alternative to the insertion sort from Cormen Algorithms book
void alternativeInsertionSort(int* array, int length){

  int i;
  int j;
  int key;
  int tmp;
  for(i = 1; i < length; i++){
    key = array[i];
    j = i-1;
    while(j >= 0 && array[j] > key){
      if(array[j] > array[j+1]){
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
      j--;
    }
  }

  return;
}

int main() {

  int arrayLength;

  printf("#### Insertion Sort Algorithm ####\n");

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

  insertionSort(array, arrayLength);

  printf("Sorted array:\n");
  printf("{");
  for(i = 0; i < arrayLength; i++){
    printf("%d ", array[i]);
  }
  printf("}\n");

  return 0;

}
