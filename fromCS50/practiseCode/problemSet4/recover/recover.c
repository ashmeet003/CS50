/*
    For the code to work and images to be stored in output folder:
    cd output
    ./recover.exe card.raw
    to remove images:
    rm *.jpg
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 512 // size of each block in file

int main(int argc, char *argv[])
{
    if (argc != 2) // if more or less than 2 arguments passes
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "rb"); // opens raw card file
    if (card == NULL)                 // if file couldn't be opened exits code
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[DATA_SIZE];
    // to name output img files
    char name[8];
    int fileNum = 0;
    // File pointer for output image
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, DATA_SIZE, card) == DATA_SIZE)
    {
        // Create JPEGs from the data
        // 0xff 0xd8 0xff 0xe*
        bool is_jpeg = buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
                       (buffer[3] & 0xF0) == 0xE0;
        if (is_jpeg) // if new image file header is found
        {
            if (img != NULL) // if a file is already open
            {                // its been written into already
                fclose(img); // then close the current file to open new
                fileNum++;   // file number is increased
            }

            sprintf(name, "%03i.jpg", fileNum); // names file name as 000.jpg; 001.jpg

            img = fopen(name, "wb"); // opens a new file to write into
            if (img == NULL)        // if couldn't be opened exits the program
            {
                printf("%s could not be opened\n", name);
                fclose(card); // closes the unopened file: card; memory leak none
                return 1;
            }
            // If already found a JPEG, keep writing blocks to it
        }

        // if a file is opened, write into it the current block of bytes
        if (img != NULL)
        {
            fwrite(buffer, 1, DATA_SIZE, img);
        }
    }

    // Close last image if open
    // closes last open files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
