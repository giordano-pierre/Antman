/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** create_leaf
*/
#include "../include/giantman.h"

int count_leaf (char *file)
{
    int stop = 0;
    int ind = 1;
    int count = 0;
    while (stop == 0) {
        while (file[ind] >= '0' && file[ind] <= '9')
            ind++;
        if (file[ind] != '@')
            stop = 1;
        else {
            count++;
            ind += 2;
        }
    }
    return count;
}

tree_t **initialise_leaf (char *file, int taille)
{
    tree_t **my_leaf = malloc (sizeof(tree_t *) * taille);
    int ind = 0;
    for (int i = 0; i < taille; i++) {
        my_leaf[i] = malloc (sizeof(tree_t));
        my_leaf[i]->c = file[ind];
        ind++;
        my_leaf[i]->occ = my_getnbr_mid (file, &ind);
        my_leaf[i]->gauche = NULL;
        my_leaf[i]->droit = NULL;
        ind++;
    }
    return my_leaf;
}
