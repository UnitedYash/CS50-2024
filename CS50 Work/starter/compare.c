#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int x = get_int("What's x: ");
    int y = get_int("What's y: ");
    if (x < y)
    {
        printf("%i is greater than %i\n", y, x);
    }
    else
    {
        printf("%i is not less than %i\n",y,x);
    }
}
