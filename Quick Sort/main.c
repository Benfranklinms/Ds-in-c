#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(start < end){
      while(arr[start] <= pivot){
        start++;
      }
      while(arr[end] > pivot){
        end--;
      }
      if(start < end){
        swap(&arr[start], &arr[end]);
      }
    }
    swap(&arr[low], &arr[end]);
    return end;
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
  }
}

void print(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d\n", arr[i]);
  }
  printf("\n");
}

int main(){
  int size, low, high;
  printf("Enter size of array : ");
  scanf("%d", &size);
  int arr[size];

  int i;
  printf("Enter elements into array : ");
  for(i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("Original array : ");
  print(arr, size);
  quickSort(arr, 0, size - 1);
  printf("Sorted array : ");
  print(arr, size);
}