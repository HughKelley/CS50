#include <stdio.h>
#include <cs50.h>

int main(void)
{

//validate input

    int height;

    height = -1;

    while (height < 0 || height > 23)
    {

        height = get_int("Positive Number: ");
    }

// write spaces and hashes

    for (int i = 1; i <= height; i++)
    {

        // spaces

        for (int j = 0; j < height - i; j++)
        {

            printf(" ");

        }

        // hashes

        for (int k = 1; k <= i; k++)
        {

            printf("#");

        }

        // space

        printf(" ");

        //hashes

        for (int k = 1; k <= i; k++)
        {

            printf("#");
        }

        //spaces

       /* for (int j = 0; j < (height - 1); j++)
        {

            printf(" ");

        }*/


        //new line

        printf("\n");



    }

}
