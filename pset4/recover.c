// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    unsigned char buffer[512];

    // open input file
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    char filename[10];
    int jpeg_num = 0;
    FILE *img;

    while (fread(&buffer, 512, 1, inptr) != 0)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xf0 || buffer[3] == 0xe0))
        {
            // close if jpeg already exists and is open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new jpeg file

            sprintf(filename, "%03i.jpg", jpeg_num);

            img = fopen(filename, "ab");

            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }

            jpeg_num++;

            printf("jpeg: %i\n", jpeg_num);

        
        }

        //already found a jpeg
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }

    }

    // close infile
    fclose(inptr);

    // close any outfiles remaining
    if (img != NULL)
    {
        fclose(img);
    }

    // success
    return 0;
}
