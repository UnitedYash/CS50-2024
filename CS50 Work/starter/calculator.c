#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("enter x: ");
    int y = get_int("enter y: ");

    double z = (double)x / (double) y;
    printf("%.20f\n", z);
}


