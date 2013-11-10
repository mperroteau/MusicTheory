#include "Form_RandomTest.h"
#include "Form_Main.h"
#include "Note.h"
#include "Instrument.h"
#include "Form_Main.h"
#include "Note.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <fmod.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <tchar.h>
#include <assert.h>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <ctime>


Note::Note()
{

}

Note::Note(int _id, string _nom,string _nom_2, int _octave, float _frequence, string _image, string _image_2)
{
	id = _id;
	nom = _nom;
	nom_2 = _nom_2;
	octave = _octave;
	frequence = _frequence;

	image = _image;
	image_2 = _image_2;
}

Note::~Note (void)
{

}

int Note::GetId()
{
	return id;
}

string Note::GetNom()
{
	return nom;
}

string Note::GetNom_2()
{
	return nom_2;
}

int Note::GetOctave()
{
	return octave;
}

float Note::GetFrequence()
{
	float _frequence = frequence;
	return _frequence;
}

string Note::GetImage()
{
	return image;
}

void Note::SetId(int _id)
{
	id = _id;
}

void Note::SetNom(string _nom)
{
	nom = _nom;
}

void Note::SetNom_2(string _nom_2)
{
	nom_2 = _nom_2;
}

void Note::SetOctave(int _octave)
{
	octave = _octave;
}

void Note::SetFrequence(float _frequence)
{
	frequence = _frequence;
}

void Note::SetImage(string _image)
{
	image = _image;
}

static void setNotes()
{
	ifstream f_notes("Data/Notes.csv"); 
	string value;
	list<Note> _Notes;

	if (f_notes)
	{
		int n_id = NULL;
		string n_nom = "";
		string n_nom_2 = "";
		int n_octave = NULL;
		float n_frequence = NULL;
		
		while ( getline( f_notes, value ) )
		{
			char *sArr = new char[value.length()+1];
			strcpy(sArr, value.c_str());
			// Declare char pointer sPtr for the tokens.
			char *sPtr;
			// Get all the tokens with " " as delimiter.
			sPtr = strtok(sArr, ";");

			int i =1;	

			// For all tokens.
			while(sPtr != NULL) 
			{
				if (i==1)
					n_id = atoi(sPtr);
				else if (i==2)
					n_nom = sPtr;
				else if (i==3)
					n_nom_2 = sPtr;
				else if (i==4)
					n_octave = atoi(sPtr);
				else if (i==5)
					n_frequence = static_cast<float>(atof(sPtr));
					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""));
			
		}
		f_notes.close();
	}
}


Note Note::getNoteById(int _id)
{
	ifstream f_notes("Data/Notes.csv"); 
	string value;
	list<Note> _Notes;

	if (f_notes)
	{
		int n_id = NULL;
		string n_nom = "";
		string n_nom_2 = "";
		int n_octave = NULL;
		float n_frequence = NULL;
		string n_image = "";
		
		while ( getline( f_notes, value ) )
		{
			char *sArr = new char[value.length()+1];
			strcpy(sArr, value.c_str());
			// Declare char pointer sPtr for the tokens.
			char *sPtr;
			// Get all the tokens with " " as delimiter.
			sPtr = strtok(sArr, ";");

			int i =1;	

			// For all tokens.
			while(sPtr != NULL) 
			{
				if (i==1)
					n_id = atoi(sPtr);
				else if (i==2)
					n_nom = sPtr;
				else if (i==3)
					n_nom_2 = sPtr;
				else if (i==4)
					n_octave = atoi(sPtr);
				else if (i==5)
					n_frequence = static_cast<float>(atof(sPtr));
				else if (i==6)
					n_image = sPtr;
					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,n_image, ""));
			
		}
		f_notes.close();
	}
	//cout << "_id : " <<_id;
	int current_id;
	int arg_id = _id;
	for (Note n : Notes)
	{
		//cout << "_id : " <<_id;
		current_id = n.id;
		if (arg_id == current_id)
			return n;
	}
}

 
void ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}



