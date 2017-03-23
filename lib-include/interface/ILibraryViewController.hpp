/*
** ILibraryViewController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ILibraryViewController.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 15:03:52 2017 Loïc Lopez
** Last update Thu Mar 23 11:14:01 2017 Matthias Prost
*/

#ifndef ILIBRAYVIEWCONTROLLER_HPP__
# define ILIBRAYVIEWCONTROLLER_HPP__

#include <map>
#include <array>


class	ILibraryViewController
{
 public:
   enum class Key : int
   {
     NEXT_GAME,
     PREV_GAME,
     ESCAPE,
   };


  virtual void drawMap(int, int) = 0;
  virtual void drawCharacter(std::array<int, 2> &position) = 0;
  virtual void drawMenu() = 0;
  virtual bool getKey(int key, Key &action, bool &exit) = 0;
  virtual void initScreen() = 0;
  virtual void displayText(std::string const &) = 0;
  virtual void endScreen() = 0;

  virtual ~ILibraryViewController() {}
};

#endif /* ILIBRAYVIEWCONTROLLER_HPP__ */
