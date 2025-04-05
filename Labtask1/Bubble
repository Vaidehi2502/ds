#include <stdio.h>
int main()
{
    int a[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int i, j, k;

    printf("The original array is :\n");
    for (i = 0; i < 11; i++)
    {
        printf("%d |", a[i]);
    }

    for (i = 0; i < 11; i++)
    {
        for (j = i + 1; j < 11 - i; j++)
        {
            if (a[i] > a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }


    printf("\n\nThe bubble sorted array is :\n");
    for (i = 0; i < 11; i++)
    {
        printf("%d |", a[i]);
    }

    return 0;
}
