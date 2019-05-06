/*
determine max size of password

determine number of possible passwords

loop over possible password sizes
loop over possible password values
*/


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

char letter;

for(int i = 0; i < 53; i++)
{

    letter = i;
    if ( i < 26)
    {
        letter = letter + 65;
    }
    else
    {
        letter = letter + 71;
    }

    printf("%c", letter);

}

printf("\n");

}




