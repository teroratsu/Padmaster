#include "projectile.h"
#include <iostream>

int Projectile::nbBullets = 0;

Projectile::Projectile()
{
    //ctor
}

Projectile::~Projectile()
{
    //ctor
}

void Projectile::kill(std::vector<Projectile>& listeProjectile)
{
    std::cout << "DEL" << id << std::endl;
    if(listeProjectile.at(listeProjectile.size()-1).getId() != listeProjectile.at(id).getId())
    {
        listeProjectile.at(listeProjectile.size()-1).setId(listeProjectile.at(id).getId());
        std::swap(listeProjectile[id], listeProjectile[listeProjectile.size()-1]);
        listeProjectile.pop_back();
        nbBullets--;
    }
    else
    {
        listeProjectile.pop_back();
        nbBullets--;
    }
}

Projectile::Projectile(const sf::Vector2f& position, const float& angle,const int& vitesse,const sf::Texture& texture,const int& idJoueur,const int& damage, const sf::Color& color)
{
    this->id = nbBullets++;
    this->idJoueur = idJoueur;
    this->position = position;
    this->angle = angle;
    this->vitesse = vitesse;
    this->damage = damage;
    sprite.setTexture(texture);

    float midHeight = sprite.getGlobalBounds().height/2;
    float midWidth = sprite.getGlobalBounds().width/2;
    sprite.setOrigin(sf::Vector2f(midWidth,midHeight));

    sprite.setRotation(angle);
    sprite.setPosition(this->position);
    sprite.setColor(color);
    std::cout << "ADD" << id << std::endl;
}

void Projectile::update()
{
    position.x += (cos(angle*(PI/180)) * vitesse);
    position.y += (sin(angle*(PI/180)) * vitesse);
    sprite.setPosition(position.x, position.y);
}

bool Projectile::isInTheArea(const int& xMin, const int& xMax, const int&yMin, const int&yMax)
{
    if(position.x < xMax && position.x > xMin && position.y < yMax && position.y > yMin)
        return true;
    else
        return false;
}

int Projectile::getId()
{
    return id;
}

sf::Sprite Projectile::getSprite()
{
    return sprite;
}

void Projectile::setId(int id)
{
    this->id = id;
}

sf::Vector2f Projectile::getPosition()
{
    return position;
}

int Projectile::getIdJoueur()
{
    return idJoueur;
}

bool Projectile::hit(const sf::Vector2f& posEnnemi,const int& rayon)
{
    int posX = posEnnemi.x - position.x;
    int posY = posEnnemi.y - position.y;
    int distance = sqrt((pow(posX,2)+pow(posY,2)));
    if(distance < rayon)
        return true;
    else
        return false;
}

int Projectile::getDamage()
{
    return damage;
}



