#include "localGame.h"
#include <iostream>


localGame::localGame()
{
    gameType = new Gametype();
    //gameType->setEnabledRandomization(false);
    //gameType->setEnabledRotation(false);
    /*thitbox = new std::thread(&localGame::ctrlHitBox, this);
    tprojectiles = new std::thread(&localGame::gestionProjectiles, this);
    tennemis = new std::thread(&localGame::gestionEnnemis, this);*/

    spawnTime = sf::milliseconds(1000);
    spawnTimeElapsed = sf::milliseconds(0);
    deltaAsBeenAdded = false;
    deltaGestionAsBeenAdded = false;
    deltaSpawn = sf::milliseconds(0);
    spawnTimeElapsedPre = sf::milliseconds(0);
    interval = sf::seconds(5);
    deltaGestion = sf::milliseconds(0);
    gestionTimeElapsed = sf::seconds(0);
    gestionTimeElapsedPre = sf::seconds(0);

    fileBackground = "interieurSpace.png";
    fileForeground = "contourSpace.png";
    fileEnnemiSkin = "asteroid.png";
    fileJoueurSkin = "vaisseau.png";
    filebullet = "bullet.png";

    points[0] = sf::Vertex(sf::Vector2f(XMIN, YMIN));
    points[1] = sf::Vertex(sf::Vector2f(XMAX, YMIN));
    points[2] = sf::Vertex(sf::Vector2f(XMIN, YMAX));
    points[3] = sf::Vertex(sf::Vector2f(XMAX, YMAX));
    points[4] = sf::Vertex(sf::Vector2f(XMIN, YMIN));
    points[5] = sf::Vertex(sf::Vector2f(XMIN, YMAX));
    points[6] = sf::Vertex(sf::Vector2f(XMAX, YMIN));
    points[7] = sf::Vertex(sf::Vector2f(XMAX, YMAX));

    if (!font.loadFromFile("font.ttf"))
    {
        // erreur...
    }

    if (!texJoueur.loadFromFile(fileJoueurSkin.c_str()))
    {
        //message d'erreur dans console
    }
    if (!texEnnemi.loadFromFile(fileEnnemiSkin.c_str()))
    {
        //message d'erreur dans console
    }
    if (!texForeground.loadFromFile(fileForeground.c_str()))
    {
        //message d'erreur dans console
    }
    if (!texBackground.loadFromFile(fileBackground.c_str()))
    {
        //message d'erreur dans console
    }
    if (!texBullet.loadFromFile(filebullet.c_str()))
    {
        //message d'erreur dans console
    }

    background.move(10,10);
    background.setTexture(texBackground);
    foreground.setTexture(texForeground);


    for(int i=0; i< 1; i++)
    {
        gameType->setNbJoueur(listeJoueur.size()+1);
        Joueur::addJoueur(listeJoueur,texJoueur,texBullet,XMIN,XMAX,YMIN,YMAX,sf::Vector2f(400,250),*gameType);
    }



    onePlayerStillAlive = true;

    scoreJoueurs = new int[listeJoueur.size()];
    nomJoueurs = new std::string[listeJoueur.size()];
    txtPseudo = new sf::Text[listeJoueur.size()];
    txtScore = new sf::Text[listeJoueur.size()];
    txtlifes = new sf::Text[listeJoueur.size()];

    for(unsigned int i=0; i<listeJoueur.size(); i++)
    {
        nomJoueurs[i] = listeJoueur[i].getPseudo();
        txtPseudo[i].setString(nomJoueurs[i]);
        txtPseudo[i].setFont(font);
        txtPseudo[i].setCharacterSize(10);
        scoreJoueurs[listeJoueur[i].getId()] = 0;
        txtScore[listeJoueur[i].getId()].setString("0");
        txtScore[listeJoueur[i].getId()].setFont(font);
        txtlifes[i].setString(listeJoueur[i].getLifeStr());
        txtlifes[i].setFont(font);
    }
    txtCurrentScore.setFont(font);

    txtCurrentScore.setPosition(sf::Vector2f(550,545));
    txtCurrentScore.setCharacterSize(15);
    txtlifes[0].setPosition(sf::Vector2f(100, 545));
    txtlifes[0].setCharacterSize(15);

    window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "PadMaster - Alpha");
    window->setVerticalSyncEnabled(true);

    myGamePad = Gamepad(1);
}

