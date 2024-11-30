#include <stdio.h>
#include <stdlib.h>

/*
Problem: give a rod of length n (e.g.: 4), what is the best way to cut and sell each part to gain the biggest value (e.g.: in 2 parts of length 2, the total is $10)
*/

#define LENGTH 41
#define NEGATIVE_INFINITY -2147483647

int PRICES[LENGTH] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30,
                      33, 36, 40, 44, 48, 52, 55, 59, 63, 67,
                      70, 74, 77, 81, 85, 90, 95, 100, 105, 110,
                      115, 120, 126, 132, 138, 145, 152, 160, 167, 175}; // Price for each rod length, length 1 is 1, length 2 is 5. It need to start with 0
int MEMOIZED_CALLS[LENGTH] = {0};
int BOTTOM_UP_CALLS[LENGTH] = {0};

int max(int, int);
int cutRod(int n);
int memoizedCutRod(int n);
int bottomUpCutRot(int n);

void main(void)
{
    int lenghtOfTheRod = 30;
    int result;
    int i;
    for (i = 0; i < LENGTH; i++)
    {
        MEMOIZED_CALLS[i] = NEGATIVE_INFINITY;
    }
    result = memoizedCutRod(lenghtOfTheRod);
    printf("The best revenue for this rod is $%d (memoized)\n", result);
    result = bottomUpCutRot(lenghtOfTheRod);
    printf("The best revenue for this rod is $%d (bottom up)\n", result);
    result = cutRod(lenghtOfTheRod);
    printf("The best revenue for this rod is $%d (normal)\n", result);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int cutRod(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int bestPrice = NEGATIVE_INFINITY;
    int i;
    for (i = 1; i <= n; i++)
    {
        bestPrice = max(bestPrice, PRICES[i] + cutRod(n - i));
    }
    return bestPrice;
}

int memoizedCutRod(int n)
{
    if (MEMOIZED_CALLS[n] >= 0)
    {
        return MEMOIZED_CALLS[n];
    }
    int bestPrice;
    if (n == 0)
    {
        bestPrice = 0;
    }
    else
    {
        bestPrice = NEGATIVE_INFINITY;
        int i;
        for (i = 1; i <= n; i++)
        {
            bestPrice = max(bestPrice, PRICES[i] + memoizedCutRod(n - i));
        }
    }
    MEMOIZED_CALLS[n] = bestPrice;
    return bestPrice;
}

int bottomUpCutRot(int n)
{
    int bestPrice;
    int i;
    for (i = 1; i <= n; i++)
    {
        bestPrice = NEGATIVE_INFINITY;
        int j;
        for (j = 1; j <= i; j++)
        {
            bestPrice = max(bestPrice, PRICES[j] + BOTTOM_UP_CALLS[i - j]);
        }
        BOTTOM_UP_CALLS[i] = bestPrice;
    }
    return BOTTOM_UP_CALLS[n];
}