#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //check for exactly 1 argument per parameters, if not return usage error
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Next we need to open the memory card file (use the hint here) if no file, return error
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Cannot open file\n");
        return 1;
    }

    unsigned char buffer[512];
    int recoveredJPEG = 0;
    int fileCount = 0;
    FILE *jpegImage = NULL;

    // Repeat and read through to recover any images on the entire card, searching 512 at a time
    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if JPEG has been found
            if (recoveredJPEG == 1)
            {
                // Start of an image has been found, so close current image
                fclose(jpegImage);
            }
            else
            {
                recoveredJPEG = 1;
            }
            char nameless[8];
            sprintf(nameless, "%03i.jpg", fileCount);
            jpegImage = fopen(nameless, "w");
            fileCount++;
        }

        //if jpeg already open then close it
        if (recoveredJPEG == 1)
        {
            //copy from buffer into the new file
            fwrite(&buffer, 512, 1, jpegImage);
        }
    }

    if (jpegImage == NULL)
    {
        fclose(jpegImage);
    }
    if (file == NULL)
    {
        fclose(file);
    }
    return 0;
}