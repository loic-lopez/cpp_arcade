//
// OpenGL.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Thu Mar 23 20:04:22 2017 Matthias Prost
//

#ifndef OpenGLCONTROLLER_HPP__
# define OpenGLCONTROLLER_HPP__

#include <GLFW/glfw3.h>

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class OpenGLViewController : public ILibraryViewController
{
 private:
  GLFWwindow	*window;
  int   score;
  int   user_x;
  int   user_y;

 public:
  OpenGLViewController();
  virtual ~OpenGLViewController();

  // Methods
  virtual void drawMap(int mapsize_x, int mapsize_y);
  virtual void drawMenu();
  virtual bool getKey(Key &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayText(std::string const &, std::string const &) const;
  virtual void endScreen();
  virtual void setScore(int);
  virtual int  getScore();
  virtual void refresh();
  virtual void setUserXY(int, int);
  virtual int  getUserX();
  virtual int  getUserY();
  virtual std::string	getLibraryName();
};

#endif /* OpenGLCONTROLLER_HPP__ */
