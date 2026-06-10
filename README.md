# TurnStrat

TurnStrat est un projet C++ simulant un jeu de stratégie au tour par tour sur un plateau. Les joueurs contrôlent différentes unités possédant leurs propres caractéristiques et peuvent les déplacer ou les faire combattre.

## Fonctionnalités

- Gestion d'un plateau de jeu.
- Création et gestion de plusieurs unités.
- Déplacement des unités.
- Système d'attaque entre unités.
- Affichage de l'état du plateau.
- Architecture orientée objet.

## Structure du projet

```text
TurnStrat/
├── include/
│   ├── Partie.h
│   ├── Soldat.h
│   ├── Templier.h
│   └── ...
├── src/
├── main.cpp
└── README.md
```

## Classes principales

### Partie

La classe `Partie` gère :

- Le plateau de jeu.
- L'ajout des unités.
- Les déplacements.
- Les combats.
- L'affichage de l'état de la partie.

### Soldat

Unité de base disposant de caractéristiques telles que :

- Points de vie
- Force d'attaque
- Nom

### Templier

Unité spécialisée héritant du comportement de base tout en possédant des caractéristiques propres.

## Exemple d'utilisation

```cpp
Partie partie1;

Soldat* ryan = new Soldat(5, 4, "Ryan");
Templier* jade = new Templier(6, 7, "Jade");

partie1.ajouter_piece(ryan);
partie1.ajouter_piece(jade);

partie1.afficher();

partie1.se_deplacer(ryan, -1, 0);

partie1.attaquer_piece(jade, ryan);

partie1.afficher();
```

## Compilation

### Avec g++

```bash
g++ main.cpp src/*.cpp -Iinclude -o TurnStrat
```

### Exécution

```bash
./TurnStrat
```

## Objectifs pédagogiques

Ce projet a été réalisé afin de pratiquer :

- La programmation orientée objet en C++.
- L'héritage et le polymorphisme.
- La gestion dynamique de la mémoire.
- La modélisation d'un jeu de stratégie.
- L'organisation d'un projet C++ en plusieurs fichiers.

## Améliorations futures

- Ajout de nouvelles classes d'unités.
- Gestion de plusieurs joueurs.
- Système de tours complet.
- Interface graphique.
- Sauvegarde et chargement des parties.

## Auteur

Rayane BIO

---
Projet développé en C++ dans un objectif d'apprentissage de la programmation orientée objet.
