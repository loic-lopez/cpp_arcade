##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Tue Mar 21 20:44:29 2017 Matthias Prost
##


Snake	=	../../games/libarcade_snake.so

CXXFLAGS	= -Wall -Wextra -Werror -I../../games-include/Snake -fPIC -shared \
		-I../../include  -ldl


################# LIB SRCS ################

Snake_SRCS	=	Snake.cpp \
			SnakeProtocol.cpp \
			SnakeAlgorithm.cpp

###########################################


################# LIB OBJS ################

Snake_OBJS	=	$(Snake_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f


all: $(Snake)

$(Snake):	$(Snake_OBJS)
	@$(CC) $(Snake_OBJS) $(CXXFLAGS) -o $(Snake) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : snake.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(Snake) $(DEFAULT)

clean	:
	@rm -f $(Snake_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(Snake_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(Snake_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f $(Snake) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) snake.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) snake.so $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)
