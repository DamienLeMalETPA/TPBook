#include <stdio.h>

void main(){
	int choix_chemin = 0;
	//navigation
	printf("La route se separe en deux, un chemin menant au château du Roi Licorne, l'autre vers la foret enchantee, ou allez-vous ?\n[1] Au Chateau du roi Licorne\n[2] A la foret enchantee");
	scanf("%d",&choix_chemin);
	switch (choix_chemin){
		case 1 :
			printf("Vous etes arrive au Chateau du roi Licorne\n");
			break;
		case 2 :
			printf("Vous etes arrive a la foret enchantee\n");
			break;
	}
	return 0;
}