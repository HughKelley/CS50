
/*
Implement your program in a file called crack.c in a directory called crack.

Your program should accept a single command-line argument: a hashed password.

If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).

Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by \n, nothing more, nothing less, with main returning 0.

Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.

Assume that each password is no longer than five (5) characters. Gasp!

Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).

Just hack together an if statement that converts from alphabeical index to ascii index and a for statement that scrolls through all 52 possible characters

*/

//make sure command line args are correct

//crypt(key, salt)

//generate password possibilities

char password[size];

do
{

for (int j = 1; j < size, j++ )
{
    password[j]


}

//put \0 at the end of each password possibility


if (crypt(password) == hashed)
{
    i = possibilities + 1;
}
}
while ( i < possibilities)




//hash with crypt

//compare
    //if different next
    //if same return the password

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

    //password parameters
        //between 1 and 5 characters
        //only alphabetical characters, upper and lower
        // 97 = a z = 122
        // 65 = A Z = 90


    //calculate size of list of every possible password
    //print every possible password


    //key question, how to break out of the for loop to check if a passwrod that's been built matches the password being looked for.

    //for loop through the posssible password sizes
        //for loop through the possible first characters
            //second
                //third
                    //fourth
                        //fifth

    //if it hasn't gotten it, give up
