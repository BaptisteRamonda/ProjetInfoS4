#include <stdio.h>
#include <stdlib.h>
#include "reseau.h"


enum eVille {PARIS = 0, TOURS, BORDEAUX, BIARRITZ, ORLEANS, LIMOGES, BRIVE, MONTAUBAN, TOULOUSE, LYON, MARSEILLE, AGEN, NARBONNE, MONTPELLIER, NICE};

struct s_ville {
    int nomVille;
};

struct s_trajet {
    Ville depart;
    Ville arrivee;
    int temps; // en minutes
};

typedef struct s_ligne {
    Ville * tEtapes;
    int nbEtapes;
    Trajet * tTrajetsPartiels;
} * Ligne;

struct s_reseau {
    Ligne * tLignes; // lignes de trains, pondérées
    Ville * tVille;  //toutes les villes accessibles grace au réseau
    Trajet * tTrajets; //tous les trajets possibles, de proche en proche
    int nbrVille;
};
/** 
 * prototype non nécéssaires a mettre dans le point h
 */
Trajet initialiseTrajet(Ville, Ville);

Ligne ParisBiarritz() {
    int nbEtapes = 4;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); // on alloue la mémoire pour creer la structure Ligne
    l->nbEtapes = nbEtapes; // on initialise le nombre de villes que la ligne comprend
    l->tEtapes = (Ville *)malloc(sizeof(struct s_ville)); // on alloue les pointeurs des tableaux (la taille n'est pas définie encore)
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet));
    /**
     * premiere étape : alloue l'espace pour le tableau d'etapes tEtapes et le remplir
     * 
     */
    for (int i = 0; i < nbEtapes; i++) {  // on alloue la memoire pour chaque element de chaque tableau
        l->tEtapes[i] = malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = TOURS;
    l->tEtapes[2]->nomVille = BORDEAUX;
    l->tEtapes[3]->nomVille = BIARRITZ;
    /** 
     * deuxieme étape : on alloue l'espace pour le tableau de trajet cette fois ci avec la fonction initialise trajet et on complete avec le temps de chaque
     * trajet partiel (autrement dit on pondere les arcs)
     */ 
    for (int i = 0; i < nbEtapes - 1; i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 60;
    l->tTrajetsPartiels[2]->temps = 90;
    return l;
}

Ligne ParisToulouse() {
    int nbEtapes = 6;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = nbEtapes;
    l->tEtapes = (Ville *)malloc(sizeof(struct s_ville)); 
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet));
    for (int i = 0; i < nbEtapes; i++) { 
        l->tEtapes[i] = malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = ORLEANS;
    l->tEtapes[2]->nomVille = LIMOGES;
    l->tEtapes[3]->nomVille = BRIVE;
    l->tEtapes[4]->nomVille = MONTAUBAN;
    l->tEtapes[5]->nomVille = TOULOUSE;
    for (int i = 0; i < nbEtapes - 1; i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 150;
    l->tTrajetsPartiels[2]->temps = 60;
    l->tTrajetsPartiels[3]->temps = 60;
    l->tTrajetsPartiels[2]->temps = 30;
    return l;
}

Ligne ParisMarseille() {
    int nbEtapes = 3;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = nbEtapes;
    l->tEtapes = (Ville *)malloc(sizeof(struct s_ville)); 
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet));
    for (int i = 0; i < nbEtapes; i++) { 
        l->tEtapes[i] = malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = LYON;
    l->tEtapes[2]->nomVille = MARSEILLE;
        for (int i = 0; i < nbEtapes - 1; i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 90;
    l->tTrajetsPartiels[1]->temps = 90;
    return l;
}
    

Ligne BordeauxNice() {
    int nbEtapes = 8;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = nbEtapes;
    l->tEtapes = (Ville *)malloc(sizeof(struct s_ville)); 
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet));
    for (int i = 0; i < nbEtapes; i++) { 
        l->tEtapes[i] = malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = BORDEAUX;
    l->tEtapes[1]->nomVille = AGEN;
    l->tEtapes[2]->nomVille = MONTAUBAN;
    l->tEtapes[3]->nomVille = TOULOUSE;
    l->tEtapes[4]->nomVille = NARBONNE;
    l->tEtapes[5]->nomVille = MONTPELLIER;
    l->tEtapes[6]->nomVille = MARSEILLE;
    l->tEtapes[7]->nomVille = NICE;
    for (int i = 0; i < nbEtapes - 1; i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 40;
    l->tTrajetsPartiels[2]->temps = 20;
    l->tTrajetsPartiels[3]->temps = 120;
    l->tTrajetsPartiels[4]->temps = 60;
    l->tTrajetsPartiels[5]->temps = 60;
    l->tTrajetsPartiels[6]->temps = 150;
    return l;
}

Trajet initialiseTrajet(Ville depart, Ville arrivee) {
    Trajet t = (Trajet)malloc(sizeof(struct s_trajet));
    t->depart = (Ville)malloc(sizeof(struct s_ville));
    t->arrivee = (Ville)malloc(sizeof(struct s_ville));
    t->depart->nomVille = depart->nomVille;
    t->arrivee->nomVille = arrivee->nomVille;
    return t;
}

Reseau creerReseau() {
    int nbLigne = 4;
    Reseau r = (Reseau)malloc(sizeof(struct s_reseau));
    r->tLignes = (Ligne *)malloc(sizeof(struct s_ligne));
    for (int i = 0; i < nbLigne; i ++) {
        r->tLignes[i] = malloc(sizeof(struct s_ligne));
    }
    r->tLignes[0] = ParisBiarritz();
    r->tLignes[1] = ParisMarseille();
    r->tLignes[2] = ParisToulouse();
    r->tLignes[3] = BordeauxNice();
    return r;
}
