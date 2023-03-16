/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** main
*/
#include "../include/antman.h"

void print_h(void)
{
    write (1, "USAGE:\n\t./antman/antman [file] [opt:1/2/3/4] > new_file\n",57);
    write (1, "\t./giantman/giantman [new_file] [opt:1/2/3/4]\n\nOPT:\n\t", 54);
    write (1, "1 - for the text files\n\t2 - for the html files\n\t", 49);
    write (1, "3 - for the image files\n\t4 - for any files\n\n", 45);
    write (1, "DESCRIPTION:\n\tthe Antman is used to compress files \n\t", 54);
    write (1, "and the Giantman is used to decompress files\n", 46);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_h();
        return 0;
    }
    if (ac != 3) {
        write (1, "Bad number of arguments !\n", 26);
        return (84);
    }
    if ((av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3')
    && av[2][0] != '4' && av[2][1] != '\0') {
        write (1, "Bad filetype !\n", 15);
        return 84;
    }
    if (verif_file (av[1]) == -1)
        return 84;
    char *file;
    if ((file = open_file (av[1])) == NULL)
        return 84;
    free (file);
    return 0;
}
