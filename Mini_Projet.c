#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int main(){

    int nLivre=0, i, trouver;
    int choix;
    int quantite[nLivre];
    char titre[nLivre], auteur [nLivre];
    float prix[nLivre];
    char titreRechercher;

    do
    {
        printf("\n**** MENU ****\n");
        printf("1- Ajouter un livre au stock \n");
        printf("2- Afficher tous les livres disponibles \n");
        printf("3- Rechercher un livre par son titre \n");
        printf("4- Mettre a jour la quantite d'un livre \n");
        printf("5- Supprimer un livre du stock \n");
        printf("6- Affichzr le nombre total de livres en stock \n");
        printf("7- Quitter \n");
        printf("Choisir un option : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1:
            printf("Entrer le nombre des livres : ");
            scanf("%d", &nLivre);
            for ( i = 0; i < nLivre && nLivre<MAX; i++)
            {
                printf("Enter le titre du livre :");
                scanf("%s ",&titre[i]);
                printf("Entrer l'auteur du livre : ");
                scanf("%s", &auteur[i]);
                printf("Entrer le prix du livre : ");
                scanf("%f", &prix[i]);
                printf("Entrer la quatite en stock : ");
                scanf("%d", &quantite[i]);
                nLivre++;
            }
            printf("Les livres bien ajoutee ");
            break;
        
        case 2:
            if (nLivre==0)
            {
                printf("Aucun livre en stock!\n");
            }
            else{
                for(i=0; i<nLivre; i++)
                {
                    printf("\nTitre : %s", titre[i]);
                    printf("\nAuteur : %s", auteur[i]);
                    printf("\nPrix : %.2f", prix[i]);
                    printf("\nQuantite : %d", quantite[i]);
                    printf("\n");
                }
            }
            break;

        case 3:
            printf("Entrer le titre du livre a rechercher : ");
            scanf("%s", &titreRechercher);
            trouver = 0;
            for(i=0; i<nLivre; i++){
                if(strcmp(titreRechercher, titre[i]) == 0) {
                        printf("\nLivre trouve : \n");
                        printf("Titre : %s\n", titre[i]);
                        printf("Auteur : %s\n", auteur[i]);
                        printf("Prix : %.2f\n", prix[i]);
                        printf("Quantite : %d\n", quantite[i]);
                        trouver = 1;
                        break;
                }
                else
                    printf("Livre non trouve!\n");
            }
            break;
        case 4:
            printf("Entrer le titre du livre a mise a jour :\n");
            scanf("%s", &titreRechercher);
            trouver=0;
            for(i=0; i<nLivre; i++){
                if (strcmp(titreRechercher, titre[i]) == 0) {
                        printf("Nouvelle quantite : ");
                        scanf("%d", &quantite[i]);
                        trouver = 1;
                        printf("Quantite mise a jour\n");
                        break;
                }
                else
                    printf("Livre non trouve!\n");
                
            }
            break;
        
        case 5:
            
            
            
            




        default:
            break;
        }

    } while (choix != 7);
    
    

}