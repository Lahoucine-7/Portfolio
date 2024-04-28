/**   INITIALISATIONS   **/
struct paddle init_paddle (int difficulte)
{
	struct paddle PAD;
	
	if (difficulte==0)
	{
		PAD.P1.x = 300; PAD.P1.y = 11;
		PAD.P2.x = 600; PAD.P2.y = 1;
	}
	
	if (difficulte==1)
	{
		PAD.P1.x = 350; PAD.P1.y = 11;
		PAD.P2.x = 550; PAD.P2.y = 1;
	}
	
	if (difficulte==2)
	{
		PAD.P1.x = 400; PAD.P1.y = 11;
		PAD.P2.x = 500; PAD.P2.y = 1;
	}
	
	return PAD;
}

struct balle init_balle (struct paddle PAD, int difficulte)
{
	struct balle B;
	B.rayon = 7;
	B.centre.x = (PAD.P1.x + PAD.P2.x)/2;
	B.centre.y = (PAD.P1.y + B.rayon + 2);
	
	
	if (difficulte==0) {B.dx = 1; B.dy = 1;}
	if (difficulte==1) {B.dx = 2; B.dy = 1;}
	if (difficulte==2) {B.dx = 2; B.dy = 2;}
	
	return B;
}

struct joueur init_joueur (void)
{
	struct joueur J;
	J.nb_de_vie = VIE_AU_LANCEMENT;
	return J;
}

/** Fin INITIALISATION **/


// Rebond de la balle sur les bord de la fenetre et des briques
struct balle rebond_bord(struct balle B, struct paddle PAD)
{	
	if ((B.centre.x - B.rayon <= PAD.P2.x) && (B.centre.y - B.rayon <= PAD.P1.y)) B.dx = -B.dx;
	if ((B.centre.x + B.rayon >= PAD.P1.x) && (B.centre.y - B.rayon <= PAD.P1.y)) B.dx = -B.dx;
	if ((B.centre.y - B.rayon < PAD.P1.y) && (B.centre.x + B.rayon > PAD.P1.x && B.centre.x - B.rayon < PAD.P2.x)) {B.dy = -B.dy; return B;}
	
	if ((B.centre.x - B.rayon < 0) && (B.dx<0)) B.dx = -B.dx;
	if ((B.centre.x + B.rayon > WIDTH) && (B.dx>0)) B.dx = -B.dx;
	if ((B.centre.y + B.rayon > HEIGHT-20) && (B.dy>0)) B.dy = -B.dy;
	if ((B.centre.y - B.rayon < 0) && (B.dy<0)) {B.dy = 0; B.dx = 0;}
	return B;
}

struct balle rebond_brique(struct balle B, struct brique BRIQUE[14][5], int *score)
{
	int i, j;
	
	for(j=0; j<5; j++)
	{
		for(i=0; i<14; i++)
		{
			if((B.centre.x > BRIQUE[i][j].B1.x) && (B.centre.x < BRIQUE[i][j].B2.x) && BRIQUE[i][j].affiche == TRUE)
			{
				if((B.centre.y + B.rayon > BRIQUE[i][j].B2.y) && (B.centre.y - B.rayon < BRIQUE[i][j].B1.y))
				{
					B.dy = -B.dy;
					BRIQUE[i][j].casse--;
					if(BRIQUE[i][j].casse == 0) BRIQUE[i][j].affiche = FALSE;
					if(BRIQUE[i][j].casse < 10) *score += 10;
					return B;
				}	
			}
			
			if((B.centre.y + B.rayon > BRIQUE[i][j].B2.y) && (B.centre.y - B.rayon < BRIQUE[i][j].B1.y) && BRIQUE[i][j].affiche == TRUE)
			{
				if((B.centre.x + B.rayon > BRIQUE[i][j].B1.x) && (B.centre.x - B.rayon < BRIQUE[i][j].B2.x))
				{
					B.dx = -B.dx;
					BRIQUE[i][j].casse--;
					if(BRIQUE[i][j].casse == 0) BRIQUE[i][j].affiche = FALSE;
					if(BRIQUE[i][j].casse < 10) *score += 10;
					return B;
				}	
			}
		}
	}
	
	return B;
}

void game_over(void)
{
	POINT P1, P2, GAMEOVER, RETOUR, CLIC;
	
	P1.x = 750;
	P1.y = 50;
	P2.x = 900;
	P2.y = 0;
	
	RETOUR.x = 765;
	RETOUR.y = 45;
	GAMEOVER.x = 25;
	GAMEOVER.y = 395;
	
	affiche_auto_on();
	
	draw_rectangle(P1, P2, blanc);
	
	aff_pol("GAME OVER", 140, GAMEOVER, blanc);
	aff_pol("RETOUR", 30, RETOUR, blanc);
	
	do
	{
		CLIC = wait_clic();
	}while(CLIC.x < 750 || CLIC.y > 50 );
	fill_screen(noir);
	affiche_auto_off();
}

