/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Main of Navy
*/

#include "head.h"

int player_choice(int ac, char **av)
{
    (void)av;
    switch(ac) {
        case (2):
            player_one(av[1]);
            break;
        case (3):
            player_two(av[1], av[2]);
            break;
        default:
            write(2, "Too many arguments. Type ./navy -h for help\n", 45);
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    misc.win = 84;
    if (start_handling(ac, av) == 1)
        return (84);
    if (player_choice(ac, av) == 1)
        return (84);

    return (misc.win);
}
