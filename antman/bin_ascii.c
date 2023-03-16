/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** bin_ascii
*/
#include "../include/antman.h"

char *find_bin (dico_t *dico, int size_dico, char c)
{
    char *temp;
    for (int i = 0; i < size_dico; i++) {
        if (dico[i].c == c) {
            temp = malloc (sizeof(char) * (my_strlen(dico[i].code) + 1));
            my_strcpy (temp, dico[i].code);
        }
    }
    return temp;
}

unsigned long count_bin (dico_t *dico, int size_dico)
{
    unsigned long nb = 0;
    for (int i = 0; i < size_dico; i++)
        nb = nb + dico[i].occ * dico[i].taille;
    nb = nb + (8 - nb % 8);
    return nb;
}

int bin_to_decimal (char *bin, int i)
{
    int dec = 0;
    if (bin[i] == '1')
        dec = dec + 2 * 2 * 2 * 2 * 2 * 2 * 2;
    if (bin[i + 1] == '1')
        dec = dec + 2 * 2 * 2 * 2 * 2 * 2;
    if (bin[i + 2] == '1')
        dec = dec + 2 * 2 * 2 * 2 * 2;
    if (bin[i + 3] == '1')
        dec = dec + 2 * 2 * 2 * 2;
    if (bin[i + 4] == '1')
        dec = dec + 2 * 2 * 2;
    if (bin[i + 5] == '1')
        dec = dec + 2 * 2;
    if (bin[i + 6] == '1')
        dec = dec + 2;
    if (bin[i + 7] == '1')
        dec = dec + 1;
    return dec;
}

void convert_ascii (char *bin, unsigned long max)
{
    int dec;
    for (unsigned long i = 0; i < max; i = i + 8) {
        dec = bin_to_decimal (bin, i);
        my_putchar (dec);
    }
}
