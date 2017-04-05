//
// OpenGL.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Mon Apr  3 02:46:43 2017 Matthias Prost
//

#ifndef OpenGLCONTROLLER_HPP__
# define OpenGLCONTROLLER_HPP__

#define GLEW_STATIC
#define GLM_FORCE_RADIANS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <fstream>
#include <iostream>

#include "../interface/ILibraryViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary();

class OpenGLViewController : public ILibraryViewController
{
 private:
  GLFWwindow		*window;
  GLuint			vertexbuffer;
  GLuint			colorbuffer;
  GLuint			VertexArrayID;
  GLuint 		programID;
  GLuint 		MatrixID;
  const GLFWvidmode	*mode;
  glm::mat4		View;
  glm::mat4 		Projection;
  glm::mat4		Model;
  glm::mat4		MVP;
  float 			horizontalAngle;
  float 			verticalAngle;
  float 			FoV;
  float 			speed;
  double 			lastTime;
  glm::vec3 		camera;
  int   			user_x;
  int   			user_y;

 public:
  OpenGLViewController();
  virtual ~OpenGLViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &);
  virtual void drawMenu(size_t &currentGame, std::vector<std::string> const &games, bool &exit);
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void clear();
  virtual void gameOver(int);
  virtual std::string	getLibraryName();
};

// DEFINED IN /lib-sources/OpenGL/LoadShaders.cpp
GLuint	LoadShaders(const char	*vertex_file_path, const char 	*fragment_file_path);

#endif /* OpenGLCONTROLLER_HPP__ */
