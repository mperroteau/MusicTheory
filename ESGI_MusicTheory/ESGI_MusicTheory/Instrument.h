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
	Note note_basse;
	Note note_haute;
	
public:
	Instrument();
	Instrument(string, string, float, float);
	string GetNom();
	string GetType();
	Note GetNote_basse();
	Note GetNote_haute();

	void SetNom(string);
	void SetType(string);
	void setNote_basse(Note);
	void setNote_haute(Note);

};

static list<Instrument> Instruments;





