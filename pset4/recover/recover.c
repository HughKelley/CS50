#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// BMP-related data types based on Microsoft's own

#include <stdint.h>

// aliases for C/C++ primitive data types
// https://msdn.microsoft.com/en-us/library/cc230309.aspx
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// information about the type, size, and layout of a file
// https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx
typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

// information about the dimensions and color format
// https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx
typedef struct
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// relative intensities of red, green, and blue
// https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;



int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    char *infile = argv[1];
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int check = 0;
    char filename[8];
    int limit = 0;
    FILE *img;
    int filecount = 0;

    while (check == 0)
    {
        uint8_t *buffer = malloc(512);
        int holder = fread(buffer, 1, 512, inptr);

        if (holder == 512)
        {
            if (filecount == 0)
            {
                //look for start block
                if (buffer[0] == 0xff &&
                    buffer[1] == 0xd8 &&
                    buffer[2] == 0xff &&
                    (buffer[3] & 0xf0) == 0xe0)
                {
                    sprintf(filename, "%03i.jpg", filecount);
                    img = fopen(filename, "w");
                    fwrite(buffer, 512, 1, img);
                    filecount = filecount + 1;
                }
            }
            else
            {
                if (buffer[0] == 0xff &&
                    buffer[1] == 0xd8 &&
                    buffer[2] == 0xff &&
                    (buffer[3] & 0xf0) == 0xe0)
                {

                    fclose(img);
                    sprintf(filename, "%03i.jpg", filecount);
                    img = fopen(filename, "w");
                    fwrite(buffer, 512, 1, img);
                    filecount = filecount + 1;
                }
                else
                {
                    //write to file
                    fwrite(buffer, 512, 1, img);
                }
            }
        }
        else
        {
            check = 1;
        }
        free(buffer);
        limit = limit + 1;
        if (limit > 1000000)
        {
            check = 1;
        }
    }

    return 0;
    //end main
}