#include <stdio.h>

void bubbleSort(int a[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(a[j + 1] > a[j]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void display(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(){
    int i, n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    display(a, n);
}