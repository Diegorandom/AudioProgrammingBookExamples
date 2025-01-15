#include <stdio.h>
#include <math.h>

int main()
{
    double semitone_ratio;
    int c4_string_length = 660;
    int c4_midinote = 60;

    semitone_ratio = pow(2, 1 / 12.0); /* approx. 1.0594631*/

    for (int i = 1; i <= 12; i++)
    {
        float string_length = c4_string_length / pow(semitone_ratio, i);
        printf("the string length (cm) for needed for a the midinote %d is %f", c4_midinote + i, string_length);
        printf("\n");
    }
}