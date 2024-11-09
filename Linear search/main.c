#include <stdio.h>

int main(){
    int n;
    int i;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    int a[n];
    int found;

    printf("Enter elements : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }


    int item;
    printf("Enter item to search : ");
    scanf("%d", &item);

    for(i = 0; i < n; i++){
        if(a[i] == item){
            printf("Item found at location %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Item not found\n");
    }
}