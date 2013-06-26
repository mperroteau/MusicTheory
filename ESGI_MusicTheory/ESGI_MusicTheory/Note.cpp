#include "Note.h"
#include "Main.cpp"


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
	//Attend la reponse
	return true;
}

