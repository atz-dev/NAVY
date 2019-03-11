/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Player one Navy
*/

#include "head.h"

void parse_algorithm(int j, int x)
{
    switch(x) {
    case (0):
        misc.ship_length = misc.buff[j] - '0';
        break;
    case (2):
        misc.pos_alpha1 = misc.buff[j] - 65;
        break;
    case (3):
        misc.pos_digit1 = misc.buff[j] - '0';
        break;
    case (5):
        misc.pos_alpha2 = misc.buff[j] - 65;
        break;
    case (6):
        misc.pos_digit2 = misc.buff[j] - '0';
        break;
    }
}

int parse_value(void)
{
    int j = 0;
    int line = 1;

    if (check_file() == 84)
        return (84);
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x <= 7; x++, j++) {
            parse_algorithm(j, x);
        }
        if (fill_board() == 84)
            return (84);
        line++;
    }
    return (0);
}

int fill_pd(int pd1, int pd2, int pa1)
{
    while (pd1 <= pd2) {
        if (misc.my_board[pd1][pa1] != 0) {
            write(2, "A ship is over another.\n", 25);
            return (84);
        }
        misc.my_board[pd1][pa1] = misc.ship_length;
        pd1 += 1;
    }
    return (0);
}

int fill_pa(int pa1, int pa2, int pd1)
{
    while (pa1 <= pa2) {
        if (misc.my_board[pd1][pa1] != 0) {
            write(2, "A ship is over another.\n", 25);
            return (84);
        }
        misc.my_board[pd1][pa1] = misc.ship_length;
        pa1 += 1;
    }
    return (0);
}

int fill_board(void)
{
    int pa1 = misc.pos_alpha1;
    int pa2 = misc.pos_alpha2;
    int pd1 = misc.pos_digit1 - 1;
    int pd2 = misc.pos_digit2 - 1;

    if (pa1 == pa2 && pd1 <= pd2) {
        if (fill_pd(pd1, pd2, pa1) == 84)
            return (84);
    }
    else if (pd1 == pd2 && pa1 != pa2) {
        if (fill_pa(pa1, pa2, pd1) == 84)
            return (84);
    } else {
        write(2, "Bad ship configuration. Type ./navy -h for help.\n", 50);
        return (84);
    }
    return (0);
}