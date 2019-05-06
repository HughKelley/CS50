#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string answer[10];

int main()
{


for (int i = 0; i < 10; i++)
{
    char text = get_char("Enter character: ");

    answer[i] = text;


}

printf("%s\n", answer);

}