#define OUTPUTRATE          48000
#define SPECTRUMSIZE        8192
#define SPECTRUMRANGE       ((float)OUTPUTRATE / 2.0f)     
#define BINSIZE      (SPECTRUMRANGE / (float)SPECTRUMSIZE)

bool Note::Listen()
{
	FMOD::System          *system  = 0;
    FMOD::Sound           *sound   = 0;
    FMOD::Channel         *channel = 0;
    FMOD_RESULT            result;
    FMOD_CREATESOUNDEXINFO exinfo;
    int                    key, driver, recorddriver, numdrivers, count, bin;
    unsigned int           version;    

	ifstream f_notes("Data/Notes.csv"); 
	string value;
	list<Note> _Notes;

	if (f_notes)
	{
		int n_id = NULL;
		string n_nom = "";
		string n_nom_2 = "";
		int n_octave = NULL;
		float n_frequence = NULL;
		string n_image = "";
		
		while ( getline( f_notes, value ) )
		{
			char *sArr = new char[value.length()+1];
			strcpy(sArr, value.c_str());
			char *sPtr;
			sPtr = strtok(sArr, ";");

			int i =1;	

			// For all tokens.
			while(sPtr != NULL) 
			{
				if (i==1)
					n_id = atoi(sPtr);
				else if (i==2)
					n_nom = sPtr;
				else if (i==3)
					n_nom_2 = sPtr;
				else if (i==4)
					n_octave = atoi(sPtr);
				else if (i==5)
					n_frequence = static_cast<float>(atof(sPtr));
				//path image
				else if (i==6)
					n_image = sPtr;
					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,n_image, ""));
			
		}
		f_notes.close();
	}

    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
        return 0;
    }

    
    result = system->setOutput(FMOD_OUTPUTTYPE_DSOUND);
  
    ERRCHECK(result);

    result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);
  
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

    }

    driver = 0;

    result = system->setDriver(driver);
    ERRCHECK(result);

    result = system->getRecordNumDrivers(&numdrivers);
    ERRCHECK(result);   
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getRecordDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

       
    }

    recorddriver = 0;
 

    printf("\n");
 
    result = system->setSoftwareFormat(OUTPUTRATE, FMOD_SOUND_FORMAT_PCM16, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = OUTPUTRATE;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;
    
    result = system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &sound);
    ERRCHECK(result);

    result = system->recordStart(recorddriver, sound, true);
    ERRCHECK(result);
    
    Sleep(200);      
    
    result = system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
    ERRCHECK(result);

    result = channel->setVolume(0);
    ERRCHECK(result);

    bin = 0;

    /*
        Main loop.
    */
    do
    {
        static float spectrum[SPECTRUMSIZE];
        float        dominanthz = 0;
        float        max;
        Note         dominantnote;
        float        binsize = BINSIZE;

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
                bin = count;
            }
        }        

        dominanthz  = (float)bin * BINSIZE; 

		ESGI_MusicTheory::Form_Main^ _form = gcnew ESGI_MusicTheory::Form_Main;
		//_form->setCurrentFrequence(dominanthz);
		//_form->setCurrentFrequence(dominanthz.ToString());
		_form->frm_frequencecourante->Text = dominanthz.ToString();
		_form->frm_frequencecourante->Refresh();

		
		float current_frequence;

		for (Note n: Notes)
		{
			current_frequence = n.frequence;
			if (dominanthz <= (current_frequence+10) && dominanthz >= (current_frequence-10) )
			{
					dominantnote = n;
					break;
			}
			
		}
		 printf("Frequence detectee : %7.1f\r", dominanthz);
		int this_note_id = this->id;
		int dominantnote_id = dominantnote.id;

		if (this_note_id == dominantnote_id)
			return true;

		system->update();

        Sleep(10);
		
		
		

        system->update();

        Sleep(10);

    } while (key != 27);

	  printf("\n");
    result = sound->release();
    ERRCHECK(result);

    result = system->release();
    ERRCHECK(result);

    return 0;
	

}

double _diffclock( clock_t clock1, clock_t clock2 ) {

        double diffticks = clock1 - clock2;
        double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );

        return diffms;
    }

