# wordle_tefy_luciano


##  Description

Ce projet consiste à réaliser un **solver du jeu Wordle** en langage C.
Le programme permet de charger une liste de mots et d’appliquer différents **filtres** afin de réduire les possibilités et trouver le mot solution.

---

##  Structure du projet

```
wordle_solver/
│
├── bin/
│   └── wordle_solver        
│
├── include/
│   └── filtre.h             
│
├── src/
│   ├── main.c               
│   └── filtre.c             
│
├── ressource/
│   └── bdd_wordle.txt       
│
└── README.md
```

##  Instructions

 Cloner le projet :

```bash
git clone https://github.com/tefy0/wordle_tefy_luciano.git
```

---

##  Exécution

```bash
./bin/wordle_solver
```

---
##  Fonctionnalités

Le programme permet :

* Charger les mots depuis un fichier (bdd_wordle.txt)
* Filtrer les mots contenant une lettre
* Filtrer les mots ne contenant pas une lettre
* Rechercher des mots contenant une sous-chaîne

---

##  Auteurs

 Tefy(propriétaire du dépôt)
 Luciano(Collaborateur)
