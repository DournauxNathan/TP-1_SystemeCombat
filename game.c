#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h


	/*TP: Systeme de combat //lien DropBox: http://bit.ly/35Q6ffC */

int main() {
	int nTour;
	nTour = 1;

	//Joueur
	int vie;
	vie = 100;

	int pointMagie;
	pointMagie = 60;

	int exp;
	exp = 0;

	int choix;

	int isPlayerPoison;
	isPlayerPoison = 0;

	//Monstre
	int vieMonstre;
	vieMonstre = 250;

	int pointMagieMonstre;
	pointMagieMonstre = 35;

	srand(time(NULL)); // initialisation de rand

	int isMonstrePoison;
	isMonstrePoison = 0;

	float degat;
	degat = 5;

	int degatPoison;
	degatPoison = 3;

	/*Début du jeu avec une phrase indicative*/
	printf("\n");
	printf("Un monstre apparait ! \n \n");

	while(vieMonstre >= 0 || vie >= 0) {
		printf("__________________________\n");
		printf("Tour: %d \n", nTour);
        printf("__________________________\n \n");
        
        printf("Heros: \n");
		printf("PV: %d | PM: %d | EXP: %d \n \n", vie, pointMagie, exp);

		printf("Monstre: \n");
		printf("PV: %d \n \n", vieMonstre);
		

		//Choix du joueur
		printf("Attaquer [1] ou Se defendre [2] ou Lancer poison [3] ou Utiliser antidote [4] \n \n");

		//Choix du monstre (Aléatoire)
    	int choixMonstre = rand()%3+1;    //entre 1-3
    	printf ("choixMonstre: %d \n \n", choixMonstre);

		printf("-> Votre choix: "); scanf("%d", &choix); 
		printf("\n");
		
		switch (choix)
		{	
				//Le joueur attaque
			case 1 :
				printf("Vous attaquez le monstre ! \n \n");
				printf("- - - - - - - - - - -\n \n");

					//Action du monstre
				if (choixMonstre == 2)
				{
					printf("Le monstre se protège \n \n");		
					vieMonstre = vieMonstre - (degat / 4);
					printf("Votre attaque n'est pas tres efficace... \n \n");
				}
				else
				{
					vieMonstre = vieMonstre - degat;
					printf("C'est super efficace ! \n \n");
					printf("- - - - - - - - - - -\n \n");
				}

				if (choixMonstre == 1)
				{
					printf("Le montre contre-attaque \n \n");
					vie = vie - degat;
					printf("Aye ! Il vous touche gravement !\n \n");
				}

				if (choixMonstre == 3)
				{
					if(pointMagieMonstre <= 0)
					{
						choixMonstre = rand()%2+1;

						if (choixMonstre == 1)
						{
							printf("Le montre contre-attaque \n \n");
							vie = vie - degat;
							printf("Aye ! Il vous touche gravement !\n \n");
						}
						else if(choixMonstre == 2)
						{
							printf("Le monstre se defend \n \n");		
							vieMonstre = vieMonstre - (degat / 4);
							printf("Votre n'attaque n'est pas tres efficace... \n \n");
							
						}
					}
					else
					{
						printf("Le monstre lance un sort de poison \n \n");
						pointMagieMonstre = pointMagieMonstre - 15;
						isPlayerPoison = 1;
					}
				}
				break;	
			
				//Le joueur se defend
			case 2 :
				printf("Vous vous préparer à contrer\n \n");
				printf("- - - - - - - - - - -\n \n");

					//Action du monstre
				if (choixMonstre == 1)
				{
					printf("Le monstre vous attaque !  \n \n");
					printf("Vous vous defendez ! \n \n");
					vie = vie - (degat / 4);
					printf("Son attaque n'est pas tres efficace... \n \n");
					printf("Vous venez de perdre %f points de vie \n \n", degat);
				}

				if (choixMonstre == 2)
				{
					printf("Le monstre se prépare à se defendre \n \n");
				}

				if (choixMonstre == 3)
				{
					if(pointMagieMonstre <= 0)
					{
						choixMonstre = rand()%2+1;

						if (choixMonstre == 1)
						{
							printf("Le montre contre-attaque \n \n");
							vie = vie - degat;
							printf("Aye ! Il vous touche gravement !\n \n");
						}
						else if(choixMonstre == 2)
						{
							printf("Le monstre se defend \n \n");		
							vieMonstre = vieMonstre - (degat / 4);
							printf("Votre n'attaque n'est pas tres efficace... \n \n");
							printf("- - - - - - - - - - -\n \n");
						}
					}
					else
					{
						printf("Le monstre lance un sort de poison \n \n");
						pointMagieMonstre = pointMagieMonstre - 15;
						isPlayerPoison = 1;
					}
				}		
			break;

				//Le joueur lance un sort
			case 3 :
				
				printf("Vous lancer un sort de poison \n \n");
				pointMagie = pointMagie - 10;
				printf("Vous avez utilise 10 points de magie \n \n");
				isMonstrePoison = 1;
				printf("- - - - - - - - - - -\n \n");
				
					//Action du monstre
				if (choixMonstre == 1)
				{
					printf("Le montre contre-attaque \n \n");
					vie = vie - degat;
					printf("Aye ! Il vous touche gravement !\n \n");
				}

				if (choixMonstre == 2)
				{
					printf("Le monstre se defend \n \n");
					printf("Sa defense est inutile face au poison \n \n");
				}

				if (choixMonstre == 3)
				{
					if(pointMagieMonstre <= 0)
					{
						choixMonstre = rand()%2+1;

						if (choixMonstre == 1)
						{
							printf("Le montre contre-attaque \n \n");
							vie = vie - degat;
							printf("Aye ! Il vous touche gravement !\n \n");
						}
						else if(choixMonstre == 2)
						{
							printf("Le monstre se defend \n \n");
							printf("Sa defense est inutile face au poison \n \n");
						}
					}
					else
					{
						printf("Le monstre lance un sort de poison \n \n");
						pointMagieMonstre = pointMagieMonstre - 15;
						isPlayerPoison = 1;
					}
				}
				printf("Le monstre a subit %d degat d'empoisonnement \n \n", degatPoison);
			break;

				//Le joueur utilise un antidote
			case 4 :
				if (isPlayerPoison <= 0)
				{
					printf("Vous n'êtes pas empoisonné...\n \n");
					printf("- - - - - - - - - - -\n \n");
				}
				else if(isPlayerPoison >= 1)
				{
					printf("Vous utiliser un antidote \n \n");
					isPlayerPoison = 0;
					printf("- - - - - - - - - - -\n \n");
				}
				
				if (isPlayerPoison <= 0)
				{
					printf("Vous n'êtes plus empoisonné\n \n");
				}

					//Action du monstre
				if (choixMonstre == 1)
				{
					printf("Le montre contre-attaque \n \n");
					vie = vie - degat;
					printf("Aye ! Il vous touche gravement !\n \n");
				}

				if (choixMonstre == 2)
				{
					printf("Le monstre se prépare à se defendre \n \n");
				}

				if (choixMonstre == 3)
				{
					if(pointMagieMonstre <= 0)
					{
						choixMonstre = rand()%2+1;

						if (choixMonstre == 1)
						{
							printf("Le monstre contre-attaque \n \n");
							vie = vie - degat;
							printf("Aye ! Il vous touche gravement !\n \n");
						}
						else if(choixMonstre == 2)
						{
							printf("Le monstre se prépare à se defendre \n \n");						
						}
					}
					else
					{
						printf("Le monstre lance un sort de poison \n \n");
						pointMagieMonstre = pointMagieMonstre - 15;
						isPlayerPoison = 1;
					}
				}
			break;
		}
		
		//Dégâts de poison / tour
		if(isMonstrePoison >= 1)
		{
			vieMonstre = vieMonstre - degatPoison;
		}
		
		if(isPlayerPoison >= 1)
		{
			vie = vie - degatPoison;
			printf("Vous subissez %d degat d'empoisonnement \n \n", degatPoison);
		}

		//Incrémentation des points de magie / tour
		if (pointMagie < 60)
		{
			pointMagie = pointMagie + 1;
			if (pointMagie == 60)
			{
				printf("Vous barre de magie est plein ! \n");
			}
		}

		nTour = nTour + 1;
	}
		
	
	//Fin du jeu
	if(vie <= 0 || vie == 0)
	{
		printf("Vous etes mort \n \n");
		exit(0);
	}
	
	if(vieMonstre <= 0 || vieMonstre == 0)
	{
		printf("Vous avez vaincu le monstre en %d tour\n \n", nTour);
		exit(0);
	}
	
	return 0;
}