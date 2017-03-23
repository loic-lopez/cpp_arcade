//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Thu Mar 23 14:04:30 2017 Matthias Prost
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
 public:
  virtual ~NcursesViewController();
  NcursesViewController();

  // Methods
  virtual void drawMap(int mapsize_x, int mapsize_y);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
  virtual bool getKey(Key &action, bool &exit);
  virtual void initScreen();
  virtual void displayText(std::string const &);
  virtual void endScreen();
};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */
