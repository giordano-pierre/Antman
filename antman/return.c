/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** return
*/
#include "../include/antman.h"

void return_tree (tree_t *tree)
{
    if (tree->gauche != NULL) {
        return_tree (tree->gauche);
    }
    if (tree->droit != NULL) {
        return_tree (tree->droit);
    }
    if (tree->gauche == NULL && tree->droit == NULL) {
        my_putchar (tree->c);
        my_put_nbr (tree->occ);
        write (1, "@", 1);
    }
}

void return_file (char *file, int size, dico_t *dico, int size_dico)
{
    unsigned long max = count_bin(dico, size_dico);
    char *bin = malloc (sizeof(char) * (max + 1));
    char *temp;
    unsigned long ind = 0;
    for (int i = 0; i < size; i++) {
        temp = find_bin (dico, size_dico, file[i]);
        for (int j = 0; temp[j] != '\0'; j++) {
            bin[ind] = temp[j];
            ind = ind + 1;
        }
        free (temp);
    }
    for (; ind < max; ind++) {
        bin[ind] = '0';
    }
    bin[ind] = '\0';
    convert_ascii (bin, max);
    free (bin);
}
