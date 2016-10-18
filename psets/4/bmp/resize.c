#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

#define BYTES_PER_PIXEL 3

int checkFactor(char* arg);
int StrToInt(char* str);

int main(int argc, char* argv[])
{   

    
    // make sure that the program is started with required number of arguments
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // save the arguments
    char* factorArg = argv[1];
    char* inName = argv[2];
    char* outName = argv[3];
    int factor;
    // make sure that the factor is acceptable
    if (!checkFactor(factorArg)) {
        printf("Please enter a valid factor from 1 to N.\n");
        return 4;
    }

    else {
        factor = StrToInt(factorArg);
    }

    // open the input file for reading and make sure it was successful otherwise exit
    FILE* inFile = fopen(inName, "r");
    if (inFile == NULL)
    {
        printf("could not open file %s. Maybe it doesn't exist ?\n", inName);
        return 2;
    }

    // open the output file for writing and make sure it was successful otherwise exit
    FILE* outFile = fopen(outName, "w");
    if (outFile == NULL)
    {
        printf("Could not create file %s.\n", outName);
        fclose(inFile);
        return 3;
    }
    
    // read the headers of the the BMP file into the structures from bmp.h
    // in order to make sure that the file is a BMP and use the info in the headers later.
    BITMAPFILEHEADER fHeader;
    fread(&fHeader, sizeof(BITMAPFILEHEADER), 1, inFile);

    BITMAPINFOHEADER infHeader;
    fread(&infHeader, sizeof(BITMAPINFOHEADER), 1, inFile);


    // make sure that the image file is a 24-bit BMP
    if (fHeader.bfType != 0x4d42 || fHeader.bfOffBits != 54 || infHeader.biSize != 40 || 
        infHeader.biBitCount != 24 || infHeader.biCompression != 0)
    {
        printf("Sorry, File is not supported.\n");
        fclose(inFile);
        fclose(outFile);
        return 4;
    }

    // keep the old height and width to use for reading the image

    LONG oldBiWidth = infHeader.biWidth;
    LONG oldBiHeight = infHeader.biHeight;
    int oldPadding =  (4 - (infHeader.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update the new height and width
    infHeader.biWidth *= factor;
    infHeader.biHeight *= factor;

    // determine padding for scanlines
    int padding =  (4 - (infHeader.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate new image size including padding but (without the headers)
    infHeader.biSizeImage = (infHeader.biWidth * abs(infHeader.biHeight)) * BYTES_PER_PIXEL + (padding * BYTES_PER_PIXEL);
    
    // calculate new file size which includes everything image + headers
    fHeader.bfSize = infHeader.biSizeImage + fHeader.bfOffBits;

    // write the file headers to the new resized image file
    fwrite(&fHeader, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&infHeader, sizeof(BITMAPINFOHEADER), 1, outFile);


    // modifying the image pixel by pixel
    for (int i = 0, biHeight = abs(oldBiHeight); i < biHeight; i++)
    {      

        // an array to keep each row
        RGBTRIPLE* tripleRow = malloc(sizeof(RGBTRIPLE) * oldBiWidth);

        // printf("padding: %i\tw: %i\n", oldPadding, oldBiWidth);

        // read current row into array
        for (int j = 0; j < oldBiWidth; j++)
        {
            fread(&tripleRow[j], sizeof(RGBTRIPLE), 1, inFile);
            // printf("%x\n", tripleRow[j]);
        }

        // SEEK THROUGH PADDING. DO NOT READ OLD PADDING (IT'S BAD FOR YA!)
        fseek(inFile, oldPadding, SEEK_CUR);

        // write new image pixels to file
        for (int h = 0; h < factor; h++)
        {   
            // resize vertically (write the pixel row again "factor" times)
            for (int w = 0; w < oldBiWidth; w++)
            {   
                // resize horizontaly (write the pixel again in the same row "factor" times)
                for (int k = 0; k < factor; k++)
                {   
                    // write a pixel to file
                    fwrite(&tripleRow[w], sizeof(RGBTRIPLE), 1, outFile);
                }
            }

            // add padding to current row
            for (int p = 0; p < padding; p++)
            {
                fputc(0x00, outFile);
            }

        }

        // free the array that contains the pixels of current row
        free(tripleRow);
    }


    fclose(inFile);
    fclose(outFile);
    
    return 0;
}


int checkFactor(char* arg)
{
    for (int i = 0; i < strlen(arg); i++)
    {
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return 0;
    }

    return 1;
}

int StrToInt(char* str)
{      
    char* end;
    int num = (int) strtol(str, &end, 10);

    return num;
}
