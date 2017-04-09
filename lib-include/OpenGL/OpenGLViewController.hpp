//
// OpenGL.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Fri Apr  7 21:28:19 2017 Matthias Prost
//

#ifndef OpenGLCONTROLLER_HPP__
# define OpenGLCONTROLLER_HPP__
#include "../interface/ILibraryViewController.hpp"
#include "OpenGL.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class OpenGLViewController : public ILibraryViewController
{
 private:
  GLFWwindow		*window;
  const GLFWvidmode	*mode;
  bool 			playGameOver;
  std::string		playerName;

 public:
  OpenGLViewController();
  virtual ~OpenGLViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &);
  virtual void drawMenu(size_t &currentGame, std::vector<std::string> const &games,
			bool &exit, size_t &currentLibrary,
			ChangeCommandType &action, std::string &playerName);
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name, std::string const &playerName);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void clear();
  virtual void gameOver(int);
  virtual void win(int);
  virtual std::string	getLibraryName() const;
  virtual void	displayPlayerName();
};

void	print(float x, float y, std::string str);

#endif /* OpenGLCONTROLLER_HPP__ */
