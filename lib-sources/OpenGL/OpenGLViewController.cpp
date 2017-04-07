//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Fri Apr  7 14:14:09 2017 Matthias Prost
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
  else if (glfwGetKey(this->window, GLFW_KEY_4) == GLFW_PRESS)
      action = ChangeCommandType::PREV_GAME;
  else if (glfwGetKey(this->window, GLFW_KEY_5) == GLFW_PRESS)
      action = ChangeCommandType::NEXT_GAME;
  else if (glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_UP;
  else if (glfwGetKey(this->window, GLFW_KEY_DOWN) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_DOWN;
  else if (glfwGetKey(this->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_RIGHT;
  else if (glfwGetKey(this->window, GLFW_KEY_LEFT) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_LEFT;

  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name)
{
  if (!glfwInit())
    return;

  this->mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  if (!(this->window = glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());
  glfwMakeContextCurrent(this->window); // Initialize GLEW
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
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void	OpenGLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  (void)width;
  glPushMatrix();

  const Vector2f floatWindowSize((float)this->mode->width, (float)this->mode->height);
  const Vector2f floatObjectSize((float)20,(float)20);
  const Vector2f relativeObjectSize(floatObjectSize.x / floatWindowSize.x, floatObjectSize.y / floatWindowSize.y);
  const Vector2f relativeObjectPosition((x / floatWindowSize.x) * 2.0f, (y / floatWindowSize.y) * 2.0f);

  if (color == Color::BLUE)
    glColor3ub(33, 150, 243);
  else if (color == Color::BLACK)
    glColor3ub(0, 0, 0);
  else if (color == Color::MAGENTA)
    glColor3ub(33, 30, 99);
  else if (color == Color::RED)
    glColor3ub(244, 67, 54);
  else if (color == Color::GREEN)
    glColor3ub(76, 175, 80);
  else if (color == Color::CYAN)
    glColor3ub(0, 188, 212);
  else if (color == Color::YELLOW)
    glColor3ub(255, 193, 7);
  else if (color == Color::WHITE)
    glColor3ub(255, 255, 255);
  glTranslatef((relativeObjectPosition.x * floatObjectSize.x),
	       -(relativeObjectPosition.y * floatObjectSize.y), 0.0f);
  glBegin(GL_QUADS);

  glVertex2f(-relativeObjectSize.x - 0.35f, -relativeObjectSize.y + 0.55f);
  glVertex2f(relativeObjectSize.x - 0.35f,  -relativeObjectSize.y  + 0.55f);
  glVertex2f(relativeObjectSize.x - 0.35f,  relativeObjectSize.y  + 0.55f);
  glVertex2f(-relativeObjectSize.x - 0.35f, relativeObjectSize.y  + 0.55f);
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
