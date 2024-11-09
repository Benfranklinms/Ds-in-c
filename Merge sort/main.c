#include <stdio.h>


void merge(int a[], int low, int mid, int high){
    int i, j , k;
    i = low;
    j = mid + 1;
    k = low;
    int b[20];

    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(i > mid){
        while(j <= high){
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(i = 0; i <= high; i++){
        a[i] = b[i];
    }
}



void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid;
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void display(int n, int a[]){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int i, n, low, high;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    int a[n];

    printf("Enter elements in array : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    low = 0;
    high = n - 1;
    mergeSort(a, low, high);
    display(n, a);
}