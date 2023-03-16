/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** antman
*/
#include "../include/antman.h"

void antman (char *file, int size)
{
    tree_t **my_leaf = create_leaf (383);
    fill_leaf (my_leaf, file, size);
    int size_leaf = calcul_size (my_leaf);
    int size_dico = size_leaf;
    dico_t *dico = create_dico (size_leaf);
    sort_leaf (my_leaf, size_leaf);
    tree_t *tree = create_tree (my_leaf, &size_leaf);
    int ind = 0;
    char *code = malloc (sizeof(char) * 100);
    temp_t temp = {code, &ind};
    fill_dico (tree, dico, 0, temp);
    free (code);
    return_tree (tree);
    return_file (file, size, dico, size_dico);
    free_tree (tree);
    free_dico (dico, size_dico);
    free_leaf (my_leaf);
}

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

void sort_leaf (tree_t **my_leaf, int size)
{
    while (is_sort (my_leaf, size) != 0) {
        for (int i = 0; i < size - 1; i++) {
            swap_elem (my_leaf, i);
        }
    }
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

int calcul_size (tree_t **my_leaf)
{
    int size = 0;
    while (my_leaf[size]->occ != 0) {
        size++;
    }
    return size;
}
