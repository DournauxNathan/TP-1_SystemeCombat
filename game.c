#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

	/*TP: Systeme de combat //lien DropBox: http://bit.ly/35Q6ffC */

//Structure: Alliés héros
struct Personnage
{
	int vie;
	int pointMagie;
	int exp;
};

int main() {
	int nTour = 1;

	//Joueur
	int vie = 100;
	int pointMagie = 100;
	int exp = 0;

	int choix;

	int isPlayerPoison;
	isPlayerPoison = 0;

	//Alliés
	struct Personnage soigneur;
	soigneur.vie = 100;
	soigneur.pointMagie = 120;
	soigneur.exp = 0;

	int choixSoigneur;
	int soinsChoix;

	struct Personnage mage;
	mage.vie = 100;
	mage.pointMagie = 150;
	mage.exp = 0;

	int choixMage;

	struct Personnage barde;
	barde.vie = 100;
	barde.pointMagie = 110;
	barde.exp = 0;

	int choixBarde;

	//Monstre
	int vieMonstre = 250;
	int pointMagieMonstre = 35;

	int choixMonstre;
	srand(time(NULL)); // initialisation de rand

	int isMonstrePoison;
	isMonstrePoison = 0;

	float degat = 5;

	int degatPoison = 3;

	void ActionSoigneur() 
	{
		if (soigneur.pointMagie >= 0)
		{
			switch (choixSoigneur)
			{
				case 1 :
				printf("Le soigneur utilise soin\n\n");
					if(soigneur.vie != 100)
					{
						soigneur.pointMagie = soigneur.pointMagie - 10;
						soigneur.vie = soigneur.vie + 25;
						printf("Le soigneur recupere 25 points de vie\n\n");
						printf("- - - - - - - - - - -\n \n");
					}
					else
					{
						printf("La vie du soigneur est deja au maximum\n\n");
						printf("- - - - - - - - - - -\n \n");
					}
				break;

				case 2 :
					printf("Le soigneur utiliser un sort de soins cible\n\n");
					if( vie >= 100 && mage.vie >= 100 && barde.vie >= 100)
					{
						printf("Personne n'as besoin de soins\n\n");
						printf("- - - - - - - - - - -\n \n");
					}
					else
					{
						soinsChoix = rand()%3+1;
						if (soinsChoix == 1 && vie < 100)
						{
							soigneur.pointMagie = soigneur.pointMagie - 15;
							vie = vie + 25;
							printf("Vous recuperer 25 points de vie \n\n");
							printf("- - - - - - - - - - -\n \n");
							
						}
						else if (soinsChoix == 1 && vie >= 100)
						{
							printf("Vous n'avez pas besoin de soins\n");
							printf("- - - - - - - - - - -\n \n");
						}
						
						if (soinsChoix == 2 && mage.vie < 100)
						{
							soigneur.pointMagie = soigneur.pointMagie - 15;
							mage.vie = mage.vie + 25;
							printf("Le mage recuperer 25 points de vie \n\n");
							printf("- - - - - - - - - - -\n \n");
						}
						else if (soinsChoix == 2 && mage.vie >= 100)
						{
							printf("Le mage n'a pas besoin de soins\n");
							printf("- - - - - - - - - - -\n \n");
						}

						if (soinsChoix == 3 && barde.vie < 100)
						{
							soigneur.pointMagie = soigneur.pointMagie - 15;
							barde.vie = barde.vie + 25;
							printf("Le barde recuperer 25 points de vie \n\n");
							printf("- - - - - - - - - - -\n \n");
						}
						else if (soinsChoix == 3 && barde.vie >= 100)
						{
							printf("Le barde n'a pas besoin de soins\n");
							printf("- - - - - - - - - - -\n \n");
						}
					}
				break;

				if(vie < 100 && soigneur.vie < 100 && mage.vie < 100 && barde.vie < 100)
				{
					printf("Le soigneur utilise un sort de soins groupe\n\n");
					printf("- - - - - - - - - - -\n \n");
					soigneur.pointMagie = soigneur.pointMagie - 30;
					vie += 15;
					soigneur.vie += 15;
					mage.vie += 15;
					barde.vie += 15;
					printf("Vous et vos coequipier recuperer 15 points de vie \n\n");
					printf("- - - - - - - - - - -\n \n");
				}
				break;
			}
		}
		else 
		{
			printf("Le soigneur n'as plus de PM\n\n");
		}

		if (soigneur.vie <= 0)
		{
			printf("Le soigneur est mort\n\n");
		}

		return;
	}

	/*Début du jeu avec une phrase indicative*/
	printf("\n");
	printf("Un monstre apparait ! \n \n");

	while(vieMonstre >= 0 || vie >= 0) {
		printf("__________________________\n");
		printf("Tour: %d \n", nTour);
        printf("__________________________\n \n");

        printf("Monstre: \n");
		printf("PV: %d \n \n", vieMonstre);
        
        printf("Vous:   | Soigneur: | Mage:   | Barde:  |       \n");
		printf("PV: %d | PV: %d   | PV: %d | PV: %d |         	\n", vie, soigneur.vie, mage.vie, barde.vie);
		printf("PM: %d | PM: %d   | PM: %d | PM: %d |          	\n", pointMagie, soigneur.pointMagie, mage.pointMagie, barde.pointMagie);
		printf("XP: %d   | XP: %d     | XP: %d   | XP: %d   |	\n\n", exp, soigneur.exp, mage.exp, barde.exp);
		
		//Choix du joueur
		printf(" Attaquer      [1]  Se defendre       [2]  \n");
		printf(" Lancer poison [3]  Utiliser antidote [4]\n\n");
		printf("	    //Inventaire [5]//               \n\n");

		//Choix des alliés
			/*Choix du soigneur: Soins[1] Soins Cible[2] Soins Groupe[3] */
		choixSoigneur = rand()%2+1;

			/*Choix du mage: Boule de feu[1] Pics de glace[2] Paralysie[3] */
		choixMage = rand()%3+1;

			/*Choix du barde: Buff Attaque[1] Buff Defense[2] Buff regen[3] */
		choixBarde = rand()%3+1;
		printf("Attaquer [1] ou Se defendre [2] ou Lancer poison [3] ou Utiliser antidote [4] \n \n");

		//Choix du monstre (Aléatoire)
			/*Choix du monstre: Attaquer[1] Se defendre[2] Poison[3] */
    	choixMonstre = rand()%3+1;

		printf("-> Votre choix: "); scanf("%d", &choix); 
		printf("\n");
		
		switch (choix)
		{	
				//Le joueur attaque
			case 1 :
				printf("Vous attaquez le monstre ! \n \n");
				printf("- - - - - - - - - - -\n \n");

				ActionSoigneur();

					//Action du monstre
				if (choixMonstre == 2)
				{
					printf("Le monstre se protege \n \n");		
					vieMonstre = vieMonstre - (degat = degat / 4);
					printf("Votre attaque n'est pas tres efficace... \n \n");
				}
				else
				{
					vieMonstre = vieMonstre - degat;
					printf("Votre attaque est efficace ! \n \n");
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
							vieMonstre = vieMonstre - (degat = degat / 4);
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
				printf("Vous vous preparer a contrer\n \n");
				printf("- - - - - - - - - - -\n \n");

				ActionSoigneur();

					//Action du monstre
				if (choixMonstre == 1)
				{
					printf("Le monstre vous attaque !  \n \n");
					printf("- - - - - - - - - - -\n \n");
					printf("Vous vous defendez ! \n \n");
					printf("- - - - - - - - - - -\n \n");
					vie = vie - (degat = degat / 4);
					printf("Son attaque n'est pas tres efficace... \n \n");
					printf("Vous venez de perdre %f points de vie \n \n", degat);
				}

				if (choixMonstre == 2)
				{
					printf("Le monstre se prepare a se defendre \n \n");
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
							vieMonstre = vieMonstre - (degat = degat / 4);
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

				ActionSoigneur();
				
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
					printf("Vous n'etes pas empoisonne...\n \n");
					printf("- - - - - - - - - - -\n \n");
					ActionSoigneur();
				}
				else if(isPlayerPoison >= 1)
				{
					printf("Vous utiliser un antidote \n \n");
					isPlayerPoison = 0;
					if (isPlayerPoison <= 0)
					{
						printf("Vous n'etes plus empoisonne\n \n");
					}
					printf("- - - - - - - - - - -\n \n");
					ActionSoigneur();
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
					printf("Le monstre se prepare a se defendre \n \n");
				}

				if (choixMonstre == 3)
				{
					if(pointMagieMonstre <= 0)
					{
						choixMonstre = rand()%2+1;

						if (choixMonstre == 1)
						{
							printf("Le montre contre-attaque \n \n");
							printf("Le monstre contre-attaque \n \n");
							vie = vie - degat;
							printf("Aye ! Il vous touche gravement !\n \n");
						}
						else if(choixMonstre == 2)
						{
							printf("Le monstre se prepare a se defendre \n \n");						
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
		if (pointMagie < 100)
		{
			pointMagie = pointMagie + 1;
			if (pointMagie == 100)
			{
				printf("Vous barre de magie est plein ! \n\n");
			}
		}

		if (soigneur.pointMagie < 120)
		{
			soigneur.pointMagie = soigneur.pointMagie + 1;
			if (soigneur.pointMagie == 120)
			{
				printf("La barre de magie du soigneur est plein ! \n\n");
			}
		}

		if (mage.pointMagie < 150)
		{
			mage.pointMagie = mage.pointMagie + 1;
			if (mage.pointMagie == 150)
			{
				printf("La barre de magie du mage est plein ! \n\n");
			}
		}

		if (barde.pointMagie < 110)
		{
			barde.pointMagie = barde.pointMagie +1;
			if (barde.pointMagie == 110)
			{
				printf("La barre de magie du barde est plein ! \n\n");
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