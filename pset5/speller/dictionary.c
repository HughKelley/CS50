/**
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include <string.h>

//define node struct here

//declare size variable here

typedef struct node
{
    bool is_word;                   //if this is true then the node is the end of a full word
    struct node *children[27];      //space for 26 letters and '
}
node;

node *root;

int *number_of_words;

/*
void * calloc(size_t nmemb, size_t size);
The calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
The memory is set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().
*/

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{

    int size = strlen(word);
    //bool checkval = false;
    node *active_pointer = root;
    int alpha_index = 0;
    bool ohword = false;
    int j = 0;
    bool wrong = false;
    bool ptr_check = true;

    while (j < size && ptr_check == true)
    {
        ohword = active_pointer->is_word;
        if (word[j] == '\'')
        {
            alpha_index = 26;
        }
        else
        {
            if (isupper(word[j]))
            {
                alpha_index = (tolower(word[j]) - 'a');
            }
            else
            {
                alpha_index = word[j] - 'a';
            }
        }

        if (active_pointer->children[alpha_index] == NULL)
        {
            ptr_check = false;
        }
        else
        {
            active_pointer = active_pointer->children[alpha_index];
        }
        j = j + 1;
    }

    if (ptr_check == false && active_pointer->children[alpha_index] == NULL)
    {
        //printf("fail on %ith letter\n", j);
        wrong = true;
    }
    else if (active_pointer->is_word == false)
    {
        wrong = true;
    }
    else
    {
        wrong = false;
    }

    return !wrong;          /*obviously this is a little weird but I saw that my code was returning exactly the opposite of the
                            correct answer and decided that rather than go back and change every true and false in the script
                            without missing any, using ! to invert was the most straightforward way to fix that.
                            Thiking about it right now, I think the code should return false if the word is spelled correctly
                            since that is the opposite of what is sensible, but an if statement evaluations true if the contents
                            evaluate to 0 like when using strcmp so maybe it should return true is the word is spelled right?
                            I'm full Vizzini from Princess Bride status trying to write this code correctly
                            Curious to see what using ! means for time required to run anyway, i think it will be negligible.
                            */
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    number_of_words = calloc(1, sizeof(int));

    // TODO

    root = calloc(1, sizeof(struct node));

    node *curr_pointer = root;

    //char *dict = (argc == 3) ? argv[2] : argv[1];

    //OPEN File

    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return 1;
    }

    int alpha_index = 0;
    int count = 0;
    bool wordtorf = false;

    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        //printf("%c", c);
        wordtorf = curr_pointer->is_word;


        //CREATE INDEX
        if (isalpha(c) || c == '\'')
        {
            if (c == '\'')
            {
                alpha_index = 26;
            }
            else if (isupper(c))
            {
                //-A
                alpha_index = c - 'A';
            }
            else
            {
                //-a
                alpha_index = c - 'a';
            }

            if (curr_pointer->children[alpha_index] == NULL)
            {
                //printf("create new node");
                curr_pointer->children[alpha_index] = calloc(1, sizeof(node));
            }

            curr_pointer = curr_pointer->children[alpha_index];
        }
        else
        {
            //must be a new word
            curr_pointer->is_word = true;
            wordtorf = curr_pointer->is_word;
            curr_pointer = root;

            //printf("update count\n");
            count = count + 1;
        }

    }

    fclose(fp);

    *number_of_words = count;
    //wordtorf = curr_pointer->is_word;

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return *number_of_words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */

bool freedom(node *point)
{

    //printf("freedom");

    for (int i = 0; i < 27; i++)
    {
        if (point->children[i] == NULL)
        {

        }
        else
        {
            freedom(point->children[i]);
        }
    }

    free(point);

    return true;



}

bool unload(void)
{
    // TODO
    //printf("unload script\n");

    node *rooter = root;


    freedom(rooter);

    free(number_of_words);

    return true;
}