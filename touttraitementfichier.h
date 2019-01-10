//
//  touttraitementfichier.h
//  Miniprojetinge1
//
//  Created by Partouche on 04/02/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef touttraitementfichier_h
#define touttraitementfichier_h

#include "traitementsurliste.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fonctionfichierDEBUT (struct Listearticle *liste, int i);
void fonctionfichierFIN(struct Listearticle *liste, int i);
struct Listearticle fonctiondetrieparNombre(struct Listearticle *liste, int i);
#endif /* touttraitementfichier_h */
