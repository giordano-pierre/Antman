/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** make_free
*/
#include "../include/antman.h"

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

void free_leaf (tree_t **my_leaf)
{
    for (int i = 1; i < 383; i++)
        if (my_leaf[i] != NULL)
            free (my_leaf[i]);
    free (my_leaf);
}

void free_dico (dico_t *dico, int size)
{
    for (int f = 0; f < size; f++) {
        free (dico[f].code);
    }
    free (dico);
}
