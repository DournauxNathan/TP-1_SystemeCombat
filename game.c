#include <stdio.h>

int main()
{
	int vie;
	vie = 30;

	int vieMonstre;
	vieMonstre = 50;
	float degat;
	degat = 5;

	printf("\n");
	printf("Un monstre sauvage apparait ! \n \n");

	while(vieMonstre >= 0 || vie >= 0)
		printf("Vous: %d \n", vie);

		printf("Monstre: %d \n \n", vieMonstre);

		//Action du joueur
		printf("Attaquer [1] ou Se defendre [2]");

		scanf("%d", &choix);
		printf("\n");

		switch (choix)
		{
			case 1 :
				printf("Vous attaquez le monstre ! \n");
				vieMonstre = vieMonstre - degat;
				printf("PV du monstre: %d \n \n", vieMonstre);
			break;

			case 2 :
				printf("Vous vous defendez ! \n \n");
				degat = degat / 4;
				vie = vie - degat;
				printf("Vous venez de perdre %df points de vie \n \n", degat);
			break;
		}
	}

	return 0;
}