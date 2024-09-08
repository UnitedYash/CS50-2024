#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getPoints(char c);


int scrabbleArray[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int main(void)
{
    string strUser1 = get_string("Player 1: ");
    string strUser2 = get_string("Player 2: ");
    int intUser1 = 0;
    int intUser2 = 0;
    for (int i = 0, n = strlen(strUser1); i < n; i++)
    {
        intUser1 += getPoints(toupper(strUser1[i]));
    }
    for (int i = 0, n = strlen(strUser2); i < n; i++)
    {
        intUser2 += getPoints(toupper(strUser2[i]));
    }

    if (intUser1 > intUser2)
    {
        printf("Player 1 wins!\n");
    }
    else if (intUser1 < intUser2)
    {
        printf("Player 2 wins!\n");
    }
    else if (intUser1 == intUser2)
    {
        printf("Tie!\n");
    }

}


int getPoints(char c)
{
    if (c >= 65 && c <= 90)
    {
        int intIndex = c - 65;
        return scrabbleArray[intIndex];
    }
    return 0;
}
