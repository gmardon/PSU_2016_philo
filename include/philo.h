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
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

enum State { UNDEFINED = (-1), SLEEP = (0), EAT = (1), THINK = (2) };

/*
typedef struct		s_stick
{
  bool			is_used;
  pthread_mutex_t	*mutex;
}			t_stick;
*/

typedef struct		s_philo
{
  //t_stick		*right_hand;
  //t_stick		*left_hand;
  int actual_turn;
  int philosophers;
  int turns;
  struct s_philo	*next;
  struct s_philo	*previous;
  enum State state;
  int			id;
  pthread_t		thread;
  pthread_mutex_t mutex;
  sem_t *sem;
}			t_philo;

typedef struct s_args 
{
  int philosophers;
  int turns;
} t_args;

int run(t_args *args);
t_philo *create_philo_list(t_args *args);
t_philo *create_philo(t_philo *previous, int philosophers, int turns, int position);
void *thread_philo(void *arg);
void pre_think(t_philo *philo);
void pre_sleep(t_philo *philo);
void eat(t_philo *philo);
void think(t_philo *philo);
void sleep(t_philo *philo);

sem_t sem;

#endif
