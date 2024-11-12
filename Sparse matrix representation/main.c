#include <stdio.h>

void createMatrix(int a[10][10], int r, int c){
    printf("Enter elements into matrix:\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void createSparse(int a[10][10], int s[10][4], int r, int c){
    int i, j, k;
    s[0][0] = r;
    s[0][1] = c;

    for (i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(a[i][j] != 0){
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }
    s[0][2] = k - 1;
}

void display(int s[10][4]){
    int i;
    printf("%d %d %d\n", s[0][0], s[0][1], s[0][2]);
    for(i = 1; i <= s[0][2]; i++){
        printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main(){
    int a[10][10], s[10][4];
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    createMatrix(a, r, c);
    createSparse(a, s, r, c);
    display(s);
    return 0;
}