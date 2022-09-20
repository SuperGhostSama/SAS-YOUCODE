#include <stdio.h> 
#include<stdlib.h>
#include <string.h>
#include <time.h>
struct product {
	float price;
    char code[20];
    char name[20];
    int quantity;

};

struct product products[100];

int chosenItem, numberOfProducts = 0;

int compare();
void showMenu();
void addAProduct();
void showPage(int chosenItem);
void chooseAnItem();
void addMultipleProducts();
void ShowProducts();
void FindProductByCode();
void FindProductByQuantity();
void BuyAProduct();
void AddToStock();
void StateOfStock();
void Time(); //affichage de temps actuel avec la date
void Statistique();//not completed


int main()
{
    showMenu();
    chooseAnItem();
}
//1- AFFICHAGE DE MENU
void showMenu(){
	system("Color 9");//code couleur 9 = Light Blue
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
//2- FONCTION DE CHOIX SUR LE MENU QUI AJOUTE UN PRINTF ET SCANF POUR SELECTIONNER LE NUMERO
void chooseAnItem(){
    do {
        printf("\n=> ");
        scanf("%d", &chosenItem);
        
        showPage(chosenItem);
        
    } while(chosenItem < 1 || chosenItem > 9);

}

//3- FONCTION D AJOUT D UN SEUL PRODUIT
void addAProduct(){
	
    printf("\n\t---  Ajouter un produit  ---\n");
    
    printf("\n-> Entrer le code du produit :\n=> ");
    scanf("%s", products[numberOfProducts].code);
    
    printf("\n-> Entrer le nom du produit :\n=> ");
    scanf("%s", products[numberOfProducts].name);
    
    printf("\n-> Entrer la quantite du produit:\n=> ");
    scanf("%d", &products[numberOfProducts].quantity);
    
    printf("\n-> Entrer le prix du produit (HT):\n=> ");
    scanf("%f", &products[numberOfProducts].price);
    
    numberOfProducts++;
    
    
    printf("\n->Produit ajouter avec succees !! \n\n");
    system("Pause");
    system("cls");
    showMenu();
    chooseAnItem();
    
}

//4- FONCTION DE SWITCH POUR ACCEDER AU CHOIX SUR LE MENU
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
            BuyAProduct();
            break;
        case 5 :
            system("cls");
            int num;
            printf("\n> [1] Chercher avec Code");
            printf("\n> [2] Chercher avec Quantite");
            scanf("%d",&num);
            switch (num){
            	case 1:
            		system("cls");
            		FindProductByCode();
            		break;
            	case 2:
            		system("cls");
					FindProductByQuantity();
					break;	
			}
            break;
        case 6 :
            system("cls");
            StateOfStock();
            break;
        case 7 :
            system("cls");
            AddToStock();
            break;
        case 8 :
            system("cls");
            system("Color 4");//Code couleur 4 = Red
            printf("\n\t---  SUPPRIMER PRODUIT  ---\n");
            printf("\n\t---  NOT AVAILABLE YET  ---\n");
            system("Pause");
			system("cls");
			showMenu();
			chooseAnItem();
            break;
        case 9 :
            system("cls");
            system("Color 4");//Code couleur 4 = Red / je l ai afficher en rouge car la fonction de statistique n est pas complété est juste provisoir
            printf("\n\t---  NOT AVAILABLE YET  ---\n");
            Statistique();
            system("Pause");
			system("cls");
			showMenu();
			chooseAnItem();
            break;
        default :
            system("cls");
            system("Color 4");//Code couleur 4 = Red
            printf("\n\t---  MERCI DE CHOISIR DU MENU  ---\n");
            system("Pause");
			system("cls");
			showMenu();
			chooseAnItem();
            break;
    }
}
//5- FONCTION D AJOUT DE PLUSIEUR PRODUIT
void addMultipleProducts(){
	int i;
	int n;
	printf("\n>Entrer combien de produit vous souhaitez ajouter :");
	scanf("%d",&n);
	for(i=0;i<n;i++){

	printf("\n\t---  Ajouter un produit  ---\n");
    
    printf("\n-> Entrer le code du produit :\n=> ");
    scanf("%s", products[numberOfProducts].code);
    
    printf("\n-> Entrer le nom du produit :\n=> ");
    scanf("%s", products[numberOfProducts].name);
    
    printf("\n-> Entrer la quantite du produit:\n=> ");
    scanf("%d", &products[numberOfProducts].quantity);
    
    printf("\n-> Entrer le prix du produit (HT):\n=> ");
    scanf("%f", &products[numberOfProducts].price);
    
    numberOfProducts++;
    
    system("cls");
    printf("\n-> Produit ajouter avec succees !! \n\n");
		
	}
	sleep(1);
	system("cls");
	showMenu();
	chooseAnItem();
}

