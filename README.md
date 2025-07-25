# Projet Client-Serveur de Gestion de Formes Géométriques 2D

## Présentation Générale

Le projet consiste en la création d'une application dédiée à la gestion de formes géométriques 2D. L'application se divise en deux parties : un client développé en C++ et un serveur en Java. Son objectif principal est de permettre l'application de diverses transformations sur les formes, telles que l'homothétie, la translation et la rotation.

Le serveur prend en charge le rendu graphique des formes, tandis que le client se charge de la sauvegarde et du chargement des données depuis un fichier. Par ailleurs, une documentation technique détaillée est fournie pour chaque composant, avec Doxygen pour la partie C++ et Javadoc pour la partie Java.

Dans le cadre de ce projet, nous avons intégré plusieurs design patterns étudiés en cours, afin de garantir une interface utilisateur intuitive tout en offrant des outils extensibles et sécurisés.

## Mode d’emploi

Le fonctionnement de l'application repose sur l'interaction fluide entre l'utilisateur, le client et le serveur.

- L'utilisateur commence par spécifier la forme géométrique qu'il souhaite créer, ainsi que ses caractéristiques.
- Le client établit une connexion avec le serveur Java afin de transmettre les détails de la forme.
- Le serveur, en écoute continue et multi-threadé, traite les requêtes simultanément.
- Une fois la requête reçue et validée, le serveur crée la forme et l’affiche dans une fenêtre graphique.
- Si les informations sont invalides, une erreur est renvoyée et la connexion est fermée.
- Le client ferme ensuite la connexion de manière sécurisée.

## Les Formes

Les formes sont modélisées par une classe abstraite. Elles peuvent être :

- **Élémentaires** : cercle, triangle, segment.
- **Complexes** : groupe de formes, qui hérite de la classe de base.

Chaque forme a une **couleur**, des **attributs spécifiques**, et peut subir des **transformations** :

- **Homothétie** : redimensionnement par un facteur d’échelle.
- **Translation** : déplacement d’une position à une autre.
- **Rotation** : rotation autour d’un point (souvent le centre).

Les contraintes sont :

- Une forme ne peut appartenir à plusieurs groupes.
- Aucune superposition n’est autorisée entre formes.

## Le Client C++

Le client C++ gère :

- La création et l'envoi de requêtes vers le serveur Java.
- La sauvegarde et le chargement des formes.

### Protocole de Communication

- Utilisation d’un **Singleton** pour la connexion (pattern `getInstance()`).
- Envoi de requêtes textuelles normalisées.
- Réinitialisation du socket à chaque requête.

### Sauvegarde de Formes

Les données sont sauvegardées dans un fichier `.txt` avec une structure lisible :

```
Cercle: center (x, y, color), radius r, color: ...
Triangle: (x1, y1, color), (x2, y2, color), (x3, y3, color), color: ...
Segment: (x1, y1, color) to (x2, y2, color), color: ...
Polygone: (x1, y1, color) ... nbPoints ..., color: ...
```

Utilisation du **design pattern Visiteur** pour la sérialisation.

### Chargement

Le fichier texte est lu et chaque ligne est analysée pour recréer les objets de formes correspondants.

## Le Serveur Java

Le serveur Java est responsable du **rendu graphique** et de la **gestion des requêtes**.

- Basé sur une **architecture multi-thread** pour la gestion de connexions simultanées.
- Analyse des chaînes de requêtes selon des conventions définies.
- Utilisation de `java.awt.*` pour le dessin graphique.

### Design Pattern : Chain of Responsibility

Permet d’ajouter de nouvelles formes sans modifier les autres gestionnaires.

## Design Patterns Utilisés

- **Singleton** (Client C++) : pour la connexion unique.
- **Visiteur** (Client C++) : pour la sauvegarde des formes dans un fichier texte.
- **Chain of Responsibility** (Serveur Java) : pour la gestion flexible des formes.

---

**Note :** Une documentation Doxygen (C++) et Javadoc (Java) est disponible pour plus de détails techniques.
