##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Mon Mar  6 10:31:07 2017 Loic Lopez
##

Qt	=	../../lib/lib_arcade_Qt.so


################# LIB SRCS ################

Qt_SRCS		=	QtViewController.cpp

###########################################


################# LIB OBJS ################

Qt_OBJS		=	$(Qt_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../lib-include/Qt

all:  $(Qt)

$(Qt):		$(Qt_OBJS)
	@$(CC) $(Qt_OBJS) -fPIC -shared -o $(Qt) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_Qt.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(Qt) $(DEFAULT)

clean	:
	@rm -f $(Qt_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(Qt_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(Qt_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f  $(Qt) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) lib_arcade_Qt.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL)  $(Qt) $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)