//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Mon Mar 27 16:15:58 2017 Matthias Prost
//

#ifndef NCURSESVIEWCONTROLLER_HPP__
# define NCURSESVIEWCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"
#include "NcursesEncap.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class NcursesViewController : public ILibraryViewController
{
  private:
    int   windowsize_x;
    int   windowsize_y;
    int   mapsize_x;
    int   mapsize_y;
    int   score;
    int   user_x;
    int   user_y;

 public:
  virtual ~NcursesViewController();
  NcursesViewController();

  // Methods
  virtual void drawSquare(int x, int y, Color const &);
  virtual void drawMenu();
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayScore(std::string const &, std::string const &) const;
  virtual void endScreen();
  virtual void setScore(int);
  virtual int  getScore();
  virtual void refresh();
  virtual std::string	getLibraryName();
};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */
