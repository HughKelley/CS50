
#include<stdio.h>
#include<cs50.h>

// example 378282246310005
// example 371449635398431
int main(void)
{
    int val = 0;
    long long cc_number;

    long long checkdigit;
    long long checker;
    long long sum = 0;
    int j;
    int k;

    do
    {
        cc_number = get_long_long("entire credit card number: ");
    }
    while (cc_number <= 0);

// run through doubled digits

//printf("double digits\n");

    checker = 100;
    j = 0;

    do
    {

        checkdigit = cc_number % checker;
        checkdigit = checkdigit / (checker / 10);
        //printf("%lld is the digit being checked\n", checkdigit);
        checkdigit = checkdigit * 2;
        //printf("doubles to %lld \n",checkdigit);

///////////////////////////////

        k = 1;
        long long doublecheck;
        long long doublecheckdigit;
        doublecheck = 10;

        do
        {

            doublecheckdigit = checkdigit % doublecheck;
            doublecheckdigit = doublecheckdigit / (doublecheck / 10);
            doublecheck = doublecheck * 10;
            //printf("%i is %lld\n",k, doublecheckdigit);
            sum = sum + doublecheckdigit;
            //printf("new sum is: %lld \n", sum);
            k = k + 1;
            //split digits from check digit and add separately
        }
        while (k <= 2);

/////////////////////////////////

        checker = checker * 100;
        //printf("%lld \n", sum);
        j = j + 1;

    }
    while (j < 8);

    //printf("single digits\n");

//run through single digits

    checker = 10;
    j = 0;
    do
    {
        checkdigit = cc_number % checker;
        checkdigit = checkdigit / (checker / 10);
        //printf("%lld \n", checkdigit);
        sum = sum + checkdigit;
        checker = checker * 100;
        //printf("%lld \n", sum);
        j = j + 1;

    }
    while (j < 8);

    //printf("%lld \n", sum);

// report whether card number is valid or not

    if (sum % 10 == 0)
    {
        //printf("valid\n");
        val = 1;
    }
    else
    {
        printf("INVALID\n");
        val = 0;
    }



    /////////////// Company Check

    if (val == 1)
    {
        val = 0;


        long long split = cc_number / 1000000000000;

        if (split < 10 && split >= 1)
        {

            if (split == 4)
            {
                printf("VISA\n");
                val = 1;

            }

        }
        else
        {

            split = cc_number / 100000000000000;
            if (split < 10 && split >= 1)
            {

                split = (cc_number % 10000000000000000);
                split = split / 100000000000000;

                if (split == 3)
                {
                    split = cc_number % 100000000000000;
                    split = split / 10000000000000;


                    if (split == 4 || split == 7)
                    {
                        printf("AMEX\n");
                        val = 1;
                    }
                }
            }

            else
            {

                split = cc_number % 10000000000000000;
                split = split / 1000000000000000;

                if (split < 10 && split >= 1)
                {


                    if (split == 4)
                    {
                        printf("VISA\n");
                        val = 1;
                    }
                    else
                    {
                        if (split == 5)
                        {

                            split = cc_number % 1000000000000000;
                            split = split / 100000000000000;

                            if (split == 1 || split == 2 || split == 3 || split == 4 || split == 5)
                            {
                                printf("MASTERCARD\n");
                                val = 1;
                            }
                        }
                    }

                }

            }
        }
    }

    while (val == 0)
    {
        printf("INVALID\n");
        val = 1;
    }


// AMEX 15X digits starts with 34 or 37

// Master Card 16 digits starts with 51, 52, 53, 54, 55

// Visa 13X or 16 digits starts with a 4

    /*

    American Express    378282246310005
    American Express\t    371449635398431
    MasterCard\t          5555555555554444
    MasterCard\t          5105105105105100
    Visa\t                4111111111111111
    Visa\t                4012888888881881
    Visa\t                4222222222222

    */

}