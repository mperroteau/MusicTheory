#include "Parametre.h"
#include "Instrument.h"

Parametre::Parametre()
{

}
Parametre::Parametre(Instrument _instru)
{
	instru = _instru;
}

Parametre::Parametre(Instrument &i, int nb)
{
	instru = i;
	nb_notes = nb;
}


Parametre::~Parametre (void)
{

}

Instrument Parametre::getInstru()
{
	return instru;
}



void Parametre::setInstru(Instrument _instru)
{
	instru = _instru;
}




