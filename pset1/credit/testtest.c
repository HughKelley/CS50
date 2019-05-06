#include<stdio.h>
#include<cs50.h>

int main(void)
{

    long long cc_number;

    do
    {
        cc_number = get_long_long("entire credit card number: ");
    }
    while (cc_number <= 0);


    int k = 1;
    long long doublechecker;
    doublechecker = 10;
    long long checkdigit;
    //split digits from checkdigit and add separately

    checkdigit = cc_number

    do
    {
        doublecheck = checkdigit % doublechecker;
        doublecheck = doublecheck / (doublechecker / 10);
        doublechecker = doublechecker * 10;

        printf("%lld",doublechecker);
        k = k + 1;
        }
        while(k <=2);



}