//6- AFFICHER TOUT LES PRODUITS
void ShowProducts(){
	//if : pour si il n y a pas de produit ajouter sur le systeme sa retourne au menu automatiquement apres 4 secondes
	if(numberOfProducts==0){
		system("Color 4");//Code couleur 4 = Red
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

//7- Fonction de comparaison POUR LE TRIAGE DECROISSANT
int compare(const void *x_void, const void *y_void)
{
 
  int x = *(int *)x_void;
  int y = *(int *)y_void;

  return y - x;
}

//8- rechercher un produit avec son code
void FindProductByCode(){
	char ProductCode[20];
	int i;
	
	printf("\n->Entrer le Code du produit : ");
	scanf("%s",ProductCode);
	
	for(i=0;i<numberOfProducts;i++){
		if (strcmp(products[i].code,ProductCode) == 0 )
		printf("\n->Code du produit : %s\t ->Nom du produit :%s\t ->Quantite du produit : %d\t ->Prix du produit en HT :%.2f\t ->Prix du produit en TTC :%.2f\n", products[i].code,products[i].name,products[i].quantity,products[i].price,products[i].price +((products[i].price)*0.15));
	}
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
}
//9- recher un produit avec la quantité
void FindProductByQuantity(){
	int ProductQuantity;
	int i;
	
	printf("\n->Entrer la Quantite du produit : ");
	scanf("%d",&ProductQuantity);
	
	for(i=0;i<numberOfProducts;i++){
		if (products[i].quantity==ProductQuantity )
		printf("\n->Quantite du produit : %d \t ->Code du produit : %s \n->Nom du produit :%s\t ->Prix du produit en HT :%.2f\t->Prix du produit en TTC :%.2f\n", products[i].quantity,products[i].code,products[i].name,products[i].price,products[i].price +((products[i].price)*0.15));
	}
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
}
//10- fontion acheter un produit / deduire du stock
void BuyAProduct(){
	//find product by code
	char ProductCode[20];
	int i;
	int number;
	int x;
	printf("\n->Entrer le Code du produit : ");
	scanf("%s",ProductCode);

	for(i=0;i<numberOfProducts;i++){
		if (strcmp(products[i].code,ProductCode) == 0 ){
		x=i;// ajouter pour stocker l indice du produit
		printf("\n->Code du produit : %s\t ->Nom du produit :%s\t ->Quantite du produit : %d\t ->Prix du produit en HT :%.2f\t ->Prix du produit en TTC :%.2f\n", products[i].code,products[i].name,products[i].quantity,products[i].price,products[i].price +((products[i].price)*0.15));
		}
	}
	printf("\n->Entrer la valeur a deduir du stock :\n");
	scanf("%d",&number);
	printf("\n->La valeur dans le stock est maintenant: %d\n",products[x].quantity-=number);
	Time();
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
}
//11- fonction ajouter au stock
void AddToStock(){
	//find product by code
	char ProductCode[20];
	int i;
	int number;
	int x;
	printf("\n->Entrer le Code du produit : ");
	scanf("%s",ProductCode);

	for(i=0;i<numberOfProducts;i++){
		if (strcmp(products[i].code,ProductCode) == 0 ){
		x=i;// ajouter pour stocker l indice du produit
		printf("\n->Code du produit : %s\t ->Nom du produit :%s\t ->Quantite du produit : %d\t ->Prix du produit en HT :%.2f\t ->Prix du produit en TTC :%.2f\n", products[i].code,products[i].name,products[i].quantity,products[i].price,products[i].price +((products[i].price)*0.15));
		}
	}
	printf("\n->Entrer la valeur a ajouter au stock :");
	scanf("%d",&number);
	printf("\n-> La Valeur dans le stock est maintenant: %d\n",products[x].quantity+=number);
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
}

//12- fonction pour afficher l etat du stock les produits<3
void StateOfStock(){
	int i;
	
	for(i=0;i<numberOfProducts;i++){
		if (products[i].quantity<3){
			printf("\n->Code du produit : %s\t ->Nom du produit :%s\t ->Quantite du produit : %d\t ->Prix du produit en HT :%.2f\t ->Prix du produit en TTC :%.2f\n", products[i].code,products[i].name,products[i].quantity,products[i].price,products[i].price +((products[i].price)*0.15));
		}
	}
	system("Pause");
	system("cls");
	showMenu();
	chooseAnItem();
}

//13- FONCTION AFFICHAGE DE TEMPS
void Time(){
  int h, min, s, day, mois, an;
  time_t now;
    
  // Renvoie l'heure actuelle
  time(&now);

  // Convertir au format heure locale
  printf("\n-> Aujourd'hui est : %s", ctime(&now));

  struct tm *local = localtime(&now);
  h = local->tm_hour;        
  min = local->tm_min;       
  s = local->tm_sec;       
  day = local->tm_mday;          
  mois = local->tm_mon + 1; // on ajoute +1 car sa commence de 0 
  an = local->tm_year + 1900;  
  
  printf("\n-> L'heure : %02d:%02d:%02d\n", h, min, s);

  // Afficher la date courante
  printf("\n-> La date : %02d/%02d/%d\n", day, mois, an);
	
}

//14- FONCTION STATISTIQUE
void Statistique(){
	float q;//quantité
	float p;//prix
	
	printf("\n-> Entrer la quantite du produit vendu :");
	scanf("%f",&q);
	printf("\n-> Entrer le prix en HT du produit vendu :");
	scanf("%f",&p);
	printf("\n-> Le total des prix des produits vendus est :%.2f",(q*p));
	printf("\n-> La moyenne des prix des produits vendus :%.2f",(q*p)/q);

}
