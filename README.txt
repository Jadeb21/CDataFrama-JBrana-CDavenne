#CDataframe-brana-davenne-bn
Projet Algorithmique et structure de donnée 1 L1

#Contributeurs

*Brana Jade - groupe BN
*Davenne Clément - groupe BN

- Lien direct vers le dépôt Git de notre projet :

https://github.com/Jadeb21/CDataFrama-JBrana-CDavenne.git

- Idée principale de notre projet :

Le CDataframe que nous avons conçu à pour but de vous faciliter la manipulation de valeur.
En effet, avec nos multiples fonctionnalités présentés dans la partie "Fonctionnalités principales de notre application",
vous pouvez réaliser tout-un-tas de chose. Les fonctionnalités de notre projet son inspiré de la bibliothèque Pandas en Python.
Comme il n'exite pas d'équivalent en langage C, nous avons réalisé ce projet grâce à nos connaissances acquérit durant ce semestre.

- Fonctionnalités principales de notre application :

Vous pouvez choisir entre un CDataframe déjà rempli ou vide.
Ensuite vous pourrez choisir entre afficher tout le cdataframe, afficher certaine ligne ou bien certaine colonne du CDataframe
D'autres fonctionnalités existes comme l'ajout et la suppression de ligne ou de colonne.

- Instructions d'exécution de notre code :

Appuyer sur le bouton vert (run) en haut.
Un menu se déroule vous demandant si vous préférez un cdataframe vide à remplir après ou si vous préférez quelque chose de déjà rempli.
Ensuite nous vous avons concocter tout-un-tas de fonctionnalité à utilisé pour que vous puissiez faire ce que vous souhaitez.
- L'ajout d'une ligne (2) ou d'une colonne (1)
- La suppression d'une ligne (3) ou d'une colonne (4)
- Renommer une colonne (5)
- Afficher tout votre CDataFrame (6)
- Verifier l'existence d'une valeur (7)
- Afficher les premieres lignes (8) ou les premiere colonnes (9) que vous voulez
- Afficher la mémoire de votre cdataframe (10)
- Acceder à une valeur en tappant sa ligne et sa colonne, puis changer cette valeur à la position donnée (11)
- Comparaison à partir d'une valeur donnée, savoir combien de valeur son supérieur, égales ou inférieurs à celle-ci dans votre cdataframe (12)
- Renvoyer le nom de toutes les colonnes presentes dans votre cdataframe (13)
- Quitter votre cdataframe (14)

Des consignes lors de l'exécution sont donnée mais pour ceux qui ne veulent pas les respecter, des saisies sécurisés ont été mises en place.
Vous pouvez remplir en dur en vous referant à la fonction hardware_cdataframe présente dans le fichier (CDataframe.c) cela sécurisera vos saisies de titre (regarder erreur du projet, en bas de la page).
Merci de bien mettre la console en pleine écran si vous voulez voire les résultats s'afficher (car comme le menu est assez conséquent, il cache le reste).

-Erreur du projet :

Pour la 8 (et 9), si vous dépassez le nombre de ligne (colonne), le programme s'arrete (s'il n'y a pas plus de 5 lignes, ne mettez pas 6)
Pour la 5, si vous avez ajouter une colonne juste avant (1) , son nom prendra celui que vous venez d'entrer aussi

-Difficultés :

Tout d'abord, nous n'avons pas bien compris le sujet et avons du recommencer toute la partie CDataframe.c.
A cause de cette erreur nous n'avons pas pu avancer beaucoup dans le projet.
La partie la plus dur du projet était justement le cdataframe.