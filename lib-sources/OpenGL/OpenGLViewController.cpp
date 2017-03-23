//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Thu Mar 23 20:04:47 2017 Matthias Prost
//

#include "OpenGLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

OpenGLViewController::OpenGLViewController()
{
  this->score = 0;
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

bool	OpenGLViewController::getKey(Key &action, bool &exit)
{
  (void)action;
  (void)exit;

  if (glfwWindowShouldClose(this->window)
      || glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
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
void	OpenGLViewController::initScreen(std::string const &name)
{
  const GLFWvidmode	*mode;

  /* Initialize the library */
  if (!glfwInit())
    return;
  // get size of screen;
  mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  /* Create a windowed mode window and its OpenGL context */
  if (!(this->window = glfwCreateWindow(mode->width, mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());

  glfwMakeContextCurrent(this->window);
}

void	OpenGLViewController::displayText(std::string const &str)
{
  (void)str;
}

void  OpenGLViewController::setUserXY(int x, int y)
{
  this->user_x = x;
  this->user_y = y;
}

int  OpenGLViewController::getUserX()
{
  return (this->user_x);
}

int  OpenGLViewController::getUserY()
{
  return (this->user_y);
}

void	OpenGLViewController::endScreen()
{
  glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  glClear(GL_COLOR_BUFFER_BIT);
  /* Swap front and back buffers */
  glfwSwapBuffers(this->window);
  /* Poll for and process events */
  glfwPollEvents();
}

void	OpenGLViewController::drawMap(int mapsize_x, int mapsize_y)
{
  (void)mapsize_x;
  (void)mapsize_y;
}