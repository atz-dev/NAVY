/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** GNL Navy
*/

#include "head.h"

char *concat(char *str1, char *str2)
{
    int i;
    char *concat_str = malloc(sizeof(char) * \
    (my_strlen(str1) + my_strlen(str2) + 1));

    for (i = 0; str1[i] != '\0'; i++)
        concat_str[i] = str1[i];
    for (int j = 0; str2[j] != '\0'; i++, j++)
        concat_str[i] = str2[j];
    concat_str[i] = '\0';
    return (concat_str);
}

char *take_line(char *temp, int fd)
{
    int tool;
    char buffer[1];

    while ((tool = read(fd, buffer, 1)) > 0) {
        buffer[tool] = '\0';
        temp = concat(temp, buffer);
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '\n') {
                temp[i] = '\0';
                return (temp);
            }
        }
    }
    return (temp);
}

char *get_next_line(int fd)
{
    static char *temp;

    temp = malloc(sizeof(char) * 1);
    temp = take_line(temp, fd);

    return (temp);
}