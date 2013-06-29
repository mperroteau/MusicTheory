#include "Form_RandomTest.h"
#include "Parametre.h"
#include "Instrument.h"
#include "Note.h"
#include "Main.cpp"




void StartTest(int nbNotes, Parametre parametres)
{

	for(int i = 0; i <= nbNotes; i++)
	{

		int note = rand() % 100;
		Note note_haute = parametres.getInstru().GetNote_haute();
		Note note_basse = parametres.getInstru().GetNote_basse();


		if (note > note_basse.GetId() && note < note_haute.GetId())
		{
			for (Note n : Notes)
			{
				if (note == n.GetId())
				{
					thisnote.value = n.GetNom();
					bool b = false;
					while (b==false)
						b == n.Listen(); // Execute listen tant que 
				}

					
			}
		}
	}

}