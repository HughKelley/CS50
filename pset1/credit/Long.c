#include <cs50.h>

long long subtract_long_longs(void)
{
    // read long long from stdin
    long long i = get_long_long("Enter a long long: ");

    // make sure we read one successfully
    if (i == LLONG_MAX)
    {
        return LLONG_MAX;
    }

    long long j = get_long_long("What do you want to subtract from %lld? ", i);

    if (j == LLONG_MAX)
    {
        return LLONG_MAX;
    }

    return i - j;
}