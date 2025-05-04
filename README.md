<img src="git_utils/banner.png" width= 100%>

<br>

---

<br>

<details>
<summary>FRENCH VERSION</summary>

## Exercice 00 - Conversion of scalar types

<details>
  <summary>Afficher/Masquer</summary>

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

</details>

<br>

---

<br>

## Exercice 01 : Serialization

<details>
  <summary>Afficher/Masquer</summary>

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

</details>

<br>

---

<br>

## Exercice 02 : Identifier le type réel

<details>
  <summary>Afficher/Masquer</summary>

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

</details>

<br>

</details>

<br>

---

<br>

<details>
<summary>ENGLISH VERSION</summary>

## Exercise 00 - Conversion of scalar types

<details>
	<summary>Show/Hide</summary>

### Objective:
Develop a `ScalarConverter` class capable of converting a string representing a literal value in C++ (char, int, float, double) into these different scalar types. This class must not be instantiable.

### Features:
- The class contains a static method `convert` that takes a string representing a literal value and displays its conversion to char, int, float, and double.
- Conversions must handle special cases such as non-displayable characters, overflows, and special values (-inf, +inf, nan).

### Constraints:
- Use only decimal notation except for characters.
- Handle pseudo-literals `-inff`, `+inff`, `nanf` for floats and `-inf`, `+inf`, `nan` for doubles.
- Display an informative message when a conversion is not possible.

### Implementation:

[Link here](https://github.com/aceyzz/CPP06/tree/main/ex00)

### `ScalarConverter` Class:
This class is designed to be non-instantiable by users, as it serves only to convert literal values into different scalar types. It includes a series of private static methods to identify the type of the input value and perform the necessary conversions.

- **`convert` Method**: 
	The main method that directs the conversion based on the detected type of the input string. It calls the appropriate methods to convert the value to char, int, float, and double.

- **Type Detection**:
	- `isChar`, `isInt`, `isFloat`, `isDouble`, `isOther`: These methods determine the type of the input string by examining its syntax.

- **Conversion to Specific Types**:
	- `toChar`: Converts the value to char if possible; displays a message if the character is non-displayable or if the conversion is impossible.
	- `toInt`: Converts the value to int, handling cases where the conversion is nonsensical or impossible.
	- `toFloat`: Handles conversions to float, including managing special values like `nanf`, `+inff`, and `-inff`.
	- `toDouble`: Converts the value to double, with special attention to values like `nan`, `+inf`, and `-inf`.
	- `toOther`: Handles conversions for strings representing special values that do not directly correspond to the previous types.

### Handling Limits and Special Values:
The conversion methods account for data type limits to avoid overflows and handle special values according to C++ specifications.

### Usage:
The class can be used to convert any string representing a C++ literal into char, int, float, and double types, displaying results or appropriate error messages for each type of conversion.

### Program Testing:
The `main.cpp` file demonstrates the use of `ScalarConverter` by converting command-line arguments and displaying the results. This test covers various cases, including standard literals, non-displayable characters, and special values.

This conversion system is an example of applying type conversion principles in C++, enabling flexible and precise manipulation of scalar types from textual representations.

</details>

<br>

---

<br>

## Exercise 01: Serialization

<details>
	<summary>Show/Hide</summary>

Implement a `Serializer` class that cannot be initialized by the user in any way. This class must contain the following static methods:

- **`uintptr_t serialize(Data* ptr);`**
This method takes a pointer as an argument and converts it into an unsigned integer of type `uintptr_t`.

- `Data* deserialize(uintptr_t raw);`
This method takes an unsigned integer parameter and converts it into a pointer to `Data`.

Write a program to test that your class works as expected. You must create a non-empty `Data` structure, i.e., containing data members.

Use `serialize()` on the address of the `Data` object and pass its return value to `deserialize()`. Then ensure that the return value of `deserialize()` is equal to the original pointer.

Don't forget to provide the files for your `Data` structure.

### Implementation

[Link here](https://github.com/aceyzz/CPP06/tree/main/ex01)

- `Data.hpp`
This file defines a `Data` structure containing two data members: a string (`std::string valStr`) and an integer (`int valInt`). This structure is used for serialization and deserialization.

- `Serializer.hpp`
This file defines the `Serializer` class, which contains two static methods (`serialize` and `deserialize`) that respectively convert a pointer to `Data` into an unsigned integer of type `uintptr_t` and vice versa. This class is designed to be non-instantiable, as indicated by the private constructor, copy constructor, assignment operator, and destructor, all defined but not publicly implemented.

- `Serializer.cpp`
This file implements the `serialize` and `deserialize` methods of the `Serializer` class. The `serialize` method uses `reinterpret_cast` to convert the pointer to `Data` into `uintptr_t`, while `deserialize` performs the reverse operation to convert a `uintptr_t` into a pointer to `Data`.

The program initializes `Data` objects, serializes and deserializes them using the `Serializer` class, and displays the results to verify that the process works as expected. The program also uses color macros defined in `colors.hpp` to enhance output visibility.

</details>

<br>

---

<br>

## Exercise 02: Identify the real type

<details>
	<summary>Show/Hide</summary>

Implement a base class `Base` that contains only a public virtual destructor. Create three empty classes `A`, `B`, and `C`, which publicly inherit from `Base`. These four classes are not required to follow the Orthodox Canonical Form.

### Objective:

- Implement the function `Base* generate(void);` which randomly instantiates `A`, `B`, or `C` and returns the instance as a `Base` pointer. Use any method of your choice for randomization.
- Implement `void identify(Base* p);` which prints the real type of the object pointed to by `p`: `"A"`, `"B"`, or `"C"`.
- Implement `void identify(Base& p);` which prints the real type of the object referenced by `p`: `"A"`, `"B"`, or `"C"`. Using a pointer in this function is prohibited.
- The inclusion of the `typeinfo` header is prohibited.
- Write a program to test that everything works as expected.

### dynamic_cast:

- `dynamic_cast` is used to determine the real type of an object pointed to by a pointer or referenced by a reference to a polymorphic base class (i.e., a class with at least one virtual member function, like our `Base` class with its virtual destructor).
- When `dynamic_cast` is used with a pointer, it returns a pointer to the target type if the object is indeed of that type or a derived type; otherwise, it returns a null pointer.
- When `dynamic_cast` is used with a reference, it throws a `std::bad_cast` exception if the cast fails.
- It is a safe way to perform type conversions when working with inheritance, ensuring that the type being cast to is indeed the type of the object.

### Implementation:

[Link here](https://github.com/aceyzz/CPP06/tree/main/ex02)

- The definition of the `Base` class with a public virtual destructor.
- The definitions of the `A`, `B`, and `C` classes inheriting from `Base`.
- The implementations of the `generate`, `identify(Base* p)`, and `identify(Base& p)` functions using `dynamic_cast` to identify the real type of objects.
- A test program illustrating the random creation of instances of `A`, `B`, or `C`, and the identification of their real type.

</details>

<br>

</details>