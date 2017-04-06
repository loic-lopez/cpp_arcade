//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Thu Apr  6 18:41:48 2017 Matthias Prost
//

#include <iostream>
#include "OpenGLViewController.hpp"

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

void	OpenGLViewController::drawMenu(size_t &currentGame, std::vector<std::string> const &games, bool &exit)
{
  (void)currentGame;
  (void)games;
  (void)exit;
}

bool	OpenGLViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  (void)commandType;
  // Compute new orientation
  if (glfwWindowShouldClose(this->window)
      || glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(this->window, GL_TRUE);
      exit = true;
      return (false);
    }
  else if (glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS)
      action = ChangeCommandType::NEXT_LIBRARY;
  else if (glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
      action = ChangeCommandType::PREV_LIBRARY;
  if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS)
    {

    }

  if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS)
    {

    }
  if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS)
    {

    }
  if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS)
    {

    }

  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name)
{
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_SAMPLES, 4);
  this->mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  if (!(this->window = glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());
  glfwMakeContextCurrent(this->window); // Initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
    {
      std::cerr << "Failed to initialize GLEW\n" << std::endl;
      return;
    }

  glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
  glfwPollEvents();
}

void	OpenGLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  (void)Game;
  (void)libraryName;
  (void)score;
  (void)width;
}

void	OpenGLViewController::endScreen()
{
  glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  glfwSwapBuffers(this->window);
  glfwPollEvents();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
#include <cmath>
class Vector2f {
 public:
  float x;
  float y;

  Vector2f(float x, float y);
  float GetLenght() const;
  void Normalize();
};

Vector2f::Vector2f(float x, float y) {
  this->x = x;
  this->y = y;
}

float Vector2f::GetLenght() const {
  return sqrt(this->x*this->x + this->y * this->y);
}

void Vector2f::Normalize() {
  float l = GetLenght();
  this->x /= l;
  this->y /= l;
}

void	OpenGLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  (void)x;
  (void)y;
  (void)color;
  (void)width;

  glPushMatrix();

  const Vector2f floatWindowSize((float) this->mode->width, this->mode->height);
  const Vector2f floatObjectSize((float) 10,(float)10);
  const Vector2f relativeObjectSize(floatObjectSize.x / floatWindowSize.x, floatObjectSize.y / floatWindowSize.y);
  const Vector2f relativeObjectPosition(x / floatWindowSize.x,   y / floatWindowSize.y);

  glTranslatef(relativeObjectPosition.x, relativeObjectPosition.y, 0.0f);

  glBegin(GL_QUADS);

  glVertex2f(-relativeObjectSize.x, -relativeObjectSize.y);
  glVertex2f(relativeObjectSize.x,  -relativeObjectSize.y);
  glVertex2f(relativeObjectSize.x,  relativeObjectSize.y);
  glVertex2f(-relativeObjectSize.x, relativeObjectSize.y);

  glEnd();
  glPopMatrix();
}

std::string	OpenGLViewController::getLibraryName()
{
  return ("OpenGL");
}

void  OpenGLViewController::gameOver(int score)
{
  (void)score;
}

void  OpenGLViewController::clear()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
