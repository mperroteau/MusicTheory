#include <stdio.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <assert.h>
#include <Windows.h>
#include <fstream>
#include "Note.h"
#include "Instrument.h"
#include "Form_Main.h"


using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;


int main()
{
	Application::Run(gcnew Form_Main);
	/*Form_Parametres^ form = gcnew Form_Parametres();
			form->Show();*/
	
	return 0;
}

