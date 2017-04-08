
//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Sat Apr  8 13:07:22 2017 Matthias Prost
//

#include "OpenGLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

char	*program_path()
{
  char *path = new char[PATH_MAX];
  if (readlink("/proc/self/exe", path, PATH_MAX) == -1)
    {
	  free(path);
	  path = NULL;
    }
  path[sizeof(path)] = '\0';
  return (path);
}

OpenGLViewController::OpenGLViewController()
{
  int 		pac = 1;
  char	*pav[] = {program_path()};

  glutInit(&pac, pav);
}

OpenGLViewController::~OpenGLViewController()
{

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
  else if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS)
    *commandType = arcade::CommandType::SHOOT;
  else if (glfwGetKey(this->window, GLFW_KEY_8) == GLFW_PRESS)
    {
      *commandType = arcade::CommandType::RESTART;
      this->playGameOver = false;
    }
  else if (glfwGetKey(this->window, GLFW_KEY_9) == GLFW_PRESS)
    {
      this->playGameOver = false;
      action = ChangeCommandType::DISPLAY_MENU;
    }
  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name)
{
  if (!glfwInit())
    return;
  this->mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  if (!(this->window = glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());
  glfwMakeContextCurrent(this->window);
  glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
}


void	OpenGLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  print(-0.05f, 0.85f, Game);
  print(-0.05f, 0.80f, libraryName);
  print(-0.05f, 0.75f, "Score");
  print(0.05f, 0.75f, std::to_string(score));
  (void)width;
}

void	OpenGLViewController::endScreen()
{
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  glfwPollEvents();
  glfwSwapBuffers(this->window);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glViewport(0,0, this->mode->width, this->mode->height);
}

void	OpenGLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  (void)width;
  glPushAttrib( GL_CURRENT_BIT );
  glPushMatrix();

  const Vector2f floatWindowSize(static_cast<float>(this->mode->width / 2.0f), static_cast<float>(this->mode->height / 2.0f));
  const Vector2f floatObjectSize(static_cast<float>(8),static_cast<float>(8));
  const Vector2f relativeObjectSize(floatObjectSize.x / floatWindowSize.x, floatObjectSize.y / floatWindowSize.y);
  const Vector2f relativeObjectPosition((x / floatWindowSize.x) * 2.0f, (y / floatWindowSize.y) * 2.0f);

  switch (color)
  {
    case Color::BLUE:
      glColor3ub(33, 150, 243);
      break;
    case Color::BLACK:
      glColor3ub(0, 0, 0);
      break;
    case Color::MAGENTA:
      glColor3ub(33, 30, 99);
      break;
    case Color::RED:
      glColor3ub(244, 67, 54);
      break;
    case Color::GREEN:
      glColor3ub(76, 175, 80);
      break;
    case Color::CYAN:
      glColor3ub(0, 188, 212);
      break;
    case Color::YELLOW:
      glColor3ub(255, 193, 7);
      break;
    case Color::WHITE:
      glColor3ub(255, 255, 255);
      break;
    case Color::SHIP:
      glColor3ub(33, 150, 243);
      break;
    case Color::ENNEMY:
      glColor3ub(244, 67, 54);
      break;
    case Color::LASER:
      glColor3ub(76, 175, 80);
      break;
    case Color::ENNEMY_LASER:
      glColor3ub(33, 30, 99);
      break;
    case Color::SNAKE_BODY:
      glColor3ub(244, 67, 54);
      break;
    case Color::SNAKE_HEAD:
      glColor3ub(33, 30, 99);
      break;
    case Color::APPLE:
      glColor3ub(76, 175, 80);
      break;
  }

  glTranslatef((relativeObjectPosition.x * floatObjectSize.x),
	       -(relativeObjectPosition.y * floatObjectSize.y), 0.0f);
  glBegin(GL_QUADS);
  glVertex2f(-relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     -relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  glVertex2f(relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x)  * floatObjectSize.x,
	     -relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  glVertex2f(relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  glVertex2f(-relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  glEnd();
  glPopAttrib();
  glPopMatrix();
}

std::string	OpenGLViewController::getLibraryName()
{
  return ("OpenGL");
}

void  OpenGLViewController::gameOver(int score)
{
  if (!this->playGameOver)
    this->playGameOver = true;
  print(-0.05f, 0.80f, "Game Over");
  print(-0.05f, 0.75f, "Score");
  print(0.05f, 0.75f, std::to_string(score));
}

void  OpenGLViewController::win(int score)
{
  if (!this->playGameOver)
    this->playGameOver = true;
  print(-0.05f, 0.80f, "Win");
  print(-0.05f, 0.75f, "Score");
  print(0.05f, 0.75f, std::to_string(score));
}

void  OpenGLViewController::clear()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
