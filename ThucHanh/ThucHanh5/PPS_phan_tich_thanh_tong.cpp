#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <stdlib.h>

#define MAX 100

#define TRUE 1

#define FALSE 0

int n, C[MAX], k, count, Stop;

void Init(void)
{

    printf("\n Nhap n=");
    scanf("%d", &n);

    k = 1;
    count = 0;
    C[k] = n;
}

void Result(void)
{

    int i;
    count++;

    printf("\n Cach chia %d:", count);

    for (i = 1; i <= k; i++)

        printf("%3d", C[i]);
}

void Next_Division(void)
{

    int i, j, R, S, D;

    i = k;

    while (i > 0 && C[i] == 1)

        i--;

    if (i > 0)
    {

        C[i] = C[i] - 1;

        D = k - i + 1;

        R = D / C[i];

        S = D % C[i];

        k = i;

        if (R > 0)
        {

            for (j = i + 1; j <= i + R; j++)

                C[j] = C[i];

            k = k + R;
        }

        if (S > 0)
        {

            k = k + 1;
            C[k] = S;
        }
    }

    else
        Stop = TRUE;
    // std::cout << "\n" << R << "\t" << S << "\t" << D;
}

void Division(void)
{

    Stop = FALSE;

    while (!Stop)
    {

        Result();

        Next_Division();
    }
}

int main(void)
{

    Init();

    Division();

    _getch();

    return 0;
}