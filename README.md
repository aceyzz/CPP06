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

## Implémentation :

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

