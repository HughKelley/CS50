#include <stdio.h>
#include <cs50.h>

int main(void)
{

    /* First validate input*/
    int n;

    n = -1;

    while (n < 0)
    {
        n = 24;

        while (n > 23)
        {
            n = get_int("Positive Number: ");
        };
    };


    /* Then go to work writing out the  spaces, hashes and new line*/

    //each row
    for (int i = 0; i < n; i++)
    {

        //spaces

        for (int j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }

        //hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("#\n");
    }
}