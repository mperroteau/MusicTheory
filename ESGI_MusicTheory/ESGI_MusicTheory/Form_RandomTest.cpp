#include "Form_RandomTest.h"
#include "Parametre.h"
#include "Instrument.h"
#include "Note.h"


void StartTest(int nbNotes, Parametre parametres)
{

	for(int i = 0; i <= nbNotes; i++)
	{

		int note = rand() % 100;
		float note_haute = parametres.getInstru().GetNote_haute();
		float note_basse = parametres.getInstru().GetNote_basse();

		Note n =  n.getNoteById(note);

		if (n.GetFrequence() > note_basse && n.GetFrequence() < note_haute)
		{
			for (Note n : Notes)
			{
				if (note == n.GetId())
				{
					//thisnote.value = n.GetNom();
					bool b = false;
					while (b==false)
						b == n.Listen(); // Execute listen tant que 
				}

					
			}
		}
	}

}