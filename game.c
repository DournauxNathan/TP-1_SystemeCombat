#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

/*Ceci est notre systeme de combat cf http://bit.ly/35Q6ffC */

int main()
{
	int nTour;
	nTour = 1;

	int vie;
	vie = 30;

	int vieMonstre;
	vieMonstre = 50;

	int choix;

	int degat;
	degat = 5;

    srand(time(NULL)); // initialisation de rand

	int pointMagie;
	pointMagie = 60;

	int pointMagieMonstre;
	pointMagieMonstre = 35;
	

	int degatPoison;
	degatPoison = 3;
	

	printf("\n");
	printf("Un monstre apparait ! \n \n");

	while(vieMonstre >= 0 || vie >= 0)
	{
		printf("__________________________\n");
		printf("Tour: %d \n", nTour);
        printf("__________________________\n \n");
        
		printf("PV: %d \n", vie);
		printf("PM: %d \n \n", pointMagie);

		printf("Monstre: %d \n \n", vieMonstre);

		//Action du joueur
		printf("Attaquer [1] ou Se defendre [2] ou Lancer poison [3] ou Utiliser antidote [4] \n \n");

		//Action du monstre
		srand(time(NULL));
    	int choixMonstre = rand()%3+1;    //entre 1-3

		scanf("%d", &choix);
		printf("\n");
		switch (choix)
		{
			case 1 :
				printf("Vous attaquez le monstre ! \n \n");

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
			
				printf("Le monstre vous attaque !  \n \n");

				printf("Vous vous defendez ! \n \n");

				degat = degat / 4;

				vie = vie - degat;

				printf("Vous venez de perdre %df points de vie \n \n", degat);
			break;

			case 3 :
				printf("Vous lancer un sort de poison \n \n");

				pointMagie = pointMagie - 7;

				printf("Vous avez utilise 7 points de magie \n \n");

				printf("Le monstre a recu %d points de poison \n \n", degatPoison);

				if(pointMagie <= 0)
				{
					printf("Vous ne disposer plus de PM \n \n");
				}
			break;

			case 4 :
		
				printf("Vous utiliser un antidote \n \n");
			break;
		}
		vieMonstre = vieMonstre - degatPoison;

		pointMagie = pointMagie + 1;
    		if (pointMagie == 60)
    		{
    		    printf("Vous barre de magie est plein ! \n");
    		    pointMagie = pointMagie;
    		}

		nTour = nTour + 1;
	}	
    	//Fin du jeu
		if(vie <= 0)
		{
			printf("Vous etes mort \n \n");
			return 0;
		}
		

		if(vieMonstre <= 0)
		{
			printf("Vous avez vaincu le monstre en %d tour\n \n", nTour);
			return 0;
		}
	
	
	return 0;
}	