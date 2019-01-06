// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize infile outfile size_in_int\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];
    int n = atoi(argv[3]);

    // Conversion error handling
    
    if (n == 0)
    {
        printf("Invalid argument. You entered '%s', please enter integer for resize value.\n", argv[3]);
    }


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // adjust header properties for resized image
    int padding_before = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int biWidth_before = bi.biWidth;
    int biHeight_before = bi.biHeight;
    bi.biWidth *= n;
    bi.biHeight *= n;
    int padding_after = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding_after) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    RGBTRIPLE pixel_array[(bi.biWidth * sizeof(RGBTRIPLE))];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(biHeight_before); i < biHeight; i++)
    {
        int pixel_array_size = 0;
        // iterate over pixels in scanline
        for (int j = 0; j < biWidth_before; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for (int x = 0; x < n; x++)
            {
                pixel_array[pixel_array_size] = triple;
                pixel_array_size++;
               // fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);


            }
        }

        printf("%i\n", pixel_array_size);

        for (int y = 0; y < n; y++)
        {

            fwrite(pixel_array, sizeof(RGBTRIPLE), bi.biWidth, outptr);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding_after; k++)
            {
                fputc(0x00, outptr);
            }
        }
        // skip over padding, if any
        fseek(inptr, padding_before, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
