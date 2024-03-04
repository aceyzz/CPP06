<img src="utils/CPP06.png" width= 100%>

## Exercice 00 - Conversion of scalar types

### Objectif :
Développer une classe `ScalarConverter` capable de convertir une chaîne de caractères représentant littéralement une valeur en C++ (char, int, float, double) vers ces différents types scalaires. Cette classe ne doit pas être instanciable.

### Fonctionnalités :
- La classe contient une méthode statique `convert` qui prend une chaîne représentant une valeur littérale et affiche sa conversion en char, int, float, et double.
- Les conversions doivent gérer les cas particuliers tels que les caractères non affichables, les overflows, et les valeurs spéciales (-inf, +inf, nan).

### Contraintes :
- Utiliser uniquement la notation décimale sauf pour les caractères.
- Gérer les pseudo littéraux `-inff`, `+inff`, `nanf` pour les floats et `-inf`, `+inf`, `nan` pour les doubles.
- Afficher un message informatif lorsqu'une conversion n'est pas possible.

### Implémentation :

[Lien ici](https://github.com/aceyzz/CPP06/tree/main/ex00)

### Classe `ScalarConverter` :
Cette classe est conçue pour ne pas être instanciable par les utilisateurs, car elle sert uniquement à convertir des valeurs littérales en différents types scalaires. Elle comprend une série de méthodes statiques privées pour identifier le type de la valeur d'entrée et effectuer les conversions nécessaires.

- **Méthode `convert`** : 
  La méthode principale qui dirige la conversion en fonction du type détecté de la chaîne d'entrée. Elle appelle les méthodes appropriées pour convertir la valeur en char, int, float, et double.

- **Détection de Type** :
  - `isChar`, `isInt`, `isFloat`, `isDouble`, `isOther` : Ces méthodes déterminent le type de la chaîne d'entrée en examinant sa syntaxe.

- **Conversion vers Types Spécifiques** :
  - `toChar` : Convertit la valeur en char si possible; affiche un message si le caractère n'est pas affichable ou si la conversion est impossible.
  - `toInt` : Convertit la valeur en int, en gérant les cas où la conversion n'est pas sensée ou possible.
  - `toFloat` : Traite les conversions vers float, y compris la gestion des valeurs spéciales comme `nanf`, `+inff`, et `-inff`.
  - `toDouble` : Convertit la valeur en double, avec une attention particulière aux valeurs spéciales `nan`, `+inf`, et `-inf`.
  - `toOther` : Gère les conversions pour des chaînes représentant des valeurs spéciales qui ne correspondent pas directement aux types précédents.

### Gestion des Limites et Valeurs Spéciales :
Les méthodes de conversion prennent en compte les limites des types de données pour éviter les débordements et traitent les valeurs spéciales conformément aux spécifications du C++.

### Utilisation :
La classe peut être utilisée pour convertir n'importe quelle chaîne représentant un littéral en C++ vers les types char, int, float et double, affichant les résultats ou des messages d'erreur appropriés pour chaque type de conversion.

### Test du Programme :
Le fichier `main.cpp` démontre l'utilisation de `ScalarConverter` en convertissant des arguments de ligne de commande et en affichant les résultats. Ce test couvre divers cas, y compris les littéraux standards, les caractères non affichables, et les valeurs spéciales.

Ce système de conversion est un exemple de l'application des principes de conversion de type en C++, permettant une manipulation flexible et précise des types scalaires à partir de représentations textuelles.

<br>

---

<br>

## Exercice 01 : Serialization

Implémentez une classe `Serializer` qui ne peut pas être initialisée par l'utilisateur de quelque manière que ce soit. Cette classe doit contenir les méthodes statiques suivantes :

- **`uintptr_t serialize(Data* ptr);`**
Cette méthode prend en argument un pointeur et le convertit en un entier non signé de type `uintptr_t`.

- `Data* deserialize(uintptr_t raw);`
Cette méthode prend un paramètre entier non signé et le convertit en un pointeur vers `Data`.

Rédigez un programme pour tester que votre classe fonctionne comme prévu. Vous devez créer une structure `Data` non vide, c'est-à-dire contenant des membres de données.

Utilisez `serialize()` sur l'adresse de l'objet `Data` et passez sa valeur de retour à `deserialize()`. Assurez-vous ensuite que la valeur de retour de `deserialize()` est égale au pointeur original.

N'oubliez pas de fournir les fichiers de votre structure `Data`.


### Implémentation

[Lien ici](https://github.com/aceyzz/CPP06/tree/main/ex01)

- `Data.hpp`
Ce fichier définit une structure `Data` contenant deux membres de données : une chaîne de caractères (`std::string valStr`) et un entier (`int valInt`). Cette structure est utilisée pour la sérialisation et la désérialisation.

- `Serializer.hpp`
Ce fichier définit la classe `Serializer`, qui contient deux méthodes statiques (`serialize` et `deserialize`) permettant respectivement de convertir un pointeur vers `Data` en un entier non signé de type `uintptr_t` et inversement. Cette classe est conçue pour ne pas être instanciable, comme indiqué par le constructeur privé, le constructeur de copie, l'opérateur d'affectation et le destructeur, tous définis mais non implémentés publiquement.

- `Serializer.cpp`
Ce fichier implémente les méthodes `serialize` et `deserialize` de la classe `Serializer`. La méthode `serialize` utilise `reinterpret_cast` pour convertir le pointeur vers `Data` en `uintptr_t`, tandis que `deserialize` effectue l'opération inverse pour convertir un `uintptr_t` en pointeur vers `Data`.

Le programme initialise des objets `Data`, les sérialise et les désérialise en utilisant la classe `Serializer`, et affiche les résultats pour vérifier que le processus fonctionne comme attendu. Le programme utilise également les macros de couleur définies dans colors.hpp pour améliorer la visibilité de la sortie.

<br>

---

<br>

## Exercice 02 : Identifier le type réel

Implémentez une classe de base `Base` qui ne contient qu'un destructeur virtuel public. Créez trois classes vides `A`, `B`, et `C`, qui héritent publiquement de `Base`. Ces quatre classes ne sont pas obligées de suivre la Forme Canonique Orthodoxe.

### Objectif :

- Implémenter la fonction `Base* generate(void);` qui instancie aléatoirement `A`, `B`, ou `C` et retourne l'instance sous forme de pointeur de `Base`. Utilisez la méthode de votre choix pour l'implémentation aléatoire.
- Implémenter `void identify(Base* p);` qui imprime le type réel de l'objet pointé par `p` : `"A"`, `"B"`, ou `"C"`.
- Implémenter `void identify(Base& p);` qui imprime le type réel de l'objet référencé par `p` : `"A"`, `"B"`, ou `"C"`. L'utilisation d'un pointeur dans cette fonction est interdite.
- L'inclusion de l'en-tête `typeinfo` est interdite.
- Écrire un programme pour tester que tout fonctionne comme prévu.

### dynamic_cast :

- `dynamic_cast` est utilisé pour déterminer le type réel d'un objet pointé par un pointeur ou référencé par une référence à une classe de base polymorphique (c'est-à-dire une classe avec au moins une fonction membre virtuelle, comme notre classe `Base` avec son destructeur virtuel).
- Quand `dynamic_cast` est utilisé avec un pointeur, il retourne un pointeur vers le type cible si l'objet est effectivement de ce type ou un type dérivé, sinon il retourne un pointeur nul.
- Quand `dynamic_cast` est utilisé avec une référence, il lève une exception de type `std::bad_cast` si le cast échoue.
- C'est une manière sûre de conversion de types lorsqu'on travaille avec l'héritage, permettant d'assurer que le type vers lequel on cast est bien le type de l'objet.

### Implémentation :

[Lien ici](https://github.com/aceyzz/CPP06/tree/main/ex02)

- La définition de la classe `Base` avec un destructeur virtuel public.
- Les définitions des classes `A`, `B`, et `C` héritant de `Base`.
- Les implémentations des fonctions `generate`, `identify(Base* p)`, et `identify(Base& p)` utilisant `dynamic_cast` pour identifier le type réel des objets.
- Un programme de test illustrant la création aléatoire d'instances de `A`, `B`, ou `C`, et l'identification de leur type réel.

<br>

---
