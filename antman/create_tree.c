/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** create_tree
*/
#include "../include/antman.h"

void swap_leaf (tree_t **my_leaf, int ind)
{
    tree_t *temp;
    temp = my_leaf[ind];
    my_leaf[ind] = my_leaf[ind + 1];
    my_leaf[ind + 1] = temp;
}

tree_t *create_tree (tree_t **my_leaf, int *size_leaf)
{
    while (*size_leaf != 1) {
        my_leaf[0] = create_nodes (my_leaf);
        my_leaf[1] = NULL;
        for (int i = 1; i < 383 - 1; i++) {
            swap_leaf (my_leaf, i);
        }
        *size_leaf = *size_leaf - 1;
        sort_leaf (my_leaf, *size_leaf);
    }
    return (my_leaf[0]);
}

tree_t *create_nodes (tree_t **my_leaf)
{
    tree_t *noeud = malloc (sizeof(tree_t));
    noeud->c = '0';
    noeud->occ = my_leaf[0]->occ + my_leaf[1]->occ;
    noeud->gauche = my_leaf[0];
    noeud->droit = my_leaf[1];
    return noeud;
}
