#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Set the block size to be read from the source file
#define BLOCK_SIZE 512
// Set the size of a filename to one byte
#define FILENAME_SIZE 8
typedef uint8_t BYTE;

// Function prototype
int is_jpg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Only accept a single command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    // Check that file was successfully opened. If not, notify user
    if (card == NULL)
    {
        printf("File can not be opened.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[FILENAME_SIZE];
    FILE *img;
    int file_count = 0;

    while (fread(buffer, BLOCK_SIZE, 1, card))
    {
        if (is_jpg(buffer) == 1)
        {
            if (file_count != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", file_count++);
            img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
        else if (file_count > 0)
        {
            // Keep writing to current file
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }
    fclose(img);
    fclose(card);
    return 0;
}

int is_jpg(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}
