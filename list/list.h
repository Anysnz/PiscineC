#ifndef __LIST__H__
#define __LIST__H__
#include <stddef.h>

struct list
{
    int data;
    struct list *next;
};

struct list *list_add(struct list *l, int e);

/* Cette fonction ajoute l'élément e devant la liste l et renvoie la tête de la
 * liste après l'insertion. Si une erreur se produit, vous devez renvoyer l tel
 * qu'il était lorsque votre fonction a été appelée. */

void list_print(struct list *l);

/* Cette fonction imprime chaque élément de la liste l, chacun séparé du
précédent par un espace, suivi d'un saut de ligne. Vous devez imprimer un saut
de ligne s'il n'y a aucun élément dans la liste. */

struct list *list_find(struct list *l, int e);

/*Cette fonction renvoie un pointeur vers le premier lien qui contient l'élément
 * e ou NULL si cet élément n'est pas trouvé. Il renvoie également NULL si l est
 * NULL.*/

struct list *list_remove(struct list *l, int e);

/*Cette fonction supprime la première occurrence de e dans l et renvoie la tête
 * de l après la suppression. Si l est NULL, list_remove renvoie NULL.  */

struct list *tri_list(struct list *l);

struct list *list_reverse_sorted_add(struct list *l, int e);

/*cette fonction insère l'élément e à sa juste place dans l, triés par ordre
 * décroissant. Il renvoie la tête de la liste après l'insertion. Si une erreur
 * se produit, vous devez renvoyer l tel qu'il était lorsque votre fonction a
 * été appelée.*/

struct list *list_remove_if(struct list *l, int (*predicate)(int));

/* Cette fonction supprime de la liste tous les éléments pour lesquels le
 * prédicat renvoie 1. Elle renvoie la tête après suppression. Si l est NULL,
 * list_remove_if renvoie NULL.*/

#endif
