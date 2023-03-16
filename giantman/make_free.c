/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** make_free
*/
#include "../include/giantman.h"

void free_tree (tree_t *tree)
{
    if (tree->gauche != NULL) {
        free_tree (tree->gauche);
    }
    if (tree->droit != NULL) {
        free_tree (tree->droit);
    }
    free (tree);
}

void free_leaf (tree_t **my_leaf, int size_leaf)
{
    for (int i = 1; i < size_leaf; i++)
        if (my_leaf[i] != NULL)
            free (my_leaf[i]);
    free (my_leaf);
}
