/*
** ILibraryViewController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ILibraryViewController.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. mars 17 15:03:52 2017 Loïc Lopez
** Last update Thu Mar 23 20:02:46 2017 Matthias Prost
*/

#ifndef ILIBRAYVIEWCONTROLLER_HPP__
# define ILIBRAYVIEWCONTROLLER_HPP__

#include <string>

class	ILibraryViewController
{
  public:
   enum class 		Key :	int
   {
     STANDBY		=	0,
     NEXT_GAME		=	1,
     PREV_GAME 		=	2,
     ESCAPE		=	3,
     UP   = 4,
     DOWN   = 5,
     LEFT   = 6,
     RIGHT  = 7,
   };

  virtual void drawMap(int, int) = 0;
  virtual void drawMenu() = 0;
  virtual bool getKey(Key &action, bool &exit) = 0;
  virtual void initScreen(std::string const &name) = 0;
  virtual void displayText(std::string const &) = 0;
  virtual void endScreen() = 0;
  virtual void setScore(int) = 0;
  virtual int  getScore() = 0;
  virtual void refresh() = 0;
  virtual void setUserXY(int, int) = 0;
  virtual int  getUserX() = 0;
  virtual int  getUserY() = 0;

  virtual ~ILibraryViewController() {}
};

#endif /* ILIBRAYVIEWCONTROLLER_HPP__ */
