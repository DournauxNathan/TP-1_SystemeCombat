#include <stdio.h>

int main()
{
	int vie;
	vie = 30;

	int vieMonstre;
	vieMonstre = 50;
	float degat;
	degat = 5;


	while(vieMonstre >= 0 || vie >= 0)
		printf("Vous: %d \n", vie);

		printf("Monstre: %d \n \n", vieMonstre);

		printf("Vous attaquez le monstre ! \n");

		vieMonstre = vieMonstre - degat;

		printf("PV du monstre: %d \n \n", vieMonstre);

		printf("Le monstre contre-attque ! \n");

		vie = vie - degat;
	}

	return 0;
}