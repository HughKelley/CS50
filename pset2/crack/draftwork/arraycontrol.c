#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(void)
{
    int size = 6;           // will eventually be an input
    char password[size];    // array that will be built.
    int i[6];               // password size index
    int j;                  // password character index
    int k;                  // character value index between 0 = "A" and 52 = "z"
    int l;                  // the index for the index array


    while (number of possibilities tested is less than total number of possibilities)
    {
        check all values for given array size

        if all values for current array size have been tried
            array size + 1

        password[i] = \0;

        hash = crypt(password);

        if hash = command line input then tested = possibilities
        else
        {
            tested = tested + 1
            character value = character value + 1
        }

        if (character value > 52)
        {
            character value = 0
        }



    }




    for(i = 0; i< size; i++ )
    {
        for (j; j < i; j++)
        {
            for (k; k <= 52; k++)


        }


    }



}

// check if passsword[index] value is greater than 52
    // if it is
        // password[index]= 0
        // index = index -1
        // check if passsword[index] value is greater than 52
        // password[index] = password[index] + 1
        //






