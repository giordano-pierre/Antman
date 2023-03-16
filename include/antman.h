/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** antman
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "arbre.h"

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    int verif_file (char *filepath);
    char *open_file (char *filepath);

    void antman (char *buffer, int size);
    int is_sort (tree_t **my_leaf, int size);
    void sort_leaf (tree_t **my_leaf, int size);
    void swap_elem (tree_t **my_leaf, int ind);
    int calcul_size (tree_t **my_leaf);

    tree_t **create_leaf (int size);
    void fill_leaf (tree_t **my_leaf, char *file, int size);
    int exist (tree_t **my_leaf, char c);
    void add_leaf (tree_t **my_leaf, char c);

    tree_t *create_nodes (tree_t **my_leaf);
    tree_t *create_tree (tree_t **my_leaf, int *size_leaf);
    dico_t *create_dico (int size);
    void fill_dico (tree_t *tree, dico_t *dico, int niveau, temp_t temp);

    void free_tree (tree_t *tree);
    void free_leaf (tree_t **my_leaf);
    void free_dico (dico_t *dico, int size);

    int my_strlen (char const *str);
    void my_strcpy(char *dest, char const *src);
    void my_put_nbr(int nb);
    void my_putchar(char c);

    void return_tree (tree_t *tree);
    void return_file (char *file, int size, dico_t *dico, int size_dico);

    char *find_bin (dico_t *dico, int size_dico, char c);
    unsigned long count_bin (dico_t *dico, int size_dico);
    void convert_ascii (char *bin, unsigned long max);
    int bin_to_decimal (char *bin, int i);

#endif /* !ANTMAN_H_ */
