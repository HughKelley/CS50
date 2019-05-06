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
    if (argc != 2)
    {
        printf("argc: %i \n", argc);
        printf("result: error\n");
        return 1;
    }

    printf("%s \n", argv[1]);

    string hash = "50pe4e2XTIS/g";  //argv[1];

    char * password = "A";
    printf("password: %s\n", password);
    //string salt = "50" ;

    string hashpass = crypt(password, "50");
    printf("hashedpass: %s\n", hashpass);
    printf("hash: %s\n", hash);


    //string A = crypt("A", "50");
    //string B = crypt("A", "50");

    if (hashedtestpassword == hashfromcommandline)
    {
    printf("match!");
    printf("hashed: %s \n", hash);
    printf("hash: %s \n", hashpass);
    }

}
