#include "Joueur.h"
#include <iostream>

int Joueur::nbrJoueurs = 0;

Joueur::Joueur()
{
    //ctor
}

Joueur::Joueur(const sf::Texture &tex,const sf::Texture &texBullet,int xMin,int xMax,int yMin,int yMax,const sf::Vector2f &pos,const Gametype& gametype, std::string pseudo)
{
    this->gametype = gametype;
    score = 0;

    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;

    vitesse = gametype.getPlayerSpeed();

    spritePerso.setTexture(tex);
    spritePerso.setPosition(pos);
    spritePerso.setOrigin(15,15);

    id = nbrJoueurs++;
    weapon = new Weapon(1,10,5,texBullet,id); //tir par seconde (3eme)
    life = gametype.getNbLife();
    position = pos;
    angle = 0;

    sf::Color color;

    if(!gametype.isTeamEnabled())
    {
        switch(id+1)
        {
        case 1:
            spritePerso.setColor(color.White);
            break;
        case 2:
            spritePerso.setColor(color.Magenta);
            break;
        case 3:
            spritePerso.setColor(color.Green);
            break;
        case 4:
            spritePerso.setColor(color.Yellow);
        }
    }
    else
    {
        //a voir (equipe)
    }


    std::ostringstream os;
    os << id+1;

    if(pseudo == "")
        this->pseudo = "MaBite-" + os.str();
    else
        this->pseudo = pseudo;
}

void Joueur::addJoueur(std::vector<Joueur> &listeJoueur,const sf::Texture &textureJoueur,const sf::Texture &texBullet, int xmin, int xmax, int ymin, int ymax,const sf::Vector2f &pos,const Gametype& gametype, std::string pseudo)
{
    listeJoueur.push_back(Joueur(textureJoueur,texBullet,xmin,xmax,ymin,ymax,pos, gametype, pseudo));
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::move(const sf::Vector2f &posStickL)
{
    spritePerso.move(sf::Vector2f(posStickL.x*gametype.getPlayerSpeed(),posStickL.y*gametype.getPlayerSpeed()));
    position = spritePerso.getPosition();
}

void Joueur::turn(const sf::Vector2f &posStickR)
{
    angle = atan2(-posStickR.y,posStickR.x)* 180 / PI;
    spritePerso.setRotation(angle);
}

void Joueur::kill(std::vector<Joueur>& listeJoueurs)
{
    listeJoueurs.at(listeJoueurs.size()-1).setId(listeJoueurs.at(id).getId());
    std::swap(listeJoueurs[id], listeJoueurs[listeJoueurs.size()-1]);
    listeJoueurs.pop_back();
    nbrJoueurs--;
}

bool Joueur::isInTheArea(float x, float y)
{
    if(position.x + x*vitesse < xMax && position.x + x*vitesse > xMin && position.y + y*vitesse < yMax && position.y + y*vitesse > yMin)
        return true;
    else
        return false;
}


bool Joueur::decLife()
{
    bool dead = false;
    if(--life < 1)
        dead = true;
    return dead;
}

void Joueur::setTexture(sf::Texture tex)
{
    spritePerso.setTexture(tex);
}

void Joueur::incScore()
{
    score++;
}

int Joueur::getLife()
{
    return life;
}

sf::Vector2f Joueur::getPosition()
{
    return position;
}

int Joueur::getXmin()
{
    return xMin;
}

int Joueur::getXmax()
{
    return xMax;
}

int Joueur::getYmin()
{
    return yMin;
}

int Joueur::getYmax()
{
    return yMax;
}

int Joueur::getId()
{
    return id;
}

int Joueur::getScore()
{
    return score;
}

std::string Joueur::getScoreStr()
{
    std::ostringstream oss;
    oss << score;
    return oss.str();
}

std::string Joueur::getLifeStr()
{
    std::ostringstream oss;
    oss << life;
    return oss.str();
}

std::string Joueur::getPseudo()
{
    return pseudo;
}

int Joueur::getVitesse()
{
    return vitesse;
}

void Joueur::setId(const int &id)
{
    this->id = id;
}

sf::Sprite Joueur::getSprite()
{
    return spritePerso;
}

float Joueur::getAngle()
{
    return angle;
}

Weapon* Joueur::getWeapon()
{
    return weapon;
}

void Joueur::fire(std::vector<Projectile>& liste,const sf::Vector2f& pos, const float& ang)
{
    const int  idJoueur = id;
    weapon->fire(liste,pos,ang,idJoueur);
}




