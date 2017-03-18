//
// NcursesController.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update jeu. mars 16 15:05:35 2017 Loïc Lopez
//

#ifndef NCURSESVIEWCONTROLLER_HPP__
# define NCURSESVIEWCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class NcursesViewController : public ILibraryViewController
{
 public:
  virtual ~NcursesViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
};

#endif /* NCURSESVIEWCONTROLLER_HPP__ */