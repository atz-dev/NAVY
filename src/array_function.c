/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Array function of Navy
*/

#include "head.h"

bool type_checker(char x)
{
    if (x != ' ' && x != '\n')
        return (true);
    return (false);
}

int word_counter(char *str)
{
    int x = 0;
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (x == 0 && type_checker(str[i]) == true) {
            count++;
            x = 1;
        }
        if (x == 1 && type_checker(str[i]) == false) {
            x = 0;
        }
    }
    return (count);
}

void malloc_this(int total, char *str, char **word_array)
{
    int i = 0;
    int actual = 0;
    int a = 0;
    int z;
    int copy;

    for (; actual < total; i++, actual++) {
        for (; str[i] != '\0' && type_checker(str[i]) == false; i++);
        a = i;
        for (; str[i] != '\0' && type_checker(str[i]) == true; i++);
        word_array[actual] = (char *)malloc(sizeof(char) * ((i - 1) - a + 2));
        z = i - 1;
        for (copy = 0; a <= z; copy++, a++)
            word_array[actual][copy] = str[a];
        word_array[actual][copy] = '\0';
    }
    word_array[total] = NULL;
}

char **my_str_to_word_array(char *str)
{
    char **word_array = NULL;
    int total = word_counter(str);

    word_array = malloc(sizeof(char *) * (total + 1));
    malloc_this(total, str, word_array);
    return (word_array);
}