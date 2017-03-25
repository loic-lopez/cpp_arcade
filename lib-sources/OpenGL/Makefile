##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Mon Mar  6 10:31:07 2017 Loic Lopez
##

OpenGL	=	../../lib/lib_arcade_OpenGL.so


################# LIB SRCS ################

OpenGL_SRCS		=	OpenGLViewController.cpp \
				LoadShaders.cpp

###########################################


################# LIB OBJS ################

OpenGL_OBJS		=	$(OpenGL_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../lib-include/OpenGL
CXXFLAGS		+=  -fPIC -shared -L/usr/local/lib -lGL -lGLEW -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama
CXXFLAGS		+=  -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau


all:  $(OpenGL)

$(OpenGL):		$(OpenGL_OBJS)
	@$(CC) $(OpenGL_OBJS) $(CXXFLAGS) -o $(OpenGL) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_OpenGL.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(OpenGL) $(DEFAULT)

clean	:
	@rm -f $(OpenGL_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(OpenGL_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OpenGL_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f  $(OpenGL) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) lib_arcade_OpenGL.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL)  $(OpenGL) $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)