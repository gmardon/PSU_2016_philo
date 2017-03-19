/*
** main.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
** Last update Sun Mar 19 23:11:16 2017 Romain
*/

#include "philo.h"

t_args	*parse_args(int argc, char *argv[])
{
  int		index;
  t_args	*args;

  args = malloc(sizeof(t_args));
  if (args == NULL)
    return NULL;

  args->philosophers = -1;
  args->turns = -1;
  index = 0;
  while (index < argc)
    {
      if (strcmp(argv[index], "-p") == 0 && (argc > index + 1))
	args->philosophers = strtol(argv[index + 1], NULL, 10);
      else if (strcmp(argv[index], "-e") == 0 && (argc > index + 1))
	args->turns = strtol(argv[index + 1], NULL, 10);
      index++;
    }
  return (args);
}

int	main(int argc, char **argv)
{
  t_args	*args;

  RCFStartup(argc, argv);
  args = parse_args(--argc, ++argv);
  if (args->philosophers == -1 || args->turns == -1)
    {
      RCFCleanup();
      exit(1);
    }
  run(args);
  RCFCleanup();
}

void    *philo_thread(void *arg)
{
  t_philo	*data;
  int		index;

  data = (t_philo *)arg;
  index = -1;
  while (++index < data->turns)
    {

      while (pthread_mutex_lock(&data->mutex) == -1);
      lphilo_take_chopstick(&data->mutex);
      lphilo_think();
      lphilo_release_chopstick(&data->mutex);
      pthread_mutex_unlock(&data->mutex);

      while (pthread_mutex_lock(&data->mutex) == -1 && pthread_mutex_lock(&data->next->mutex) == -1);
      lphilo_take_chopstick(&data->mutex);
      lphilo_take_chopstick(&data->next->mutex);
      lphilo_eat();
      lphilo_release_chopstick(&data->mutex);
      lphilo_release_chopstick(&data->next->mutex);
      pthread_mutex_unlock(&data->mutex);
      pthread_mutex_unlock(&data->next->mutex);
      lphilo_sleep();
    }
  pthread_exit(0);
}

int	run(t_args *args)
{
  t_philo	*list;
  int		index;


  if ((list = malloc(sizeof(t_philo) * args->philosophers)) == NULL)
    return (-1);
  index = -1;
  while (++index < args->philosophers)
    {
      if (index == args->philosophers - 1)
        list[index].next = &list[0];
      else
        list[index].next = &list[index + 1];
      pthread_create(&list[index].thread, NULL, philo_thread, &list[index]);
      list[index].turns = args->turns;
    }
  index = -1;
  while (++index < args->philosophers)
    pthread_join(list[index].thread, NULL);
  return (0);
}
