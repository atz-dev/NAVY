/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Board Navy
*/

#include "head.h"

void print_clear_board(int **board)
{
    my_putstr("\nmy positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int line = 0; line < 8; line++) {
        my_putnbr(line + 1);
        my_putchar('|');
        for (int i = 0; i < 8; i++) {
            board[line][i] == 0 ? \
            my_putchar('.') : (board[line][i] == 10 ? \
            my_putchar('x') : (board[line][i] == 20 ? \
            my_putchar('o') : my_putnbr(board[line][i])));
            i < 7 ? my_putchar(' ') : my_putchar('\n');
        }
    }
}

void print_hide_board(int **board)
{
    my_putstr("\nenemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int line = 0; line < 8; line++) {
        my_putnbr(line + 1);
        my_putchar('|');
        for (int i = 0; i < 8; i++) {
            board[line][i] == 10 ? \
            my_putchar('x') : (board[line][i] == 20 ? \
            my_putchar('o') : my_putchar('.'));
            i < 7 ? my_putchar(' ') : my_putchar('\n');
        }
    }
}