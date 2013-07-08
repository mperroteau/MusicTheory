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
	string image_2;

public:
	Note(void);
	Note(int, string, string, int, float, string, string);
	~Note(void);
	
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
	void GetSong();
	

	bool IsSong(float);

	Note getNoteByFrequence(float);
	Note getNoteById(int);

	float Play();
	float Listen();
	
};

static void setNotes();
static list<Note> Notes;


