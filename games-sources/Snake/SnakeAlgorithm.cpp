/*
** SnakeAlgorithm.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SnakeAlgorithm.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  dim. avr. 02 20:13:36 2017 Loïc Lopez
** Last update dim. avr. 02 20:13:36 2017 Loïc Lopez
*/

#include "Snake.hpp"

void	SnakeAlgorithm(arcade::GetMap *Map, std::vector<arcade::Position> *snake, SaveCommand *last_key)
{
  for (size_t j = snake->size() - 1; j > 0 ; j--)
    {
      snake->at(j).x = snake->at(j - 1).x;
      snake->at(j).y = snake->at(j - 1).y;
    }
  if ((Map->type == arcade::CommandType::GO_UP
       && *last_key != SaveCommand::DOWN) ||
      (Map->type == arcade::CommandType::GO_DOWN
       && *last_key == SaveCommand::UP))
    {
      snake->at(0).y--;
      *last_key = SaveCommand::UP;
    }
  else if ((Map->type == arcade::CommandType::GO_DOWN
	    && *last_key != SaveCommand::UP) ||
	   (Map->type == arcade::CommandType::GO_UP
	    && *last_key == SaveCommand::DOWN))
    {
      snake->at(0).y++;
      *last_key = SaveCommand::DOWN;
    }
  else if ((Map->type == arcade::CommandType::GO_LEFT
	    && *last_key != SaveCommand::RIGHT) ||
	   (Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key == SaveCommand::LEFT))
    {
      snake->at(0).x--;
      *last_key = SaveCommand::LEFT;
    }
  else if ((Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key != SaveCommand::LEFT) ||
	   (Map->type == arcade::CommandType::GO_LEFT
	    && *last_key == SaveCommand::RIGHT))
    {
      snake->at(0).x++;
      *last_key = SaveCommand::RIGHT;
    }
}