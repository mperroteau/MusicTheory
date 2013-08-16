#include "Parametre.h"
#include "Instrument.h"

Parametre::Parametre()
{

}
Parametre::Parametre(Instrument _instru)
{
	instru = _instru;
}

Parametre::Parametre(Instrument &i, int lvl, int nb)
{
	instru = i;
	niveau = lvl;
	nb_notes = nb;
}


Parametre::~Parametre (void)
{

}

Instrument Parametre::getInstru()
{
	return instru;
}

int Parametre::getNiveau()
{
	return niveau;
}

void Parametre::setInstru(Instrument _instru)
{
	instru = _instru;
}

void Parametre::setNiveau(int _niveau)
{
	niveau = _niveau;
}


