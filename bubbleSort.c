#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int* array, int length){

  int i;
  int j;
  int key;
  int tmp;

  for(i = 1; i < length; i++){
    j = 1;

    while(j < length){
      if(array[j] < array[j-1]){
        tmp = array[j-1];
        array[j-1] = array[j];
        array[j] = tmp;
      }
      j++;
    }
  }
  return;
}


int main() {

  int arrayLength;

  printf("#### Bubble sort algorithm ####\n");

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

  bubbleSort(array, arrayLength);

  printf("Sorted array:\n");
  printf("{");
  for(i = 0; i < arrayLength; i++){
    printf("%d ", array[i]);
  }
  printf("}\n");

  free(array);

  return 0;

}
