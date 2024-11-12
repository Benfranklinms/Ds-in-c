#include <stdio.h>

struct poly
{
    float coeff;
    int exp;
};
struct poly p1[10], p2[10], p3[10];

int readpoly(struct poly p[])
{
    int t, i;
    printf("Enter no of terms in the polynomial:");
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        printf("Enter coefficent of term %d:", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent of the term %d:", i + 1);
        scanf("%d", &p[i].exp);
    }
    printf("\n");
    return t;
}

int addpoly(struct poly p1[], struct poly p2[], struct poly p3[], int t1, int t2)
{
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2)
    {
        if (p1[i].exp == p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if (p1[i].exp > p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
    }
    while (i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }
    while (j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }
    return k;
}

void displaypoly(struct poly p[], int t)
{
    int k = 0;
    for (k = 0; k < t - 1; k++)
    {
        printf("%0.2f(x^%d)+", p[k].coeff, p[k].exp);
    }
    printf("%0.2f(x^%d)+", p[t - 1].coeff, p[t - 1].exp);
}
int main()
{
    int t1, t2, t3;
    printf("Polynomial 1\n");
    t1 = readpoly(p1);
    displaypoly(p1, t1);
    printf("Polynomial 2\n");
    t2 = readpoly(p2);
    displaypoly(p2, t2);
    printf("\n Added polynomial\n");
    t3 = addpoly(p1, p2, p3, t1, t2);
    displaypoly(p3, t3);
    return 0;
}