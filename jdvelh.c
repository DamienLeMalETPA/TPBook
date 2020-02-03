#include <stdio.h>
#include <string.h>

struct Chapitre{
	char description[999];
	int gain_or;
	int gain_pv;
	int next[100];
};
typedef struct Chapitre Chapitre;

int deplacement(Chapitre * varChapitre, Chapitre * varChoix, Chapitre * varChoix2){
	int test = 0;
	int choix_chemin = 0;
	printf("Depuis %s, vous pouvez aller a plusieurs endroits :\n[%d] %s \n[%d] %s \n",(*varChapitre).description,(*varChapitre).next[0], (*varChoix).description,(*varChapitre).next[1], (*varChoix2).description);
	while (test == 0){
		scanf("%d",&choix_chemin);
		if ((choix_chemin == (*varChapitre).next[0])||(choix_chemin == (*varChapitre).next[1])){
			test = 1;
		}else{
			printf("Choix impossible !\n");
		}
	}
	return choix_chemin;
}

int main(){
	Chapitre chapitre[99];

	strcpy(chapitre[1].description,"Le Chemin");
	chapitre[1].gain_or = 0;
	chapitre[1].gain_pv = 0;
	chapitre[1].next[0] = 2;
	chapitre[1].next[1] = 3;

	strcpy(chapitre[2].description,"Le Chateau du Roi Licorne");
	chapitre[2].gain_or = 10;
	chapitre[2].gain_pv = 10;
	chapitre[2].next[0] = 1;
	chapitre[2].next[1] = 3;

	strcpy(chapitre[3].description,"La Foret Enchantee");
	chapitre[3].gain_or = 20;
	chapitre[3].gain_pv = 20;
	chapitre[3].next[0] = 1;
	chapitre[3].next[1] = 2;
	
	int boucle = 0;
	int chapitre_actuel = 1;
	int choix = 0;

	while (boucle == 0){
		//navigation
		switch (chapitre_actuel){
			case 1 :
				printf("Vous etes sur %s \n", chapitre[1].description);
				chapitre_actuel = deplacement(&chapitre[1], &chapitre[2], &chapitre[3]);
				break;
			case 2 :
				printf("Vous etes sur %s \n", chapitre[2].description);
				chapitre_actuel = deplacement(&chapitre[2], &chapitre[1], &chapitre[3]);
				break;
			case 3 :
				printf("Vous etes sur %s \n", chapitre[3].description);
				chapitre_actuel = deplacement(&chapitre[3], &chapitre[1], &chapitre[2]);
				break;
		}
	}
	return 0;
}