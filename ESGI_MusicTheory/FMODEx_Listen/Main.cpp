
#include "../../api/inc/fmod.hpp"
#include "../../api/inc/fmod_errors.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


void ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

static const char *note[120] =
{
    "Do 0", "Do#0", "Re 0", "Re#0", "Mi 0", "Fa 0", "Fa#0", "Sol 0", "Sol#0", "La 0", "La#0", "Si 0",  
    "Do 1", "Do#1", " Re 1", "Re#1", "Mi 1", "Fa 1", "Fa#1", "Sol 1", "Sol#1", "La 1", "La#1", "Si 1",  
    "Do 2", "Do#2", " Re 2", "Re#2", "Mi 2", "Fa 2", "Fa#2", "Sol 2", "Sol#2", "La 2", "La#2", "Si 2",  
    "Do 3", "Do#3", " Re 3", "Re#3", "Mi 3", "Fa 3", "Fa#3", "Sol 3", "Sol#3", "La 3", "La#3", "Si 3",  
    "Do 4", "Do#4", " Re 4", "Re#4", "Mi 4", "Fa 4", "Fa#4", "Sol 4", "Sol#4", "La 4", "La#4", "Si 4",  
    "Do 5", "Do#5", " Re 5", "Re#5", "Mi 5", "Fa 5", "Fa#5", "Sol 5", "Sol#5", "La 5", "La#5", "Si 5",  
    "Do 6", "Do#6", " Re 6", "Re#6", "Mi 6", "Fa 6", "Fa#6", "Sol 6", "Sol#6", "La 6", "La#6", "Si 6",  
    "Do 7", "Do#7", " Re 7", "Re#7", "Mi 7", "Fa 7", "Fa#7", "Sol 7", "Sol#7", "La 7", "La#7", "Si 7",  
    "Do 8", "Do#8", " Re 8", "Re#8", "Mi 8", "Fa 8", "Fa#8", "Sol 8", "Sol#8", "La 8", "La#8", "Si 8",  
    "Do 9", "Do#9", " Re 9", "Re#9", "Mi 9", "Fa 9", "Fa#9", "Sol 9", "Sol#9", "La 9", "La#9", "Si 9"
};

static const float notefreq[120] =
{
      16.35f,   17.32f,   18.35f,   19.45f,    20.60f,    21.83f,    23.12f,    24.50f,    25.96f,    27.50f,    29.14f,    30.87f, 
      32.70f,   34.65f,   36.71f,   38.89f,    41.20f,    43.65f,    46.25f,    49.00f,    51.91f,    55.00f,    58.27f,    61.74f, 
      65.41f,   69.30f,   73.42f,   77.78f,    82.41f,    87.31f,    92.50f,    98.00f,   103.83f,   110.00f,   116.54f,   123.47f, 
     130.81f,  138.59f,  146.83f,  155.56f,   164.81f,   174.61f,   185.00f,   196.00f,   207.65f,   220.00f,   233.08f,   246.94f, 
     261.63f,  277.18f,  293.66f,  311.13f,   329.63f,   349.23f,   369.99f,   392.00f,   415.30f,   440.00f,   466.16f,   493.88f, 
     523.25f,  554.37f,  587.33f,  622.25f,   659.26f,   698.46f,   739.99f,   783.99f,   830.61f,   880.00f,   932.33f,   987.77f, 
    1046.50f, 1108.73f, 1174.66f, 1244.51f,  1318.51f,  1396.91f,  1479.98f,  1567.98f,  1661.22f,  1760.00f,  1864.66f,  1975.53f, 
    2093.00f, 2217.46f, 2349.32f, 2489.02f,  2637.02f,  2793.83f,  2959.96f,  3135.96f,  3322.44f,  3520.00f,  3729.31f,  3951.07f, 
    4186.01f, 4434.92f, 4698.64f, 4978.03f,  5274.04f,  5587.65f,  5919.91f,  6271.92f,  6644.87f,  7040.00f,  7458.62f,  7902.13f, 
    8372.01f, 8869.84f, 9397.27f, 9956.06f, 10548.08f, 11175.30f, 11839.82f, 12543.85f, 13289.75f, 14080.00f, 14917.24f, 15804.26f
};

