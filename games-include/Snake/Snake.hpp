/*
** Snake.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:01:26 2017 Loïc Lopez
// Last update Thu Mar 30 15:53:50 2017 Matthias Prost
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
  std::string				libraryName;
  arcade::GetMap			*Map;
  std::vector<arcade::Position>		_snake;
  int 					      applePosition;
  bool					      popApple;
  virtual void				wait_second(int);
  SaveCommand         last_key;
  int                 score;

 public:
  Snake(std::string const &);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  virtual ~Snake();

  virtual void setMap();
  virtual void drawMap(ILibraryViewController *libraryInstance);
  virtual bool play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
  virtual int  getScore();
  virtual void setScore(int);
  virtual std::string getGameName();
};

#endif /* SNAKE_HPP__ */
