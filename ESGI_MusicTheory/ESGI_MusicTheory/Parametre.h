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
	Parametre(void);
	Parametre(Instrument);
};


