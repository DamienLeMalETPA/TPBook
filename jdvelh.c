#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

struct Chapitre{
	int id;
	char description[999];
	int gain_or;
	int gain_pv;
	int next[100];
};
typedef struct Chapitre Chapitre;

int deplacement(Chapitre * varChapitre, Chapitre * varChoix, Chapitre * varChoix2){
	int test = 0;
	int choix_chemin = 0;
	printf("Depuis %s, vous pouvez aller a plusieurs endroits :\n[%d] %s \n[%d] %s \n[0] Sauvegarder\n",(*varChapitre).description,(*varChapitre).next[0], (*varChoix).description,(*varChapitre).next[1], (*varChoix2).description);
	while (test == 0){
		scanf("%d",&choix_chemin);
		if ((choix_chemin == (*varChapitre).next[0])||(choix_chemin == (*varChapitre).next[1])){
			test = 1;
		}else if (choix_chemin == 0){
			return choix_chemin;
		} else {
			printf("Choix impossible !\n");
		}
	}
	return choix_chemin;
}
void bilan(int g,int p,int * g_p,int * pv_p){
	*g_p += g;
	*pv_p += p;
	if (*g_p < 0){
		*g_p = 0;
	}
	if (*pv_p > 100){
		*pv_p = 100;
	}
	printf("or : %d\npv : %d\n",*g_p,*pv_p);
}
void save(int *pv, int *gold, int *id_actuel){
	FILE *save = fopen("file.txt", "w");
	fprintf(save, "pv: %d, gold: %d, id_actuel: %d \n", *pv, *gold, *id_actuel);
	fclose(save);


}


int main(){
	srand(time(NULL));
	Chapitre chapitre[99];

	strcpy(chapitre[1].description,"Le Chemin");
	chapitre[1].id = 1;
	chapitre[1].gain_or = 0;
	chapitre[1].gain_pv = 0;
	chapitre[1].next[0] = 2;
	chapitre[1].next[1] = 3;

	strcpy(chapitre[2].description,"Le Chateau du Roi Licorne (Il vous faut 20 pieces pour passer la douane)");
	chapitre[2].id = 2;
	chapitre[2].gain_or = 10;
	chapitre[2].gain_pv = -20;
	chapitre[2].next[0] = 1;
	chapitre[2].next[1] = 3;

	strcpy(chapitre[3].description,"La Foret Enchantee");
	chapitre[3].id = 3;
	chapitre[3].gain_or = -10;
	chapitre[3].gain_pv = -50;
	chapitre[3].next[0] = 1;
	chapitre[3].next[1] = 2;
	
	int boucle = 0;
	int chapitre_actuel = 1;
	int id_actuel = 1;//garde en mémoire le chapitre précédent
	int hand = 0;
	int choix = 0;
	int choix2 = 0;
	int pv = 100;
	int gold = 10;

	while (pv > 0){
		//navigation
		switch (chapitre_actuel){
			case 0 :
				save(&pv, &gold, &id_actuel);
				break;
			case 1 :
				id_actuel = 1;
				printf("Vous etes sur %s \n", chapitre[1].description);
				chapitre_actuel = deplacement(&chapitre[1], &chapitre[chapitre[1].next[0]], &chapitre[chapitre[1].next[1]]);
				bilan(chapitre[1].gain_or,chapitre[1].gain_pv,&gold,&pv);
				break;
			case 2 :
				if (gold < 20){ //condition
					printf("Vous n'avez pas assez de pieces !\n");
					chapitre_actuel = deplacement(&chapitre[id_actuel], &chapitre[chapitre[id_actuel].next[0]], &chapitre[chapitre[id_actuel].next[1]]);
					break;
				}
				id_actuel = 2;
				printf("Vous etes sur %s \n", chapitre[2].description);
				printf("Le roi Licorne vous remercie de votre visite et vous paie 10 pieces d'or pour partir, vous refusez et les gardes vous chassent du chateau, vous coutant 20 pv !\n");
				bilan(chapitre[2].gain_or,chapitre[2].gain_pv, &gold, &pv);
				chapitre_actuel = deplacement(&chapitre[2], &chapitre[chapitre[2].next[0]], &chapitre[chapitre[2].next[1]]);
				break;
			case 3 :
				id_actuel = 3;
				printf("Vous etes sur %s \n", chapitre[3].description);
				printf("Vous rencontrez un lutin dans la foret enchantee, il vous propose un jeu : si vous arrivez a deviner dans quelle main il cache son tresor, vous le remportez ! Voulez-vous jouer ?\n[1] Oui\n[2] Non\n");
				scanf("%d",&choix);
				if (choix == 1){
					hand = (1 + (rand () % (2)));
					choix2 = 0;
					printf("Faites votre choix :\n[1] Main droite\n[2] Main gauche\n");
					scanf("%d",&choix);
					if (hand == choix){
						printf("Vous remportez le tresor du lutin : *PAF* c'etait sa meillleure technique de boxe australienne, vous perdez 50 pv ainsi que 10 pieces qui sont tombes de votre poche en tombant\n");
						bilan(chapitre[3].gain_or,chapitre[3].gain_pv,&gold,&pv);
					}else{
						printf("Vous aurez plus de chance la prochaine fois ! Vous sortez alors de la foret sans aucun autre evenements\n");
						bilan(0,0,&gold,&pv);
					}
				}else{
					printf("Vous continuez votre chemin et tombez dans un trou cache par des branches, vous perdez 50 pv ainsi que 10 pieces perdues lors de votre chute\n");
					bilan(chapitre[3].gain_or,chapitre[3].gain_pv,&gold,&pv);
				}
				chapitre_actuel = deplacement(&chapitre[3], &chapitre[chapitre[3].next[0]], &chapitre[chapitre[3].next[1]]);
				break;
		}
	}
	printf("Vous etes morts !\n");
	return 0;
}