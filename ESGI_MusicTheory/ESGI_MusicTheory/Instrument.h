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
	list<Note> Notes;
	
public:
	Instrument(string, string, float, float);
	string GetNom();
	string GetType();

	void SetNom();
	void SetType();

};


Instrument::Instrument(string _nom, string _type, float _note_basse, float _note_haute)
{
	nom =_nom;
	type = _type;
	
	/*
	Pour toute note comprise entre note basse et note haute, ajouter la note à la liste
	*/

}


