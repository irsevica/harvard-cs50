#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>

int is_rest(char *s);
int duration(char *fraction);
int frequency(char *note);

int main(void)
{
    char *fraction = "1/4";
    char note[5] = "A#3";
    char s[10];
    s[0] = '\0';

    int rest_result = is_rest(s);
    if (rest_result == 1)
    {
        printf("String is a rest\n");
    }
    else
    {
        printf("String is a note\n");
    }
    
    int dur_result = duration(fraction);
    printf("Num of 1/8th notes long for value %s: %d\n", fraction, dur_result);

    int freq_result = frequency(note);
    printf("Frequency of %s is: %dhz\n", note, freq_result);
}

int is_rest(char *s)
{
    if (s[0] != '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int duration(char *fraction)
{
    int nominator = fraction[0] - '0';
    int denominator = fraction[2] - '0';

    if (denominator != 8)
        nominator =  8 / denominator;

    return nominator;
}

int frequency(char *note)
{
    char key[1];
    key[0] = note[0];
    char accidental[1];
    accidental[0] = '\0';
    char octave[1];
    double freq = 0.0;

    if (note[1] == '#' || note [1] == 'b')
    {
        accidental[0] = note[1];
        octave[0] = note[2];
    }
    else
    {
        octave[0] = note[1];
    }

    int octave_int = octave[0] - '0';
    
    // Adjust for key

    switch(key[0])
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }

    // Adjust for octave
    if(octave_int > 4)
    {
        for(int i = 0; i < octave_int - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if(octave_int < 4)
    {
        for(int i = 0; i < 4 - octave_int; i++)
        {
            freq /= 2.0;
        }
    }

    // Adjust for accidental
    if(accidental[0] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if(accidental[0] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return frequency
    int ret = round(freq);
    return ret;

}