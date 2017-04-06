##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Mon Mar 20 11:21:22 2017 Matthias Prost
##


Ncurses	=	../../lib/lib_arcade_Ncurses.so


################# LIB SRCS ################

Ncurses_SRCS	=	NcursesViewController.cpp \
			NcursesMenuController.cpp \
			NcursesEncap.cpp \


###########################################


################# LIB OBJS ################

Ncurses_OBJS	=	$(Ncurses_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../lib-include/Ncurses -lmenu -lncurses -fPIC -shared

all: $(Ncurses)

$(Ncurses):	$(Ncurses_OBJS)
	@$(CC) $(Ncurses_OBJS) $(CXXFLAGS) -o $(Ncurses) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_Ncurses.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(Ncurses) $(DEFAULT)

clean	:
	@rm -f $(Ncurses_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(Ncurses_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(Ncurses_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f $(Ncurses) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) lib_arcade_Ncurses.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) lib_arcade_Ncurses.so $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)
