#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    /* argc should be 2. Of course, if the user provides more than one command-line argument at the prompt,
    argc could be greater than 2, in which case, again, your program should print an error and return 1.
    */

    //turn key into an integer

    int key = atoi(argv[argc - 1]); //check man pages for atoi about what it wil do if input is not all letters

if (isupper('A') && isupper('B'))
{
    printf("Both characters are uppercase alphabetic!\n");
}

    printf("key is: %i\n",key);

    // get text to encipher

    string text = get_string("plaintext: ");


    // go through text one letter at a time.

    int limit = strlen(text);

    for (int i = 0; i < limit; i++)
        {

            char letter = text[i];
            printf("%c\n",letter);

           if (isupper(letter) = true)
           {
                printf("upper\n");
                letter = letter + key;
                printf("%c/n",letter);
           }
           else
           {
               if (islower(letter) = true)
               {
                   printf("lower\n");
                letter = letter + key;
                printf("%c\n", letter);
               }
               else
               {
               }
           }
        }
}