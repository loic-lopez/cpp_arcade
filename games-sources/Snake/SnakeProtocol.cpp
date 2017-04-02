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

void	Snake::playProtocol()
{
  char buffer;
  this->Map->type = arcade::CommandType::PLAY;
  this->setMap();
  while ((buffer = (char) std::cin.get()) != EOF)
    {
      arcade::CommandType commandType = (arcade::CommandType)static_cast<unsigned>(buffer);
      this->Map->type = commandType;
      if (commandType == arcade::CommandType::GET_MAP)
	{
	  this->Map->type = commandType;
	  write(1, &this->Map->type, sizeof(arcade::CommandType));
	  write(1, &this->Map->width, sizeof(uint16_t));
	  write(1, &this->Map->height, sizeof(uint16_t));
	  write(1, &this->Map->tile, sizeof(arcade::TileType) * this->Map->height * this->Map->width);
	}
      else if (commandType == arcade::CommandType::WHERE_AM_I)
	{
	  this->whereAmI =
	   reinterpret_cast<arcade::WhereAmI *>(malloc(sizeof(arcade::WhereAmI)
						       + this->_snake.size()
				      * sizeof(arcade::Position)));
	  this->whereAmI->lenght = (uint16_t) this->_snake.size();
	  this->whereAmI->type = commandType;
	  for (size_t j = 0; j < this->_snake.size(); j++)
	    {
	      this->whereAmI->position[j].x = this->_snake.at(j).x;
	      this->whereAmI->position[j].y = this->_snake.at(j).y;
	    }
	  write(1, &this->whereAmI->type, sizeof(arcade::CommandType));
	  write(1, &this->whereAmI->lenght, sizeof(uint16_t));
	  write(1, &this->whereAmI->position, sizeof(arcade::Position) * this->whereAmI->lenght);
	}
      else
	SnakeAlgorithm(this->Map, &this->_snake, &this->last_key);
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