localGame::~localGame()
{
    //dtor
}

void localGame::lancer()
{
    srand (time(NULL));// la base

    while (window->isOpen())
    {
        if(myGamePad.Connected()) // gestion du gamepad
        {
            myGamePad.Update(); //la base t'sais
            if(myGamePad.LeftTrigger()>0 && onePlayerStillAlive)
                gameType->setPlayerSpeed(10);
            else
            {
                if(gameType->getPlayerSpeed() != 5)
                {
                    gameType->setPlayerSpeed(5);
                }
            }

            if(!myGamePad.LStick_InDeadzone() && onePlayerStillAlive) // déplacer pastèque
            {
                // if(listeJoueur[0].getPosition().x + myGamePad.LeftStick_X()*listeJoueur[0].getVitesse() < XMAX && listeJoueur[0].getPosition().x + myGamePad.LeftStick_X()*listeJoueur[0].getVitesse() > XMIN && listeJoueur[0].getPosition().y - myGamePad.LeftStick_Y()*listeJoueur[0].getVitesse() < YMAX && listeJoueur[0].getPosition().y - myGamePad.LeftStick_Y()*listeJoueur[0].getVitesse() > YMIN)
                if(listeJoueur[0].isInTheArea(myGamePad.LeftStick_X(),- myGamePad.LeftStick_Y()))
                {
                    listeJoueur[0].move(sf::Vector2f(myGamePad.LeftStick_X(),-myGamePad.LeftStick_Y())); // décalage relatif à la position actuelle
                    /*listeJoueur[1].move(sf::Vector2f(-myGamePad.LeftStick_X(),myGamePad.LeftStick_Y()));
                    listeJoueur[2].move(sf::Vector2f(-myGamePad.LeftStick_X(),-myGamePad.LeftStick_Y()));
                    listeJoueur[3].move(sf::Vector2f(myGamePad.LeftStick_X(),myGamePad.LeftStick_Y()));*/
                    for(unsigned int i=0; i<listeEnnemis.size(); i++)
                        listeEnnemis[i].setPosCible(listeJoueur[0].getPosition());
                }

            }
            if(myGamePad.GetButtonPressed(XButtons.B)) // fermer la fenêtre
                window->close();
            if(!myGamePad.RStick_InDeadzone() && onePlayerStillAlive) // rotation de la pastèque
                listeJoueur[0].turn(sf::Vector2f(myGamePad.RightStick_X(),myGamePad.RightStick_Y()));
            if(myGamePad.RightTrigger()>0 && onePlayerStillAlive)
                listeJoueur[0].fire(listeProjectiles,listeJoueur[0].getPosition(), listeJoueur[0].getAngle()); //debbuguer ma poule ><
            //getchar();
            //Joueur::addJoueur(listeJoueur,texJoueur,XMIN,XMAX,YMIN,YMAX,sf::Vector2f(400,250));
        }
        else
        {
            sf::Event event; // tellement useless pour l'instant
            while (window->pollEvent(event) && onePlayerStillAlive)//gestion souris clavier ? non j'ai la flemme :^)
            {
                //à venir;
            }
        }

        updateGame();
        draw();
    }
}

void localGame::draw() //TODO Draw The name ! + Life
{
    window->clear();//We will never forget you <3

    window->draw(background);

    for(unsigned int i=0; i<listeEnnemis.size(); i++)// afficher les ennemis
        window->draw(listeEnnemis[i].getSprite());
    for(unsigned int i=0; i<listeJoueur.size(); i++)//affiche les joueurs
        window->draw(listeJoueur[i].getSprite());

    for(unsigned int i =0; i<listeJoueur.size(); i++)
    {
        txtPseudo[i].setPosition(listeJoueur[i].getPosition() + sf::Vector2f(-25,-35)); //pseudo au dessus du nom
        window->draw(txtPseudo[i]);
    }

    if(Projectile::nbBullets >0)
    {
        for(int i=0; i< Projectile::nbBullets; i++)
        {
            window->draw(listeProjectiles[i].getSprite());
            std::cout << "ID: " << listeProjectiles[i].getId() << " - Inst: " << Projectile::nbBullets +1 << std::endl;
        }
    }

    window->draw(points, 8, sf::Lines);//le cadre

    window->draw(foreground);

    window->draw(txtCurrentScore);
    window->draw(txtlifes[0]);

    window->display();
}

void localGame::ctrlHitBox()
{
    bool inTheHitBox = false;
    int distance, posX, posY;
    //std::cout << listeJoueur.size();
    for(unsigned int i=0; i<listeJoueur.size(); i++)//vla les test de malade
    {
        for(unsigned int j=0; j<listeEnnemis.size(); j++)
        {
            posX = listeEnnemis[j].getPosition().x - listeJoueur[i].getPosition().x;
            posY = listeEnnemis[j].getPosition().y - listeJoueur[i].getPosition().y;
            distance = sqrt((pow(posX,2)+pow(posY,2)));
            //distance =(int) sqrt((listeJoueur[i].getPosition().x - listeEnnemis[j].getPosition().x)*(listeJoueur[i].getPosition().x - listeEnnemis[j].getPosition().x) + (listeJoueur[i].getPosition().y - listeEnnemis[j].getPosition().y)*(listeJoueur[i].getPosition().y - listeEnnemis[j].getPosition().y));
            if( distance < 15 + listeEnnemis[j].getRayon())//distance entre les deux
                inTheHitBox = true;
            if(inTheHitBox)
            {
                listeEnnemis[j].kill(listeEnnemis);
                if(listeJoueur[i].decLife()) // si ça tue le joueur
                {
                    scoreJoueurs[listeJoueur[i].getId()] = listeJoueur[i].getScore(); //garde le score du joueur en mémoire
                    txtlifes[i].setString("You died ...");
                    listeJoueur[i].kill(listeJoueur); // on enlève le joueur de la game
                }
                j = listeEnnemis.size();
            }

        }
    }
    if(listeJoueur.size()==0)
        onePlayerStillAlive = false;
}

void localGame::gestionEnnemis()
{
    int minRan = 0;
    int maxRan = listeJoueur.size()-1;
    int rang = 0;
    if(maxRan != minRan)
        rang = (int) rand() % maxRan +minRan;
    for(unsigned int i=0; i<listeEnnemis.size(); i++)
    {
        listeEnnemis[i].move();
        for(int j=0; j<Projectile::nbBullets; j++ )
        {
            if(listeProjectiles[j].hit(listeEnnemis[i].getPosition(), listeEnnemis[i].getRayon()))
            {
                int idJoueur = listeProjectiles[j].getIdJoueur();
                listeProjectiles[j].kill(listeProjectiles);//PUTAIN D'SA MAMAIRE J'AVAIS MIS UN PUTAIN DE 'I' AU LIEU DU 'J' AAAAAAAAAAAAH ><
                if(listeEnnemis[i].decLife(listeProjectiles[j].getDamage()))
                {
                    listeJoueur[idJoueur].incScore();
                    listeEnnemis[i].kill(listeEnnemis);
                    j = Projectile::nbBullets;
                }
            }
        }
        //if(listeEnnemis[i].getPosition().x > listeEnnemis[i].getXmax() || listeEnnemis[i].getPosition().x < listeEnnemis[i].getXmin() || listeEnnemis[i].getPosition().y < listeEnnemis[i].getYmin() || listeEnnemis[i].getPosition().y > listeEnnemis[i].getYmax())
        if(!listeEnnemis[i].isInTheArea())
        {
            listeEnnemis[i].kill(listeEnnemis);
            for(unsigned int j=0 ; j < listeJoueur.size(); j++)
                listeJoueur[j].incScore();// on monte le score de tous les joueurs
        }
        listeEnnemis[i].setPosCible(listeJoueur[rang].getPosition());
    }
}

