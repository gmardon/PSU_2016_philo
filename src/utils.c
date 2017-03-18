/*
** list.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 10:21:35 2017 Guillaume MARDON
** Last update Fri Mar 17 10:22:23 2017 Guillaume MARDON
*/
#include "philo.h"

int is_num(char *nbr)
{
    int index;

    index = -1;
    while (nbr[++index])
    {
        if (nbr[index] < '0' || nbr[index] > '9')
            return (0);
    }
    return (1);
}