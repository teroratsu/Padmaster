#ifndef GESTIONFENETRE_H
#define GESTIONFENETRE_H

#include <SFML/Graphics.hpp>
#include "Ennemis.h"
#include "Joueur.h"
#include "projectile.h"

class gestionFenetre
{
    public:
        gestionFenetre();
        ~gestionFenetre();

        const int XMIN;
        const int XMAX;
        const int YMIN;
        const int YMAX;

        std::vector<Ennemis> listeEnnemis;
        std::vector<Joueur> listeJoueur;
        std::vector<Projectile> listeProjectiles;
};

#endif // GESTIONFENETRE_H
