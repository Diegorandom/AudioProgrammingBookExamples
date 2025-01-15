/* listing 1.2. Calculate frequency of a MIDI Note number */
#include <stdio.h>
#include <math.h>

int main()
{
    double semitone_ratio;
    double c0;        /* for frequency of MIDI Note 0 */
    double c5;        /* for frequency of Middle C */
    double frequency; /* freq we want to find */
    int midinote;     /* given this note */
    double fracmidi;
    float pitchBend;

    /* calculate required numbers */

    semitone_ratio = pow(2, 1 / 12.0); /* approx. 1.0594631*/
    /* find Middle C, 3 semitones above A = 220 */
    c5 = 220.0 * pow(semitone_ratio, 3);
    /* MIDI Note 0 is C, 5 octaves below Middle C */
    c0 = c5 * pow(0.5, 5);

    /* find nearest MIDI note to a given frequency in Hz */
    /* uses the log rule:
       log_a(N) = log_b(N) / log_b(a)
           to find the log of a value to base 'semitone_ratio'.
    */
    frequency = 400.0;
    fracmidi = log(frequency / c0) / log(semitone_ratio);
    /* round fracmidi to the nearest whole number */
    midinote = (int)(fracmidi + 0.5);

    pitchBend = (fracmidi - midinote) * 100;

    printf("The nearest MIDI note to the frequency %f is %d\n", frequency,
           midinote);
    printf("pitchbend = %f%%\n", pitchBend);

    return 0;
}