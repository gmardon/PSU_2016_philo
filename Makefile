#
# Makefile for philo in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_philo/src/
#
# Made by Guillaume MARDON
# Login   <guillaume.mardon@epitech.eu@epitech.eu>
#
# Started on  Fri Mar 17 09:31:43 2017 Guillaume MARDON
# Last update Fri Mar 17 10:05:54 2017 Guillaume MARDON
#

NAME				=		philo

CC					=		gcc

NOW 				:=	$(shell date +"%d %h %g:%R")

DEFAULT				=		"\033[00m"
GREEN				=		"\033[0;32m"
HIGHLIGHTED			=		"\033[2;102m"
DELETION 			=		"\033[2;103m"
TEAL				=		"\033[1;34m"
RED					=		"\033[1;31m"
ECHO				=		/bin/echo -e

SRC_P				=	src/

SRC					=	$(SRC_P)main.c

OBJ					=	$(SRC:.c=.o)

CFLAGS  = -I./include/ -Wall -pedantic -fPIC -Wl,-rpath,./lib

LDFLAGS  = 		-I./include -L./lib -lriceferee -pthread

RM					=	rm -vf

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(SRC) -o $(NAME) $(LDFLAGS) 
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)

clean:
		@$(RM) $(OBJ)
		@$(ECHO) $(DELETION)"OBJs PROPERLY DELETED"$(DEFAULT)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) $(DELETION)"BINARY PROPERLY DELETED"$(DEFAULT)

re:		fclean all

.PHONY:		all clean fclean re

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@  && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)
