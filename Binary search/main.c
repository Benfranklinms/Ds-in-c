#include <stdio.h>

int binary_search(int a[],int n,int data){
    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(a[mid] == data){
            return mid;
        }
        else if(data > a[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n,data,i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into array : ");
    for(i = 0; i < n ;i++){
        scanf("%d" ,&a[i]);
    }
    printf("Enter elements to search : ");
    scanf("%d",&data);
    int sort = binary_search(a,n,data);
    if(sort != -1){
        printf("Element found at %d", sort + 1);
    }
    else{
        printf("Element not found in array");
    }
}