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

extern "C" IGameModel *Play();

class	Snake : public IGameModel
{
 private:
  std::string libraryName;
  std::array<int, 2>	characterPosition;
  std::map<int, int>	map;

 public:
  Snake();
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  virtual ~Snake();

  // Methods
  virtual void	setCharacterPosition(std::array<int, 2> &position);
  virtual std::array<int, 2> &getCharacterPosition();
  virtual void setMap(std::map<int, int> &);
  virtual std::map<int, int>	&getMap();
  virtual void getInputs();
  virtual bool	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
};

#endif /* SNAKE_HPP__ */