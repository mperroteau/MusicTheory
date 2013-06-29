#include "Note.h"
#include "Main.cpp"


#include "FMODEx\fmod.h"

/*
To use OpenAL with Visual Studio, do the following (this 
assumes you have OpenAL installed in the default location  
on drive C:). 

In project properties, 

-- add 
C:\Program Files\OpenAL 1.1 SDK\include to 
C++ -> General -> Additional Include Directories

-- add  C:\Program Files\OpenAL 1.1 SDK\libs\Win32
   to Linker -> General -> Additional Library Directories

-- add  OpenAL32.lib ALut.lib at the end  to 
   Linker -> Input -> Additional Dependencies 

in your source code, you'll need 


#include "al.h" 
#include "alc.h" 
#include "alut.h"
*/



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
	for (Note n : Notes)
	{
		if (_frequence == n.GetFrequence())
			return n;
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


bool Note::Listen()
{
	// FMOD
    int input, output;
 
    FMOD_SYSTEM *system;
 
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, 0);
    FMOD_System_SetOutput(system, FMOD_OUTPUTTYPE_DSOUND);
 
    FMOD_SOUND *sound;
    FMOD_System_CreateSound(system, 0, FMOD_2D | FMOD_SOFTWARE | FMOD_OPENUSER, 0, &sound);
 
	// Ouput FMOD
 
    FMOD_CHANNEL *channel = 0;
 
	// Input FMOD
 
    FMOD_CREATESOUNDEXINFO exinfo;
    FMOD_System_GetRecordNumDrivers(system, &input);
 
    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
 
    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = 44100;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels / 10;
    // Enregistrera pendant 10ms, si tu veux 100ms par exemple, enlève le "/ 10"
 
    FMOD_System_CreateSound(system, 0, FMOD_2D | FMOD_SOFTWARE | FMOD_OPENUSER, &exinfo, &sound);


	float spectre[1024] = {0};

	char nomMicro[100] = {0};

		/*Grâce à l'initialisation, tu as le nombre de micro connectés, dans la variable input.
	Tu peux parcourirr tous les micros et récupérer leurs noms en faisant :*/

	for(int i = 0; i < input; i++)
	{
		FMOD_System_GetRecordDriverInfo(system, i, nomMicro, 100, 0);
		printf("%d - %s\n", i, nomMicro);
	}

	//Ensuite, idem avec output pour les hauts parleurs :
	char nomHP[100] = {0};
	for(int i = 0; i < output; i++)
	{
		FMOD_System_GetDriverInfo(system, i, nomHP, 100, 0);
		printf("%d - %s\n", i, nomHP);
	}

	// Défini les haut-parleurs
	//FMOD_System_SetDriver(system, output);
	// Initialise l'envoi du son récupéré du micro dans les haut-parleurs
	// FMOD_Sound_SetMode(sound, FMOD_LOOP_NORMAL);
 
	// Commence la récupération du son
	FMOD_System_RecordStart(system, input, sound, 1);
	// Commence l'envoi du son récupéré du micro dans les haut-parleurs
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);

	//Et, enfin, dans la boucle principale, tu mets à jour le tableau des fréquences (qui se mets à jour toutes les 30ms il me semble).

	while(1)
	{
		//FMOD_Channel_GetSpectrum(channel, spectre, LARGEUR_F, 0, FMOD_DSP_FFT_WINDOW_BLACKMANHARRIS);
		float _frequence = FMOD_Channel_GetSpectrum(channel, spectre, 10, 0,FMOD_DSP_FFT_WINDOW_BLACKMANHARRIS);
		if (frequence == _frequence)
			return true;
		
		// Tu peux t'en servir exactmeent comme dans le tuto de m@teo21
 
		FMOD_System_Update(system);
	}

	return false;
}