void localGame::gestionProjectiles()
{
    for(int j=0; j<Projectile::nbBullets; j++)
    {
        listeProjectiles[j].update();
        if(!listeProjectiles[j].isInTheArea(XMIN,XMAX,YMIN,YMAX))
            listeProjectiles[j].kill(listeProjectiles);//hardcore ais tu vois mort naturelle des projectiles
    }
}

void localGame::gestionDonneeInterface()
{
    for(unsigned int i =0; i<listeJoueur.size(); i++)
    {
        std::string score = (std::string) listeJoueur[i].getScoreStr();
        std::string lifes = listeJoueur[0].getLifeStr();
        txtScore[listeJoueur[i].getId()].setString(score);
        txtlifes[i].setString("Lifes : " + lifes);
    }

    if(onePlayerStillAlive)
    {
        std::string score = listeJoueur[0].getScoreStr();
        txtCurrentScore.setString("Score : " + score);
    }

}

void localGame::updateGame()
{
    sf::Time elapsed = clockGlobal.getElapsedTime();
    sf::Time calcTime = clockCalc.getElapsedTime();

    spawnTimeElapsed += sf::milliseconds(clockSpawn.getElapsedTime().asMilliseconds()) - sf::milliseconds(spawnTimeElapsedPre.asMilliseconds());
    if(!deltaAsBeenAdded)
    {
        spawnTimeElapsed += deltaSpawn;
        deltaAsBeenAdded = true;
    }
    spawnTimeElapsedPre = clockSpawn.getElapsedTime();

    //std::cout << spawnTimeElapsed.asMilliseconds() << " : " << spawnTime.asMilliseconds() << std::endl;
    if(spawnTimeElapsed.asMilliseconds() > spawnTime.asMilliseconds() && onePlayerStillAlive)
    {
        deltaSpawn = sf::milliseconds(spawnTimeElapsed.asMilliseconds()) - sf::milliseconds(spawnTime.asMilliseconds());
        deltaAsBeenAdded = false;
        Ennemis::addEnnemis(listeEnnemis,texEnnemi,XMIN,XMAX,YMIN,YMAX,listeJoueur[0].getPosition(),*gameType);

        if( elapsed.asSeconds() > interval.asSeconds())
        {
            interval += sf::seconds(5);
            if(spawnTime > sf::milliseconds(100))
                spawnTime -= sf::milliseconds(50);
        }
        clockSpawn.restart();
        spawnTimeElapsed = sf::milliseconds(0);
        spawnTimeElapsedPre = sf::milliseconds(0);
    }

    gestionTimeElapsed += sf::milliseconds(clockEvent.getElapsedTime().asMilliseconds()) - sf::milliseconds(gestionTimeElapsedPre.asMilliseconds());
    if(!deltaGestionAsBeenAdded)
    {
        gestionTimeElapsed += deltaGestion;
        deltaGestionAsBeenAdded =true;
    }
    gestionTimeElapsedPre = gestionTimeElapsed;

    if(gestionTimeElapsed > sf::milliseconds(400));
    {
        clockEvent.restart();
        deltaGestion = gestionTimeElapsed - sf::milliseconds(400); // pour le lag

        //std::thread tprojectiles(&localGame::gestionProjectiles, this);
        gestionProjectiles();
        //std::thread tennemis(&localGame::gestionEnnemis, this);
        gestionEnnemis();


        if(calcTime > sf::milliseconds(500))
        {
            ctrlHitBox();
            //std::thread thitbox(&localGame::ctrlHitBox, this); // gère les contact entre les ennemis et les joueurs + gère la disparitino du joueur
            clockCalc.restart();
        }

        gestionDonneeInterface();
    }
}
