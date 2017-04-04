//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Mon Apr  3 02:40:45 2017 Matthias Prost
//

#ifndef NCURSESVIEWCONTROLLER_HPP__
# define NCURSESVIEWCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"
#include "NcursesEncap.hpp"
#include "menu.h"

extern "C" ILibraryViewController	*loadLibrary();

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]));

class NcursesViewController : public ILibraryViewController
{
  private:
    int   windowsize_x;
    int   windowsize_y;

 public:
  virtual ~NcursesViewController();
  NcursesViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &);
  virtual void drawMenu(size_t &currentGame);
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void gameOver(int);
  virtual void clear();
  virtual std::string	getLibraryName();
};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */
