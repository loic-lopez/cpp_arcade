##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Mon Mar  6 10:31:07 2017 Loic Lopez
##


Pacman	=	../../games/pacman.so


################# LIB SRCS ################

Pacman_SRCS	=	Pacman.cpp

###########################################


################# LIB OBJS ################

Pacman_OBJS	=	$(Pacman_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../games-include/Pacman

all: $(Pacman)

$(Pacman):	$(Pacman_OBJS)
	@$(CC) $(Pacman_OBJS) -fPIC -shared -o $(Pacman) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : pacman.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(Pacman) $(DEFAULT)

clean	:
	@rm -f $(Pacman_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(Pacman_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(Pacman_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f $(Pacman) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) pacman.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) pacman.so $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)