#pragma once
#include <string>
#include <list>
#include "Instrument.h"

using namespace std;

class Parametre
{
private:
	Instrument instru;

public:
	Parametre();
	Parametre(Instrument);
};


Parametre::Parametre(Instrument _instru)
{
	instru = _instru;
}