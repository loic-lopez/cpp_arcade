/*
** SnakeProtocol.cpp.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SnakeProtocol.cpp.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 01 15:05:06 2017 Loïc Lopez
** Last update sam. avr. 01 15:05:06 2017 Loïc Lopez
*/

#include "Snake.hpp"

typedef IGameModel *(*play_function_type)(std::string const &);


#include <unistd.h>
#include <algorithm>

void	Snake::playProtocol()
{
  std::string 	line;
  size_t 	i = 0;

  this->setMap();
  while (true)
    {
      std::cin >> line;
      arcade::CommandType commandType = (arcade::CommandType)static_cast<unsigned>(line[i]);

      if (i == line.length() - 1)
	  break;
      if (commandType == arcade::CommandType::GET_MAP)
	  write(1, this->Map->tile, sizeof(this->Map + this->Map->height * this->Map->width));
      i++;
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