//
//  traitementsurliste.h
//  Miniprojetinge1
//
//  Created by Partouche on 04/02/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef traitementsurliste_h
#define traitementsurliste_h


#include "touttraitementfichier.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Article Article;
struct Article{
    
    char nomduproduit[20]; //non du produit POMME
    int quantite; //quantité : exemple 100g
    float txdegucide; // Taux de glucide : 0.14 (allant de 0 a 1)
    Article* nxt;
    
};

typedef struct Listearticle Listearticle;
struct Listearticle
{
    Article *premierelement;
};

Listearticle *initialisationchaine();
void inclusiondunarticledanslaliste(Listearticle *liste, int j);
void RechercherlaListe(Listearticle *liste, int j);
void suppressiondansliste(Listearticle *liste);
void afficherlaListe(Listearticle *liste, int i);

#endif /* traitementsurliste_h */
