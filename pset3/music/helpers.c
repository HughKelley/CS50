

// Helper functions for music

#include <cs50.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

/*
string get_string(va_list *args, const string format, ...) __attribute__((format(printf, 2, 3)));
string GetString(void) __attribute__((deprecated));
#define get_string(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_string(NULL, NULL)))(get_string(NULL, __VA_ARGS__))
*/

/*
 * Prompts user for a line of text from standard input and returns
 * it as a string (char *), sans trailing line ending. Supports
 * CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user
 * inputs only a line ending, returns "", not NULL. Returns NULL
 * upon error or no input whatsoever (i.e., just EOF). Stores string
 * on heap, but library's destructor frees memory on program's exit.
 */


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    //get string input
    //return to user the number of eighth notes that the note should be
    // over 8 over 4 over 2 over over 1
    //first is numberator
    //last is denominator
    //use atoi to convert to integer value
    //printf("duration fraction: %s\n", fraction);

    int num = atoi(&fraction[0]);
    int den = atoi(&fraction[2]);


    for (int i = 0; i < 5; i++)
    {
        if (den < 8)
        {
            num = num * 2;
            den = den * 2;
        }
    }

//printf("num: %i\n",num);
//printf("den: %i\n",den);


    return num;



}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //match letter to a letter in NOTES string

    float freq = 261.63;

    //Start with what note it is

    char NOTES[] = {'C', 'Z', 'D', 'Y', 'E', 'F', 'X', 'G', 'W', 'A', 'V', 'B'};

    for (int i = 0; i < 12; i++)
    {
        if (note[0] == NOTES[i])
        {
            float up = pow(2, i / 12.0);
            freq = freq * up ;
        }
    }

    //then adjust for flat or sharp
    int accidental = 0;

    if (note[1] == '#')
    {
        freq = freq * pow(2, 1 / 12.0);
        accidental = 1;
    }

    if (note[1] == 'b')
    {
        freq = freq / pow(2, 1 / 12.0);
        accidental = 1;
    }

    //then adjust for octave

    //printf("freq before octave change: %f\n",freq);

    int oct = 0;

    if (accidental == 0)
    {
        oct = atoi(&note[1]);
    }

    if (accidental == 1)
    {
        oct = atoi(&note[2]);
    }

    if (oct < '4')
    {
        //int down = 4 - oct;
        //printf("down : %i\n", down);
        freq = freq / pow(2, (4.0 - oct));
    }

    if (oct > '4')
    {
        //int up = oct - 4;
        //printf("up by: %i\n",up);
        freq = freq * pow(2, (oct - 4.0));
    }

    //printf("freq after octave change: %f\n",freq);

    freq = round(freq);

    return freq;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    //get "s" loaded in and accesible
    //get first couple characters in the string loaded in
    //check if the first character is /r or /n
    //return true or false

    int check = s[0];

    if (check == 0)
    {
        //printf("it is a rest\n");
        return 1;
    }
    else
    {
        //printf("must not be a rest\n");
        return 0;
    }



}
