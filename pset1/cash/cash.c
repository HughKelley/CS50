#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float n = 0;
    int i = 0;

    do
    {

        n = get_float("positive: ");

    }
    while (n < 0);

//printf("%f\n",n);

    n = 100 * n;

    n = round(n);


//printf( "n = %f\n", n);


    while (n >= 25)
    {

        n = n - 25;
        i = i + 1;

    }


    while (n >= 10)
    {

        n = n - 10;
        i = i + 1;

    }

    while (n >= 5)
    {

        n = n - 5;
        i = i + 1;

    }

    while (n >= 1)
    {

        n = n - 1;
        i = i + 1;

    }

    printf("Number of coins required: %i \n", i);

    /*

    while n is greater or equal to 25
        n-25
        i = i + 1


    while n is greater than or equal to 10

        n-10
        i = i + 1

    while n is greater than or equal to 5

    n-5
    i = i + 1

    while n is greater than or equal to 1

    n-1
    i = i + 1
    */



}