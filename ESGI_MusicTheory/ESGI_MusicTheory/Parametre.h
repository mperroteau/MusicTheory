#pragma once
#include <string>
#include <list>
#include "Instrument.h"

using namespace std;

class Parametre
{
private:
	Instrument instru;
	int niveau;
	int nb_notes;

public:
	Parametre(void);
	Parametre(Instrument&, int, int);
	Parametre(Instrument);
	~Parametre(void);

	Instrument getInstru(void);
	int getNiveau(void);
	int getNb_notes(void);

	void setInstru(Instrument);
	void setNiveau(int);
	void setNb_notes(int);

};


