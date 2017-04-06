##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Mon Mar 20 14:35:33 2017 Yassir Jabbari
##

SFML	=	../../lib/lib_arcade_SFML.so

################# LIB SRCS ################

SFML_SRCS	=	SFMLViewController.cpp

###########################################


################# LIB OBJS ################

SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../lib-include/SFML -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -fPIC -shared

all: $(SFML) 

$(SFML):	$(SFML_OBJS)
	@$(CC) $(SFML_OBJS) $(CXXFLAGS) -o $(SFML) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_SFML.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(SFML) $(DEFAULT)

clean	:
	@rm -f $(SFML_OBJS)  && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(SFML_OBJS)  $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(SFML_OBJS)  $(DEFAULT)

fclean	:	clean
	@rm -f $(SFML)  && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) lib_arcade_SFML.so  $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) lib_arcade_SFML.so  $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)
