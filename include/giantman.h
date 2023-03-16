/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** giantman
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "arbre.h"

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_

    int verif_file (char *filepath);
    char *open_file (char *filepath);

    void giantman (char *file, unsigned int size);
    void search_leaf (char *bin, tree_t *tree, int *ind);
    void return_file (char *bin, tree_t *tree, int occurence_tot);

    int get_start (char *file, int size_leaf);
    char *dec_to_bin (int c);
    char *create_bin (char *file, unsigned int size, int start);

    tree_t **initialise_leaf (char *file, int taille);
    int count_leaf (char *file);
    int count_total (tree_t **my_leaf, int size_leaf);

    void swap_leaf (tree_t **my_leaf, int ind);
    tree_t *create_nodes (tree_t **my_leaf);
    tree_t *create_tree (tree_t **my_leaf, int *size_leaf);

    int is_sort (tree_t **my_leaf, int size);
    void swap_elem (tree_t **my_leaf, int ind);
    void sort_leaf (tree_t **my_leaf, int size);

    void free_leaf (tree_t **my_leaf, int size_leaf);
    void free_tree (tree_t *tree);

    int	my_getnbr_mid (char const *str, int *indice);
    void my_putchar(char c);

#endif /* !GIANTMAN_H_ */
