#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    int nLivre = 0;
    int choix, trouver;
    int nAjouter;
    int quantite[MAX];
    char titre[MAX][100], auteur[MAX][100];
    float prix[MAX];
    char titreRechercher[100];
    
    printf("\n                ----- Systeme de Gestion de Stock de Librairie -----\n");
    do {
        printf("\n   **** MENU ****\n");
        printf("1. Ajouter des livres \n");
        printf("2. Afficher tous les livres \n");
        printf("3. Rechercher un livre par son titre \n");
        printf("4. Mettre a jour la quantite d'un livre \n");
        printf("5. Supprimer un livre \n");
        printf("6. Afficher le nombre total de livres \n");
        printf("7. Quitter \n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                do {
                    printf("Combien de livres souhaitez-vous ajouter ? ");
                    scanf("%d", &nAjouter);

                    if (nAjouter > (MAX - nLivre)) {
                        printf("Impossible de ajouter plus de %d livres\n", MAX - nLivre);
                    }
                } while (nAjouter > (MAX - nLivre));

                for (int i = 0; i < nAjouter; i++) {
                    printf("\nAjouter du livre %d\n", i + 1);
                    printf("Entrer le titre du livre : ");
                    scanf(" %[^\n]", titre[nLivre]);
                    printf("Entrer l'auteur du livre : ");
                    scanf(" %[^\n]", auteur[nLivre]);
                    printf("Entrer le prix du livre : ");
                    scanf("%f", &prix[nLivre]);
                    printf("Entrer la quantite en stock : ");
                    scanf("%d", &quantite[nLivre]);
                    nLivre++; 
                }
                if(nAjouter >= 2)
                {printf("\n %d livres ajoutes avec succes \n", nAjouter);
                }
                else 
                    printf("\n Livre ajoute avec succes");
               break;
            

            case 2:
                if (nLivre == 0) {
                    printf("Aucun livre disponible dans le stock\n");
                } else {
                    printf("Liste des livres disponibles : \n");
                    for (int i = 0; i < nLivre; i++) {
                        printf("\nTitre : %s", titre[i]);
                        printf("\nAuteur : %s", auteur[i]);
                        printf("\nPrix : %.2f", prix[i]);
                        printf("\nQuantite : %d", quantite[i]);
                        printf("\n");
                    }
                }
                break;

            case 3:
                printf("Entrez le titre du livre a rechercher : ");
                scanf(" %[^\n]", titreRechercher);
                trouver = 0;
                for (int i = 0; i < nLivre; i++) {
                    if (strcmp(titre[i], titreRechercher) == 0) {
                        printf("\nLivre trouve : \n");
                        printf("\nTitre : %s", titre[i]);
                        printf("\nAuteur : %s", auteur[i]);
                        printf("\nPrix : %.2f", prix[i]);
                        printf("\nQuantite : %d", quantite[i]);
                        trouver = 1;
                        break;
                    }
                }
                if (trouver == 0) {
                    printf("Livre non trouve\n");
                }
                break;

            case 4:
                printf("Entrez le titre du livre dont vous voulez mettre a jour la quantite : ");
                scanf(" %[^\n]", titreRechercher);
                trouver = 0;
                for (int i = 0; i < nLivre; i++) {
                    if (strcmp(titre[i], titreRechercher) == 0) {
                        printf("Entrez la nouvelle quantite : ");
                        scanf("%d", &quantite[i]);
                        printf("Quantite mise a jour avec succes\n");
                        trouver = 1;
                        break;
                    }
                }
                if (trouver == 0) {
                    printf("Livre non trouve\n");
                }
                break;

            case 5:
                printf("Entrez le titre du livre a supprimer : ");
                scanf(" %[^\n]", titreRechercher);
                trouver = 0;
                for (int i = 0; i < nLivre; i++) {
                    if (strcmp(titre[i], titreRechercher) == 0) {
                        for (int j = i; j < nLivre - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        nLivre--;
                        printf("Livre supprime avec succes\n");
                        trouver = 1;
                        break;
                    }
                }
                if (trouver == 0) {
                    printf("Livre non trouve\n");
                }
                break;

            case 6:
                int total = 0;
                for (int i = 0; i < nLivre; i++) {
                    total = total + quantite[i];
                }
                printf("Nombre total de livres en stock : %d\n", total);
                break;

            case 7:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer\n");
                break;
        }

    } while (choix != 7);

    return 0;
}
