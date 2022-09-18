#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Section Structure
struct produit 
{
	char Code[50];
	char Nom[50];
	int Quantite;
	float Prix;
}
struct produit produit[4];

//AJOUTER NV PRODUIT
void addNewProduct() 
{
	int i=0,numOfProduct;
	printf("\n--- Processus de l Ajout de nouveau Produits ---\n\n");
	printf("> Combien de produits voulez-vous ajouter ? \n\n-> ");
	scanf("%d", &numOfProduct);
	
	  for (i = 0; i < numOfProduct; i++)
    {

        printf("--- Creation de produit %d\n\n", i + 1);

        printf("\n-> Code du Produit : ");
        scanf("%d", &produit[i].Code);

        printf("\n-> Nom du Produit : ");
        scanf("%s", &produit[i].Nom);

        printf("\n-> Quantite du Produit : ");
        scanf("%s", &produit[i].Quantite);

        printf("\n-> Prix du Produit : ");
        scanf("%s", &produit[i].Prix);

        printf("\n*** Votre produit a ete cree avec succes ***\n");
    }

    displayMenu();
}

