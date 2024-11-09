#include <stdio.h>

int a[100];

void buildTree(int a[], int i, int item){
    int ch;
    int value;

    a[i] = item; // root node

    printf("Do you want a left node : ");
    scanf("%d", &ch);
    if(ch == 1){
        printf("Enter a value : ");
        scanf("%d", &value);
        buildTree(a, 2 * i, value);
    }
    printf("Do you want a right node : ");
    scanf("%d", &ch);
    if(ch == 1){
        printf("Enter a value : ");
        scanf("%d", &value);
        buildTree(a, 2 * i + 1, value);
    }
}

void preorder(int a[], int index){
    if (index >= 100 || a[index] == -1) return;  // Base case: empty node or out-of-bounds

    printf("%d ", a[index]);  // Print current node
    preorder(a, 2 * index);    // Traverse left subtree
    preorder(a, 2 * index + 1); // Traverse right subtree
}

void inorder(int a[], int index){
    inorder(a, 2 * index);
    printf("%d", a[index]);
    inorder(a, 2 * index + 1);
}

void postorder(int a[], int index){
    postorder(a, 2 * index);
    postorder(a, 2 * index + 1);
    printf("%d", a[index]);
}

void creation(){
    int i;
    int root;


    for(i = 0; i < 100; i++){
        a[i] = -1;
    }

    printf("Enter node : ");      // setting root node
    scanf("%d", &root);
    buildTree(a, 1, root);

    printf("Tree is : ");
    for(i = 0; i < 20; i++){
        if(a[i] == -1){
            printf("-");
        }
        else{
            printf("%d", a [i]);
        }
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("1. Creation\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                creation();
                break;
            case 2:
                preorder(a, 1);
                break;
            case 3:
                inorder(a, 1);
                break;
            case 4:
                postorder(a, 1);
            case 5:
                return 0;
            default:
                printf("Enter correct choice");
        }
    }
    return 0;
}