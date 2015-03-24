#ifndef LOCALGAME_H
#define LOCALGAME_H

#include "gestionFenetre.h"
#include "Gamepad.h"
#include "Gametype.h"
#include <thread>

#define WIDTH 800
#define HEIGHT 600

class localGame : public gestionFenetre
{
    public:
        localGame();
        ~localGame();
        void lancer();
        void draw();
        void ctrlHitBox();
        void gestionEnnemis();
        void gestionProjectiles();
        void gestionDonneeInterface();
        void updateGame();

    private:

        Gamepad myGamePad;
        Gametype* gameType;
        bool onePlayerStillAlive;

        sf::Texture texBackground;//texture
        sf::Texture texForeground;
        sf::Texture texEnnemi;
        sf::Texture texJoueur;
        sf::Texture texBullet;

        sf::Font font;
        sf::Text* txtScore;
        sf::Text* txtPseudo;
        sf::Text  txtCurrentScore; //score courant commun juste pour le mode de jeu de survie
        sf::Text* txtlifes;

        sf::Sprite background;//sprite
        sf::Sprite foreground;

        sf::Clock clockGlobal;
        sf::Clock clockEvent;
        sf::Clock clockCalc;
        sf::Clock clockSpawn;
        sf::Time spawnTime;
        sf::Time spawnTimeElapsed;
        sf::Time spawnTimeElapsedPre;
        bool deltaAsBeenAdded;
        bool deltaGestionAsBeenAdded;
        sf::Time deltaSpawn;
        sf::Time interval;
        sf::Time deltaGestion;
        sf::Time gestionTimeElapsed;
        sf::Time gestionTimeElapsedPre;


        std::string fileBackground;//fileFinder
        std::string fileForeground;
        std::string fileEnnemiSkin;
        std::string fileJoueurSkin;
        std::string filebullet;

        sf::RenderWindow* window; // fenêtre

        sf::Vertex points[8];

        int* scoreJoueurs;
        std::string* nomJoueurs;

        /*std::thread* thitbox;
        std::thread* tprojectiles;
        std::thread* tennemis;*/
};

#endif // LOCALGAME_H
