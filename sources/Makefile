##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Fri Mar 17 18:41:30 2017 Matthias Prost
##

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -ldl -I../include -I../lib-include -I../games-include/interface

NAME            = ../arcade

SRCS            = main.cpp \
		 							GameCore.cpp \
									Cencapsulation.cpp \

OBJS            = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS)  $(CXXFLAGS) -o $(NAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : arcade" $(DEFAULT)  || \
	$(ECHO) $(RED) "[ERROR]" $(TEAL) $(NAME) $(DEFAULT)
clean	:
	@rm -f $(OBJS)  && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(OBJS)  $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OBJS)  $(DEFAULT)

fclean	:	clean
	@rm -f $(NAME)  && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) arcade $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) arcade  $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)
