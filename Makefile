##
## Makefile for Makefile in /home/jabbar_y/rendu/cpp_arcade
##
## Made by Yassir Jabbari
## Login   <jabbar_y@epitech.net>
##
## Started on  Mon Mar  6 09:53:13 2017 Yassir Jabbari
## Last update Mon Mar  6 10:31:07 2017 Loic Lopez
##

all:
	@make --no-print-directory -C lib-sources
	@make --no-print-directory -C games-sources
	@make --no-print-directory -C sources


clean:
	@make clean  --no-print-directory -C lib-sources
	@make clean  --no-print-directory -C games-sources
	@make clean  --no-print-directory -C sources

fclean:
	@make fclean  --no-print-directory -C lib-sources
	@make fclean  --no-print-directory -C games-sources
	@make fclean  --no-print-directory -C sources

re:
	@make re  --no-print-directory -C lib-sources
	@make re  --no-print-directory -C games-sources
	@make re  --no-print-directory -C sources

