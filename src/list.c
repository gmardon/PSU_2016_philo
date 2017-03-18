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

t_philo *create_philo_list(t_args *args)
{
    t_philo	*start;
    t_philo	*actual;
    int index;

    index = 0;
    actual = NULL;
    while (index++ < args->philosophers)
        actual = create_philo(actual, args->philosophers, args->turns, index);
    start = actual;
    while (actual->next != NULL)
        actual = actual->next;
    actual->next = start;
    start->previous = actual;
    return (start);
}