#include <cs50.h>
#include <stdio.h>
int intCheckSum(long cardNum);
int getType(long cardNum);
int intNumber(long n);
int main(void)
{
    long n = get_long("Number: ");
    int intCheck = intCheckSum(n) % 10;
    int intNumbers = intNumber(n);
    if (intCheck == 0)
    {
        int intDigit = getType(n);
        if (intDigit == 0)
        {
            printf("INVALID\n");
        }
        else if ((intDigit == 37 || intDigit == 34) && intNumbers == 15)
        {
            printf("AMEX\n");
        }
        else if (intDigit == 51 || intDigit == 52 || intDigit == 53 || intDigit == 54 ||
                 intDigit == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (intDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int intCheckSum(long cardNum)
{
    long card = cardNum;
    int intCount = 1;
    int intDigit;
    int intProduct1 = 0;
    int intProduct2 = 0;
    int intTemp;

    while (cardNum > 0)
    {
        intDigit = cardNum % 10;
        cardNum = cardNum / 10;
        if (intCount % 2 == 0)
        {
            if (intDigit * 2 > 9)
            {
                intTemp = intDigit * 2;
                while (intTemp > 0)
                {
                    intDigit = intTemp % 10;
                    intTemp = intTemp / 10;
                    intProduct1 += intDigit;
                }
            }
            else
            {
                intProduct1 += intDigit * 2;
            }
            intCount++;
        }
        else
        {
            intProduct2 += intDigit;
            intCount++;
        }
    }
    return intProduct2 + intProduct1;
}

int getType(long n)
{
    int intCount = 0;
    long card = n;
    int intDigit = 0;
    while (card > 0)
    {
        card = card / 10;
        intCount++;
    }
    card = n;
    int intCardNum = 0;
    if (intCount == 15)
    {
        intCount = 0;
        while (card > 0)
        {
            card = card / 10;
            if (intCount == 12)
            {
                intDigit = card % 100;
                intCardNum = intDigit;
            }
            intCount++;
        }
    }
    else if (intCount == 13)
    {
        intCount = 0;
        while (card > 0)
        {
            card = card / 10;
            if (intCount == 11)
            {
                intDigit = card % 100;
                intCardNum = intDigit;
            }
            intCount++;
        }
    }
    else if (intCount == 16)
    {
        intCount = 0;
        while (card > 0)
        {
            card = card / 10;
            if (intCount == 13)
            {
                intDigit = card % 100;
                intCardNum = intDigit;
            }
            intCount++;
        }
        if (intCardNum / 10 % 10 == 4)
        {
            intCardNum = 4;
        }
    }
    else
    {
        intCardNum = 0;
    }
    return intCardNum;
}

int intNumber(long n)
{
    int intCount = 0;
    long number = n;
    while (number > 0)
    {
        number = number / 10;
        intCount++;
    }
    return intCount;
}