// DÃ©placement de la balle
struct balle deplace_balle(int **score, struct balle B, struct paddle PAD)
{
	B.centre.x += B.dx;
	B.centre.y += B.dy;
	B = rebond_brique(B, BRIQUE, *score);
	B = rebond_bord(B, PAD);
	return B;
}

struct paddle deplace_paddle(struct paddle PAD)
{
	POINT deplacement = get_arrow();
	deplacement.x = deplacement.x * 2; // vitesse de deplacement multipliée par 2
	PAD.P1.x += deplacement.x;
	PAD.P2.x += deplacement.x;
	
	if(PAD.P1.x < 0) {PAD.P1.x -= deplacement.x; PAD.P2.x -= deplacement.x;}
	if(PAD.P2.x > WIDTH) {PAD.P1.x -= deplacement.x; PAD.P2.x -= deplacement.x;}
	
	return PAD;
}

void affiche_paddle(struct paddle PAD) 
{
	draw_fill_rectangle(PAD.P1, PAD.P2, blanc);
}

void affiche_balle(struct balle B) 
{
	draw_fill_circle(B.centre,B.rayon,blanc);
}

void efface_paddle(struct paddle PAD)
{
	draw_fill_rectangle(PAD.P1, PAD.P2, noir);
}

void efface_balle(struct balle B)
{
	draw_fill_circle(B.centre,B.rayon,noir);
}

void continuer(int *rejouer)
{
	POINT P1, P2, P3, P4, CONTINUER, QUITTER, CLIC;
	P1.x = 300;
	P1.y = 425;
	P2.x = 600;
	P2.y = 325;
	
	P3.x = 300;
	P3.y = 275;
	P4.x = 600;
	P4.y = 175;
	
	CONTINUER.x = 300;
	CONTINUER.y = 410;
	
	QUITTER.x = 340;
	QUITTER.y = 260;
	
	affiche_auto_on();
	
	draw_fill_rectangle(P1, P2, noir);
	draw_fill_rectangle(P3, P4, noir);
	draw_rectangle(P1, P2, blanc); // Continuer
	draw_rectangle(P3, P4, blanc); // Quitter
	
	aff_pol("CONTINUER", 49, CONTINUER, blanc);
	aff_pol("QUITTER", 50, QUITTER, blanc);
	
	do
	{
		CLIC = wait_clic();
		if (CLIC.x >= P1.x && CLIC.x <= P2.x && CLIC.y >= P2.y && CLIC.y <= P1.y)
			*rejouer = 1;
		if (CLIC.x >= P3.x && CLIC.x <= P4.x && CLIC.y >= P4.y && CLIC.y <= P3.y)
			*rejouer = 0;
	}while(CLIC.x < 300 || CLIC.x > 600 || CLIC.y > 425 || CLIC.y < 175 || (CLIC.y < 325 && CLIC.y > 275));
	
	affiche_auto_off();
}

int faute(struct joueur *J, struct balle *B, struct paddle *PAD, int difficulte, int *score)
{
	int c = 1;
	J->nb_de_vie -= 1;
	*score -= 50;
	if (J->nb_de_vie > 0) continuer(&c);
	fill_screen(noir);
	if (c == 1) // Continuer
	{
		*PAD = init_paddle(difficulte);
		*B = init_balle(*PAD, difficulte);
		return c;
	}
	else // Quitter
	{
		return 0;
	}
	
}

int menu(void)
{
	POINT P1, P2, P3, P4, P5, P6, JOUER, DIFFICULTE, CREDITS, CLIC;
	
	P1.x = 300;
	P1.y = 500;
	P2.x = 600;
	P2.y = 400;
	
	P3.x = 300;
	P3.y = 350;
	P4.x = 600;
	P4.y = 250;
	
	P5.x = 300;
	P5.y = 200;
	P6.x = 600;
	P6.y = 100;
	
	JOUER.x = 370;
	JOUER.y = 485;
	DIFFICULTE.x = 300;
	DIFFICULTE.y = 335;
	CREDITS.x = 335;
	CREDITS.y = 185;
	
	draw_rectangle(P1, P2, blanc);
	draw_rectangle(P3, P4, blanc);
	draw_rectangle(P5, P6, blanc);
	
	aff_pol("JOUER", 50, JOUER, blanc);
	aff_pol("DIFFICULTE", 50, DIFFICULTE, blanc);
	aff_pol("CREDITS", 50, CREDITS, blanc);
	
	do
	{
		CLIC = wait_clic();
	}while(CLIC.x < 300 || CLIC.x > 600 || CLIC.y < 100 || CLIC.y > 500 || (CLIC.y < 400 && CLIC.y > 350) || (CLIC.y < 250 && CLIC.y > 200));
	
	if (CLIC.y < 500 && CLIC.y > 400)
		return 1;
	if (CLIC.y < 350 && CLIC.y > 250)
		return 2;
	if (CLIC.y < 200 && CLIC.y > 100)
		return 3;
	else
		return 0;
}

