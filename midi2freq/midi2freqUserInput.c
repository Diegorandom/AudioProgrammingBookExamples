#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cctype>

int main()
{
    double c5, c0, semitone_ratio, frequency;
    int midinote;
    char message[256] = {0};
    semitone_ratio = pow(2, 1.0 / 12);
    c5 = 220.0 * pow(semitone_ratio, 3);
    c0 = c5 * pow(0.5, 5);
    printf("Enter MIDI note (0 - 127): ");
    scanf("%s", message);

    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] == '.')
        {
            printf("The MIDI note is a float \n");
            return 1;
        }
        if (!std::isdigit(message[i]))
        {
            printf("There is an invalid number: %s \n", &message[i]);
            return 1;
        }
    }

    printf("\n");

    if (message[0] == '\0')
    {
        printf("Have a nice day!\n");
        return 1;
    }
    midinote = atoi(message);
    if (midinote < 0)
    {
        printf("Sorry - %s is a bad MIDI note number\n", message);
        return 1;
    }
    if (midinote > 127)
    {
        printf("Sorry - %s is beyond the MIDI range!\n", message);
        return 1;
    }
    frequency = c0 * pow(semitone_ratio, midinote);
    printf("frequency of MIDI note %d = %f Hz\n", midinote, frequency);
    return 0;
}