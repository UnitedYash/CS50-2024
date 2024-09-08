#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int intAverage;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            intAverage = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = intAverage;
            image[i][j].rgbtGreen = intAverage;
            image[i][j].rgbtRed = intAverage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][j];
        }

    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int intRed, intBlue, intGreen;
            intRed = intBlue = intGreen = 0;
            int intCounter = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int z = -1; z < 2; z++)
                {
                    int intCurrX = i + x;
                    int intCurrZ = j + z;
                    if (intCurrX < 0 || intCurrX > (height - 1)|| intCurrZ < 0|| intCurrZ > (width - 1))
                    {
                        continue;
                    }
                    intRed += image[intCurrX][intCurrZ].rgbtRed;
                    intGreen += image[intCurrX][intCurrZ].rgbtGreen;
                    intBlue += image[intCurrX][intCurrZ].rgbtBlue;
                    intCounter++;
                }
            }
            tempImage[i][j].rgbtRed = round((intRed + 0.0) / intCounter);
            tempImage[i][j].rgbtGreen = round((intGreen + 0.0) / intCounter);
            tempImage[i][j].rgbtBlue = round((intBlue + 0.0) / intCounter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    int Gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int Gy[3][3] = {{-1,-2,-1},{0,0,0}, {1,2,1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int intRedChannel = 0;
            int intGreenChannel = 0;
            int intBlueChannel = 0;
            int intGxGreen = 0;
            int intGxBlue = 0;
            int intGxRed = 0;
            int intGyGreen = 0;
            int intGyBlue = 0;
            int intGyRed = 0;
            for (int x = -1; x < 2; x++)
            {

                for (int y = -1; y < 2; y++)
                {
                    if (i + x < 0 || i + x > height - 1 || y + j < 0 || y + j > width - 1)
                    {
                        continue;
                    }
                    intGxGreen += Gx[x + 1][y + 1] * image[i + x][j + y].rgbtGreen;
                    intGxRed += Gx[x + 1][y + 1] * image[i + x][j + y].rgbtRed;
                    intGxBlue += Gx[x + 1][y + 1] * image[i + x][j + y].rgbtBlue;
                    intGyGreen += Gy[x + 1][y + 1] * image[i + x][j + y].rgbtGreen;
                    intGyRed += Gy[x + 1][y + 1] * image[i + x][j + y].rgbtRed;
                    intGyBlue += Gy[x + 1][y + 1] * image[i + x][j + y].rgbtBlue;


                }
            }
            intRedChannel = round(sqrt(pow(intGxRed,2) + pow(intGyRed,2)));
            intGreenChannel = round(sqrt(pow(intGxGreen,2) + pow(intGyGreen,2)));
            intBlueChannel = round(sqrt(pow(intGxBlue,2) + pow(intGyBlue,2)));
            if (intRedChannel > 255)
            {
                intRedChannel = 255;
            }
            if (intGreenChannel > 255)
            {
                intGreenChannel = 255;
            }
            if (intBlueChannel > 255)
            {
                intBlueChannel = 255;
            }
            tempImage[i][j].rgbtBlue = intBlueChannel;
            tempImage[i][j].rgbtGreen = intGreenChannel;
            tempImage[i][j].rgbtRed = intRedChannel;

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}
