/*
** ILibraryViewController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ILibraryViewController.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 15:03:52 2017 Loïc Lopez
** Last update ven. mars 17 15:03:52 2017 Loïc Lopez
*/

#ifndef ILIBRAYVIEWCONTROLLER_HPP__
# define ILIBRAYVIEWCONTROLLER_HPP__

#include <map>
#include <array>

class	ILibraryViewController
{
 public:
  virtual void drawMap(std::map<int, int> &) = 0;
  virtual void drawCharacter(std::array<int, 2> &position) = 0;
  virtual void drawMenu() = 0;


  virtual ~ILibraryViewController() {}
};

#endif /* ILIBRAYVIEWCONTROLLER_HPP__ */
