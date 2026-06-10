## 📖 À propos

**TurnStrat** est un projet éducatif en C++ qui simule un jeu de stratégie au tour par tour sur un plateau. Les joueurs contrôlent différentes unités ayant chacune leurs propres caractéristiques et peuvent les déplacer, les faire combattre et gérer les dynamiques du jeu.

Ce projet démontre les principes fondamentaux de la **programmation orientée objet** en C++.

---

## ✨ Fonctionnalités

- ✅ Gestion complète d'un plateau de jeu
- ✅ Création et gestion de plusieurs unités (Soldats, Templiers, etc.)
- ✅ Système de déplacement avec gestion de grille
- ✅ Système de combat dynamique entre unités
- ✅ Affichage en temps réel de l'état du plateau
- ✅ Architecture orientée objet complète
- ✅ Gestion dynamique de la mémoire

---

## 🏗️ Architecture

### Structure du projet

```
TurnStrat/
├── include/                 # En-têtes C++
│   ├── Partie.h            # Classe principale du jeu
│   ├── Soldat.h            # Classe de l'unité Soldat
│   ├── Templier.h          # Classe de l'unité Templier
│   └── ...
├── src/                     # Fichiers d'implémentation
├── main.cpp                 # Point d'entrée de l'application
├── TurnStrat.cbp           # Configuration Code::Blocks
└── README.md               # Cette documentation
```

### Classes principales

#### 🎮 **Partie**
Gère l'ensemble de la logique du jeu :
- Gestion du plateau de jeu
- Ajout et suppression d'unités
- Déplacement des unités
- Système de combat
- Affichage et mise à jour de l'état du jeu

**Méthodes clés:**
- `ajouter_piece()` - Ajoute une unité au plateau
- `se_deplacer()` - Déplace une unité sur le plateau
- `attaquer_piece()` - Lance une attaque entre deux unités
- `afficher()` - Affiche l'état actuel du plateau

#### ⚔️ **Soldat**
Unité de base avec caractéristiques :
- **Points de vie (PV)** : Santé de l'unité
- **Force d'attaque** : Dégâts infligés lors d'une attaque
- **Nom** : Identifiant unique de l'unité

#### 🛡️ **Templier**
Unité spécialisée héritant de Soldat avec :
- Ses propres statistiques (généralement plus fortes)
- Comportement adapté au combat

---

## 🚀 Installation et Compilation

### Prérequis

- **GCC/G++** (recommandé) ou tout compilateur C++11 compatible
- **Make** (optionnel)
- **Code::Blocks** (optionnel, voir `TurnStrat.cbp`)

### Compiler avec g++

```bash
g++ main.cpp src/*.cpp -Iinclude -o TurnStrat
```

### Compiler avec gcc

```bash
gcc main.cpp src/*.c -Iinclude -o TurnStrat
```

### Exécuter le programme

```bash
./TurnStrat
```

---

## 📝 Exemple d'utilisation

```cpp
#include "include/Partie.h"
#include "include/Soldat.h"
#include "include/Templier.h"

int main()
{
    // Créer une partie
    Partie partie1;

    // Créer des unités
    Soldat* ryan = new Soldat(5, 4, "Ryan");           // PV=5, Force=4
    Templier* jade = new Templier(6, 7, "Jade");       // PV=6, Force=7
    Soldat* gard = new Soldat(4, 5, "Gard");
    Templier* yame = new Templier(7, 8, "Yame");

    // Ajouter les unités au plateau
    partie1.ajouter_piece(ryan);
    partie1.ajouter_piece(jade);
    partie1.ajouter_piece(gard);
    partie1.ajouter_piece(yame);

    // Afficher l'état initial
    std::cout << "État initial :" << std::endl;
    partie1.afficher();

    // Déplacer les unités
    partie1.se_deplacer(ryan, -1, 0);
    partie1.se_deplacer(jade, -1, 0);

    std::cout << "\nAprès déplacement :" << std::endl;
    partie1.afficher();

    // Engager le combat
    partie1.attaquer_piece(gard, ryan);

    std::cout << "\nAprès combat :" << std::endl;
    partie1.afficher();

    return 0;
}
```

---

## 🎯 Objectifs pédagogiques

Ce projet a été conçu pour pratiquer :

- 📚 Programmation Orientée Objet (POO) en C++
- 🔗 Héritage et polymorphisme
- 💾 Gestion dynamique de la mémoire (new/delete)
- 🎨 Modélisation d'un système de jeu
- 📁 Organisation modulaire d'un projet C++
- 🎮 Simulation d'une logique de jeu de stratégie

---

## 🔮 Améliorations futures

- [ ] Ajouter de nouvelles classes d'unités (Archer, Mage, etc.)
- [ ] Gestion de plusieurs joueurs avec tours alternés
- [ ] Système de tours complet avec chronomètre
- [ ] Interface graphique (SDL2, SFML, etc.)
- [ ] Sauvegarde et chargement des parties (fichiers JSON/CSV)
- [ ] Système de statistiques et progression
- [ ] Terrain avec différents types de cases (herbe, montagne, eau)
- [ ] Compétences spéciales par unité

---

## 📋 Prérequis de compilation

| Élément | Version |
|---------|---------|
| C++ | C++11 ou supérieur |
| Compilateur | GCC 5.0+ ou Clang 3.3+ |
| OS | Linux, Windows (MinGW), macOS |

---

## 📖 Documentation du code

Les fichiers d'en-tête contiennent des commentaires détaillés pour chaque classe et méthode.

Pour consulter la documentation complète, consultez les fichiers dans `include/`.

---

## 🤝 Contribution

Les contributions sont bienvenues ! N'hésitez pas à :
- Signaler des bugs
- Proposer des améliorations
- Soumettre des pull requests

---

## 📄 Licence

Ce projet est libre d'utilisation à des fins éducatives.

---

## 👨‍💻 Auteur

**Rayane BIO**
- GitHub: [@RAYANEBIO](https://github.com/RAYANEBIO)

---

## 📞 Support

Pour toute question ou problème, veuillez :
1. Consulter les issues existantes
2. Créer une nouvelle issue avec une description détaillée
3. Inclure le message d'erreur et votre environnement
