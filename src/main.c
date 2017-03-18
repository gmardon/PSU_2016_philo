/*
** main.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
** Last update Fri Mar 17 10:05:54 2017 Guillaume MARDON
*/
#include "philo.h"

t_args *parse_args(int argc, char *argv[]) 
{
    int index;
    t_args *args;

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

int main(int argc, char **argv)
{
    RCFStartup(argc, argv);
    t_args *args;
    args = parse_args(--argc, ++argv);
    if (args->philosophers == -1 || args->turns == -1) 
    {
        RCFCleanup();
        exit(1);
    }
    run(args);
    RCFCleanup();
}

int run(t_args *args) 
{
    t_philo *list;
    t_philo	*philo;
    int index;

    list = create_philo_list(args);
    index = 0;
    philo = list->next;
    while (index < args->philosophers)
    {
        pthread_create(&(philo->thread), NULL, thread_philo, philo);
        philo = philo->next;
        index++;
    }
    philo = list->next;
    index = 0;
    while (index < philo->philosophers)
    {
        pthread_join(philo->thread, NULL);
        philo = philo->next;
        index++;
    }
}