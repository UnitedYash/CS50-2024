#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keyCipher(char c, int key);
bool isDigit1(string words);
int main(int argc, string argv[])
{
    if (argc == 2 && isDigit1(argv[1]) == true)
    {
        string strText = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(strText); i < n; i++)
        {
            if ((strText[i] < 65 || (strText[i] > 90 && strText[i] > 122)))
            {
                printf("%c", strText[i]);
            }
            else
            {
                printf("%c", keyCipher(strText[i], atoi(argv[1])));
            }

        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 1;
}


char keyCipher(char c, int key)
{
    int intKey = 0;
    if (c >= 65 && c <= 90)
    {
        intKey = c - 65;
        intKey = (intKey + key) % 26;
        intKey+=65;

    }
    else if (c >= 97 && c <=122)
    {
        intKey = c - 97;
        intKey = (intKey + key) % 26;
        intKey+=97;
    }
    return intKey;
}
bool isDigit1(string words)
{
    for (int i = 0, n = strlen(words); i < n; i++)
    {
        if (isdigit(words[i]) == false)
        {
            return false;
        }
    }
    return true;
}
