#include <stdio.h>

void insertionSort(int a[], int n){
    int i = 0, j = 1;
    int temp;
    for(i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;
    while(j >= 0 && a[j] > temp){
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = temp;
    }
}

void print(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

int main(){
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements into array : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Original array : ");
    print(a, n);
    insertionSort(a, n);
    printf("Array after sorting : ");
    print(a, n);
}