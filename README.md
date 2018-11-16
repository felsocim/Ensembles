# Ensembles

Le but de cette bibliothèque est de fournir une simple représentation numérique des ensembles mathématiques et des opérations asociées telles que l'intersection, l'union mais aussi la composition, etc. Elle a été réalisée en tant que projet universitaire dans le cadre des cours de structures de données et algorithmes. Ce répertoire contient également des programmes de test capables de produire des fichiers de log permettant de vérifier les résultats.

## Compilation

Le fichier **Makefile** fourni permet la compilation sous Linux de la bibliothèque ainsi que des programmes de test mais aussi d'effectuer quelques tests de base tout en produisant des fichiers de log correspondants.

Pour compiler toute la bibliothèque ainsi que les programmes de test, exécutez la commande suivante :

`make all`

Pour effectuer un jeu de tests de base et produire des fichiers de log correspondants, exécutez :

`make log`

Vous retrouverez les fichiers de log produits dans le dossier **log** qui sera créé dans le répertoire racine.

## Utilisation de la bibliothèque

La documentation technique décrivant l'ensemble des fonctions fournies par la bibliothèque peut être générée à l'aide du logiciel **Doxygen**. Après l'installation de ce dernier via votre gestionnaire de paquets, lancez la commande suivante pour générer la version de la documentation la plus récente :

`doxygen Doxyfile`

## Auteur

* [**Marek Felsoci**](mailto:marek.felsoci@etu.unistra.fr) - [Cursus Master en Ingénierie : Informatique, systèmes et réseaux](http://cmi-informatique.unistra.fr/reseaux/) - [Université de Strasbourg](http://unistra.fr)

## Licence

Voir le fichier [LICENSE](LICENSE) dans la racine de ce répertoire.
