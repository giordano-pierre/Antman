/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** create_struct
*/
#include "../include/antman.h"

tree_t **create_leaf (int size)
{
    tree_t **my_leaf = malloc (sizeof(tree_t *) * size);
    for (int i = 0; i < size; i++) {
        my_leaf[i] = malloc (sizeof(tree_t));
        my_leaf[i]->c = '0';
        my_leaf[i]->occ = 0;
        my_leaf[i]->droit = NULL;
        my_leaf[i]->gauche = NULL;
    }
    return my_leaf;
}

void fill_leaf (tree_t **my_leaf, char *file, int size)
{
    for (int i = 0; i < size; i++) {
        if (exist (my_leaf, file[i]) == -1)
            add_leaf (my_leaf, file[i]);
    }
}

int exist (tree_t **my_leaf, char c)
{
    for (int i = 0; my_leaf[i]->occ != 0; i++) {
        if (my_leaf[i]->c == c) {
            my_leaf[i]->occ = my_leaf[i]->occ + 1;
            return 0;
        }
    }
    return -1;
}

void add_leaf (tree_t **my_leaf, char c)
{
    int i = 0;
    for (; my_leaf[i]->occ != 0; i++);
    my_leaf[i]->c = c;
    my_leaf[i]->occ = 1;
}
