Padmaster - GDD
=============

> [**Voir le GDD sur Google Doc**](http://derpy.me/GDD "lien vers le GDD")

![CA_01 PADMASTER](http://image.noelshack.com/fichiers/2015/13/1427321619-ca01-p.jpg)

#### **1. A propos du projet**#
	- Le but du projet
	- Pourquoi un tel projet

#### **2. Cahiers des charges**#
	- Le moteur de jeu
	- Le jeu

#### **3. Productions graphiques**#
	- Concept art
	- Ressources 2D

------

### **1. A propos du projet**#

###### Le but du projet #
Développer un moteur de jeu axé sur la production en parallèle d’un jeu en 2D (Padmaster). L'objectif serait d'obtenir une démo fonctionnelle du jeu et une base réutilisable pour nos futures productions. 
Le moteur est conçus sur une base [openGL](https://www.opengl.org/) et est codé à l’aide de bibliothèques telles que la [SFML2.2](http://www.sfml-dev.org/index-fr.php).
Le jeu se veut open-source, vous avez donc accès à l'ensemble du code source et des ressources utilisées pour mener à bien le projet.

###### pourquoi un tel projet  #
Ce projet a pour but de nous apprendre à gérer un projet en équipe. Il est développé sur notre temps libre et nous avons donc pour vocation d’apprendre plus de choses encore.
Ce projet est aussi un moyen de prouver notre motivation et notre sérieux si l’occasion s’y prêtait. 

*Un des pourquoi du projet est aussi dû au fait que nous somme tous joueurs chacun de notre côté et motivé à mettre en commun nos compétences pour réaliser ensemble un petit projet pour s’amuser.*

### **2. Cahier des charges**#

#### **2.1. Le moteur de jeu**#
L'élément principale du projet sur quoi tout repose est le moteur de jeu. Celui-ci doit pouvoir fonctionner pour tous les cas d'utilisations dont nous pourrions avoir besoin pour développer un jeu 2D. Ce moteur est un moteur 2D et ne convient qu'à la conception de jeu 2D bien spécifiques (shooters).

#### **2.2. Padmaster**#
_Padmaster est le jeu vidéo test pour lequel est développé le moteur de jeu, il sert aussi de sandbox pour tester et développer notre moteur de jeu. Le jeu est encore à l'état de réflexion ainsi le cahier des charges est encore en pleine conception._

_Le joueur contrôle un vaisseau spatial en vue de dessus, il peut se déplacer librement dans une carte **généré de façon procédurale**. Cette map est est parsemée d’obstacles naturels : des astéroïdes et autres astres flottants. Des Entités hostiles peuples aussi l’immensité de l’univers et viendront interagir avec le joueur de diverses façon._

#####Background :#

L’Homme a depuis longtemps quitté la Terre pour se réfugier en orbite. Nos contrées maintenant hostiles ont été puisées de leurs ressources et c’est dans l’immensité de l’univers que nous nous sommes en allé.  
	Nous nous sommes réfugié progressivement dans ces stations orbitales qui flottes un peu partout dans l’univers. L’innovation est telle que le voyage spatial se fait de façon simple et a bien moindre coût avec des technologies toujours plus ingénieuses et puissantes.  
Nous vivions désormais bien au delà des frontières que l’homme s’était imposé, Au gré des découvertes l’Homme fît la connaissance d’êtres primitifs, des micro-organismes fascinants qui étaient capable de synthétiser naturellement de l’eau simplement par photosynthèse.  
L’Homme pouvait enfin prospérer, c’était l’âge d’or de l’humanité.
	Cela n’a que bien trop peu durée, l’Homme a été et reste un loup pour l’Homme, toujours avide de pouvoir et de richesse les premiers pirates de l’espace faisaient leur apparition. C’est sans vergogne qu’ils détroussaient les honnêtes marchands de leur richesses.  
	Pour lutter contre ces groupuscules indépendants une milice a été mise en place pour contrôler le trafic spatial et défaire le réseau de trafiquants. Cette milice a été déployé sur l’ensemble du réseau et porte le nom de Commandement spatial International.  


#####Scénario : *Didacticiel & Introduction*#

• Vous incarnez un jeune astronaute engagé au service du commandement spatial international, vous finalisé vos examen pour intégrer l’équipe d’intervention.  
_{Suivre les directives pour mener à bien le didacticiel}  
[Introduction aux contrôles du jeu : Se déplacer, tirer]_  

• Au cours d’une mission de routine en temps qu’agent de la milice spatial vous êtes amené à escorter un convois entre deux station orbitales. Le voyage ne se passe pas comme prévu et vous vous retrouvé pris dans un embuscade d’un groupe de pirates.  
_{Participer au combat - Objectif : éliminer les vaisseaux pirates}  
[Introduction aux quêtes : accepter un quête, voir les objectifs]  
[Introduction aux contrôles du jeu : Tirer sur des cibles en mouvement (verrouiller une cible)]  
[Introduction aux mécaniques de base du jeu : la monnaie, l’xp]_  

• Arrivés à la station orbitale vous menez à bien votre mission et touchez votre récompense. Vous faites la connaissance de [Insérer un nom de meuf] experte en mécanique qui vous invite à lui rendre visite (ce que vous faites bande de coquinous).
Vous arrivez dans un hangar c’est ici que siège votre vaisseau quand vous n’êtes pas en balade. Depuis cet endroit vous pouvez modifier votre vaisseau ou bien même en acheter un nouveau !  
_{En bonne compagnie - Objectif : rendre visite à [Nom de la meuf]
sous-objectifs : - réparer son vaisseau -équiper un nouvel armement -Améliorer l’équipement}  
[Introduction aux quêtes : Terminer une quête]  
[Introduction à l’interface : naviguer dans la station - naviguer dans les menus]_  

#####__Le Vaisseau__ :
Le vaisseau du joueur peut réaliser des actions simples telles que :
se déplacer, ramasser des items et tirer.
__Gameplay du vaisseau__ :
#####_Déplacement_ :
Le vaisseau se pilote à l’aide des touches fléchées du clavier et d’une souris pour la visée.
#####_Armement_ :
Le vaisseau est équipé d’un armement afin de détruire les objets l'entourant. Plusieurs type de tir sont donc disponible et débloqué en fonction de la progression du joueur dans le jeu. 
#####_Caractéristiques du Vaisseau_# :
__Une barre de vie__ → correspond à l’état de la coque du vaisseau, la quantité de vie diffère selon le type de vaisseau et son type de coque (améliorations, modules…). Si la barre de vie atteint 0 alors le joueur meure. pour restaurer sa barre de vie deux options sont possible, acheter un drone réparateur qui réparera votre vaisseau automatiquement et ce progressivement.  
__Une réserve d’oxygène__ → décrémente en fonction du temps, se recharge gratuitement dans n’importe qu’elle station orbitale, contre de l’argent auprès d’un marchand itinérant ou dans les débris de vaisseaux - Des modules permettent d’agrandir cette capacité. Si la quantité d’oxygène atteint 0 alors le joueur meure. (la durée d’épuisement de l’oxygène est relativement longue pour ne pas altérer négativement le gameplay, mais il faut garder un oeil dessus).  
__Le bouclier - armure céleste (overshield)__ → Protection supplémentaire de votre vaisseau contre les attaques ennemies. L’overshield est capable de résister à quelques tir avant de céder aux attaques ennemies. Sa résistance dépend du niveau et module et se recharge automatiquement hors combat.  
__L’énergie__ → pour fonctionner votre vaisseau à besoin d’énergie, sans elle les fonctions du vaisseaux seraient désactivées et vous seriez voué à une mort certaine. L’énergie est utilisée de façon passive en très faible quantité pour faire fonctionner votre appareil et de façon active pour vous déplacer et régénérer votre bouclier par exemple. (tout comme la réserve d’oxygène la capacité en énergie du vaisseau lui permet de fonctionner relativement longtemps).  
__La vitesse__ d’un vaisseau dépendra de son moteur (et ses caractéristiques) et du type de vaisseau. (Des modules permettent d’étendre la vitesse max du vaisseau, son accélération…).  
__Le nombre de modules__ du vaisseau dépend principalement de sa taille (donc du type de vaisseau).  
#####_Modules_ :
Un vaisseau peu s’équiper de divers modules, toutes sortes de modules sont proposés par tous les marchands de base et certains sont à crafter vous même ou débloqué via votre progression dans le jeu.
Il y a différents types de modules : 
__Les modules d’amélioration__ : ces équipements sont des bonus qui on pour but de renforcer les caractéristiques de votre vaisseau.  
__Les modules de soutient__ : tels que les tourelles automatiques, les drones réparateurs  
__Les modules passifs__ : vous donnes différents bonus élémentaires  
#####_L’environnement_ :  
l’environnement dans lequel évolue le joueur est l’espace, l’univers, lequel est composé de diverses entités, comme d’autres vaisseaux, des astéroïdes et des objets que le joueur peut ramasser.  
La carte est généré en fonction de l'avancée du joueur. L’univers se découpes en zones généré de façon procédural bien que des éléments soient prédéfinit et statiques (comme les bases orbitales).   
#####_Les planètes_  
L’univers regorge de diverses planètes à explorer, celle-ci sont accessibles par tous les explorateurs inter-galactiques. ces explorations ne sont pas sans risques, mieux vaut être bien équipé avant d’y pénétrer.  
#####_Les Astéroïdes_    
les astéroïdes flottant dans l’espace peuvent être dangereux si votre vaisseau entre en collision avec eux, cela abîmera la coque de celui-ci et divisera l'astéroïde en deux parties, chaque astéroïde bouge de façon indépendante et libre dans l’univers, de la même façon si le joueur en détruit un il le divisera en un certain nombre de fragment et libérera éventuellement des bonus et matériaux.  
#####_Les Bonus Ponctuels_   
Des bonus sont récupérables sur la carte et boosteront une de vos statistique de façon temporaire. Ces bonus peuvent également être acheté auprès des marchands et utilisés depuis l’emplacement rapide.  
Le joueur peut obtenir les bonus suivants : __vitesse / puissance des armes / bouclier__...  
#####_Les Ennemis_    
D’autres vaisseaux plus ou moins puissant peuplent l’espace, il cherchent à détruire le joueur.
Ces vaisseaux sont du même type que le joueur, ils peuvent tout aussi bien être équiper de modules. Ils sont facilement reconnaissables et n’hésiteront pas à vous attaquer pour voler vos biens.
un vaisseaux ennemi détruit abandonnera peut-être des pièces d’équipements plus ou moins rares, ou d’autre items tout aussi précieux.  
#####_Les Neutres_  
Des vaisseaux neutre peuvent traverser votre zone, ces vaisseaux peuvent être :  
Des vaisseaux Marchands - Convois / marchands itinérants - pour vendre des bien ou proposer des quêtes annexes.  
Des vaisseaux mercenaires ou militaire qui peuvent vous proposer de l’aide contre de l’argent ou tout simplement continuer sans prêter attention à vous.    
Le cas particulier des mercenaires est qu’ils peuvent être recrutés pour vous aider un certain temps et ce jusqu’à épuisement du temps ou la destruction de leur vaisseau. Ces vaisseaux sont du même type que le joueur, ils peuvent tout aussi bien être équiper de modules.  
#####_Les Alliés_  
Des vaisseau peuvent aider à vous débarrasser de vos ennemis pendant certaines quêtes scénarisées. Ces vaisseaux sont invincibles et n’ont par conséquent pas de barre de vie.  
Ces vaisseaux sont du même type que le joueur, ils peuvent tout aussi bien être équiper de modules.  
#####_Les Stations Spatiales_  
Elles permettent la réparation du vaisseau, l’achat/ventes d’armes/composants    
Vous pouvez également acquérir un nouveau vaisseau dans les stations, les différents types de vaisseaux sont débloqués en fonction de votre progression et coûteront un montant d’or à l’achat.    
La taverne du voyageur Galactique est le lieu idéal pour vous reposer de vos aventures mais également l’endroit où il vous sera possible de recevoir des quêtes comme des contrats d’escorte, des mises à prix de pirates malfamés (contrats d’assassinat).   
Certains contrats “exotiques” sont faisable une fois uniquement et vous ferons gagner plus de points de contrat et des plans de craft uniques. elles mettent à prix la tête des plus vils des pirates donc ne vous attendez pas à venir à bout d’eux aussi facilement.  
#####_HeadHunter - Le clan des mercenaires qui ont du cran_  
Headhunter (chasseurs de tête en français) est une alliance de plusieurs mercenaires auquel vous adhéré au début du jeu. Plus vous réalisez de quête et plus vous remporterez de points de contrats qui vous feront monter en grade et vous donneront accès à un marchand unique qui dévoilera pour vous sa plus belle marchandise.  
#####_Les Warp Gates_  
L’Univers est immensément grand autant dire qu’accéder à des régions lointaine peut être long, même très long parfois c’est pourquoi des portails spaciaux (les Warp Gates) vous permettront de vous déplacer rapidement d’une zone à un autre instantanément.  
#####_Les avis de recherche_  
Si vous vous montrez malhonnêtes (détroussez d'honnêtes marchands) ou jouez au pirate vous aussi ne vous étonnez pas d’être vu comme une ordure de la part des vaisseaux neutres. Si votre réputation baisse, les marchands vous feront de moins en moins confiance et gonfleront leurs prix, de plus de moins en moins de contrats vous seront proposés - cependant - vos ennemis pourrait devenir vos nouveaux alliés, il vous faudra vous écarter de la zone car les autorité n’hésiteront pas à vous tirer à vue. Pour remonter votre réputation, l’anonymat reste la meilleure des solutions, vous pouvez également payer un intermédiaire qui fera effacer votre prime.  
Si vous choisissez de vivre la vie de bandit, vous aurez néanmoins accès à des stations orbitales qui proposeront d’autres types de services et contrats comme le détournement de convois par exemple.  
#####_Les Objets_   
En plus des objets bonus temporaires, d’autres objets sont disponibles à l’achat et utilisables par le joueur. Ces objets peuvent arborer l’un des types d’objet suivant :
#####__équipement du vaisseau__ : 
 __armes__ ( missiles / laser / projectiles )   
 __bouclier__ / drone ( arme ou réparation )  
 __utilisable__ (usage unique) : projectiles / power ups  
#####_La monnaie_ :  
La monnaie du jeu permet de commercer pour acheter/vendre des objets mais aussi de recruter des mercenaires et de réaliser bien d’autres actions.  
La monnaie a plus ou moins de valeur en fonction des lignes commerciales (Les marchands n’hésiteront pas à faire des baisses de prix pour les clients qui ont une bonne réputation. Les objets coûteront plus ou moins chère en fonction de leur niveau de rareté).  
Partir vers l’inconnu bien que ce soit risquer c’est aussi avoir plus de chances de trouver des objets rares au cours de phase d’explorations.  
#####_La Difficulté_ :
__Easy__ (Promenade céleste) : si vous mourrez, vous revenez simplement à la dernière sauvegarde.  
__Medium__ (Astronaute amateur) : si vous mourrez, vous revenez à la dernière sauvegarde avec une perte d’xp et d’argent..  
__Hard__ (Explorateur vétéran) : Si votre vaisseau venait à être détruit, celui-ci serait supprimé et vous n’aurez pas d’autres choix que d’en racheter un, vous perdez également de l’argent et de l’xp.  
__Epic__ (Courageux .. ou tout simplement fou ?) : vous mourrez définitivement : en clair, si votre vaisseau est détruit vous devrez recommencer le jeu depuis le début.  
#####_Les types de quêtes_ :  
_Escorte_ :
Parfois des convois vous demanderont de l’aide et être escorté dans des zones dangereuse.  
_Destruction_ :  
Les missions de destructions consiste en la destruction d’un ennemi ou d’un groupe d'ennemis ou encore à sécuriser une station spatiale par exemple.  
_Capture_ :  
La capture de zone peut être employé pour avoir accès à de nouvelles zones ( via des portes de warp ), de station spatiale, de villes orbitales.  
_Exploration_ :  
Certaines quêtes consistes juste à explorer des planètes pour y faire des relevés ou sécuriser ses alentours.
#####_Les touches_ :  
_mappage des touches par défaut_ :  
__En orbite__ :  
souris →  déplacer le curseur  
clique gauche →  sélectionner une option dans le menu  
echap → accéder au menu  
__En vaisseau__ :  
zqsd → se déplacer  
clique gauche →  tir principal  
clique droit → tir secondaire (skill ?)  
clique central → verrouiller un ennemi  
A : Utiliser l’objet en raccourcis  
é” - 23 → changer l’objet en raccourcis  
echap → accéder au menu  
E →  Interagir (vaisseau neutre)  
#####_Le Multijoueur_ :   
Pouvoir se connecter avec un ami.  
#####__Les Ester Eggs__  ( parce que c’est toujours important ) :  
_Halo_ :  
Un vaisseau appelé le Pillar of Autumn se balade dans la carte du jeu, le joueur pour parler avec lui, lui répondant des phrases en rapport avec l’univers de Halo :    
	“ Vous n’auriez pas vu un anneau de 30 000Km de diamètre ? “ // sources vérifiées :)  
_Le cas des Poneys_ :  
Un poney a une certaine chance de sortir d’un astéroïde brisé par un joueur.  

### **3. Productions graphiques**#

###### Concept Art #

> 2D Artist / Concept Artist - [Tero](http://teroratsu.deviantart.com/ "deviantArt")

early concept for Padmaster ![CA_01 PADMASTER](http://image.noelshack.com/fichiers/2015/13/1427321619-ca01-p.jpg)

Interface ![CA_02 PADMASTER](http://image.noelshack.com/fichiers/2015/14/1428100183-full-hd-x1-6-ca-01.jpg)

###### Ressources 2D #

Aucun contenu disponible - voir le dossier [ressources](https://github.com/teroratsu/Padmaster/tree/master/ressources) pour plus de contenu.




