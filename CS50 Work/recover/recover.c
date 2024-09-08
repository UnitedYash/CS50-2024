#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: recover image_file\n");
        return 1;
    }
    FILE *currFile = fopen(argv[1], "rb");
    if (currFile == NULL)
    {
        printf("Could not Open file %s", argv[1]);
        return 1;
    }

    BYTE buffer[512];
    int intNumberOfJPEGS = 0;
    char Filename[8];
    FILE *outptr = NULL;


    while (fread(buffer, sizeof(BYTE), 512, currFile) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(Filename, "%03i.jpg", intNumberOfJPEGS);
            outptr = fopen(Filename, "wb");
            intNumberOfJPEGS++;
        }
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, outptr);
        }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(currFile);
    return 0;


}
