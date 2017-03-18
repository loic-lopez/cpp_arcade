//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update jeu. mars 16 15:07:20 2017 Loïc Lopez
//

#ifndef SFMLCONTROLLER_HPP__
# define SFMLCONTROLLER_HPP__

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class SFMLViewController : public ILibraryViewController
{
  virtual ~SFMLViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
};

#endif /* SFMLCONTROLLER_HPP__ */