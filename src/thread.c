/*
** thread.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
** Last update Fri Mar 17 10:05:54 2017 Guillaume MARDON
*/
#include "philo.h"

void *thread_philo(void *arg)
{
    t_philo	*philo;

    philo = (t_philo*) arg;
    while (1)
    {
        if (philo->state == THINK)
            pre_think(philo);
        else if (philo->state == EAT)
            sleep(philo);
        else if (philo->state == SLEEP)
            pre_sleep(philo);
        if (philo->actual_turn >= philo->turns)
	        return (NULL);
    }
    return (NULL);
}

void pre_sleep(t_philo *philo)
{  
    pthread_mutex_lock(&(philo->mutex));
    think(philo);
}

void pre_think(t_philo *philo)
{
    printf("[%d] try wait\n", philo->id);
    pthread_mutex_lock(&(philo->mutex));
    pthread_mutex_lock(&(philo->next->mutex));
    eat(philo);
    printf("[%d] end wait\n", philo->id);
}