#include "Gametype.h"

int Gametype::nbJoueur = 1;
int Gametype::nbLife = 3;
int Gametype::playerSpeed = 5;

Gametype::Gametype(int nbJoueur,int nbLife,int playerSpeed,bool randomizeMonsterScale,bool rotationEnabled, bool following,bool team, int nbTeam): NBJOUEUR_MAX(4)
{
    /*this->nbJoueur = nbJoueur;
    this->nbLife = nbLife;
    this->playerSpeed = playerSpeed;*/
    this->randomizeMonsterScale = randomizeMonsterScale;
    this->rotationEnabled = rotationEnabled;
    this->following = following;
    this->team = team;
    this->nbTeam = nbTeam;
}

Gametype::Gametype(const Gametype &gametype):NBJOUEUR_MAX(4)
{
    /*this->nbJoueur = gametype.getNbJoueur();
    this->nbLife = gametype.getNbLife();
    this->playerSpeed = gametype.getPlayerSpeed();*/
    this->randomizeMonsterScale = gametype.israndomizationEnabled();
    this->rotationEnabled = gametype.isRotationEnabled();
    this->following = gametype.isFollowingEnabled();
    this->team = gametype.isTeamEnabled();
    this->nbTeam = gametype.getNbTeam();
}

void Gametype::operator=(const Gametype& gametype)
{
    /*nbJoueur = gametype.getNbJoueur();
    nbLife = gametype.getNbLife();
    playerSpeed = gametype.getPlayerSpeed();*/
    randomizeMonsterScale = gametype.israndomizationEnabled();
    rotationEnabled = gametype.isRotationEnabled();
    following = gametype.isFollowingEnabled();
    team = gametype.isTeamEnabled();
    nbTeam = gametype.getNbTeam();
}

Gametype::~Gametype()
{
}

void Gametype::setEnabledRotation(bool value)
{
    rotationEnabled = value;
}

void Gametype::setEnabledRandomization(bool value)
{
    randomizeMonsterScale = value;
}

void Gametype::setEnabledFollowing(bool value) //notClassicalMod -> against fictionnals ships
{
    following = value;
}

void Gametype::setEnabledTeam(bool value)
{
    team = value;
}

void Gametype::setNbJoueur(int value) // listeJoueur.size()
{
    if(value > 0 && value <= NBJOUEUR_MAX)
        nbJoueur = value;
}

void Gametype::setNbLife(int value)
{
    if(value >0)
        nbLife = value;
}

void Gametype::setPlayerSpeed(int value)
{
    if(value > 0)
        playerSpeed = value;
}

int Gametype::getNbJoueur() const
{
    return nbJoueur;
}

int Gametype::getNbLife() const
{
    return nbLife;
}

int Gametype::getPlayerSpeed() const
{
    return playerSpeed;
}

bool Gametype::isRotationEnabled() const
{
    return rotationEnabled;
}

bool Gametype::israndomizationEnabled() const
{
    return randomizeMonsterScale;
}

bool Gametype::isFollowingEnabled() const
{
    return following;
}

bool Gametype::isTeamEnabled() const
{
    return team;
}

void Gametype::setNbTeam(int value)
{
    if(value > 0  && value < nbJoueur)
        nbTeam = value;
}

int Gametype::getNbTeam() const
{
    return nbTeam;
}
