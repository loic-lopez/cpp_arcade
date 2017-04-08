//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Fri Apr  7 21:28:40 2017 Matthias Prost
//

#ifndef NCURSESVIEWCONTROLLER_HPP__
# define NCURSESVIEWCONTROLLER_HPP__

#include <algorithm>
#include <signal.h>
#include "../interface/ILibraryViewController.hpp"
#include "NcursesEncap.hpp"
#include "menu.hpp"

extern "C" ILibraryViewController	*loadLibrary();

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define _KEY_ENTER 10
#define _KEY_ESC	27

class NcursesViewController : public ILibraryViewController
{
 private:
  int   windowsize_x;
  int   windowsize_y;
  MENU	*menu;
  WINDOW	*menu_win;
  ITEM	*my_items[4];
  bool	playGameOver;
  std::string	functionCaller;
  std::string	playerName;
  int 		width;

 public:
  virtual ~NcursesViewController();
  NcursesViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &);
  virtual void drawMenu(size_t &currentGame, std::vector<std::string> const &games,
			bool &exit, size_t &currentLibrary, ChangeCommandType &action, std::string &);
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name, std::string const &);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void gameOver(int);
  virtual void win(int);
  virtual void clear();
  virtual std::string	getLibraryName() const;
  virtual void	displayPlayerName();

};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */
