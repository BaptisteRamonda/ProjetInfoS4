#include <stdio.h>
#include <stdlib.h>
#include "reseau.h"

#define NBVILLE 100

enum eVille {PARIS = 0, TOURS, BORDEAUX, BIARRITZ, ORLEANS, LIMOGES, BRIVE, MONTAUBAN, TOULOUSE, LYON, MARSEILLE, AGEN, NARBONNE, MONTPELLIER, NICE};

struct s_ville {
    int nomVille;
};

struct s_trajet {
    Ville depart;
    Ville arrivee;
    int temps; // en minutes
};

struct s_ligne {
    Ville * tEtapes;
    int nbEtapes;
    Trajet * tTrajetsPartiels;
};

struct s_reseau {
    Ligne * tLignes;// lignes de trains, pondérées
    int nbLigne; 
    Ville * tVille;  //toutes les villes accessibles grace au réseau
    int nbVille;
    Trajet * tTrajets; //tous les trajets possibles, de proche en proche
};
/** 
 * prototype non nécéssaires a mettre dans le point h
 */
Trajet initialiseTrajet(Ville, Ville);


void afficheNomDeVille(Ville v) {
    switch (v->nomVille)
    {
    case PARIS:
        printf("PARIS");
        break;
    case TOULOUSE:
        printf("TOULOUSE");
        break;
    case BRIVE:
        printf("BRIVE");
        break;
    case MONTPELLIER:
        printf("MONTPELLIER");
        break;
    case AGEN:
        printf("AGEN");
        break;
    case MARSEILLE:
        printf("MARSEILLE");
        break;
    case TOURS:
        printf("TOURS");
        break; 
    case ORLEANS:
        printf("ORLEANS");
        break;
    case NARBONNE:
        printf("NARBONNE");
        break;
    case BORDEAUX:
        printf("BORDEAUX");
        break;
    case LYON:
        printf("LYON");
        break;
    case LIMOGES:
        printf("LIMOGES");
        break;
    case MONTAUBAN:
        printf("MONTAUBAN");
        break;
    case NICE:
        printf("NICE");
        break;
    case BIARRITZ:
        printf("BIARRITZ");
        break;   
    default:
        printf("%d", v->nomVille);
        break;
    }
}

Trajet initialiseTrajet(Ville depart, Ville arrivee) {
    Trajet t = (Trajet)malloc(sizeof(struct s_trajet));
    t->depart = (Ville)malloc(sizeof(struct s_ville));
    t->arrivee = (Ville)malloc(sizeof(struct s_ville));
    t->depart->nomVille = depart->nomVille;
    t->arrivee->nomVille = arrivee->nomVille;
    return t;
}

Ligne ParisToulouse() {
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 6;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (int i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = ORLEANS;
    l->tEtapes[2]->nomVille = LIMOGES;
    l->tEtapes[3]->nomVille = BRIVE;
    l->tEtapes[4]->nomVille = MONTAUBAN;
    l->tEtapes[5]->nomVille = TOULOUSE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*(l->nbEtapes - 1));    
    for (int i = 0; i < (l->nbEtapes - 1); i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 150;
    l->tTrajetsPartiels[2]->temps = 60;
    l->tTrajetsPartiels[3]->temps = 60;
    l->tTrajetsPartiels[4]->temps = 30;

    return l;
}

Ligne BordeauxNice() {
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 8;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (int i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = BORDEAUX;
    l->tEtapes[1]->nomVille = AGEN;
    l->tEtapes[2]->nomVille = MONTAUBAN;
    l->tEtapes[3]->nomVille = TOULOUSE;
    l->tEtapes[4]->nomVille = NARBONNE;
    l->tEtapes[5]->nomVille = MONTPELLIER;
    l->tEtapes[6]->nomVille = MARSEILLE;
    l->tEtapes[7]->nomVille = NICE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes) - 1));    
    for (int i = 0; i < (l->nbEtapes - 1); i ++){
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

Ligne ParisMarseille() {
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 3;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (int i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0] = malloc(sizeof(struct s_ville));
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = LYON;
    l->tEtapes[2]->nomVille = MARSEILLE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes)-1));    
    for (int i = 0; i < (l->nbEtapes - 1); i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 90;
    l->tTrajetsPartiels[1]->temps = 90;
    return l;
}

Ligne ParisBiarritz() {
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); // on alloue la mémoire pour creer la structure Ligne
    l->nbEtapes = 4; // on initialise le nombre de villes que la ligne comprend
    //l->tEtapes = (Ville *)malloc(sizeof(struct s_ville)); // on alloue les pointeurs des tableaux (la taille n'est pas définie encore)
    /**
     * premiere étape : alloue l'espace pour le tableau d'etapes tEtapes et le remplir
     * 
     */
      // on alloue la memoire pour chaque element de chaque tableau
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (int i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0] = malloc(sizeof(struct s_ville));
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = TOURS;
    l->tEtapes[2]->nomVille = BORDEAUX;
    l->tEtapes[3]->nomVille = BIARRITZ;
    /** 
     * deuxieme étape : on alloue l'espace pour le tableau de trajet cette fois ci avec la fonction initialise trajet et on complete avec le temps de chaque
     * trajet partiel (autrement dit on pondere les arcs)
     */ 
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes)-1));
    for (int i = 0; i < l->nbEtapes - 1; i ++) {
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 60;
    l->tTrajetsPartiels[2]->temps = 90;
    return l;
}

Reseau creerReseau() { // la seule fonction qu'on utilisera vraiment
    Reseau r = (Reseau)malloc(sizeof(struct s_reseau));
    r->nbLigne = 4;
    r->tLignes = calloc(r->nbLigne,sizeof(Ligne));
    for (int i = 0; i < r->nbLigne; i ++) {
        r->tLignes[i] = (Ligne)malloc(sizeof(struct s_ligne));
    }
    r->tLignes[0] = ParisBiarritz();
    r->tLignes[1] = ParisMarseille();
    r->tLignes[2] = ParisToulouse();
    r->tLignes[3] = BordeauxNice();

    r->tVille = calloc(NBVILLE,sizeof(Ville));
    r->nbVille = 0;
    /**
     * on remplit le tableau de villes G du reseau X (X = (G, U))
     */ 
    for (int l = 0; l < r->nbLigne; l ++) {
        for (int i = 0; i < r->tLignes[l]->nbEtapes; i ++) {
            int dejaDedans = 0;                     //on ne veut pas de doublons alors
            for (int n = 0; n < r->nbVille; n ++) { // on verifie que la ville qu'on ajoute au tableau n'est pas déja comprise dans le tableau
                if (r->tLignes[l]->tEtapes[i]->nomVille == r->tVille[n]->nomVille) {
                    dejaDedans = 1;
                }
            }
            if (dejaDedans == 0) {
                r->tVille[r->nbVille] = (Ville)malloc(sizeof(struct s_ville));
                r->tVille[r->nbVille]->nomVille = r->tLignes[l]->tEtapes[i]->nomVille;
                r->nbVille ++;
            }
        }
    }
    return r;
}

int main() {
    Reseau r = creerReseau();
    printf( "OK\n");
    for (int i = 0; i < r->nbVille; i++) {
        afficheNomDeVille(r->tVille[i]);
        printf ("\n");
    }
    printf( "OK\n");
    return 0;
}
