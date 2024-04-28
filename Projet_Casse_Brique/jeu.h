/*   STRUCTURES   */
struct balle
{
	POINT centre;
	int rayon;
	int dx, dy;
};

struct paddle
{
	POINT P1, P2;
};

struct joueur
{
	int nb_de_vie;
};

struct brique
{
	POINT B1;
	POINT B2;
	BOOL affiche;
	int casse;
};

/* Fin STRUCTURES */

/*   PROTOTYPES   */

struct paddle init_paddle (int difficulte);
struct balle init_balle (struct paddle PAD, int difficulte);
struct joueur init_joueur (void);

struct balle rebond_bord(struct balle B, struct paddle PAD);
struct balle rebond_brique(struct balle B, struct brique BRIQUE[14][5], int *score);

void game_over(void);
void gagne(void);
void touche(void);

struct balle deplace_balle(int **score, struct balle B, struct paddle PAD);
struct paddle deplace_paddle(struct paddle PAD);
void affiche_paddle(struct paddle PAD);
void affiche_balle(struct balle B);
void efface_paddle(struct paddle PAD);
void efface_balle(struct balle B);

void continuer(int *rejouer);
int faute(struct joueur *J, struct balle *B, struct paddle *PAD, int difficulte, int *score);

int menu(void);
void choix_difficulte(int *choix);
void credits(void);

int init_niveau(int niveau);
int verif_niveau(struct brique BRIQUE[14][5]);

void jeu (struct joueur *J, int difficulte);
void entete(int niveau, int score, int nb_de_vie);

void affiche_brique_restantes(struct brique BRIQUE[14][5]);
void efface_brique(struct brique BRIQUE[14][5]);


/* Fin PROTOTYPES */

/**   DEFINES   **/

#define VIE_AU_LANCEMENT 5

/** Fin DEFINES **/

/*   STRUCTURE GLOBALES    */

struct brique BRIQUE[14][5];

/* Fin STRUCTURES GLOBALES */


/* ABANDONNÉS */

/*FILE *enregistrer_score(char *nom, int score_obtenu, int niveau)
{
	FILE *resultat;
	resultat = fopen("Resultats.txt", "a");
	if (resultat == NULL)
		printf("\nErreur dans la fonction 'enregistrer_score'.\n");
	fprintf(resultat, "%s - %d - %d\n", nom, niveau, score_obtenu);
	fclose(resultat);
	if(!(execlp("Resultats.txt", NULL)))
		printf("ERREUR LANCEMENT FICHIER TXT");
	return resultat;
}*/
