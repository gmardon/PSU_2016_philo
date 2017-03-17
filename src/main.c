/*
** main.c for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
** Last update Fri Mar 17 10:05:54 2017 Guillaume MARDON
*/
#include "../include/philo.h"

t_args *parse_args(int argc, char *argv[]) 
{
    int index;
    t_args *args;

    args = malloc(sizeof(t_args));
    if (args == NULL)
        exit(84);

    index = 0;
    while (index < argc) 
    {
        if (strcmp(argv[index], "-e") == 0 && (argc > index + 1)) 
        {
            args->philosophers = strtol(argv[index++], NULL, 10);
            printf("philosophers: %d\n",  args->philosophers);
        }
        printf(argv[index]);
        index++;
    }
    return (args);
}

int main(int argc, char **argv)
{
    RCFStartup(argc, argv);
    t_args *args;

    args = parse_args(--argc, ++argv); 
    RCFCleanup();
}
