/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** arbre
*/

#ifndef ARBRE_H_
    #define ARBRE_H_

    typedef struct arbre_huff {
        char c;
        unsigned int occ;
        struct arbre_huff *gauche;
        struct arbre_huff *droit;
    } tree_t;

    typedef struct dico {
        char c;
        int occ;
        char *code;
        int taille;
    } dico_t;

    typedef struct temp {
        char *code;
        int *ind;
    } temp_t;

    typedef struct encode {
        char *str1;
        char *str2;
        int nb;
    } encode_t;

#endif /* !ARBRE_H_ */
