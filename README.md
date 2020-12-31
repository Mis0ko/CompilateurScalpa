# compilation
Informations au peuple :
le ; du end est mis seulement pour terminer les instructions d'une fonction
l'affectation d'une fonction et l'appel de fonction doit marcher sans pb (à voir avec vos tests)
le typage est aussi pris en compte pour l'affection d'une fonction et pour les types des arguments
le truc "param a ; param b" veut dire f(b,a) c'est inversé
call f,2 veut dire on appelle f avec les 2 paramètres précédents
j'ai modifié le print\_quad dans quad.c et rajouté un nouveau quad_type dans quad.h pour l'affectation avec des fonctions
les fonctions liés aux fonctions sont dans function.c et function.h, j'ai modifié des include aussi
le fichier test contient un exemple

/!\ les fonctions comme argument avec ref pas encore implémenté (éventuellement la flemme)
ex : function maxtab(ref f : int)
