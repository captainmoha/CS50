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

typedef uint8_t BYTE;
int isStartJPG(BYTE* buffer);

int main(void)
{
    
    FILE* imgFile = fopen(RAW_IMG, "r");
    FILE* newImg;

    BYTE buffer[512];

    int imagesFound = 0;
    int isWriting = 0;
    char title[5];

    while(fread(buffer, sizeof(buffer), 1, imgFile) == 1)
    {   
        // printf("in\n");

        BYTE bufferBegin[3];

        for (int i = 0; i < 3; i++)
        {
            bufferBegin[i] = buffer[i];
        }

        if (isStartJPG(bufferBegin))
        {   
            isWriting = 1;
            imagesFound++;
            // printf("Images found %03d\n", imagesFound);
            sprintf(title, "%03d.jpg", imagesFound-1);
            if (imagesFound > 1)
                fclose(newImg);
            newImg = fopen(title, "w");
        }

        if (isWriting)
            fwrite(buffer, sizeof(buffer), 1, newImg);
        
    }

    fclose(newImg);
    fclose(imgFile);
}

int isStartJPG(BYTE* buffer)
{   
    BYTE JPG_mark[] = {0xff, 0xd8, 0xff};

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
