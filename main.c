//
//  main.c
//  Miniprojetinge1
//
//  Created by Partouche on 03/02/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traitementsurliste.h"
#include "touttraitementfichier.h"



int main()
{
    int menu=1;
    int i=0;
    int compteur;
    Listearticle liste = *initialisationchaine();
    i=fonctionfichierDEBUT(&liste, i);
    
    while (menu==1 || menu== 2 || menu==3 || menu==4 || menu==5){
        printf("Voulez vous : \n1. Ajouter un nouveau produit : 1\n2. Afficher la liste d'article : 2\n3. Rechercher un produit : 3\n4. Supprimer un élément de la liste : 4\n5. Trier la liste : 5\n6. Sortir du programme : 6\n");
        scanf("%d", &menu);
        compteur=i+1;
        
        
        switch (menu){
            case 1 :
                inclusiondunarticledanslaliste(&liste, i);
                i++;
                break;
            case 2 :
                //for (int j=1; j<compteur; j++){
                afficherlaListe(&liste, i);
                //}
                break;
            case 3 :
                RechercherlaListe(&liste, i);
                break;
            case 4 :
                suppressiondansliste(&liste);
                i--;
                break;
            case 5 :
                liste = fonctiondetrieparNombre(&liste, i);
                break;

        }
    };
    fonctionfichierFIN(&liste, i);
    
}
