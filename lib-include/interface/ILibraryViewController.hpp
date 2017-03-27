/*
** ILibraryViewController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ILibraryViewController.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 15:03:52 2017 Loïc Lopez
// Last update Fri Mar 24 08:42:10 2017 Yassir Jabbari
*/

#ifndef ILIBRAYVIEWCONTROLLER_HPP__
# define ILIBRAYVIEWCONTROLLER_HPP__

#include <string>
#include "../../include/Protocol.hh"
#include "../../include/ArcadeEnum.hpp"

class	ILibraryViewController
{
  public:
  virtual void drawSquare(int x, int y, Color const &) = 0;
  virtual void drawMenu() = 0;
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit) = 0;
  virtual void initScreen(std::string const &name) = 0;
  virtual void displayText(std::string const &, std::string const &) const = 0;
  virtual void endScreen() = 0;
  virtual void setScore(int) = 0;
  virtual int  getScore() = 0;
  virtual void refresh() = 0;
  virtual std::string	getLibraryName() = 0;

  virtual ~ILibraryViewController() {}
};

#endif /* ILIBRAYVIEWCONTROLLER_HPP__ */
