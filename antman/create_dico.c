/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** create_dico
*/
#include "../include/antman.h"

dico_t *create_dico (int size)
{
    dico_t *dico = malloc (sizeof(dico_t) * size);
    for (int i = 0; i < size; i++) {
        dico[i].c = '0';
        dico[i].occ = 0;
        dico[i].code = 0;
        dico[i].taille = 0;
    }
    return dico;
}

void fill_dico (tree_t *tree, dico_t *dico, int niveau, temp_t temp)
{
    if (tree->gauche != NULL) {
        temp.code[niveau] = '0';
        fill_dico (tree->gauche, dico, niveau + 1, temp);
    }
    if (tree->droit != NULL) {
        temp.code[niveau] = '1';
        fill_dico (tree->droit, dico, niveau + 1, temp);
    }
    if (tree->gauche == NULL && tree->droit == NULL) {
        temp.code[niveau] = '\0';
        dico[temp.ind[0]].code = malloc (sizeof(char ) * \
        (my_strlen (temp.code) + 1));
        dico[temp.ind[0]].c = tree->c;
        dico[temp.ind[0]].occ = tree->occ;
        my_strcpy (dico[temp.ind[0]].code, temp.code);
        dico[temp.ind[0]].taille = niveau;
        temp.ind[0] = temp.ind[0] + 1;
    }
}
