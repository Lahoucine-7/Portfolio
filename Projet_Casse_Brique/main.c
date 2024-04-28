#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "jeu.h"
#include "niveaux.h"
#include "jeu.c"

int main(void)
{
	int choix, /*score = 0,*/ difficulte = 1;
	struct joueur J;
	
	init_graphics(900,600);
	SDL_WM_SetCaption("Casse Brique", NULL);
	do
	{
		affiche_auto_on();
		fill_screen(noir);
		choix = menu();
		fill_screen(noir);
		
		if (choix == 1)
		{
			J = init_joueur();
			jeu(&J, difficulte);
		}
		
		if (choix == 2) choix_difficulte(&difficulte);
		if (choix == 3) credits();
		if (choix == 0) printf("\nErreur fonction menu.\n");
		affiche_auto_off();
		
	}while (1);

	wait_escape();
    return EXIT_SUCCESS;
}