bool Note::Listen(double __timer)
{
	FMOD::System          *system  = 0;
    FMOD::Sound           *sound   = 0;
    FMOD::Channel         *channel = 0;
    FMOD_RESULT            result;
    FMOD_CREATESOUNDEXINFO exinfo;
    int                    key, driver, recorddriver, numdrivers, count, bin;
    unsigned int           version;    
	double _timer = __timer;

	ifstream f_notes("Data/Notes.csv"); 
	string value;
	list<Note> _Notes;

	if (f_notes)
	{
		int n_id = NULL;
		string n_nom = "";
		string n_nom_2 = "";
		int n_octave = NULL;
		float n_frequence = NULL;
		string n_image = "";
		
		while ( getline( f_notes, value ) )
		{
			char *sArr = new char[value.length()+1];
			strcpy(sArr, value.c_str());
			char *sPtr;
			sPtr = strtok(sArr, ";");

			int i =1;	

			// For all tokens.
			while(sPtr != NULL) 
			{
				if (i==1)
					n_id = atoi(sPtr);
				else if (i==2)
					n_nom = sPtr;
				else if (i==3)
					n_nom_2 = sPtr;
				else if (i==4)
					n_octave = atoi(sPtr);
				else if (i==5)
					n_frequence = static_cast<float>(atof(sPtr));
				//path image
				else if (i==6)
					n_image = sPtr;
					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,n_image, ""));
			
		}
		f_notes.close();
	}

    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
        return 0;
    }

    
    result = system->setOutput(FMOD_OUTPUTTYPE_DSOUND);
  
    ERRCHECK(result);

    result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);
  
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

    }

    driver = 0;

    result = system->setDriver(driver);
    ERRCHECK(result);

    result = system->getRecordNumDrivers(&numdrivers);
    ERRCHECK(result);   
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getRecordDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

       
    }

    recorddriver = 0;
 

    printf("\n");
 
    result = system->setSoftwareFormat(OUTPUTRATE, FMOD_SOUND_FORMAT_PCM16, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = OUTPUTRATE;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;
    
    result = system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &sound);
    ERRCHECK(result);

    result = system->recordStart(recorddriver, sound, true);
    ERRCHECK(result);
    
    Sleep(200);      
    
    result = system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
    ERRCHECK(result);

    result = channel->setVolume(0);
    ERRCHECK(result);

    bin = 0;

    /*
        Main loop.
    */
	
	clock_t start = clock();
	clock_t end;
	double currentimer;

    do
    {
        static float spectrum[SPECTRUMSIZE];
        float        dominanthz = 0;
        float        max;
        Note         dominantnote;
        float        binsize = BINSIZE;

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
                bin = count;
            }
        }        

        dominanthz  = (float)bin * BINSIZE; 

		ESGI_MusicTheory::Form_Main^ _form = gcnew ESGI_MusicTheory::Form_Main;
		//_form->setCurrentFrequence(dominanthz);
		//_form->setCurrentFrequence(dominanthz.ToString());
		_form->frm_frequencecourante->Text = dominanthz.ToString();
		_form->frm_frequencecourante->Refresh();

		
		float current_frequence;

		for (Note n: Notes)
		{
			current_frequence = n.frequence;
			if (dominanthz <= (current_frequence+10) && dominanthz >= (current_frequence-10) )
			{
					dominantnote = n;
					break;
			}
			
		}
		 printf("Frequence detectee : %7.1f\r", dominanthz);
		int this_note_id = this->id;
		int dominantnote_id = dominantnote.id;

		if (this_note_id == dominantnote_id)
			return true;

		system->update();

        Sleep(10);
		
		
		

        system->update();

        Sleep(10);
		end = clock();
		currentimer = _diffclock(end,start);

	} while ((key != 27) && (_timer>currentimer));

	return false;

	//printf("\n");
    /*result = sound->release();
    ERRCHECK(result);

    result = system->release();
    ERRCHECK(result);*/

    //return 0;
	

}




	




