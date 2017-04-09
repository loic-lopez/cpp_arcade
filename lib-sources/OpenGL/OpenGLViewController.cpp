
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

bool 			isLoaded = false;

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

char	*program_path()
{
  char *path = new char[PATH_MAX];
  if (OpenGL::_readlink("/proc/self/exe", path, PATH_MAX) == -1)
    path = NULL;
  path[sizeof(path)] = '\0';
  return (path);
}

OpenGLViewController::OpenGLViewController()
{
  if (!isLoaded)
    {
      int 		pac = 1;
      char	*pav[] = {program_path()};

      OpenGL::_glutInit(&pac, pav);
      isLoaded = true;
    }
}

OpenGLViewController::~OpenGLViewController()
{

}

bool	OpenGLViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  (void)commandType;
  // Compute new orientation
  if (OpenGL::_glfwWindowShouldClose(this->window)
      || OpenGL::_glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      OpenGL::_glfwSetWindowShouldClose(this->window, GL_TRUE);
      exit = true;
      return (false);
    }
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS)
      action = ChangeCommandType::NEXT_LIBRARY;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
      action = ChangeCommandType::PREV_LIBRARY;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_4) == GLFW_PRESS)
      action = ChangeCommandType::PREV_GAME;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_5) == GLFW_PRESS)
      action = ChangeCommandType::NEXT_GAME;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_UP;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_DOWN) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_DOWN;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_RIGHT;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_LEFT) == GLFW_PRESS)
      *commandType = arcade::CommandType::GO_LEFT;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS)
    *commandType = arcade::CommandType::SHOOT;
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_8) == GLFW_PRESS)
    {
      *commandType = arcade::CommandType::RESTART;
      this->playGameOver = false;
    }
  else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_9) == GLFW_PRESS)
    {
      this->playGameOver = false;
      action = ChangeCommandType::DISPLAY_MENU;
    }
  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name, std::string const &playername)
{
  if (!OpenGL::_glfwInit())
    return;
  this->mode = OpenGL::_glfwGetVideoMode(OpenGL::_glfwGetPrimaryMonitor());
  if (!(this->window = OpenGL::_glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());
  OpenGL::_glfwMakeContextCurrent(this->window);
  OpenGL::_glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
  this->playerName = "Player Name: " + playername;
  glfwSwapInterval(1);
}


void	OpenGLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  print(-0.05f, 0.85f, Game);
  print(-0.05f, 0.80f, libraryName);
  print(-0.05f, 0.75f, "Score");
  print(0.05f, 0.75f, std::to_string(score));
  static_cast<void>(width);
}

void	OpenGLViewController::endScreen()
{
  OpenGL::_glfwDestroyWindow(this->window);
  OpenGL::_glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  OpenGL::_glfwSwapBuffers(this->window);
  OpenGL::_glfwPollEvents();
  this->clear();
  OpenGL::_glMatrixMode(GL_MODELVIEW);
  OpenGL::_glLoadIdentity();
  OpenGL::_glViewport(0,0, this->mode->width, this->mode->height);
}

void	OpenGLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  OpenGL::_glPushAttrib( GL_CURRENT_BIT );
  OpenGL::_glPushMatrix();

  const Vector2f floatWindowSize(static_cast<float>(this->mode->width / 2.0f), static_cast<float>(this->mode->height / 2.0f));
  const Vector2f floatObjectSize(static_cast<float>(8),static_cast<float>(8));
  const Vector2f relativeObjectSize(floatObjectSize.x / floatWindowSize.x, floatObjectSize.y / floatWindowSize.y);
  const Vector2f relativeObjectPosition((x / floatWindowSize.x) * 2.0f, (y / floatWindowSize.y) * 2.0f);

  switch (color)
  {
    case Color::BLUE:
      OpenGL::_glColor3ub(33, 150, 243);
      break;
    case Color::BLACK:
      OpenGL::_glColor3ub(0, 0, 0);
      break;
    case Color::MAGENTA:
      OpenGL::_glColor3ub(33, 30, 99);
      break;
    case Color::RED:
      OpenGL::_glColor3ub(244, 67, 54);
      break;
    case Color::GREEN:
      OpenGL::_glColor3ub(76, 175, 80);
      break;
    case Color::CYAN:
      OpenGL::_glColor3ub(0, 188, 212);
      break;
    case Color::YELLOW:
      OpenGL::_glColor3ub(255, 193, 7);
      break;
    case Color::WHITE:
      OpenGL::_glColor3ub(255, 255, 255);
      break;
    case Color::SHIP:
      OpenGL::_glColor3ub(33, 150, 243);
      break;
    case Color::ENNEMY:
      OpenGL::_glColor3ub(244, 67, 54);
      break;
    case Color::LASER:
      OpenGL::_glColor3ub(76, 175, 80);
      break;
    case Color::ENNEMY_LASER:
      OpenGL::_glColor3ub(33, 30, 99);
      break;
    case Color::SNAKE_BODY:
      OpenGL::_glColor3ub(244, 67, 54);
      break;
    case Color::SNAKE_HEAD:
      OpenGL::_glColor3ub(33, 30, 99);
      break;
    case Color::APPLE:
      OpenGL::_glColor3ub(76, 175, 80);
      break;
  }

  OpenGL::_glTranslatef((relativeObjectPosition.x * floatObjectSize.x),
	       -(relativeObjectPosition.y * floatObjectSize.y), 0.0f);
  OpenGL::_glBegin(GL_QUADS);
  OpenGL::_glVertex2f(-relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     -relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  OpenGL::_glVertex2f(relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x)  * floatObjectSize.x,
	     -relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  OpenGL::_glVertex2f(relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  OpenGL::_glVertex2f(-relativeObjectSize.x - (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.x,
	     relativeObjectSize.y + (static_cast<float>(width) / floatWindowSize.x) * floatObjectSize.y);
  OpenGL::_glEnd();
  OpenGL::_glPopMatrix();
  OpenGL::_glPopAttrib();
}

std::string	OpenGLViewController::getLibraryName() const
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
  OpenGL::_glClear(GL_COLOR_BUFFER_BIT);
}

void	OpenGLViewController::displayPlayerName()
{
  print(-0.05f, 0.70f, this->playerName);
}