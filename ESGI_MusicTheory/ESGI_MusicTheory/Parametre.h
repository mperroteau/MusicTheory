#pragma once
#include <string>
#include <list>
#include "Instrument.h"
#include "Main.cpp"

using namespace std;

class Parametre
{
private:
	Instrument instru;
	int niveau;

public:
	Parametre(void);
	Parametre(Instrument);
	~Parametre(void);

	Instrument getInstru(void);
	int getNiveau(void);

	void setInstru(Instrument);
	void setNiveau(int);

};


