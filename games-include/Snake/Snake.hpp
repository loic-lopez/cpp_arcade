/*
** Snake.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:01:26 2017 Loïc Lopez
// Last update Fri Mar 24 08:41:19 2017 Yassir Jabbari
*/

#ifndef SNAKE_HPP__
# define SNAKE_HPP__

#include <iostream>
#include <vector>
#include "../interface/IGameModel.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &);

class	Snake : public IGameModel
{
 private:
  std::string libraryName;
  int	  map[70][50];
  std::vector<std::pair<int, int>> _snake;
  virtual void  wait_second();

 public:
  Snake(std::string const &);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  virtual ~Snake();

  virtual void setMap();
  virtual void getInputs();
  virtual bool play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
  virtual std::string getGameName();
};

#endif /* SNAKE_HPP__ */
