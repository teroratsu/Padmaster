#include "Weapon.h"
#include <iostream>

Weapon::Weapon()
{
    //ctor
}

Weapon::~Weapon()
{

}

Weapon::Weapon(const int& damage, const int& bulletSpeed, const int& bulletFireRate, const sf::Texture& tex,const int& id)
{
    enabled = true;
    this->damage = damage;
    this->bulletFireRate = bulletFireRate;
    this->bulletSpeed = bulletSpeed;
    this->texBullets = tex;
    this->idJoueur = id;

    fireRate = sf::milliseconds(1000)/sf::Int64(bulletFireRate);
    fireTimeElapsed = sf::milliseconds(0);
    fireTimeElapsedPre = sf::milliseconds(0);
    deltaSpawn = sf::milliseconds(0);
    deltaAsBeenAdded = true;
}

bool Weapon::isWeaponAuthorised()
{
    return enabled;
}

void Weapon::setEnabled(bool value)
{
    if(value)
        enabled=true;
    else
        enabled=false;
}

void Weapon::fire(std::vector<Projectile>& bullets,const sf::Vector2f& pos, const float&ang,const int&idJoueur)
{
    if(enabled)
    {
        fireTimeElapsed += sf::milliseconds(clockFire.getElapsedTime().asMilliseconds()) - sf::milliseconds(fireTimeElapsed.asMilliseconds());
        if(!deltaAsBeenAdded)
        {
            fireTimeElapsed += deltaSpawn;
            deltaAsBeenAdded = true;
        }
        fireTimeElapsedPre = clockFire.getElapsedTime();


        if(fireTimeElapsed.asMilliseconds() > fireRate.asMilliseconds())
        {
            std::cout << fireTimeElapsed.asMilliseconds() << " : " << fireRate.asMilliseconds() << std::endl;
            clockFire.restart();
            fireTimeElapsed = sf::milliseconds(0);
            fireTimeElapsedPre = sf::milliseconds(0);

            deltaSpawn = sf::milliseconds(fireTimeElapsed.asMilliseconds()) - sf::milliseconds(fireRate.asMilliseconds());
            deltaAsBeenAdded = false;
            for(int i=0; i<3; i++)
            {
                bullets.push_back(Projectile(pos,ang +i*10,bulletSpeed,texBullets,idJoueur,damage));
            }

            /*bullets.push_back(Projectile(pos,ang +90,bulletSpeed,texBullets,idJoueur,damage));
            bullets.push_back(Projectile(pos,ang -90,bulletSpeed,texBullets,idJoueur,damage));*/
        }
    }
}

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getFireRate()
{
    return bulletFireRate;
}

int Weapon::getSpeed()
{
    return bulletSpeed;
}



