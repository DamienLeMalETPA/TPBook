#include <stdio.h>

struct Chapitre{
	char description[999];
	int gain_or;
	int gain_pv;
	int next[100];
};
typedef struct Chapitre chapitre;

int deplacement(chapitre * varChapitre, char lieu1[99], char lieu2[99]){
	int test = 0;
	int choix_chemin = 0;
	printf("Depuis %s, vous pouvez aller a plusieurs endroits :\n[%d] %s \n[%d] %s \n",(*varChapitre).description,(*varChapitre).next[1], lieu1,(*varChapitre).next[2], lieu2 );
	while (test == 0){
		scanf("%d",&choix_chemin);
		if ((choix_chemin == (*varChapitre).next[1])||(choix_chemin == (*varChapitre).next[2])){
			test = 1;
		}
	}
	return choix_chemin;
}
 


int main(){
	chapitre chapitre1 = {"Le Chemin",0,0,{0,1,2}};//0
	chapitre chapitre2 = {"Le Chateau du Roi Licorne",10,10,{1,0,2}};//1
	chapitre chapitre3 = {"La Foret Enchantee",20,30,{2,0,1}};//2
	
	int boucle = 0;
	int chapitre_actuel = 0;
	int choix = 0;

	while (boucle == 0){
		//navigation
		switch (chapitre_actuel){
			case 0 :
				printf("Vous etes sur %s \n", chapitre1.description);
				chapitre_actuel = deplacement(&chapitre1, "Le Chateau du Roi Licorne","La Foret Enchantee");
				break;
			case 1 :
				printf("Vous etes sur %s \n", chapitre2.description);
				chapitre_actuel = deplacement(&chapitre2,"Le Chemin","La Foret Enchantee");
				break;
			case 2 :
				printf("Vous etes sur %s \n", chapitre3.description);
				chapitre_actuel = deplacement(&chapitre3,"Le Chemin","Le Chateau du Roi Licorne");
				break;
		}
	}
	return 0;
}