/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Error handling of Navy
*/

#include "head.h"

void help_message(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid:  only for the 2nd player.  ");
    my_putstr("pid of the first player.\n");
    my_putstr("     navy_positions:  ");
    my_putstr("file representing the positions of the ships.\n");
}

int start_handling(int ac, char **av)
{
    int len = 0;

    if (ac == 1) {
        write(2, "Too few arguments. Type ./navy -h for help.\n", 45);
        return (1);
    }
    else if (ac > 1) {
        len = my_strlen(av[1]);
        if (len == 2 && av[1][0] == '-' && av[1][1] == 'h') {
            help_message();
            return (1);
        }
    }
    return (0);
}

int is_digit(int i)
{
    if (misc.buff[i] < 48 || misc.buff[i] > 57)
        return (1);
    return (0);
}

int is_alpha(int i)
{
    if (misc.buff[i] < 65 || misc.buff[i] > 90)
        return (1);
    return (0);
}

int check_file(void)
{
    if (check_size() == 84)
        return (84);
    if (check_type() == 84)
        return (84);
    if (check_char() == 84)
        return (84);
    if (check_length() == 84) {
        write(2, "One or more ships are too long.\n", 33);
        return (84);
    }
    return (0);
}