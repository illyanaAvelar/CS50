#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avarage = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avarage = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            avarage = avarage / 3;
            avarage = round(avarage);
            image[i][j].rgbtRed = avarage;
            image[i][j].rgbtGreen = avarage;
            image[i][j].rgbtBlue = avarage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE aux [height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            aux[i][j].rgbtRed = image[i][j].rgbtRed;
            aux[i][j].rgbtGreen = image[i][j].rgbtGreen;
            aux[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        int k = width;
        for (int j = 0; j < width; j++)
        {
            k--;
            image[i][j].rgbtRed = aux[i][k].rgbtRed;
            image[i][j].rgbtGreen = aux[i][k].rgbtGreen;
            image[i][j].rgbtBlue = aux[i][k].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //this matrix will contain temporary values, so we don't alterate the values that will be used to calculate the avarage of the pixels
    RGBTRIPLE aux[height][width];

    //copying the image to the auxiliary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            aux[i][j].rgbtRed = image[i][j].rgbtRed;
            aux[i][j].rgbtGreen = image[i][j].rgbtGreen;
            aux[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    //going through the image calculating the value of the pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //if it is the first line, it is a corner
            //we have to treat the corner separately
            if (i == 0)
            {
                //if it is the first row
                if (j == 0)
                {
                    image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j + 1].rgbtBlue + aux[i + 1][j].rgbtBlue +
                                                      aux[i + 1][j + 1].rgbtBlue) / 4);
                    image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j + 1].rgbtGreen +
                                                       aux[i + 1][j].rgbtGreen + aux[i + 1][j + 1].rgbtGreen) / 4);
                    image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j + 1].rgbtRed +
                                                     aux[i + 1][j].rgbtRed + aux[i + 1][j + 1].rgbtRed) / 4);
                }
                else
                    //if it is the last row
                    if (j == width - 1)
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j - 1].rgbtBlue + aux[i + 1][j].rgbtBlue +
                                                          aux[i + 1][j - 1].rgbtBlue) / 4);
                        image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j - 1].rgbtGreen +
                                                           aux[i + 1][j].rgbtGreen + aux[i + 1][j - 1].rgbtGreen) / 4);
                        image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j - 1].rgbtRed +
                                                         aux[i + 1][j].rgbtRed + aux[i + 1][j - 1].rgbtRed) / 4);
                    }
                //if it is a row in between
                    else
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j - 1].rgbtBlue + aux[i][j + 1].rgbtBlue +
                                                          aux[i + 1][j].rgbtBlue + aux[i + 1][j - 1].rgbtBlue + aux[i + 1][j + 1].rgbtBlue) / 6);
                        image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j - 1].rgbtGreen + aux[i][j + 1].rgbtGreen +
                                                           aux[i + 1][j].rgbtGreen + aux[i + 1][j - 1].rgbtGreen + aux[i + 1][j + 1].rgbtGreen) / 6);
                        image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j - 1].rgbtRed + aux[i][j + 1].rgbtRed +
                                                         aux[i + 1][j].rgbtRed + aux[i + 1][j - 1].rgbtRed + aux[i + 1][j + 1].rgbtRed) / 6);
                    }
            }
            //if it is the last line
            else if (i == height - 1)
            {
                //if it is the fisrt row
                if (j == 0)
                {
                    image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j + 1].rgbtBlue + aux[i - 1][j].rgbtBlue +
                                                      aux[i - 1][j + 1].rgbtBlue) / 4);
                    image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j + 1].rgbtGreen + aux[i - 1][j].rgbtGreen +
                                                       aux[i - 1][j + 1].rgbtGreen) / 4);
                    image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j + 1].rgbtRed + aux[i - 1][j].rgbtRed +
                                                     aux[i - 1][j + 1].rgbtRed) / 4);
                }
                else
                    //if it is the last row
                    if (j == width - 1)
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j - 1].rgbtBlue + aux[i - 1][j].rgbtBlue +
                                                          aux[i - 1][j - 1].rgbtBlue) / 4);
                        image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j - 1].rgbtGreen + aux[i - 1][j].rgbtGreen +
                                                           aux[i - 1][j - 1].rgbtGreen) / 4);
                        image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j - 1].rgbtRed + aux[i - 1][j].rgbtRed +
                                                         aux[i - 1][j - 1].rgbtRed) / 4);
                    }
                //if it is a row in between
                    else
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i][j - 1].rgbtBlue + aux[i][j + 1].rgbtBlue +
                                                          aux[i - 1][j].rgbtBlue + aux[i - 1][j - 1].rgbtBlue + aux[i - 1][j + 1].rgbtBlue) / 6);
                        image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i][j - 1].rgbtGreen + aux[i][j + 1].rgbtGreen +
                                                           aux[i - 1][j].rgbtGreen + aux[i - 1][j - 1].rgbtGreen + aux[i - 1][j + 1].rgbtGreen) / 6);
                        image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i][j - 1].rgbtRed + aux[i][j + 1].rgbtRed + aux[i - 1][j].rgbtRed +
                                                         aux[i - 1][j - 1].rgbtRed + aux[i - 1][j + 1].rgbtRed) / 6);
                    }
            }
            else
            {
                //if it is the first row
                if (j == 0)
                {
                    image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i - 1][j].rgbtBlue + aux[i + 1][j].rgbtBlue +
                                                      aux[i][j + 1].rgbtBlue + aux[i - 1][j + 1].rgbtBlue + aux[i + 1][j + 1].rgbtBlue) / 6);
                    image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i - 1][j].rgbtGreen + aux[i + 1][j].rgbtGreen +
                                                       aux[i][j + 1].rgbtGreen +  aux[i - 1][j + 1].rgbtGreen +  aux[i + 1][j + 1].rgbtGreen) / 6);
                    image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i - 1][j].rgbtRed + aux[i + 1][j].rgbtRed +
                                                     aux[i][j + 1].rgbtRed + aux[i - 1][j + 1].rgbtRed + aux[i + 1][j + 1].rgbtRed) / 6);
                }
                else
                    //last row
                    if (j == width - 1)
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i][j].rgbtBlue + aux[i - 1][j].rgbtBlue + aux[i + 1][j].rgbtBlue +
                                                          aux[i][j - 1].rgbtBlue + aux[i - 1][j - 1].rgbtBlue + aux[i + 1][j - 1].rgbtBlue) / 6);
                        image[i][j].rgbtGreen = round(ceil(aux[i][j].rgbtGreen + aux[i - 1][j].rgbtGreen + aux[i + 1][j].rgbtGreen +
                                                           aux[i][j - 1].rgbtGreen + aux[i - 1][j - 1].rgbtGreen + aux[i + 1][j - 1].rgbtGreen) / 6);
                        image[i][j].rgbtRed = round(ceil(aux[i][j].rgbtRed + aux[i - 1][j].rgbtRed + aux[i + 1][j].rgbtRed + aux[i][j - 1].rgbtRed +
                                                         aux[i - 1][j - 1].rgbtRed + aux[i + 1][j - 1].rgbtRed) / 6);
                    }
                //middle
                    else
                    {
                        image[i][j].rgbtBlue = round(ceil(aux[i - 1][j - 1].rgbtBlue + aux[i - 1][j].rgbtBlue + aux[i - 1][j + 1].rgbtBlue +
                                                          aux[i][j - 1].rgbtBlue + aux[i][j].rgbtBlue + aux[i][j + 1].rgbtBlue +
                                                          aux[i + 1][j - 1].rgbtBlue + aux[i + 1][j].rgbtBlue + aux[i + 1][j + 1].rgbtBlue) / 9);
                        image[i][j].rgbtGreen = round(ceil(aux[i - 1][j - 1].rgbtGreen + aux[i - 1][j].rgbtGreen + aux[i - 1][j + 1].rgbtGreen +
                                                           aux[i][j - 1].rgbtGreen + aux[i][j].rgbtGreen + aux[i][j + 1].rgbtGreen +
                                                           aux[i + 1][j - 1].rgbtGreen + aux[i + 1][j].rgbtGreen + aux[i + 1][j + 1].rgbtGreen) / 9);
                        image[i][j].rgbtRed = round(ceil(aux[i - 1][j - 1].rgbtRed + aux[i - 1][j].rgbtRed + aux[i - 1][j + 1].rgbtRed +
                                                         aux[i][j - 1].rgbtRed + aux[i][j].rgbtRed + aux[i][j + 1].rgbtRed +
                                                         aux[i + 1][j - 1].rgbtRed + aux[i + 1][j].rgbtRed + aux[i + 1][j + 1].rgbtRed) / 9);
                    }
            }
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int sobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //a temporary value to Red Green and Blue calculated values
    int value = 0;
    int SXred, SXgreen, SXblue, SYred, SYgreen, SYblue;
    //this matrix will contain temporary values, so we don't alterate the values that will be used
    RGBTRIPLE aux[height][width];

    //copying the image to the auxiliary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            aux[i][j].rgbtRed = image[i][j].rgbtRed;
            aux[i][j].rgbtGreen = image[i][j].rgbtGreen;
            aux[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //these values are cumulative, so they need to be reset for each pixel
            SXred = 0;
            SXgreen = 0;
            SXblue = 0;
            SYred = 0;
            SYgreen = 0;
            SYblue = 0;
            //a 3x3 matrix of the pixels around the one we want to calculate
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    //using the Sobel operator
                    if (!(i - 1 + m < 0 || i - 1 + m > height - 1 || j - 1 + n < 0 || j - 1 + n > width - 1))
                    {
                        SXred = SXred + (aux[i - 1 + m][j - 1 + n].rgbtRed * sobelX[m][n]);
                        SXgreen = SXgreen + (aux[i - 1 + m][j - 1 + n].rgbtGreen * sobelX[m][n]);
                        SXblue = SXblue + (aux[i - 1 + m][j - 1 + n].rgbtBlue * sobelX[m][n]);
                        SYred = SYred + (aux[i - 1 + m][j - 1 + n].rgbtRed * sobelY[m][n]);
                        SYgreen = SYgreen + (aux[i - 1 + m][j - 1 + n].rgbtGreen * sobelY[m][n]);
                        SYblue = SYblue + (aux[i - 1 + m][j - 1 + n].rgbtBlue * sobelY[m][n]);
                    }
                }
            }
            //assigning the rgb value of the pixel
            value = round(sqrt((SXred * SXred) + (SYred * SYred)));
            if (value > 255)
            {
                value = 255;
            }
            image[i][j].rgbtRed = value;

            value = round(sqrt((SXgreen * SXgreen) + (SYgreen * SYgreen)));
            if (value > 255)
            {
                value = 255;
            }
            image[i][j].rgbtGreen = value;

            value = round(sqrt((SXblue * SXblue) + (SYblue * SYblue)));
            if (value > 255)
            {
                value = 255;
            }
            image[i][j].rgbtBlue = value;

        }
    }
    return;
}