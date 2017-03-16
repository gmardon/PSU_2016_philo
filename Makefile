##
## Makefile for Philo in /home/romain/Delivery/Projects/PSU_2016_philo
##
## Made by Romain
## Login   <romain.goasdoue@epitech.eu>
##
## Started on  Thu Mar 16 13:27:31 2017 Romain
## Last update Thu Mar 16 13:43:44 2017 Romain
##

NAME	=

SRC	=

OBJ	=

RM	= rm -rf

CC	= gcc

all:	$(NAME)

$(NAME):
	$(CC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

