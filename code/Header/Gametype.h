#ifndef GAMETYPE_H
#define GAMETYPE_H


class Gametype
{
    public:
        Gametype(int =1,int =3,int =5,bool =true,bool =true, bool =false,bool =false, int =2); //dans l'ordre des attributs en private
        Gametype(const Gametype &gametype);
        ~Gametype();

        void operator=(Gametype const &); // surcharge op�rateur

        void setEnabledRotation(bool);
        void setEnabledRandomization(bool); //scale
        void setEnabledFollowing(bool);
        void setEnabledTeam(bool);

        void setNbJoueur(int);
        void setNbLife(int);
        void setPlayerSpeed(int);
        void setNbTeam(int);
        int getNbJoueur() const;
        int getNbLife()const;
        int getPlayerSpeed()const;
        int getNbTeam()const;

        bool isRotationEnabled() const;
        bool israndomizationEnabled() const;
        bool isFollowingEnabled() const;
        bool isTeamEnabled() const;

        static int nbJoueur; // nb joueur au lancement souhait�
        static int nbLife;// nombre de vies
        static int playerSpeed; // vitesse du joueur

    private:
        const int NBJOUEUR_MAX; //nombre de joueur max

        bool randomizeMonsterScale; // les ennemis qui spawn sont de taille diff�rente
        bool rotationEnabled; //roattion des monstres sur eux m�me (asteroid)
        bool following; // les monstres vous suivent
        bool team; //faire des �quipes (al�atoires)
        int nbTeam; //si activ�

};

#endif // GAMETYPE_H
