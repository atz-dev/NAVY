/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Function of Navy
*/

#include "head.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
        return (0);
    }
    if (nb < 10) {
        my_putchar('0' + nb);
        return (0);
    }
    my_putnbr(nb / 10);
    my_putchar('0' + nb % 10);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int side = 1;

    while ((*str < 47 || *str > 58) && *str != 0) {
        str = str + 1;
        i = i + 1;
    }
    if (i > 0 && *(str - 1) == 45)
        side = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        nbr *= 10;
        nbr += *str - 48;
        str += 1;
    }
    nbr *= side;
    return (nbr);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
