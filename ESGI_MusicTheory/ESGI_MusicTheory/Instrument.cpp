#include "Instrument.h"

Instrument::Instrument()
{

}
Instrument::Instrument(string _nom, string _type, float _note_basse, float _note_haute)
{
	nom =_nom;
	type = _type;
	Note n;
	note_basse = n.getNoteByFrequence(_note_basse);
	note_haute = n.getNoteByFrequence(_note_basse);
	
	
	/*
	Pour toute note comprise entre note basse et note haute, ajouter la note à la liste
	*/

}

string Instrument::GetNom()
{
	return nom;
}

string Instrument::GetType()
{
	return type;
}

Note Instrument::GetNote_basse()
{
	return note_basse;
}

Note Instrument::GetNote_haute()
{
	return note_haute;
}

void Instrument::SetNom(string _nom)
{
	nom = _nom;
}
void Instrument::SetType(string _type)
{
	type = _type;
}
void Instrument::setNote_basse(Note _note_basse)
{
	note_basse = _note_basse;
}
void Instrument::setNote_haute(Note _note_haute)
{
	note_haute = _note_haute;
}

