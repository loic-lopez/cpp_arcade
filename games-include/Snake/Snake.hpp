/*
** Snake.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:01:26 2017 Loïc Lopez
** Last update jeu. mars 16 16:01:26 2017 Loïc Lopez
*/

#ifndef SNAKE_HPP__
# define SNAKE_HPP__

#include <iostream>
#include "../interface/IGameModel.hpp"

extern "C" IGameModel *Play(std::string const &libraryName);

class	Snake : public IGameModel
{
 private:
  std::string libraryName;

 public:
  Snake(std::string const &);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  virtual ~Snake();
};

#endif /* SNAKE_HPP__ */