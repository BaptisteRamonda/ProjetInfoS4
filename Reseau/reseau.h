#ifndef __RESEAU_H__
#define __RESEAU_H__

typedef struct s_ville *Ville;
typedef struct s_trajet *Trajet;
typedef struct s_reseau *Reseau;
typedef struct s_ligne *Ligne;

Ligne ParisBiarritz();
Ligne ParisToulouse();
Ligne BordeauxNice();
Ligne ParisMarseille();

Trajet initialiseTrajet(Ville, Ville);
void afficheNomDeVille(Ville);
Reseau creerReseau();

#endif
