
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(int argc, string argv[])
{


    // check command line arguments
    if (argc != 2)
    {
        //printf("argc: %i \n", argc);
        //printf("result: error\n");
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hashinput = argv[argc - 1];
    char salty[3];
    salty[0] = hashinput[0];
    salty[1] = hashinput[1];
    salty[2] = '\0';


    //printf(" hash: %s", hashinput);

    int size = 5;
    char index[size];
    //int value = 65;
    int max = 387659012;    //could be set dynamically instead of using a magic number with the possibilities script that takes
                            // number of possible values and number of possible positions as command line arguments and prints
                            // the number of possible combinations. possibilities.c

    //set initial array values
    for (int i = 0; i < size; i++)
    {
        index[i] = 0;
    }

    //build array possibilities and check one by one

    for (int j = 0; j < max; j++)
    {
        /*if (j == 100000000)
        {
            printf("first hundred million");
        }
        if (j == 200000000)
        {
            printf("second hundred million");
        }
        if (j == 300000000)
        {
            printf("third hundred million");
        }*/

        index[0] = index[0] + 1;

        if (index[0] > 52)
        {
            index[0] = 1;
            index[1] = index[1] + 1;

            if (index[1] > 52)
            {
                index[1] =  1;
                index[2] = index[2] + 1;

                if (index[2] > 52)
                {
                    index[2] = 1;
                    index[3] = index[3] + 1;

                    if (index[3] > 52)
                    {
                        index[3] = 1;
                        index[4] = index[4] + 1;

                        if (index[4] > 52)
                        {
                            index[4] = 1;
                            index[5] = index[5] + 1;

                            if (index[5] > 52)
                            {
                                index[5] = 1;
                            }
                        }
                    }
                }
            }
        }

        //printf("password: ");


        // convert to ascii values from alphabetical index


        char test[6];

        for (int i = 0; i < size; i++)
        {

            char letter;

            if (index[i] == 0)
            {
                letter = index[i];
            }
            else
            {
                if (index[i] <= 26)
                {
                    letter = index[i] + 64;
                }
                else
                {
                    letter = index[i] + 70;
                }
            }
            //printf("%c",letter);
            test[i] = letter;
        }

        //eprintf("%s\n", test);
        string hashtest = crypt(test, salty);
        //printf("hashed test: %s\n", hashtest);
        //printf("hash input: %s\n", hashinput);

        if (strcmp(hashtest, hashinput) == 0)
        {
            printf("%i \n", j);
            printf("password is: %s\n", test);
            j = max + 1;
        }
    }

//printf("password: %s\n", index);

//printf("Done\n");



}
