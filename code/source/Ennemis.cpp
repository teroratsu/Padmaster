#include "Ennemis.h"
#include <iostream>

int Ennemis::nbrEnnemi = 0;

/*TUDOUX_LIST
Gérer vitesse en fonction du mode (normal + lent, hard, plus rapide) + hardcore == suivit de l'angle (majdirection) // paramètre
Intégrer un menu; (sélectionner type de partie, lancer) voir pour intégrer le score plus tard (monsieur Romain s'en charge
recouper le skin, lui refaire sa gueule (on voit ça demain :))
gérer hitbox en fonction du rayon (distance entre posCible, et ennemis // à chaque frame)
*/


Ennemis::Ennemis()
{

}

Ennemis::Ennemis(const sf::Texture&  texture,int xmin,int xmax,int ymin,int ymax,const sf::Vector2f &posCible,const Gametype& gametype)
{
    this->gametype = gametype;
    id = nbrEnnemi++;
    this->posCible = posCible;
    sprite.setTexture(texture);
    sprite.setOrigin(25,25);

    float scale = 1;

    if(this->gametype.israndomizationEnabled())
    {
        scale = rand()%3 + 0.8;
        sprite.setScale(scale, scale);
    }
    rayon = (int)  25 * scale;

    this->life = (int) 2*scale;

    vitesse = (rand()% 6 + 4) /scale;

    xMin = xmin-25;
    yMin = ymin-25;
    xMax = xmax+25;
    yMax = ymax+25;

    if(rand()%2 == 0)//spawn en abscisse
    {
        posX = floor((rand()%xMax) + xMin);
        if(rand()%2 == 0)
            posY = yMin;
        else
            posY = yMax;
    }
    else //spawn en en ordonnée
    {
        posY = floor((rand()%yMax) + yMin);
        if(rand()%2 == 0)
            posX = xMin;
        else
            posX = xMax;
    }
    position = sf::Vector2f(posX, posY);
    float _posX = posX - posCible.x;//pour l'angle
    float _posY = posY - posCible.y;
    this->angle = atan2(_posY,_posX) * 180 / PI;
    majDirection();
    //std::cout << nbrEnnemi << " | " << position.x << " : " << position.y << "| vit : " << vitesse << " rot : "  << angle << std::endl;
}

void Ennemis::addEnnemis(std::vector<Ennemis> &listeEnnemis,const sf::Texture &textureEnnemi, int xmin, int xmax, int ymin, int ymax,const sf::Vector2f &posCible,const Gametype& gametype)
{
    //Ennemis (textureEnnemi,xmin,xmax,ymin,ymax,posCible);
    listeEnnemis.push_back(Ennemis(textureEnnemi,xmin,xmax,ymin,ymax,posCible, gametype));
}

Ennemis::~Ennemis()
{
    //nbrEnnemi--;
}

void Ennemis::majDirection()
{
    float _posY = posCible.y - position.y;
    float _posX = posCible.x - position.x;

    angle = (atan2(_posY,_posX))* 180/PI;

    sprite.setRotation(angle);
}

sf::Sprite Ennemis::getSprite()
{
    return this->sprite;
}

void Ennemis::setPosCible(sf::Vector2f pos) // impérativement avant quoi que ce soit (après création)
{
    posCible = pos;
}

void Ennemis::move()
{
    if(gametype.isFollowingEnabled())
        majDirection();
    if(gametype.isRotationEnabled())
        animation();
    this->position.x += (cos((angle*(PI/180))) * this->vitesse);
    this->position.y += (sin((angle*(PI/180))) * this->vitesse);
    sprite.setPosition(position.x, position.y);

}

void Ennemis::animation()
{
    sprite.rotate(vitesse);
}

void Ennemis::kill(std::vector<Ennemis>& listeEnnemis)
{
    listeEnnemis.at(listeEnnemis.size()-1).setId(listeEnnemis.at(id).getId());
    std::swap(listeEnnemis[id], listeEnnemis[listeEnnemis.size()-1]);
    listeEnnemis.pop_back();
    nbrEnnemi--;
}

bool Ennemis::isInTheArea()
{
    if(position.x < xMax && position.x > xMin && position.y < yMax && position.y > yMin)
        return true;
    else
        return false;
}

bool Ennemis::decLife(int damage)
{
    bool dead = false;
    life -= damage;
    if(life < 1)
        dead = true;
    return dead;
}

int Ennemis::getId()
{
    return id;
}

void Ennemis::setId(const int& id)
{
    this->id = id;
}

int Ennemis::getNbrEnnemi()
{
    return nbrEnnemi;
}

sf::Vector2f Ennemis::getPosition()
{
    return position;
}

int Ennemis::getXmin()
{
    return xMin;
}

int Ennemis::getXmax()
{
    return xMax;
}

int Ennemis::getYmin()
{
    return yMin;
}

int Ennemis::getYmax()
{
    return yMax;
}

int Ennemis::getRayon()
{
    return rayon;
}

//getter/setter

