/*
** Snake.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:01:26 2017 Loïc Lopez
// Last update Fri Mar 31 15:53:50 2017 Matthias Prost
*/

#ifndef SNAKE_HPP__
# define SNAKE_HPP__

#include <iostream>
#include <vector>
#include "../interface/IGameModel.hpp"
#include "../../include/Cencapsulation.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &);
extern "C" void Play(void);


class	Snake : public IGameModel
{
 private:
  bool					alreadyLaunch;
  std::string				libraryName;
  arcade::GetMap			*Map;
  std::vector<arcade::Position>	_snake;
  int 					applePosition;
  bool					popApple;
  SaveCommand         			last_key;
  int                 			score;
  arcade::WhereAmI			*whereAmI;


 public:
  Snake(std::string const &libname);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  virtual ~Snake();

  virtual void setMap();
  virtual void drawMap(ILibraryViewController *libraryInstance);
  virtual ChangeCommandType	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
  virtual int  getScore();
  virtual void setScore(int);
  virtual std::string getGameName();
  virtual void  playProtocol(void);
};

typedef IGameModel *(*play_function_type)(std::string const &);
void	SnakeAlgorithm(arcade::GetMap *Map, std::vector<arcade::Position> *snake, SaveCommand *last_key);

#endif /* SNAKE_HPP__ */
