#include <stdio.h> 
#include<stdlib.h>

struct product {
	float price;
    char code[20];
    char name[20];
    int quantity;

};

struct product products[100];

int chosenItem, numberOfProducts = 0;

void showMenu();
void addAProduct();
void showPage(int chosenItem);
void chooseAnItem();
void addMultipleProducts();
void ShowProducts();
int compare();



int main()
{
    showMenu();
    chooseAnItem();
}
// AFFICHAGE DE MENU
void showMenu(){
    printf("\n\t---  MENU  ---\n");
    printf("\n> [1] Ajouter un nouveau produit");
    printf("\n> [2] Ajouter plusieurs produits");
    printf("\n> [3] Afficher tout les produits");
    printf("\n> [4] Acheter un produit");
    printf("\n> [5] Chercher un produit");
    printf("\n> [6] Etat du stock");
    printf("\n> [7] Ajouter au stock");
    printf("\n> [8] Supprimer un produit");
    printf("\n> [9] Afficher les statistiques");
}
// FONCTION D AJOUT D UN SEUL PRODUIT
void addAProduct(){
    printf("Ajouter un produit :\n\n");
    
    printf("Entrer le code du produit :\n=> ");
    scanf("%s", products[numberOfProducts].code);
    
    printf("Entrer le nom du produit :\n=> ");
    scanf("%s", products[numberOfProducts].name);
    
    printf("Entrer la quantite du produit:\n=> ");
    scanf("%d", &products[numberOfProducts].quantity);
    
    printf("Entrer le prix du produit (HT):\n=> ");
    scanf("%f", &products[numberOfProducts].price);
    
    numberOfProducts++;
    
    system("cls");
    printf("Produit ajouter avec succees !! \n\n");
    
    showMenu();
    chooseAnItem();
    
}
// FONCTION DE SWITCH POUR ACCEDER AU CHOIX SUR LE MENU
void showPage(int chosenItem) {
    
    switch(chosenItem){
        case 1 :
            system("cls");
            addAProduct();
            break;
        case 2 :
            system("cls");
            addMultipleProducts();
            break;
        case 3 :
            system("cls");
            ShowProducts();
            break;
        case 4 :
            system("cls");
            printf("Acheter un produit");
            break;
        case 5 :
            system("cls");
            printf("Chercher un produit");
            break;
        case 6 :
            system("cls");
            printf("Etat du stock");
            break;
        case 7 :
            system("cls");
            printf("Ajouter au stock");
            break;
        case 8 :
            system("cls");
            printf("Supprimer un produit");
            break;
        case 9 :
            system("cls");
            printf("Afficher les statistiques");
            break;
        default :
            system("cls");
            printf("Please choose from the menu! \n");
            showMenu();
            break;
    }
}
//FONCTION DE CHOIX SUR LE MENU QUI AJOUTE UN PRINTF ET SCANF POUR SELECTIONNER LE NUMERO
void chooseAnItem(){
    do {
        printf("\n=> ");
        scanf("%d", &chosenItem);
        
        showPage(chosenItem);
        
    } while(chosenItem < 1 || chosenItem > 9);

}

//FONCTION D AJOUT DE PLUSIEUR PRODUIT
void addMultipleProducts(){
	int i;
	int n;
	printf("\n>Entrer combien de produit vous souhaitez ajouter :");
	scanf("%d",&n);
	for(i=0;i<n;i++){

	printf("Ajouter un produit :\n\n");
    
    printf("Entrer le code du produit :\n=> ");
    scanf("%s", products[numberOfProducts].code);
    
    printf("Entrer le nom du produit :\n=> ");
    scanf("%s", products[numberOfProducts].name);
    
    printf("Entrer la quantite du produit:\n=> ");
    scanf("%d", &products[numberOfProducts].quantity);
    
    printf("Entrer le prix du produit (HT):\n=> ");
    scanf("%f", &products[numberOfProducts].price);
    
    numberOfProducts++;
    
    system("cls");
    printf("Produit ajouter avec succees !! \n\n");
		
	}
	sleep(1);
	system("cls");
	showMenu();
	chooseAnItem();
}

//AFFICHER TOUT LES PRODUITS
void ShowProducts(){
	//if : pour si il n y a pas de produit ajouter sur le systeme sa retourne au menu automatiquement apres 4 secondes
	if(numberOfProducts==0){
		printf("\n>Il n y a pas de produit dans le systeme...Retour au menu");	
		sleep(4);
		system("cls");
		showMenu();
		chooseAnItem();
	}
	//lister tout les produits dans l ordre décroissant
	qsort(products, numberOfProducts, sizeof(struct product), compare);
	//for :pour afficher les informations du produit qui sont ajouter sur le systeme
	int i;
	for(i=0;i<numberOfProducts;i++){
	printf("\n->Nom du produit :%s\t ->Prix du produit en HT :%.2f\t ->Prix du produit en TTC :%.2f\n",products[i].name,products[i].price,products[i].price +((products[i].price)*0.15));
	}
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
	// CALCULE DU PRIX DU HT EN TTC 15% : products[i].price +((products[i].price)*0.15)
}

// Fonction de comparaison POUR LE TRIAGE DECROISSANT
int compare(const void *x_void, const void *y_void)
{
 
  int x = *(int *)x_void;
  int y = *(int *)y_void;

  return y - x;
}



