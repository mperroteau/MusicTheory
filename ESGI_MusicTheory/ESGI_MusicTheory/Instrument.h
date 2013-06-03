#pragma once
#include <string>
#include <list> 
#include "Note.h"
using namespace std;

class Instrument
{
private:
	string nom;
	string type;
	float note_basse;
	float note_haute;
	//list<Note> Notes;
	
public:
	Instrument(string, string, float, float);
	string GetNom();
	string GetType();
	float GetNote_basse();
	float GetNote_haute();

	void SetNom(string);
	void SetType(string);
	void setNote_basse(float);
	void setNote_haute(float);

};





