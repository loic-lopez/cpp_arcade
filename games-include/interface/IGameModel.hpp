/*
** IGameModel.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/IGameModel.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 13:55:07 2017 Loïc Lopez
** Last update Wed Apr  5 14:55:17 2017 Matthias Prost
*/

#ifndef IGAMEMODEL_HPP__
# define IGAMEMODEL_HPP__

#include <array>
#include <map>
#include <string>
#include <unistd.h>
#include <chrono>
#include <vector>
#include "../../lib-include/interface/ILibraryViewController.hpp"
#include "../../include/Protocol.hh"
#include "../../include/ArcadeEnum.hpp"

class	IGameModel
{
 public:
  virtual void setMap() = 0;
  virtual void drawMap(ILibraryViewController *libraryInstance) = 0;
  virtual ChangeCommandType	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &, std::string const &) = 0;
  virtual int  getScore() = 0;
  virtual void setScore(int) = 0;
  virtual std::string getGameName() = 0;
  virtual void  playProtocol(void) = 0;

  virtual ~IGameModel() {}
};

#endif /* IGAMEMODEL_HPP__ */
