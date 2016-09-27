# efrei-c-tp2
//-----------Pour l'utilisation--------------------//

Modifier les variables fileFilm, filePersonne, fileData dans fonctions.c pour correspondre au chemin absolu des fichiers du projet.



//---------------------Enoncé---------------------//
TP-2 : Les pointeurs, fonctions et structures

Les bases de données sont des moyens de stocker de nombreuses informations qui sont en relation les unes avec les autres. Pour créer une base de données, il est très souvent nécessaire d'identifier les différents objets qui seront modélisés et stockés, pour éviter de stocker des informations de manière redondante. Nous allons simuler une petite base de données cinématographique contenant des films.
Découpage et organisation des données :
+ Pour chaque film, il faudra stocker :
•	Son titre
•	Son année de sortie
•	Son réalisateur
•	Ses acteurs principaux (de 1 à 3)
•	Sa durée en minutes
•	Un genre, parmi : Action, Horreur, Comédie, Documentaire, Policier, Drame, Animation, Science-Fiction (un film a au maximum 1 genre)

+ Pour chaque réalisateur et chaque acteur, il faudra stocker :
•	Son nom
•	Son prénom
•	Sa date de naissance
•	Sa nationalité
Une telle base de données peut être interrogée ou traitée par ce que l'on appelle des requêtes. Par exemple, on peut demander à afficher tous les éléments d'un film, à créer ou supprimer un film, à modifier certaines informations.
Une opération classique consiste, par exemple, à établir toute la filmographie d'un acteur ou d'un réalisateur. Pour cela, est-il nécessaire de stocker, pour chaque réalisateur ou acteur, l'ensemble des films associés ?
De la même manière, un réalisateur ou acteur a souvent plusieurs films à son actif. Par exemple, David Fincher (né le10 mai 1962 à Denver, aux USA) a réalise Fight Club, Seven et The Game, entre autres. Est-il nécessaire, pour chacun des films cités, de stocker à chaque fois ces informations sur le réalisateur ? Comment pourrait-on éviter de dupliquer ces informations ?
Définissez les types : film, acteur, réalisateur.
Ecrivez les définitions de 3 tableaux : un comportant des films, un comportant les réalisateurs, un comportant les acteurs.
Ecrire les fonctions suivantes :
Affichage des informations relatives à tous les films
exemple de résultat demandé :
Fiche FILM
Fight Club (1999)
Réalisateur : David Fincher
Acteurs : Brad Pitt, Edward Norton, Helena Bonham Carter
Durée : 2h15
Genre : Action

Affichage de la liste de tous les réalisateurs
Exemple de résultat demandé
Fiche REALISATEUR
Nom : David Fincher
Date de naissance : 10 mai 1962
Nationalité : américaine

Recherche d'un film par son titre, et affichage si le film existe

Travail demandé :
-  utiliser les structures de données adéquates pour la réalisation de votre projet
-  donner les prototypes de toutes vos fonctions
-  implémenter les fonctions nécessaires pour avoir un lancement de votre application sous forme de menu : lister les films, lister les réalisateurs, rechercher un film par titre, quitter.
 
Bonus :
-  penser à utiliser des fichiers texte ou autre format de base de données pour stocker toutes vos données sur disque
-  penser à utiliser une interface console ou graphique conviviale
Livrable :
-  vous pouvez vous mettre en trinôme au maximum
-  votre rendu doit comporter au moins 3 fichiers : fonctions.h, fonctions.c et Main.c
-  le code source est à rendre avant lundi 26 septembre 9h00 en format compressé
