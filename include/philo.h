/*
** philo.h for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/include/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 10:21:35 2017 Guillaume MARDON
** Last update Fri Mar 17 10:22:23 2017 Guillaume MARDON
*/
#ifndef _PHILO_H_
#define _PHILO_H_
#include "extern.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum { false, true } bool;

typedef struct		s_stick
{
  bool			is_used;
  pthread_mutex_t	*mutex;
}			t_stick;

typedef struct		s_philo
{
  t_stick		*right_hand;
  t_stick		*left_hand;
  bool			is_left;
  bool			is_right;
  int			rize_eat;
  int			rize_quant;
  int			id;
  pthread_t		*thread;
}			t_philo;

typedef struct s_args 
{
  int philosophers;
  int turns;
} t_args;

#endif