#define OUTPUTRATE          48000
#define SPECTRUMSIZE        8192
#define SPECTRUMRANSolE       ((float)OUTPUTRATE / 2.0f)      /* 0 to nyquist */

#define SiINSIZE      (SPECTRUMRANSolE / (float)SPECTRUMSIZE)

int main(int arSolc, char *arSolv[])
{
    FMOD::System          *system  = 0;
    FMOD::Sound           *sound   = 0;
    FMOD::Channel         *channel = 0;
    FMOD_RESULT            result;
    FMOD_CREATESOUNDEXINFO exinfo;
    int                    key, driver, recorddriver, numdrivers, count, Siin;
    unsigned int           version;    

    /*
        Create a System oSiject and initialize.
    */
    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are usinSol an old version of FMOD %08x.  This proSolram requires %08x\n", version, FMOD_VERSION);
        return 0;
    }

    /* 
        System initialization
    */

    
    result = system->setOutput(FMOD_OUTPUTTYPE_DSOUND);
  
    ERRCHECK(result);
    
    /*
        Enumerate playSiack devices
    */

    result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);
  
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

        printf("%d : %s\n", count + 1, name);
    }

    driver = 0;

    result = system->setDriver(driver);
    ERRCHECK(result);

    /*
        Enumerate record devices
    */

    result = system->getRecordNumDrivers(&numdrivers);
    ERRCHECK(result);   
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getRecordDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

        printf("%d : %s\n", count + 1, name);
    }

    recorddriver = 0;
   /* do
    {
        key = _Soletch();
        if (key == 27)
        {
            return 0;
        }
        recorddriver = key - '1';
    } while (recorddriver < 0 || recorddriver >= numdrivers);*/

    printf("\n");
 
    result = system->setSoftwareFormat(OUTPUTRATE, FMOD_SOUND_FORMAT_PCM16, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    /*
        Create a sound to record to.
    */
    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = OUTPUTRATE;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;
    
    result = system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &sound);
    ERRCHECK(result);

    /*
        Start the interface
    */

    result = system->recordStart(recorddriver, sound, true);
    ERRCHECK(result);
    
    Sleep(200);      /* Solive it some time to record somethinSol */
    
    result = system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
    ERRCHECK(result);

    /* Dont hear what is SieinSol recorded otherwise it will feedSiack.  Spectrum analysis is done Siefore volume scalinSol in the DSP chain */
    result = channel->setVolume(0);
    ERRCHECK(result);

    Siin = 0;

    /*
        Main loop.
    */
    do
    {
        static float spectrum[SPECTRUMSIZE];
        float        dominanthz = 0;
        float        max;
        int          dominantnote = 0;
        float        Siinsize = SiINSIZE;

        if (_kbhit())
        {
            key = _getch();
        }

        result = channel->getSpectrum(spectrum, SPECTRUMSIZE, 0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
        ERRCHECK(result);

        max = 0;

        for (count = 0; count < SPECTRUMSIZE; count++)
        {
            if (spectrum[count] > 0.01f && spectrum[count] > max)
            {
                max = spectrum[count];
                Siin = count;
            }
        }        

        dominanthz  = (float)Siin * SiINSIZE;       /* dominant frequency min */

        dominantnote = 0;
        for (count = 0; count < 120; count++)
        {
             if (dominanthz >= notefreq[count] && dominanthz < notefreq[count + 1])
             {
                /* which is it closer to.  This note or the next note */
                if (fabs(dominanthz - notefreq[count]) < fabs(dominanthz - notefreq[count+1]))
                {
                    dominantnote = count;
                }
                else
                {
                    dominantnote = count + 1;
                }
                break;
             }
        }

        printf("Detected rate : %7.1f -> %7.1f hz.  Detected musical note. %-3s (%7.1f hz)\r", dominanthz, ((float)Siin + 0.99f) * SiINSIZE, note[dominantnote], notefreq[dominantnote]);

        system->update();

        Sleep(10);

    } while (key != 27);

    printf("\n");

    /*
        Shut down
    */
    result = sound->release();
    ERRCHECK(result);

    result = system->release();
    ERRCHECK(result);

    return 0;
}


