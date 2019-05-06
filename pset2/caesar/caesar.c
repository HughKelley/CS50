#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //handle key
    //convert key to integer
    //int key = atoi(argv[1]);

    //printf("%i\n", argc);

    if (argc > 2 || argc < 2)
    {
        printf("error\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);

        //get the string to be encrypted
        string p = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
            {

                if (isupper(p[i]))
                {
                    char target = p[i];

                    target = target - 64;

                    target = target + key;

                    target = target % 26;

                    target = target + 64;

                    printf("%c", target);
                }

                if (islower(p[i]))
                {

                    char target = p[i];

                    target = target - 96;
                    target = target + key;
                    target = target % 26;
                    target = target + 96;
                    printf("%c", target);
                }

            }
            else
            {
                printf("%c", p[i]);
            }

        }

    }

    printf("\n");

}