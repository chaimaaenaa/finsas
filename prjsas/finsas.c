#include <stdio.h>
#include <string.h>

struct tache {
    int id;
    char nom[50];
    char description[50];
    char datelimite[20];
    int priorite;
};

void ajoutertach(struct tache taches[], int *nbrtaches) {
    if (*nbrtaches < 50) {
        printf("id: ");
        scanf("%d", &taches[*nbrtaches].id); // Corrected the format specifier
        printf("nom: ");
        scanf("%s", taches[*nbrtaches].nom);
        printf("Description: ");
        scanf("%s", taches[*nbrtaches].description);
        printf("Date limite: ");
        scanf("%s", taches[*nbrtaches].datelimite);
        printf("Priorité: ");
        scanf("%d", &taches[*nbrtaches].priorite);
        (*nbrtaches)++;
        printf("Tâche ajoutée avec succès.\n");
    } else {
        printf("La liste de tâches est pleine.\n");
    }
    printf("****************\n");
}

void Affichertach(struct tache taches[], int nbrtaches) {
    printf("Liste des tâches :\n");
    for (int i = 0; i < nbrtaches; i++) {
        printf("Tâche %d :\n", i + 1);
        printf("id: %d\n", taches[i].id); // Corrected the format specifier
        printf("nom: %s\n", taches[i].nom);
        printf("Description: %s\n", taches[i].description);
        printf("Date limite: %s\n", taches[i].datelimite);
        printf("Priorité: %d\n", taches[i].priorite);
        printf("****************\n");
    }
}

void modifiertach(struct tache taches[], int nbrtaches) {
    int index;
    printf("Indiquez le numéro de la tâche à modifier : ");
    scanf("%d", &index);
    if (index >= 1 && index <= nbrtaches) {
        printf("Nouvelle id: ");
        scanf("%d", &taches[index - 1].id); // Corrected the format specifier
        printf("Nouvelle nom: ");
        scanf("%s", taches[index - 1].nom);
        printf("Nouvelle description: ");
        scanf("%s", taches[index - 1].description);
        printf("Nouvelle date limite: ");
        scanf("%s", taches[index - 1].datelimite);
        printf("Nouvelle priorité: ");
        scanf("%d", &taches[index - 1].priorite);
        printf("Tâche modifiée avec succès.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
    printf("****************\n");
}

void supprimertach(struct tache taches[], int *nbrtaches) {
    int index;
    printf("Indiquez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);
    if (index >= 1 && index <= *nbrtaches) {
        for (int i = index - 1; i < *nbrtaches - 1; i++) {
            taches[i] = taches[i + 1];
        }
        (*nbrtaches)--;
        printf("Tâche supprimée avec succès.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
    printf("****************\n");
}

void sorttachpardate(struct tache taches[], int nbrtaches, int ascendante) {
    for (int i = 0; i < nbrtaches - 1; i++) {
        for (int j = 0; j < nbrtaches - i - 1; j++) {
            if (ascendante) {
                if (strcmp(taches[j].datelimite, taches[j + 1].datelimite) > 0) {
                    struct tache temp = taches[j];
                    taches[j] = taches[j + 1];
                    taches[j + 1] = temp;
                }
            } else {
                if (strcmp(taches[j].datelimite, taches[j + 1].datelimite) < 0) {
                    struct tache temp = taches[j];
                    taches[j] = taches[j + 1];
                    taches[j + 1] = temp;
                }
            }
        }
    }
    printf("Tâches triées avec succès.\n");
    printf("****************\n");
}

void filtrertach(struct tache taches[], int nbrtaches, int typeDeFilter) {
    if (typeDeFilter == 1) {
        int priorite;
        printf("Indiquez la priorité à filtrer : ");
        scanf("%d", &priorite);

        printf("Tâches avec priorité %d :\n", priorite);
        for (int i = 0; i < nbrtaches; i++) {
            if (taches[i].priorite == priorite) {
                printf("Tâche %d :\n", i + 1);
                printf("id: %d\n", taches[i].id); // Corrected the format specifier
                printf("nom: %s\n", taches[i].nom);
                printf("Description: %s\n", taches[i].description);
                printf("Date limite: %s\n", taches[i].datelimite);
                printf("Priorité: %d\n", taches[i].priorite);
                printf("****************\n");
            }
        }
    } else if (typeDeFilter == 2) {
        char dateLimite[11];
        printf("Indiquez la date limite à filtrer (format YYYY-MM-DD): ");
        scanf("%s", dateLimite);

        printf("Tâches avec date limite %s :\n", dateLimite);
        for (int i = 0; i < nbrtaches; i++) {
            if (strcmp(taches[i].datelimite, dateLimite) == 0) {
                printf("Tâche %d :\n", i + 1);
                printf("id: %d\n", taches[i].id); // Corrected the format specifier
                printf("nom: %s\n", taches[i].nom);
                printf("Description: %s\n", taches[i].description);
                printf("Date limite: %s\n", taches[i].datelimite);
                printf("Priorité: %d\n", taches[i].priorite);
                printf("****************\n");
            }
        }
    } else {
        printf("Type de filtre non pris en charge.\n");
    }
    printf("**\n");
}

int main() {
    struct tache taches[50];
    int nbrtaches = 0;
    int Choix;

    do {
        printf("\n1. Ajouter une tâche\n");
        printf("2. Afficher la liste de tâches\n");
        printf("3. Modifier les tâches\n");
        printf("4. Supprimer une tâche\n");
        printf("5. Trier les tâches par date\n");
        printf("6. Filtrer les tâches\n");
        printf("7. Quitter\n");
        printf(" entrer votre Choix  : ");
        scanf("%d", &Choix);

        switch (Choix) {
            case 1:
                ajoutertach(taches, &nbrtaches);
                break;
            case 2:
                Affichertach(taches, nbrtaches);
                break;
            case 3:
                modifiertach(taches, nbrtaches);
                break;
            case 4:
                supprimertach(taches, &nbrtaches);
                break;
            case 5:
                sorttachpardate(taches, nbrtaches, 1);
                break;
            case 6:
                int typeDeFilter;
                printf("1. Filtrer par priorité\n");
                printf("2. Filtrer par date\n");
                printf("Type de filtre : ");
                scanf("%d", &typeDeFilter);
                filtrertach(taches, nbrtaches, typeDeFilter);
                break;
            case 7:
                printf("sala !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (Choix != 7);

    return 0;
}
