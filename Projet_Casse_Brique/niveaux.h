
void niveau_1(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = FALSE;
			BRIQUE[i][j].casse = 1;
		}
	}
	
	BRIQUE[10][4].affiche = TRUE;
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}

void niveau_2(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j%2 == 0) BRIQUE[i][j].casse = 2;
			else BRIQUE[i][j].casse = 1;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}

void niveau_3(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j%2 == 0 || i%2 == 0) BRIQUE[i][j].casse = 2;
			else BRIQUE[i][j].casse = 1;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}

void niveau_4(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j%2 == 0) BRIQUE[i][j].casse = 3;
			else BRIQUE[i][j].casse = 2;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}

void niveau_5(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j == 4) BRIQUE[i][j].casse = 4;
			else BRIQUE[i][j].casse = 2;
		}
	}
	
	BRIQUE[5][2].casse = 100;
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}


void niveau_6(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j%2 == 1) BRIQUE[i][j].casse = 5;
			else BRIQUE[i][j].casse = 1;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}	
}

void niveau_7(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(i == 0 || i == 13) BRIQUE[i][j].casse = 100;
			else BRIQUE[i][j].casse = 3;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}
}

void niveau_8(struct brique (BRIQUE[14][5]))
{
	int i = 0, j = 0, k = 2;
	
	for (j = 0; j < 5; j++)
	{
		for(i=0; i<14; i++)
		{
			BRIQUE[i][j].affiche = TRUE;
			if(j == 2 && i < 13 && i > 0) BRIQUE[i][j].casse = 100;
			else BRIQUE[i][j].casse = 2;
		}
	}
	
	for(j=0; j<5; j++)
	{
		BRIQUE[0][j].B1.x = 3;
		BRIQUE[0][j].B2.x = BRIQUE[0][j].B1.x + 62;
		
		if(j == 0)
		{
			BRIQUE[0][0].B1.y = 600 - 20 - k;
			BRIQUE[0][0].B2.y = BRIQUE[0][0].B1.y - 40;
		}
		else
		{
			BRIQUE[0][j].B1.y = BRIQUE[0][j-1].B1.y - 40 - k;
			BRIQUE[0][j].B2.y = BRIQUE[0][j-1].B2.y - 40 - k;
		}
		
		for(i=1; i<14; i++)
		{
			BRIQUE[i][j].B1.x = BRIQUE[i-1][j].B1.x +(k + 62);
			BRIQUE[i][j].B1.y = BRIQUE[i-1][j].B1.y;
			BRIQUE[i][j].B2.x = BRIQUE[i-1][j].B2.x + (k + 62);
			BRIQUE[i][j].B2.y = BRIQUE[i-1][j].B2.y;
		}	
	}
}
