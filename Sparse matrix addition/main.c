#include <stdio.h>

void sparsematx(int a[10][10], int r, int c, int s[10][4])
{
    int k = 1;
    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
                s[0][2]++;
            }
        }
    }
}

int addsparsematx(int s1[10][4], int s2[10][4], int s3[10][4], int k1, int k2)
{
    int i = 1, j = 1, k = 1;
    s3[0][0] = s1[0][0];
    s3[0][1] = s1[0][1];
    s3[0][2] = 0;
    while (i <= k1 && j <= k2)
    {
        if (s1[i][0] == s2[j][0])
        {
            if (s1[i][1] == s2[j][1])
            {
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2] + s2[j][2];
                i++;
                j++;
            }
            else if (s1[i][1] < s2[j][1])
            {
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                i++;
            }
            else
            {
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                j++;
            }
            k++;
        }
        else if (s1[i][0] < s2[j][0])
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            i++;
            k++;
        }
        else
        {
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            j++;
            k++;
        }
    }
    while (i <= k1)
    {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++;
        k++;
    }
    while (j <= k2)
    {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++;
        k++;
    }
    s3[0][2] = k - 1;
    return k - 1;
}

void displaysparse(int s3[10][4])
{
    printf("%d %d %d\n", s3[0][0], s3[0][1], s3[0][2]);
    for (int i = 1; i <= s3[0][2]; i++)
    {
        printf("%d %d %d\n", s3[i][0], s3[i][1], s3[i][2]);
    }
}

int main()
{
    int a1[10][10], a2[10][10];
    int s1[10][4], s2[10][4], s3[10][4];
    int rows, cols;

    printf("Enter number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > 10 || cols > 10)
    {
        printf("Matrix dimensions exceed the predefined size of 10x10.\n");
        return 1;
    }

    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }

    printf("Enter number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > 10 || cols > 10)
    {
        printf("Matrix dimensions exceed the predefined size of 10x10.\n");
        return 1;
    }

    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }

    sparsematx(a1, rows, cols, s1);
    sparsematx(a2, rows, cols, s2);

    int numNonZero = addsparsematx(s1, s2, s3, s1[0][2], s2[0][2]);

    displaysparse(s3);

    return 0;
}