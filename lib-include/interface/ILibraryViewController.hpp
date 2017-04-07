/*
** ILibraryViewController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ILibraryViewController.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 15:03:52 2017 Loïc Lopez
// Last update Fri Apr  7 21:31:24 2017 Matthias Prost
*/

#ifndef ILIBRAYVIEWCONTROLLER_HPP__
# define ILIBRAYVIEWCONTROLLER_HPP__

#include <string>
#include <vector>
#include "../../include/Protocol.hh"
#include "../../include/ArcadeEnum.hpp"

class	ILibraryViewController
{
  public:
  virtual void drawSquare(int width, int x, int y, Color const &) = 0;
  virtual void drawMenu(size_t &currentGame, std::vector<std::string> const &games, bool &exit) = 0;
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit) = 0;
  virtual void initScreen(std::string const &name) = 0;
  virtual void displayScore(int width, std::string const &, std::string const &, int) = 0;
  virtual void endScreen() = 0;
  virtual void refresh() = 0;
  virtual void clear() = 0;
  virtual void gameOver(int) = 0;
  virtual std::string	getLibraryName() = 0;
  virtual void win(int) = 0;

  virtual ~ILibraryViewController() {}
};

#endif /* ILIBRAYVIEWCONTROLLER_HPP__ */
