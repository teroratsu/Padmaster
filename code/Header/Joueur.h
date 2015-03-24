#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Gamepad.h"
#include <string>
#include <sstream>
#include "Gametype.h"
#include "Weapon.h"
#include "projectile.h"

#define PI 3.141592653589793238462643383279502884

class Weapon;
class Joueur
{
    public:
        Joueur(); // à garder on sait jamais
        Joueur(const sf::Texture &,const sf::Texture &,int,int,int,int,const sf::Vector2f &,const Gametype&, std::string = "");
        ~Joueur();
        //dans les deux cas passer un sf::vector(myGamePad.RightStick_X(),myGamePad.LeftStick_Y())
        void move(const sf::Vector2f&); // pasteque.move(sf::Vector2f(myGamePad.LeftStick_X()*5,-myGamePad.LeftStick_Y()*5));
        void turn(const sf::Vector2f&); // atan2(-myGamePad.RightStick_Y(),myGamePad.RightStick_X())* 180 / PI;
        void kill(std::vector<Joueur>&);
        void setTexture(sf::Texture);
        void incScore();
        bool decLife();
        bool isInTheArea(float,float);

        int getLife();
        std::string getLifeStr();

        sf::Vector2f getPosition();
        int getXmin();
        int getXmax();
        int getYmin();
        int getYmax();
        int getVitesse();
        int getId();
        int getScore();
        float getAngle();
        Weapon* getWeapon();
        std::string getScoreStr();
        std::string getPseudo();
        sf::Sprite getSprite();

        void fire(std::vector<Projectile>&,const sf::Vector2f&, const float&);

        void setId(const int&);

        static void addJoueur(std::vector<Joueur>&,const sf::Texture&,const sf::Texture &, int, int, int, int,const sf::Vector2f&,const Gametype&,std::string = "");

    private:
        int id;
        sf::Vector2f position;
        sf::Sprite spritePerso;
        int xMin, xMax, yMin, yMax; //coordo de dplc dans la box
        float angle;
        int vitesse;
        Gamepad gamepad; // manette
        Weapon* weapon;

        int life;
        int score;

        std::string pseudo;
        Gametype gametype;

        static int nbrJoueurs; //gestion de l'id
};

#endif // JOUEUR_H
