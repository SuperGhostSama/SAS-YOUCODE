#include <stdio.h>

int main () {
	int i=0;
	int NumDeProduit;
	
	printf("\n--- Processus de l ajout de produit ---\n\n");

    printf("> Combient de produits voulez-vous ajouter ? \n\n-> ");
    scanf("%d", &NumDeProduit);
    
	for (i = 0; i < NumDeProduit; i++)
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
	return 0;
}
