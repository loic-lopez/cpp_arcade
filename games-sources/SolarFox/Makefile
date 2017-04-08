##
## Makefile for Makefile in /home/lopez_i/cpp_arcade
##
## Made by Loic Lopez
## Login   <loic.lopez@epitech.eu>
##
## Started on  Mon Mar  6 09:53:13 2017 Loic Lopez
## Last update Thu Apr  6 18:16:42 2017 Matthias Prost
##


SolarFox	=	../../games/libarcade_solarfox.so


################# LIB SRCS ################

SolarFox_SRCS	=	SolarFox.cpp \
			SolarFoxAlgorithm.cpp \
			Shoots.cpp \
			SolarFoxProtocol.cpp \
			../commun/Cencapsulation.cpp

###########################################


################# LIB OBJS ################@

SolarFox_OBJS	=	$(SolarFox_SRCS:.cpp=.o)

###########################################

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CC              = g++

RM              = rm -f

CXXFLAGS 	= -Wall -Wextra -Werror -I../../games-include/SolarFox -fPIC -shared -I../../include

all: $(SolarFox)

$(SolarFox):	$(SolarFox_OBJS)
	@$(CC) $(SolarFox_OBJS) $(CXXFLAGS) -o $(SolarFox) && \
        $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : solarfox.so" $(DEFAULT)  || \
        $(ECHO) $(RED) "[ERROR]" $(TEAL) $(SolarFox) $(DEFAULT)

clean	:
	@rm -f $(SolarFox_OBJS) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(SolarFox_OBJS) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(SolarFox_OBJS) $(DEFAULT)

fclean	:	clean
	@rm -f $(SolarFox) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) solarfox.so $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) solarfox.so $(DEFAULT)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "--->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)
