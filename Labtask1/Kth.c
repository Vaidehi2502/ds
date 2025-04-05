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

    int n = sizeof(a) / sizeof(a[0]);
    int temp;

    // Sort the array in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\n\nEnter the value of k: ");
    scanf("%d", &k);

    if (k > 0 && k <= n)
    {
        printf("The %dth largest element is %d\n", k, a[k - 1]);
    }
    else
    {
        printf("Invalid value of k\n");
    }
    return 0;
}
