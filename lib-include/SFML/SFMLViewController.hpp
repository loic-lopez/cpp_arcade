//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Tue Mar 21 21:07:38 2017 Matthias Prost
//

#ifndef SFMLCONTROLLER_HPP__
# define SFMLCONTROLLER_HPP__

#include <SFML/Graphics.hpp>
#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class SFMLViewController : public ILibraryViewController
{
private:
  sf::RenderWindow window;
 public:
  virtual ~SFMLViewController();
  SFMLViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
  virtual bool getEscapeKey(int &);
  virtual void initScreen();
  virtual void displayText(std::string const &);
  virtual void endScreen();
};

#endif /* SFMLCONTROLLER_HPP__ */
