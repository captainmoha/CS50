/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define RAW_IMG "card.raw"
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int isStartJPG(BYTE* buffer);

int main(void)
{
    
    // open the raw image file
    FILE* rawImgFile = fopen(RAW_IMG, "r");

    // this file will contain the jpg we're currently writing to
    FILE* newImg;

    // this string will keep the title of the current jpg
    char title[5];

    // buffer for reading the raw image file block by block since it was a fat32 file system
    BYTE buffer[BLOCK_SIZE];

    // number of images found so far
    int imagesFound = 0;

    // flag to signify when we should start writing the first image
    int isWriting = 0;


    // read the raw file block by block and store each block in a buffer until the file is over
    while(fread(buffer, sizeof(buffer), 1, rawImgFile) == 1)
    {   
        // printf("in\n");

        // store the first 3 bytes of the bufffer in an array in order to pass it to the isStartJPG function
        BYTE bufferBegin[3];
        for (int i = 0; i < 3; i++)
        {
            bufferBegin[i] = buffer[i];
        }

        // if the block is the first block of a jpg
        if (isStartJPG(bufferBegin))
        {   
            // start writing!
            isWriting = 1;
            imagesFound++;

            // printf("Images found %03d\n", imagesFound);

            // format the title in the form of 000-nnn
            sprintf(title, "%03d.jpg", imagesFound-1);

            // if we find another image let's close the old image file to save it
            if (imagesFound > 1)
                fclose(newImg);

            // and then open a new file to store the new image in
            newImg = fopen(title, "w");
        }

        // write only if we are writing to a jpg file
        if (isWriting)
            fwrite(buffer, sizeof(buffer), 1, newImg);
        
    }

    // close the raw image file and the new image file
    fclose(newImg);
    fclose(rawImgFile);
}

int isStartJPG(BYTE* buffer)
{   
    /*
    *   takes the first 3 bytes of a buffer from a fat file-system file
    *   returns whether or not the buffer is the start of a jpg file
    */

    // every jpg image starts with these three bytes
    BYTE JPG_mark[] = {0xff, 0xd8, 0xff};

    // check if the bytes are correct jpg markers

    for (int i = 0; i < 3; i++)
    {   
        // printf("b : %x\tj : %x\n", buffer[i], JPG_mark[i]);
        if (!(buffer[i] == JPG_mark[i]))
        {   
            // printf("nope\n");
            return 0;
        }
    }
    // printf("YEAH\n");
    return 1;
}
