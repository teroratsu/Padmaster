#ifndef WEAPON_H
#define WEAPON_H

#include "projectile.h"
#include "Joueur.h"

class Weapon
{
    public:
        Weapon();
        Weapon(const int&, const int&, const int&,const sf::Texture&, const int&);
        ~Weapon();

        bool isWeaponAuthorised(); // return enabled
        void setEnabled(bool);

        void fire(std::vector<Projectile>&, const sf::Vector2f&, const float&,const int&);//control the fireRate, cr�� des bullets en fonction de l'avanc�e de la clock
        int getDamage();
        int getFireRate();
        int getSpeed();

    private:
        int damage; //dommages par balle
        int bulletSpeed; // vitesse des balles tir�es
        int bulletFireRate; //vitesse de feu
        bool enabled; // arme activ�e ou non
        int idJoueur; //idDuJoueurPropri�taire

        sf::Texture texBullets;
        sf::Clock clockFire;
        sf::Time fireRate;
        sf::Time fireTimeElapsed;
        sf::Time fireTimeElapsedPre;
        sf::Time deltaSpawn;

        bool deltaAsBeenAdded;
};

#endif // WEAPON_H
