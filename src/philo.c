/*
** philo.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
** Last update Fri Mar 17 10:05:54 2017 Guillaume MARDON
*/
#include "philo.h"

void init_philo(t_philo *philo)
{
  if ((philo->id % 2) == 0)
    philo->state = EAT;
  else
    philo->state = SLEEP;
  if ((philo->id) == (philo->philosophers - 1) && (philo->philosophers % 2) == 1)
    philo->state = THINK;
}

t_philo *create_philo(t_philo *previous, int philosophers, int turns, int position)
{
    t_philo *philo;

    while (previous && previous->next)
      previous = previous->next;
    if ((philo = malloc(sizeof(t_philo))) == NULL)
        return (NULL);
    philo->actual_turn = 0;
    philo->turns = turns;
    philo->philosophers = philosophers;
    philo->id = position;
    philo->previous = previous;
    init_philo(philo);
    pthread_mutex_init(&(philo->mutex), NULL);
    if (previous != NULL)
        previous->next = philo;
    philo->next = NULL;
    if (previous)
        return (previous);
    return (philo);
}

void think(t_philo *philo)
{
    lphilo_take_chopstick(&(philo->mutex));
    philo->state = THINK;
    lphilo_think();
    lphilo_release_chopstick(&(philo->mutex));
    pthread_mutex_unlock(&(philo->mutex));
}

void eat(t_philo *philo)
{
    lphilo_take_chopstick(&(philo->mutex));
    lphilo_take_chopstick(&(philo->next->mutex));
    philo->actual_turn += 1;
    philo->state = EAT;
    lphilo_eat();
    lphilo_release_chopstick(&(philo->mutex));
    lphilo_release_chopstick(&(philo->next->mutex));
    pthread_mutex_unlock(&(philo->mutex));
    pthread_mutex_unlock(&(philo->next->mutex));
}

void sleep(t_philo *philo)
{
    lphilo_sleep();
    philo->state = SLEEP;
}