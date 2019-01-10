//
//  traitementsurliste.c
//  Miniprojetinge1
//
//  Created by Partouche on 04/02/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "traitementsurliste.h"


Listearticle *initialisationchaine(){
    
    Listearticle *liste = malloc(sizeof(*liste));
    Article *article = malloc(sizeof(*article));
    
    if (liste == NULL || article == NULL)
    {
        exit(0);
    }
    
    article->quantite = 0;
    article->txdegucide = 0;
    article->nxt = NULL;
    liste->premierelement = article;
    
    return liste;
}


void inclusiondunarticledanslaliste(Listearticle *liste, int j)
{
    /* Création du nouvel élément */
    Article *nouveau = malloc(sizeof(*nouveau));
    

    int quantite;
    float txdegucide;
    char nomduproduit[30];
    
    printf("Veuillez rentrer le nom du produit\n");
    scanf("%s", nomduproduit);


    //fgets(nomduproduit, 19, stdin);
    printf("Veuillez entrer la quantite\n");
    scanf("%d", &quantite);
    printf("Veuillez rentrer le taux de glucide (decimal compris entre 0 et 1)\n");
    scanf("%f", &txdegucide);
    
    if (liste == NULL || nouveau == NULL)
    {
        exit(0);
    }
    
    strcpy(nouveau->nomduproduit, nomduproduit);
    nouveau->txdegucide = txdegucide;
    nouveau->quantite = quantite;
    
    // Insertion en debut de liste de la fiche produit
    nouveau->nxt = liste->premierelement;
    liste->premierelement = nouveau;
}

void RechercherlaListe(Listearticle *liste, int j)
{
    float trouvaille2 = 0.0;
    int trouvaille1 = 0;
    char trouvaille[20];


    int i=1;
    int poub=5;
    if (liste == NULL)
    {
        exit(0);
    }
    
    Article *actuel = liste->premierelement;

    while (poub!=1 && poub!=2 && poub!=3){
        printf("Pour faire votre recherche quel champ vous interesses ? 1. Nom 2. Quantite 3. Taux de glucide\n");
        scanf("%d", &poub);
    };
    printf("Super ! Que voulez vous recherchez dans le champ selectionné ?\n");

    switch (poub){
        case 1:
            scanf("%s", trouvaille);
        break;
        case 2:
            scanf("%d", &trouvaille1);
        break;
        case 3:
            scanf("%f", &trouvaille2);
        break;
    }
    
    while (i <= j)
    {
        if (actuel->txdegucide == trouvaille2 || strcmp(actuel->nomduproduit, trouvaille) == 0 || actuel->quantite == trouvaille1){
            printf("Le resultat de votre recherche est le produit suivant : %s \n", actuel->nomduproduit);
            printf("Voici ça quantite : %d et son taux de glucide : %f\n", actuel->quantite, actuel->txdegucide);
            i=j+1;
        }
        
        else {
            actuel = actuel->nxt;
            i++;
        }
    } 
}

void suppressiondansliste(Listearticle *liste)
{
    int j=1;
    int i=0; // Numero de l'article 
    printf("Saissisez le numero du produit que vous voulez supprimer\n");
    scanf("%d", &i);

    if (liste == NULL)
    {
        exit(0);
    }
    
    Article *actuel = liste->premierelement; // n-1
    Article *ECM = liste->premierelement; // n
    Article *apres = liste->premierelement; // n+1
    
    while (j <= i-2)
    {
        actuel = actuel->nxt;
        j++;
    }
    j=1;
    while (j <= i-1)
    {
        ECM = ECM->nxt;
        j++;
    }
    j=1;
        while (j <= i)
    {
        apres = apres->nxt;
        j++;
    }
    actuel->nxt = apres;
    free(ECM);


}

void afficherlaListe(Listearticle *liste, int i)
{
    int j=1;
    if (liste == NULL)
    {
        exit(0);
    }
    
    Article *actuel = liste->premierelement;
    
    while (j <= i)
    {
        //printf("%d -> ", actuel->code);
        printf("Le %s est le produit %d \n", actuel->nomduproduit, j);
        printf("la quantite est %d\n", actuel->quantite);
        printf("Le taux de glucide est de %f \n", actuel->txdegucide);
        
        actuel = actuel->nxt;
        j++;
    }
}

