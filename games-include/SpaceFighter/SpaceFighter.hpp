/*
** SpaceFighter.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SpaceFighter.hpp.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:02:17 2017 Loïc Lopez
** Last update Mon Mar 27 18:54:07 2017 Matthias Prost
*/

#ifndef SPACEFIGHTER_HPP__
# define SPACEFIGHTER_HPP__

#include <iostream>
#include "../interface/IGameModel.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &);

class SpaceFighter : public IGameModel
{
 private:
  std::string	libraryName;
  int   pos_x;
  int   pos_y;
  virtual void  wait_second(int);

 public:
  SpaceFighter(std::string const &);
  SpaceFighter(SpaceFighter const &);
  SpaceFighter &operator=(SpaceFighter const &);
  virtual ~SpaceFighter();

  // Methods
  virtual void setMap();
  virtual void drawMap(ILibraryViewController *libraryInstance);
  virtual bool	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
  virtual std::string getGameName();
};

#endif /* SPACEFIGHTER_HPP__ */
