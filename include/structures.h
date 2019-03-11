/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Structures of navy
*/

#include <stdlib.h>

typedef struct usefull_s
{
    int ok;
    int win;
    int sig_tool;
    int delimiter;
    int my_pid;
    int other_pid;
    int ship_length;
    int pos_digit1;
    int pos_digit2;
    int pos_alpha1;
    int pos_alpha2;
    int input_alpha;
    int input_digit;
    int **my_board;
    int **other_board;
    char *buff;
    char *input;
}usefull_t;
