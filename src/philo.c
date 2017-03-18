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

int run(t_args *args) 
{
    printf("run\n");
    t_philo *list;
    t_philo	*philo;
    int index;

    list = create_philo_list(args);
    /*sem_init(&sem, 0, (args->philosophers / 2));
  philo = info->philo;
  index = 0;
  philo = info->philo;
  while (index < args->philosophers)
    {
      pthread_create(&(philo->thread), NULL, thread_philo, philo);
      philo = philo->next;
      index++;
    }
  philo = info->philo;
  index = 0;
  while (index < philo->p)
    {
      pthread_join(philo->thread, NULL);
      philo = philo->next;
      index++;
    }*/
}

void reset_philo(t_philo *philo)
{

}