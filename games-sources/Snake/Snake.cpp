//
// pacman.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/pacman.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update jeu. mars 16 14:55:07 2017 Loïc Lopez
//

#include "Snake.hpp"

extern "C" IGameModel *Play(std::string const &libraryName)
{
  return (new Snake(libraryName));
}

Snake::Snake(std::string const &libraryName)
{
  this->libraryName = libraryName;
}

Snake &Snake::operator=(Snake const &snake)
{
  if (this != &snake)
    this->libraryName = snake.libraryName;
  return (*this);
}

Snake::~Snake()
{
}

Snake::Snake(Snake const &snake)
{
  this->libraryName = snake.libraryName;
}

