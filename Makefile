NAME				=		philo

CXX					=		gcc

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

OBJ					=		$(SRC:.c=.o)

CXXFLAGS			+= 	-Wall -Wextra -pedantic -g -lpthread

INCLUDE				=	./include

RM					=	rm -vf

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CXX) $(SRC) -o $(NAME)
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)

clean:
		@$(RM) $(OBJ)
		@$(ECHO) $(DELETION)"OBJs PROPERLY DELETED"$(DEFAULT)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) $(DELETION)"BINARY PROPERLY DELETED"$(DEFAULT)

re:		fclean all

.PHONY:		all clean fclean re

.c.o:
		@$(CXX) $(CXXFLAGS) -I ./include -c $< -o $@  && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)
