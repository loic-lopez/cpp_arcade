/*
** SnakeProtocol.cpp.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SnakeProtocol.cpp.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 01 15:05:06 2017 Loïc Lopez
** Last update Sat Apr  1 19:43:04 2017 Matthias Prost
*/

#include "Snake.hpp"

typedef IGameModel *(*play_function_type)(std::string const &);

#include <unistd.h>

void	Snake::playProtocol()
{
  std::string 	line;
  //size_t 	i = 0;
  arcade::CommandType commandType = arcade::CommandType::GET_MAP;

  this->setMap();
  while (true)
    {
      //std::cin >> line;

      this->Map->type = commandType;
      if (commandType == arcade::CommandType::GET_MAP)
	{
	  write(1, this->Map, sizeof(sizeof(arcade::GetMap)
				     + (35 * 35 * sizeof(arcade::TileType))));
	  commandType = arcade::CommandType::WHERE_AM_I;
	}
      else if (commandType == arcade::CommandType::WHERE_AM_I)
	{
	  this->whereAmI =
	   reinterpret_cast<arcade::WhereAmI *>(malloc(sizeof(arcade::WhereAmI)
						       + this->_snake.size()
				      * sizeof(arcade::Position)));
	  this->whereAmI->type = commandType;
	  this->whereAmI->lenght = this->_snake.size();
	  for (size_t j = 0; j < this->_snake.size(); j++)
	    {
	      this->whereAmI->position[j].x = this->_snake.at(j).x;
	      this->whereAmI->position[j].y = this->_snake.at(j).y;
	    }
	  write(1, this->whereAmI, sizeof(arcade::Position) * this->_snake.size());
	  commandType = arcade::CommandType::GET_MAP;
	}
    }
}

extern "C" void Play(void)
{
  void	*game = NULL;
  play_function_type	play = NULL;
  IGameModel	*gameModel;

  if (!(game = Cencapsulation::c_dlopen("games/libarcade_snake.so", RTLD_LAZY)))
    {
      if (!(game = Cencapsulation::c_dlopen("libarcade_snake.so", RTLD_LAZY)))
	{
	  std::cerr << Cencapsulation::c_dlerror() << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  if (!(play = reinterpret_cast<play_function_type>(Cencapsulation::c_dlsym(game, "createInstanceGame"))))
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  std::string line;
  gameModel = play("");
  gameModel->playProtocol();
}