void jeu (struct joueur *J, int difficulte)
{
	struct balle B;
	struct paddle PAD;
	int rejouer = 1, jouer = 1, score = 0, *pscore, niveau = 1;
	pscore = &score;
	
	affiche_auto_off();
	
	do
	{
		
		touche();
		jouer = init_niveau(niveau);
		rejouer = jouer;
		PAD = init_paddle(difficulte);
		B = init_balle(PAD, difficulte);
		while(jouer == 1 && J->nb_de_vie > 0)
		{
			entete(niveau, score, J->nb_de_vie);
			affiche_balle(B);
			affiche_paddle(PAD);
			affiche_brique_restantes(BRIQUE);
			affiche_all();
			efface_brique(BRIQUE);
			efface_paddle(PAD);
			efface_balle(B);
			PAD = deplace_paddle(PAD);
			B = deplace_balle(&pscore, B, PAD);
			
			if (B.dx == 0 && B.dy == 0)
			{
				jouer = faute(J, &B, &PAD, difficulte, &score);
				if(jouer == 0) rejouer = jouer;
			}
			if (J->nb_de_vie == 0) {game_over(); jouer = 0; }
			if (verif_niveau(BRIQUE) != 1) {jouer = 0; niveau++;}
		}
	}while(J->nb_de_vie > 0 && rejouer == 1);
	
	if(J->nb_de_vie == 0) game_over();
	else if (niveau > 8) gagne();
}

void choix_difficulte(int *choix)
{
	POINT P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, DIFFICULTE, FACILE, MOYENNE, DIFFICILE, RETOUR, CLIC;
	
	P1.x = 300;
	P1.y = 550;
	P2.x = 600;
	P2.y = 450;
	
	P3.x = 300;
	P3.y = 350;
	P4.x = 600;
	P4.y = 270;
	
	P5.x = 300;
	P5.y = 240;
	P6.x = 600;
	P6.y = 160;
	
	P7.x = 300;
	P7.y = 130;
	P8.x = 600;
	P8.y = 50;
	
	P9.x = 750;
	P9.y = 50;
	P10.x = 900;
	P10.y = 0;
	
	DIFFICULTE.x = 300;
	DIFFICULTE.y = 535;
	FACILE.x = 375;
	FACILE.y = 338;
	MOYENNE.x = 350;
	MOYENNE.y = 228;
	DIFFICILE.x = 350;
	DIFFICILE.y = 118;
	RETOUR.x = 765;
	RETOUR.y = 45;
	
	do
	{
		fill_screen(noir);
		
		draw_rectangle(P1, P2, blanc);
		draw_rectangle(P3, P4, blanc);
		draw_rectangle(P5, P6, blanc);
		draw_rectangle(P7, P8, blanc);
		draw_rectangle(P9, P10, blanc);
		
		if(*choix == 0)
			draw_fill_rectangle(P3, P4, gris);
		if(*choix == 1)
			draw_fill_rectangle(P5, P6, gris);
		if(*choix == 2)
			draw_fill_rectangle(P7, P8, gris);
			
		aff_pol("DIFFICULTE", 50, DIFFICULTE, blanc);
		aff_pol("FACILE", 40, FACILE, blanc);
		aff_pol("MOYENNE", 40, MOYENNE, blanc);
		aff_pol("DIFFICILE", 40, DIFFICILE, blanc);
		aff_pol("RETOUR", 30, RETOUR, blanc);
			
		CLIC = wait_clic();
		if((CLIC.x > 300 && CLIC.x < 600) && (CLIC.y > 270 && CLIC.y < 350))
			*choix = 0;
		if((CLIC.x > 300 && CLIC.x < 600) && (CLIC.y > 160 && CLIC.y < 240))
			*choix = 1;
		if((CLIC.x > 300 && CLIC.x < 600) && (CLIC.y > 50 && CLIC.y < 130))
			*choix = 2;
	}while(CLIC.x < 750 || CLIC.y > 50);
	
}

