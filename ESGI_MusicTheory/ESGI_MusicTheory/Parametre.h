#pragma once
#include <string>
#include <list>
#include "Instrument.h"

using namespace std;

class Parametre
{
private:
	Instrument instru;
	int nb_notes;

public:
	Parametre(void);
	Parametre(Instrument&, int);
	Parametre(Instrument);
	~Parametre(void);

	Instrument getInstru(void);
	int getNb_notes(void);

	void setInstru(Instrument);
	void setNb_notes(int);

};


