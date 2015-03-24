#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Gametype.h"
#define PI 3.141592653589793238462643383279502884


class Ennemis
{
    public:
        Ennemis();
        Ennemis(const sf::Texture &,int,int,int,int,const sf::Vector2f &, const Gametype &);
        ~Ennemis();

        sf::Sprite getSprite();
        void setTexture(sf::Texture);
        void setPosCible(sf::Vector2f);
        void majDirection(); //v2 suivant  la pasteque
        int getNbrEnnemi();
        bool isInTheArea();
        void animation();
        bool decLife(int);

        void kill(std::vector<Ennemis>&);

        void move();

        static void addEnnemis(std::vector<Ennemis>&,const sf::Texture&, int, int, int, int,const sf::Vector2f&, const Gametype &);

        int getId();
        void setId(const int&);
        sf::Vector2f getPosition();
        int getXmin();
        int getXmax();
        int getYmin();
        int getYmax();
        int getRayon();

        static int nbrEnnemi; // liste

    private:
        int posX;
        int posY;
        sf::Vector2f position;
        int xMin, xMax, yMin, yMax;
        float angle;
        float anglepre;
        int vitesse;
        int life;
        int id;
        sf::Sprite sprite;
        sf::Vector2f posCible;
        int rayon;

        Gametype gametype;
};


#endif // ENNEMIS_H
