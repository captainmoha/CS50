#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{	

	
	// make sure that the program is started with required number of arguments
	if (argc != 3)
	{
		printf("Usage: ./whodunit inputImg outputImg\n");
		return 1;
	}

	// save the names of the files
	char* inName = argv[1];
	char* outName = argv[2];

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

	// write the file headers to the new verdict image file
	fwrite(&fHeader, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&infHeader, sizeof(BITMAPINFOHEADER), 1, outFile);

	for (int i = 0, biHeight = abs(infHeader.biHeight); i < biHeight; i++)
	{
		for (int j = 0; j < infHeader.biWidth; j++)
		{
			RGBTRIPLE triple;
			fread(&triple, sizeof(RGBTRIPLE), 1, inFile);

			// check if the current pixel is red
			if (triple.rgbtRed == 255 && triple.rgbtGreen == 0 && triple.rgbtBlue == 0) {
				// turn into white
				triple.rgbtGreen = 255;
				triple.rgbtBlue = 255;
			}

			fwrite(&triple, sizeof(RGBTRIPLE), 1, outFile);
		}
	}

	fclose(inFile);
	fclose(outFile);
	
	return 0;
}
