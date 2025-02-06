# DM Réseaux : Calcul et Manipulation des Adresses IP

## Présentation
Ce projet a pour but de manipuler les adresses IP et les masques de sous-réseau en langage C. À travers différentes parties, nous allons permettre à l'utilisateur de saisir, convertir et calculer des informations essentielles sur les adresses réseau.

## Contenu du DM

### Partie 1 : Saisie et conversion d'une adresse IP
- Saisie d'une adresse IP au format `xxx.xxx.xxx.xxx`
- Conversion en un entier 32 bits
- Validation de la saisie

### Partie 2 : Saisie et validation d'un masque de sous-réseau
- Saisie d'un masque réseau au format `xxx.xxx.xxx.xxx`
- Vérification de sa validité
- Conversion en un entier 32 bits

### Partie 3 : Calcul de l'adresse réseau
- Application d'un `ET` logique entre l'adresse IP et le masque de sous-réseau
- Affichage du résultat sous la forme `xxx.xxx.xxx.xxx`

### Partie 4 : Calcul de l'adresse de broadcast
- Application d'un `OU` logique entre l'adresse réseau et le complément du masque de sous-réseau
- Affichage du résultat

### Partie 5 : Calcul de la notation CIDR (PAS FAIT)
- Comptage du nombre de bits à `1` dans le masque de sous-réseau
- Conversion en notation `/xx`

### Partie 6 : Intégration et affichage des résultats (PAS FAIT)
- Intégration de toutes les fonctions dans un programme principal
- Tests avec différentes adresses IP et masques

## Compilation et exécution
Un `Makefile` est fourni pour simplifier la compilation.
```bash
make partie1   # Compile la partie 1
./partie1      # Exécute le programme

make partie2   # Compile la partie 2
./partie2      # Exécute le programme

make partie3   # Compile la partie 3
./partie3      # Exécute le programme

make partie4   # Compile la partie 4
./partie4      # Exécute le programme
```

## Conclusion
Ce projet permet de mieux comprendre le fonctionnement des réseaux IP et d'améliorer ses compétences en programmation C en manipulant les adresses et masques de sous-réseau.

📌 **Objectif :** Fournir un outil fonctionnel et didactique pour l'apprentissage du réseau ! 🚀
