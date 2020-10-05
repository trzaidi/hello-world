#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate pixels for height and width
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //need to get current average of R G B values for pixel image
            RGBTRIPLE pixel = image[i][j];
            int average =  round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);

            //need to replace extracted values with int average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            //apply sepia formula to the pixel values, assign as int, round value to int
            //**instruction said to use exact formula so assigning int value to givein originalColors int
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            //cap the value at 255 per instruction
            if (sepiaRed < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (sepiaGreen < 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaBlue < 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //need a temporary array to use
    RGBTRIPLE temppixel[((width - 1)/2)+ 1];

    //swap the location values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= round((width - 1)/ 2) ; j++)
        {
            temppixel[j] = image[i][j];
        }
        for (int j = 0; j <= round((width - 1)/ 2) ; j++)
        {
            image[i][j] = image[i][width + (-j - 1)];
        }
        for (int j = 0; j <= round((width - 1)/ 2) ; j++)
        {
            image[i][width + (-j - 1)] = temppixel[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //image copy
    RGBTRIPLE temppixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blurRed = 0;
            int blurGreen = 0;
            int blurBlue = 0;
            int counter = 0;

            // Iterate through each neighbor around the pixel
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    // If the i-value or j-value is invalid, ignore the pixel
                    if (i + r >= 0 && i + r <= height - 1 && j + c >= 0 && j + c <= width - 1)
                    {
                        blurRed = blurRed + image[i + r][j + c].rgbtRed;
                        blurGreen = blurGreen + image[i + r][j + c].rgbtGreen;
                        blurBlue = blurBlue + image[i + r][j + c].rgbtBlue;
                        counter++;
                    }
                }
            }
            // Total up and average out pixel values and store in temppixel
            temppixel[i][j].rgbtRed = round((float) blurRed / counter);
            temppixel[i][j].rgbtGreen = round((float) blurGreen / counter);
            temppixel[i][j].rgbtBlue = round((float) blurBlue / counter);

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temppixel[i][j];
        }
    }
    return;
}
