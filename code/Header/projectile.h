#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "SFML/Graphics.hpp"
#include <cmath>

#define PI 3.141592653589793238462643383279502884

class Projectile
{
    public:
        Projectile();
        Projectile(const sf::Vector2f&,const float&,const int&,const sf::Texture&,const int&,const int&, const sf::Color& = sf::Color::White);
        ~Projectile();

        void update(); //penser à le détruire si en dehors des bornes
        bool isInTheArea(const int&, const int&, const int&, const int&); //pour la disparition naturelle
        void kill(std::vector<Projectile>&); //indice bulle
        bool hit(const sf::Vector2f&,const int&);

        int getId();
        int getDamage();
        int getIdJoueur();
        sf::Vector2f getPosition();
        sf::Sprite getSprite();
        void setId(int);

        static int nbBullets;
    private:
        sf::Vector2f position;
        float angle; //(angle de rotation)
        int id;
        int idJoueur;
        int vitesse;
        int damage;
        sf::Sprite sprite;
};

#endif // PROJECTILE_H
