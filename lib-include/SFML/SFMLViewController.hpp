//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Thu Mar 23 16:57:29 2017 Matthias Prost
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
  int   score;
  int   user_x;
  int   user_y;
 public:
  virtual ~SFMLViewController();
  SFMLViewController();

  // Methods
  virtual void drawMap(int mapsize_x, int mapsize_y);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
  virtual bool getKey(Key &action, bool &exit);
  virtual void initScreen();
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
