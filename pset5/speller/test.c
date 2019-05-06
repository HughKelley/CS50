//Implenent a Trie

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check for correct number of args
    if (argc != 2)
    {
        printf("Usage: ./test word\n");
        return 1;
    }

    char *word = argv[1];

    typedef struct node
    {
        bool is_word;                   //if this is true then the node is the end of a full word
        struct node *children[27];      //space for 26 letters and '
    }
    node;

    node *root = malloc(sizeof(struct node)); //should be globally declared

    node *current_pointer = root;   //this one will change to reflect progress along the trie path

    int alpha_index = 0;

    int word_length = strlen(word);

    printf("length: %i\n", word_length);

    int curr_letter;

    for(int i =0; i <strlen(word); i++)
    {

        if (&word[i] == NULL)        //end of a word
        {
            printf("null");
            current_pointer->is_word = true;
            current_pointer = root;
        }
        else
        {
            if(isalpha(word[i]))
            {
                printf("is alpha\n");
                if (isupper(word[i]))
                {
                    printf("%c\n", word[i]);
                    //alpha_index = word[i] - 'A';
                    curr_letter = word[i]- 'A';
                    printf("current letter upper: %i\n",curr_letter);
                }
                else
                {
                    printf("%c\n", word[i]);
                    alpha_index = word[i] - '\'';
                    curr_letter = word[i] - '\'';
                    printf("current letter lower: %i\n",curr_letter);
                }
            }
            else
            {
                if (word[i] == '\'')
                {
                    curr_letter = word[i] - 12;
                }
            }

            if (current_pointer->children[curr_letter] == NULL)
            {
                printf("create pointer for %i\n", curr_letter);

                current_pointer->children[curr_letter] = calloc(1,sizeof(struct node));


            }

                printf("set pointer value\n");
                current_pointer = current_pointer->children[curr_letter];

        }
    }


//print

current_pointer = root;

for (int l = 0; l < 27; l++)
{
    //printf("for loop");

    if (current_pointer->children[l] == NULL)
    {
        printf("null\n");

    }
    else
    {
        printf("letter found is: %c\n",l+'a');
        current_pointer = current_pointer->children[l];
        l = 0;
    }
}

printf("\n");
 //end main

}



//https://www.geeksforgeeks.org/trie-insert-and-search/