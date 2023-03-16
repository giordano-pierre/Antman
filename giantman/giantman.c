/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** giantman
*/
#include "../include/giantman.h"

void giantman (char *file, unsigned int size)
{
    int size_leaf = count_leaf (file);
    int start = get_start (file, size_leaf);
    tree_t **my_leaf = initialise_leaf (file, size_leaf);
    tree_t *tree = create_tree (my_leaf, &size_leaf);
    char *bin = create_bin (file, size, start);
    int occurence_tot = tree->occ;
    return_file (bin, tree, occurence_tot);
    free (bin);
    free_tree (tree);
    free_leaf (my_leaf, size_leaf);
}

void search_leaf (char *bin, tree_t *tree, int *ind)
{
    while (1) {
        if (tree->gauche == NULL && tree->droit == NULL) {
            my_putchar (tree->c);
            break;
        }
        if (bin[*ind] == '0') {
            tree = tree->gauche;
            *ind = *ind + 1;
        } else {
            tree = tree->droit;
            *ind = *ind + 1;
        }
    }
}

void return_file (char *bin, tree_t *tree, int occurence_tot)
{
    int ind = 0;
    for (int i = 0; i < occurence_tot; i++) {
        search_leaf (bin, tree, &ind);
    }
}
