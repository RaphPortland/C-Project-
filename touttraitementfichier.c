//
//  touttraitementfichier.c
//  Miniprojetinge1
//
//  Created by Partouche on 04/02/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "touttraitementfichier.h"

int fonctionfichierDEBUT(Listearticle *liste, int i){
    FILE *fic=NULL;
    if (fic != NULL){printf("Il y a eu un pb a l'ouverture du fichier\n");}
    
    fic=fopen("/Users/partoucheraph/Desktop/Start2c/Miniprojetinge1/Miniprojetinge1/miniproject.txt", "r");

    if (fic!=NULL){
        while (!feof(fic)){
            
            Article *nouveau = malloc(sizeof(*nouveau));
            int quantite;
            char nomduproduit[20];
            float txdegucide;
            
            //scanf("%c", poub);
            fscanf(fic, "Nom du produit : %s ", nomduproduit);
            fscanf(fic, "Quantite du produit : %d ", &quantite);
            fscanf(fic, "Taux de glucide dans le produit : %f \n", &txdegucide);
            
            if (liste == NULL || nouveau == NULL)
            {
                //exit(0);
            }
            // Placement des valeurs dans la structure "nouveau"
            strcpy(nouveau->nomduproduit, nomduproduit);
            nouveau->txdegucide = txdegucide;
            nouveau->quantite = quantite;
            
            // Insertion en debut de liste de la fiche produit
            nouveau->nxt = liste->premierelement;
            liste->premierelement = nouveau;
            
            //incrementation du nombre d'article
            i++;
        }
        // Fermeture du fichier
        fclose(fic);
    }
    else {printf("ça passe par la du coup exit");
    }
    return i;
    
}

void fonctionfichierFIN(Listearticle *liste, int i){
    FILE *fic=NULL;
    if (fic != NULL){printf("Il y a eu un pb a l'ouverture du fichier\n");}
    
    fic=fopen("/Users/partoucheraph/Desktop/Start2c/Miniprojetinge1/Miniprojetinge1/miniproject.txt", "w");
    
    if (fic!=NULL){
        
            
            int j=1;
            if (liste == NULL)
            {
                exit(0);
            }
            
            Article *actuel = liste->premierelement;
            
            while (j <= i)
            {
                //printf("%d -> ", actuel->code);
                fprintf(fic, "Nom du produit : %s ", actuel->nomduproduit);
                fprintf(fic, "Quantite du produit : %d ", actuel->quantite);
                fprintf(fic, "Taux de glucide dans le produit : %f \n", actuel->txdegucide);
                
                actuel = actuel->nxt;
                j++;
            }
        // Fermeture du fichier 
        fclose(fic);
        }

    
    
    else {exit(0);}


}

struct Listearticle fonctiondetrieparNombre(Listearticle *liste, int i){

    int triepar=0;
    int j=1;
    int max=0;
    int dowhile=1;
    int compteur=0;
    int min=0;
    Article *bis=malloc(sizeof(*bis));
    Article *bisbis=malloc(sizeof(*bisbis));
    Listearticle *liste2 = malloc(sizeof(*liste2));
// Initialisatiion de la chaine 
    bisbis->quantite = 0;
    bisbis->txdegucide = 0;
    bisbis->nxt = NULL;
    liste2->premierelement = bisbis;
//
    bis=liste->premierelement;
    
    do {
    printf("Voulez vous trier par : 1.Taux de glucide ou par 2. Quantite \n");
    scanf("%d", &triepar);
    if (triepar!=1 && triepar !=2){
        printf("Veuillez recommencer en inserant 1 ou 2 ! \n");
    }

    }while (triepar!=1 && triepar !=2);
    
    switch(triepar){
        case 1: 
            // Obtention du maximum de la liste en taux de glucide
            while (j <= i){
                if( max < bis->txdegucide){
                    max=bis->txdegucide;
                }
                j++;
                bis=bis->nxt;
            }
            j=1;
            bis = liste->premierelement;
            printf("Le max de taux de glucide est de %d", max);
            do{

                            // On cherche le min
                            while (j <= i){
                                if( min < bis->txdegucide){
                                    min=bis->txdegucide;
                                }
                                j++;
                                bis=bis->nxt;
                            }
                            j=1;
                            while(j<=i){
                                //Si on a trouver a quoi correspond le min alors :
                                if (bis->txdegucide==min){
                                    strcpy(bisbis->nomduproduit, bis->nomduproduit);
                                    bisbis->txdegucide = bis->txdegucide;
                                    bisbis->quantite = bis->quantite;
                                    
                                    // Insertion en debut de liste de la fiche produit
                                    bisbis->nxt = liste2->premierelement;
                                    liste2->premierelement = bisbis;
                                    // Qaund trouver supression dans la liste 
                                    dowhile++;
                                    int x=1;
                                    int w=0;
                                    w=i;

                                        if (liste == NULL)
                                        {
                                            exit(0);
                                        }
                                    
                                    Article *actuel = liste->premierelement; // n-1
                                    Article *ECM = liste->premierelement; // n
                                    Article *apres = liste->premierelement; // n+1
                                    
                                    while (x <= w-2)
                                    {
                                        actuel = actuel->nxt;
                                        x++;
                                    }
                                    x=1;
                                    while (x <= w-1)
                                    {
                                        ECM = ECM->nxt;
                                        x++;
                                    }
                                    x=1;
                                    while (x <= w)
                                        {
                                        apres = apres->nxt;
                                        x++;
                                    }
                                    actuel->nxt = apres;
                                    free(ECM);
                                    j++;
                                    w--;
                                }      
                                bis=bis->nxt;                              
                            }
                //i=w;
                bis = liste->premierelement;
            } while (dowhile<i);
        break;

            printf("Valeur de dowhile : %d Valeur de i : %d Valeur de compteur : %d Valeur de max : %d\n", dowhile, i,compteur,max);
        }



    

    return *liste2;
}
