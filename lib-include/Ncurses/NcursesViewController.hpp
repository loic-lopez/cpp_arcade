//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Tue Mar 21 21:07:13 2017 Matthias Prost
//

#ifndef NCURSESVIEWCONTROLLER_HPP__
# define NCURSESVIEWCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"
#include "NcursesEncap.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class NcursesViewController : public ILibraryViewController
{
 public:
  virtual ~NcursesViewController();
  NcursesViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
  virtual bool getEscapeKey(int &);
  virtual void initScreen();
  virtual void displayText(std::string const &);
  virtual void endScreen();
};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */
