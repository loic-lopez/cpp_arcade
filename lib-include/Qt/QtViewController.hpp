//
// Qt.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Qt.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Mon Mar 20 10:56:02 2017 Matthias Prost
//

#ifndef QTCONTROLLER_HPP__
# define QTCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class QtViewController : public ILibraryViewController
{
  virtual ~QtViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void loadScreen();
};

#endif /* QTCONTROLLER_HPP__ */
