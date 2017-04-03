//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Mon Apr  3 02:40:27 2017 Matthias Prost
//

#ifndef SFMLCONTROLLER_HPP__
# define SFMLCONTROLLER_HPP__

#include <SFML/Graphics.hpp>
#include "../interface/ILibraryViewController.hpp"
#include <iostream>

extern "C" ILibraryViewController	*loadLibrary();

class SFMLViewController : public ILibraryViewController
{
private:
  sf::RenderWindow window;
  sf::RectangleShape rectangle;
  int   windowsize_x;
  int   windowsize_y;
  int   mapsize_x;
  int   mapsize_y;
  int   user_x;
  int   user_y;

 public:
  virtual ~SFMLViewController();
  SFMLViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &color);
  virtual void drawMenu();
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void clear();
  virtual void gameOver(int);
  virtual std::string	getLibraryName();
};

#endif /* SFMLCONTROLLER_HPP__ */
