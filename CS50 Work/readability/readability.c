#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//string[] getWords(string strWords);

int main(void)
{
    string strWords = get_string("Enter: ");
    int intAverageNumWords = 0;
    int intNumberOfWords = 0;
    int intNumberOfSentences = 0;
    for (int i = 0, n = strlen(strWords); i < n;i++)
    {
        if (intNumberOfWords <= 100)
        {
            if (toupper(strWords[i]) >= 65 && toupper(strWords[i]) <= 90)
            {
                intAverageNumWords++;
            }
            else if (strWords[i] == ' ')
            {
                intNumberOfWords++;
            }
            else if (strWords[i] == '!' || strWords[i] == '.' || strWords[i] == '?')
            {
                intNumberOfSentences++;
            }

        }

    }
    intNumberOfWords++;
    float intL = 0;
    float intS = 0;

    intL = (intAverageNumWords / (float)intNumberOfWords) * 100.0;
    intS = (intNumberOfSentences / (float)intNumberOfWords) * 100.0;


    float intFormula = 0.0588 * intL - 0.296 * intS - 15.8;
    int Formula = (int)(intFormula + 0.50);
    if (Formula < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Formula > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Formula);
    }
}
