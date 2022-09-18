#include <stdio.h> 
#include<stdlib.h>

struct product {
    char code[20];
    char name[20];
    int quantity;
    float price;
};

struct product products[100];

int chosenItem, numberOfProducts = 0;

void showMenu();
void addAProduct();
void showPage(int chosenItem);
void chooseAnItem();

int main()
{
    showMenu();
    chooseAnItem();
}

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

void addAProduct(){
    printf("Ajouter un produit :\n\n");
    
    printf("Entrer le code du produit :\n=> ");
    scanf("%s", products[numberOfProducts].code);
    
    printf("Entrer le nom du produit :\n=> ");
    scanf("%s", products[numberOfProducts].name);
    
    printf("Entrer la quantite du produit:\n=> ");
    scanf("%d", &products[numberOfProducts].quantity);
    
    printf("Entrer le prix du produit :\n=> ");
    scanf("%f", &products[numberOfProducts].price);
    
    numberOfProducts++;
    
    system("clear");
    printf("Produit ajouter avec succees !! \n\n");
    
    showMenu();
    chooseAnItem();
    
}

void showPage(int chosenItem) {
    
    switch(chosenItem){
        case 1 :
            system("clear");
            addAProduct();
            break;
        case 2 :
            system("clear");
            printf("Ajouter plusieurs produits");
            break;
        case 3 :
            system("clear");
            printf("Afficher tout les produits");
            break;
        case 4 :
            system("clear");
            printf("Acheter un produit");
            break;
        case 5 :
            system("clear");
            printf("Chercher un produit");
            break;
        case 6 :
            system("clear");
            printf("Etat du stock");
            break;
        case 7 :
            system("clear");
            printf("Ajouter au stock");
            break;
        case 8 :
            system("clear");
            printf("Supprimer un produit");
            break;
        case 9 :
            system("clear");
            printf("Afficher les statistiques");
            break;
        default :
            system("clear");
            printf("Please choose from the menu! \n");
            showMenu();
            break;
    }
}

void chooseAnItem(){
    do {
        printf("\n=> ");
        scanf("%d", &chosenItem);
        
        showPage(chosenItem);
        
    } while(chosenItem < 1 || chosenItem > 9);
}