void credits()
{
	POINT P1, P2, P3, P4, MIA, ETDS, ETD1, ETD2, RETOUR, CLIC;
	
	P1.x = 150;
	P1.y = 500;
	P2.x = 750;
	P2.y = 100;
	
	P3.x = 750;
	P3.y = 50;
	P4.x = 900;
	P4.y = 0;
	
	RETOUR.x = 765;
	RETOUR.y = 45;
	MIA.x = 300;
	MIA.y = 500;
	ETDS.x = 150;
	ETDS.y = 400;
	ETD1.x = 150;
	ETD1.y = 300;
	ETD2.x = 150;
	ETD2.y = 200;
	
	draw_rectangle(P1, P2, blanc);
	draw_rectangle(P3, P4, blanc);
	
	aff_pol("[L1 MIASHS]", 50, MIA, blanc);
	aff_pol("Etudiants :", 50, ETDS, blanc);
	aff_pol("EL FARRAN  Lahoucine", 50, ETD1, blanc);
	aff_pol("     IKNI         Yannis", 50, ETD2, blanc);
	aff_pol("RETOUR", 30, RETOUR, blanc);
	
	do
	{
		CLIC = wait_clic();
	}while(CLIC.x < 750 || CLIC.y > 50 );
	
}

void entete(int niveau, int score, int nb_de_vie)
{
	POINT P1, P2;
	char nv[300] = "";
	
	P1.x = 0;
	P1.y = HEIGHT;
	P2.x = WIDTH;
	P2.y = HEIGHT - 20;
	draw_fill_rectangle(P1, P2, noir);
	sprintf(nv, "NIVEAU : %d                                        VIE(S) RESTANTES : %d                                                                 SCORE : %d", niveau, nb_de_vie, score);
	draw_rectangle(P1, P2, blanc);
	
	aff_pol(nv, 15, P1, blanc);
}

void touche(void)
{
	POINT ESPACE;
	SDL_Event touche;
	
	ESPACE.x = 10;
	ESPACE.y = 325;
	
	affiche_auto_on();
	
	aff_pol("APPUYEZ SUR LA BARRE D'ESPACE", 50, ESPACE, blanc);
	
	do
	{
		SDL_WaitEvent(&touche);
	}while(touche.key.keysym.sym != ' ' );
	fill_screen(noir);
	affiche_auto_off();
}

void affiche_brique_restantes(struct brique BRIQUE[14][5])
{
	int i, j;
	
	for(j=0; j<5; j++)
	{
		for(i=0; i<14; i++)
		{
			if(BRIQUE[i][j].affiche == TRUE && BRIQUE[i][j].casse > 0)
			{
				switch (BRIQUE[i][j].casse)
				{
				case 1:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, blanc);
					break;
				case 2:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, vert);
					break;
				case 3:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, jaune);
					break;
				case 4:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, orangered);
					break;
				case 5:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, rouge);
					break;
				default:
					draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, steelblue);
					BRIQUE[i][j].casse++;
					break;
				}
				
			}
		}
	}
}

void efface_brique(struct brique BRIQUE[14][5])
{
	int i, j;
	
	for(j=0; j<5; j++)
	{
		for(i=0; i<14; i++)
		{
			draw_fill_rectangle(BRIQUE[i][j].B1, BRIQUE[i][j].B2, noir);
		}
	}
}

int init_niveau(int niveau)
{
	switch (niveau)
	{
	case 1:
		niveau_1(BRIQUE);
		return 1;
		break;
	case 2:
		niveau_2(BRIQUE);
		return 1;
		break;
	case 3:
		niveau_3(BRIQUE);
		return 1;
		break;
	case 4:
		niveau_4(BRIQUE);
		return 1;
		break;
	case 5:
		niveau_5(BRIQUE);
		return 1;
		break;
	case 6:
		niveau_6(BRIQUE);
		return 1;
		break;
	case 7:
		niveau_7(BRIQUE);
		return 1;
		break;
	case 8:
		niveau_8(BRIQUE);
		return 1;
		break;
	default:
		printf("\nVOUS AVEZ FINI LES NIVEAUX\n");
		return 0;
		break;
	}
}

int verif_niveau(struct brique BRIQUE[14][5])
{
	int i, j;
	
	for(j=0; j<5; j++)
	{
		for(i=0; i<14; i++)
		{
			if(BRIQUE[i][j].casse < 6)
			{
				if(BRIQUE[i][j].affiche == TRUE) return 1;
			}
		}
	}
	
	return 0;
}

void gagne(void)
{
	POINT P1, P2, GAGNE, RETOUR, CLIC;
	
	P1.x = 750;
	P1.y = 50;
	P2.x = 900;
	P2.y = 0;
	
	RETOUR.x = 765;
	RETOUR.y = 45;
	GAGNE.x = 25;
	GAGNE.y = 395;
	
	affiche_auto_on();
	
	draw_rectangle(P1, P2, blanc);
	
	aff_pol("BRAVO", 150, GAGNE, blanc);
	aff_pol("RETOUR", 30, RETOUR, blanc);
	
	do
	{
		CLIC = wait_clic();
	}while(CLIC.x < 750 || CLIC.y > 50 );
	fill_screen(noir);
	affiche_auto_off();
}


