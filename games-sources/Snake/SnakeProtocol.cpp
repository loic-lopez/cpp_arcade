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

void	MoveSnakeProtocol(arcade::GetMap *Map, std::vector<arcade::Position> *snake, SaveCommand *last_key)
{
  if (Map->type == arcade::CommandType::PLAY)
    {
      for (size_t j = snake->size() - 1; j > 0 ; j--)
	{
	  snake->at(j).x = snake->at(j - 1).x;
	  snake->at(j).y = snake->at(j - 1).y;
	}
      if (*last_key == SaveCommand::UP)
	snake->at(0).y--;
      else if (*last_key == SaveCommand::DOWN)
	snake->at(0).y++;
      else if (*last_key == SaveCommand::LEFT)
	snake->at(0).x--;
      else if (*last_key == SaveCommand::RIGHT)
	snake->at(0).x++;
    }
}
void	SnakeAlgorithmProtocol(arcade::GetMap *Map, SaveCommand *last_key)
{
  if ((Map->type == arcade::CommandType::GO_UP
       && *last_key != SaveCommand::DOWN) ||
      (Map->type == arcade::CommandType::GO_DOWN
       && *last_key == SaveCommand::UP))
    *last_key = SaveCommand::UP;
  else if ((Map->type == arcade::CommandType::GO_DOWN
	    && *last_key != SaveCommand::UP) ||
	   (Map->type == arcade::CommandType::GO_UP
	    && *last_key == SaveCommand::DOWN))
    *last_key = SaveCommand::DOWN;
  else if ((Map->type == arcade::CommandType::GO_LEFT
	    && *last_key != SaveCommand::RIGHT) ||
	   (Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key == SaveCommand::LEFT))
    *last_key = SaveCommand::LEFT;
  else if ((Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key != SaveCommand::LEFT) ||
	   (Map->type == arcade::CommandType::GO_LEFT
	    && *last_key == SaveCommand::RIGHT))
    *last_key = SaveCommand::RIGHT;
}

void	Snake::playProtocol()
{
  arcade::CommandType commandType = arcade::CommandType::PLAY;

  this->setMap();
  while (std::cin.read(reinterpret_cast<char *>(&commandType), sizeof(arcade::CommandType)))
    {
      this->Map->type = commandType;
      if (commandType == arcade::CommandType::GET_MAP)
	{
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->type), sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->width), sizeof(uint16_t));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->height), sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->tile), sizeof(arcade::TileType) * this->Map->height * this->Map->width);
	}
      else if (commandType == arcade::CommandType::WHERE_AM_I)
	{
	  this->whereAmI =
	   new arcade::WhereAmI[sizeof(arcade::WhereAmI) + this->_snake.size()
				      * sizeof(arcade::Position)];
	  this->whereAmI->lenght = (uint16_t) this->_snake.size();
	  this->whereAmI->type = commandType;
	  for (size_t j = 0; j < this->_snake.size(); j++)
	    {
	      this->whereAmI->position[j].x = this->_snake.at(j).x;
	      this->whereAmI->position[j].y = this->_snake.at(j).y;
	    }
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->type),
			  sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->lenght),
			  sizeof(uint16_t));
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->position),
			  sizeof(arcade::Position) * this->whereAmI->lenght);
	  delete this->whereAmI;
	}
      else
	{
	  SnakeAlgorithmProtocol(this->Map, &this->last_key);
	  MoveSnakeProtocol(this->Map, &this->_snake, &this->last_key);
	}
    }
}

extern "C" void Play(void)
{
  IGameModel	*gameModel = new Snake("");

  gameModel->playProtocol();
}
