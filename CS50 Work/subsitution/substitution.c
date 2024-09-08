#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char getConverted(char strKey[], char c);
bool checkKey(char strKey[], int intLength);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            char strArray[26];
            for (int i = 0, n = strlen(argv[1]);i < n; i++)
            {
                strArray[i] = toupper(argv[1][i]);
            }
            if (checkKey(strArray, strlen(argv[1])))
            {
                string strWords = get_string("plaintext:");
                printf("ciphertext: ");
                for (int i = 0, n = strlen(strWords);i < n; i++)
                {
                    if (isalpha(strWords[i]))
                    {
                        printf("%c", getConverted(strArray, strWords[i]));
                    }
                    else
                    {
                        printf("%c", strWords[i]);
                    }

                }
                printf("\n");
                return 0;
            }
            else
            {
                printf("Key Has Duplicates.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 1;


}

char getConverted(char strKey[], char c)
{
    bool shouldConvert = false;
    if (islower(c))
    {
        shouldConvert = true;
    }
    int intC = toupper(c) - 'A';
    intC = strKey[intC];
    if (shouldConvert)
    {
        return tolower(intC);
    }
    return (intC);
}

bool checkKey(char strKey[], int intLength)
{
    int strOtherArray[26] = {0};
    int intTemp = 0;
    for (int i = 0; i < intLength; i++)
    {
        if (!isalpha(strKey[i]))
        {
            return false;
        }
        else if (strOtherArray[toupper(strKey[i]) - 'a'] == 1)
        {
            return false;
        }
        else
        {
            strOtherArray[toupper(strKey[i]) - 'a'] = 1;
        }
    }
    return true;
}
