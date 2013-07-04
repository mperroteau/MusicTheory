#include "Note.h"
#include <stdio.h>
#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"
#include <iostream>
#include <Windows.h>
#include <fmod.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
 
#include <math.h>




#include "FMODEx\fmod.h"

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
	return frequence;
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

void Note::GetSong()
{
	//Joue la note courante
}

bool Note::IsSong(float _frequence)
{
	//TO DO : Appliquer une marge
	if (frequence == _frequence)
		return true;
	else
		return false;

}

Note Note::getNoteByFrequence(float _frequence)
{
	Note old;
	Note best;
	int i = 0;
	float current_result_up = NULL;
	float current_result_down = NULL;
	float best_result = 100;

	cout <<_frequence;

	for (list<Note>::iterator n = Notes.begin(); n != Notes.end(); n++)
	{
		Note current = *n;

		current_result_up = current.GetFrequence() - _frequence;
		current_result_down = _frequence - current.GetFrequence();

		if (n != Notes.begin())
			current_result_down = _frequence - old.GetFrequence();

		if (current_result_up < best_result)
			best = current;
		else if (current_result_down < best_result)
			best = old;
		
		old = *n;

	}

	return best;
	
	for (Note n : Notes)
	{   
		/*cout << n.GetFrequence();
		if (i < 1)
		{	
			if (_frequence == n.GetFrequence())
				return n;
		}
		else 
		{
			if ((_frequence > old.GetFrequence() && _frequence < n.GetFrequence()) ||(_frequence < old.GetFrequence() && _frequence > n.GetFrequence()))
			{ 
				result_old = _frequence - old.GetFrequence();
				result_n = n.GetFrequence() - _frequence;
				if (result_old<result_n)
					return old;
				else 
					return n;
			}
		}*/
		

		

	}

}

Note Note::getNoteById(int _id)
{
	for (Note n : Notes)
	{
		if (_id == n.GetId())
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

float Note::Play()
{
	FMOD::System    *system;
    FMOD::Channel   *channel = 0;
    FMOD::DSP       *dsp = 0;
    FMOD_RESULT      result;
    int              key;
    unsigned int     version;

	  /*
        Create a System object and initialize.
    */
    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
        return 0;
    }

    result = system->init(32, FMOD_INIT_NORMAL, NULL);
    ERRCHECK(result);

    /*
        Create an oscillator DSP units for the tone.
    */
    result = system->createDSPByType(FMOD_DSP_TYPE_OSCILLATOR, &dsp);
    ERRCHECK(result);
	//result = dsp->setParameter(FMOD_DSP_OSCILLATOR_RATE, 440.0f);       /* musical note 'A' */
	result = dsp->setParameter(FMOD_DSP_OSCILLATOR_RATE, frequence);  /*Note courante */
    ERRCHECK(result);

	/*Frequence*/


	 system->update();

	  {
			float frequency = frequence, volume = 0, pan = 0;
			result = system->playDSP(FMOD_CHANNEL_REUSE, dsp, true, &channel);
            channel->setVolume(0.9f);
            result = dsp->setParameter(FMOD_DSP_OSCILLATOR_TYPE, 0);
            ERRCHECK(result);
            channel->setPaused(false);

            bool playing = true;
			 
          
            if (channel)
            {
                channel->getFrequency(&frequency);
                channel->getVolume(&volume);
                channel->getPan(&pan);
                channel->isPlaying(&playing);
            }

            printf("Channel %s : Frequency %.1f Volume %.1f Pan %.1f  \r", playing ? "playing" : "stopped", frequency, volume, pan);
        }
}

float Note::Listen()
{

}

	




