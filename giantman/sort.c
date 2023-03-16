/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** sort
*/
#include "../include/giantman.h"

int is_sort (tree_t **my_leaf, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (my_leaf[i]->occ > my_leaf[i + 1]->occ)
            return -1;
        if (my_leaf[i]->occ == my_leaf[i + 1]->occ &&
            my_leaf[i]->c > my_leaf[i + 1]->c)
            return -1;
    }
    return 0;
}

void swap_elem (tree_t **my_leaf, int ind)
{
    if (my_leaf[ind]->occ > my_leaf[ind + 1]->occ) {
        tree_t *temp = my_leaf[ind];
        my_leaf[ind] = my_leaf[ind + 1];
        my_leaf[ind + 1] = temp;
    }
    if (my_leaf[ind]->occ == my_leaf[ind + 1]->occ)
        if (my_leaf[ind]->c > my_leaf[ind + 1]->c) {
            tree_t *temp = my_leaf[ind];
            my_leaf[ind] = my_leaf[ind + 1];
            my_leaf[ind + 1] = temp;
        }
}

void sort_leaf (tree_t **my_leaf, int size)
{
    while (is_sort (my_leaf, size) != 0) {
        for (int i = 0; i < size - 1; i++) {
            swap_elem (my_leaf, i);
        }
    }
}
