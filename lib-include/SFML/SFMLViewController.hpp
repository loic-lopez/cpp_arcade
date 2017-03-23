//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Thu Mar 23 19:56:29 2017 Matthias Prost
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
  int   windowsize_x;
  int   windowsize_y;
  int   mapsize_x;
  int   mapsize_y;
  int   score;
  int   user_x;
  int   user_y;

 public:
  virtual ~SFMLViewController();
  SFMLViewController();

  // Methods
  virtual void drawMap(int, int);
  virtual void drawMenu();
  virtual bool getKey(Key &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayText(std::string const &);
  virtual void endScreen();
  virtual void setScore(int);
  virtual int  getScore();
  virtual void refresh();
  virtual void setUserXY(int, int);
  virtual int  getUserX();
  virtual int  getUserY();
};

#endif /* SFMLCONTROLLER_HPP__ */
