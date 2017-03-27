/*
** IGameModel.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/IGameModel.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 13:55:07 2017 Loïc Lopez
** Last update Mon Mar 27 18:54:46 2017 Matthias Prost
*/

#ifndef IGAMEMODEL_HPP__
# define IGAMEMODEL_HPP__

#include <array>
#include <map>
#include <string>
#include "../../lib-include/interface/ILibraryViewController.hpp"
#include "../../include/Protocol.hh"

class	IGameModel
{
private:
  virtual void  wait_second(int) = 0;
 public:
  virtual void setMap() = 0;
  virtual void drawMap(ILibraryViewController *libraryInstance) = 0;
  virtual bool	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &) = 0;
  virtual std::string getGameName() = 0;

  virtual ~IGameModel() {}
};

#endif /* IGAMEMODEL_HPP__ */
