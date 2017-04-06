//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Mon Apr  3 02:47:07 2017 Matthias Prost
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
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	{
	  exit = true;
	  return (false);
	}
      if (event.type == SDL_KEYDOWN)
	{
	  SDLKey keyPressed = event.key.keysym.sym;
	  if (keyPressed == SDLK_ESCAPE)
	    {
	      exit = true;
	      return (false);
	    }
	  else if (keyPressed == SDLK_2)
	    {
	      action = ChangeCommandType::PREV_LIBRARY;
	      return (true);
	    }
	  else if (keyPressed == SDLK_3)
	    {
	      action = ChangeCommandType::NEXT_LIBRARY;
	      return (true);
	    }
	  else if (keyPressed == SDLK_4)
	    {
	      action = ChangeCommandType::PREV_GAME;
	      return (true);
	    }
	  else if (keyPressed == SDLK_5)
	    {
	      action = ChangeCommandType::NEXT_GAME;
	      return (true);
	    }
	  else if (keyPressed == SDLK_UP)
	    {
	      *commandType = arcade::CommandType::GO_UP;
	      return (true);
	    }
	  else if (keyPressed == SDLK_DOWN)
	    {
	      *commandType = arcade::CommandType::GO_DOWN;
	      return (true);
	    }
	  else if (keyPressed == SDLK_LEFT)
	    {
	      *commandType = arcade::CommandType::GO_LEFT;
	      return (true);
	    }
	  else if (keyPressed == SDLK_RIGHT)
	    {
	      *commandType = arcade::CommandType::GO_RIGHT;
	      return (true);
	    }
	}
    }
  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption(name.c_str(),NULL);
  SDL_SetVideoMode(1280, 720, 32, SDL_OPENGL);
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
  SDL_Quit();
}

void  OpenGLViewController::refresh()
{
  glFlush();
  SDL_GL_SwapBuffers();
}

void	OpenGLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  glBegin(GL_QUADS);
  glColor3ub(0,0,255);
  glVertex2d(-0.75,-0.75);
  glVertex2d(-0.75,0.75);
  glColor3ub(255,0,0);
  glVertex2d(0.75,0.75);
  glVertex2d(0.75,-0.75);
  (void)x;
  (void)y;
  (void)color;
  (void)width;
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
  glClear(GL_COLOR_BUFFER_BIT);
}