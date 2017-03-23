//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Thu Mar 23 14:47:11 2017 Matthias Prost
//

#include "OpenGLViewController.hpp"
#include <GL/gl.h>

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

OpenGLViewController::OpenGLViewController()
{

}

OpenGLViewController::~OpenGLViewController()
{

}

void  OpenGLViewController::setScore(int score)
{
  this->score = score;
}

int  OpenGLViewController::getScore()
{
  return (this->score);
}

void	OpenGLViewController::drawMenu()
{
}

void	OpenGLViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

bool	OpenGLViewController::getKey(Key &action, bool &exit)
{
  if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      exit = true;
      return (false);
    }
  else if (glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS)
      action = ILibraryViewController::Key::NEXT_GAME;
  else if (glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
      action = ILibraryViewController::Key::PREV_GAME;
  return (true);
}

// Changer et enlever la boucle pour intégrer aux jeux
void	OpenGLViewController::initScreen()
{
  const GLFWvidmode	*mode;

  /* Initialize the library */
  if (!glfwInit())
    return;
  // get size of screen;
  mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  /* Create a windowed mode window and its OpenGL context */
  if (!(this->window = glfwCreateWindow(mode->width, mode->height, "Hello World", NULL, NULL)))
      return (this->endScreen());

  glfwMakeContextCurrent(this->window);
}

void	OpenGLViewController::displayText(std::string const &str)
{
  (void)str;
  glClear(GL_COLOR_BUFFER_BIT);
  /* Swap front and back buffers */
  glfwSwapBuffers(this->window);
  /* Poll for and process events */
  glfwPollEvents();
}

void	OpenGLViewController::endScreen()
{
  glfwTerminate();
}
