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

        int keylen = strlen(argv[1]);
        int check = 0;
        string cipher = argv[1];

        for (int i = 0; i < keylen; i++)
        {
            if (isalpha(cipher[i]))
            {

            }
            else
            {
                check = 1;
            }
        }

        if (check != 0)
        {
            printf("error\n");
            return 1;
        }
        else
        {


            //get the string to be encrypted
            string p = get_string("plaintext: ");
            int stringlen = strlen(p);
            printf("ciphertext: ");

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n
            //encipher\n

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //encipher\n

            ////////\n
            //determine key
            ///////////

            //key counter variable
            int h = 0;

            for (int i = 0; i < stringlen; i++)
            {


                ////////
                //determine key
                ///////////
                int ind = h % keylen;
                //printf("h = %i\n", h);

                //printf("ind: %i\np length: %i\n", ind, stringlen);

                int key = cipher[ind];     // the key is the integer value of the given character of the key word

                //printf("key : %i \n", key);

                if (isupper(key))
                {
                    // convert to alpha key by subtracting necessary value
                    key = key - 65;
                    //printf("key: %i \n", key);
                }
                else
                {
                    //case doesn't matter for characters in the key is all lower case alphabetical indexed
                    if (islower(key))
                    {
                        // convert to alpha key by subtracting necessary value
                        key = key - 97;
                        //printf("key: %i \n", key);
                    }
                    else
                    {

                    }
                    //printf("key is: %i \n", key);
                }

                if (isalpha(p[i]))
                {

                    if (isupper(p[i]))
                    {
                        char target = p[i];

                        target = target - 65;

                        target = target + key;

                        target = target % 26;

                        target = target + 65;

                        printf("%c", target);
                        h = h + 1;
                    }

                    if (islower(p[i]))
                    {

                        char target = p[i];

                        target = target - 97;
                        target = target + key;
                        target = target % 26;
                        target = target + 97;
                        printf("%c", target);
                        h = h + 1;
                    }

                }
                else
                {
                    printf("%c", p[i]);
                }



            }//close for loop that moves through key chars

        } //close isalpha check for each char in key string

    }//close argv size check

    printf("\n");

}