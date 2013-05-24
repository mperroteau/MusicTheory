#pragma once
#include <string>
#include <list>
using namespace std;

class Note
{
private:
	int id;
	string nom;
	string nom_2;
	int octave;
	float frequence;
	
	string image;

public:
	Note(void);
	Note(int, string, string, int, float, string);
	
	int GetId();
	string GetNom();
	string GetNom_2();
	int GetOctave();
	float GetFrequence();
	string GetImage();

	void SetId(int);
	void SetNom(string);
	void SetNom_2(string);
	void SetOctave(int);
	void SetFrequence(float);
	void SetImage(string);
};


Note::Note(int _id, string _nom,string _nom_2, int _octave, float _frequence, string _image)
{
	id = _id;
	nom = _nom;
	nom_2 = _nom_2;
	octave = _octave;
	frequence = _frequence;

	image = _image;
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