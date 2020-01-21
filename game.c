#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

int main()
{
	int vie;
	vie = 30;

	int vieMonstre;
	vieMonstre = 50;

	float degat;
	degat = 5;

	int choix;

	printf("\n");
	printf("Un monstre sauvage apparait ! \n \n");

	while(vieMonstre >= 0 || vie >= 0)
	{
		printf("Vous: %d \n", vie);

		printf("Monstre: %d \n \n", vieMonstre);

		//Action du joueur
		printf("Attaquer [1] ou Se defendre [2]");

		//Action du monstre
		srand(time(NULL));
    	int choixMonstre = rand()%3+1;    //entre 1-3

		scanf("%d", &choix);
		printf("\n");

		switch (choix)
		{
			case 1 :
				printf("Vous attaquez le monstre ! \n");

				if (choixMonstre == 2)
				{
					printf("Le monstre se defend \n");		
					vieMonstre = vieMonstre - (degat / 4);
					printf("Votre n'attaque n'est pas tres efficace... \n");
				}
				else
				{
				vieMonstre = vieMonstre - degat;

				printf("PV du monstre: %d \n \n", vieMonstre);

				printf("C'est super efficace ! \n");
				}
			break;

			case 2 :
				printf("Vous vous defendez ! \n \n");

				if (choixMonstre == 1)
				{
					degat = degat / 4;
					vie = vie - degat;
					printf("Vous venez de perdre %1f points de vie \n \n", degat);
				}

				
			break;
		}
	}

	return 0;
}