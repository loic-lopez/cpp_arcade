//
// OpenGL.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Tue Mar 21 21:07:35 2017 Matthias Prost
//

#ifndef OpenGLCONTROLLER_HPP__
# define OpenGLCONTROLLER_HPP__

#include <GLFW/glfw3.h>

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class OpenGLViewController : public ILibraryViewController
{
 public:
  OpenGLViewController();
  virtual ~OpenGLViewController();

  // Methods
  virtual void drawMap(std::map<int, int> &);
  virtual void drawCharacter(std::array<int, 2> &position);
  virtual void drawMenu();
  virtual bool getEscapeKey(int &);
  virtual void initScreen();
  virtual void displayText(std::string const &);
  virtual void endScreen();
};

#endif /* OpenGLCONTROLLER_HPP__ */
