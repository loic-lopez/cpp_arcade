//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Mon Mar 20 10:57:14 2017 Matthias Prost
//

#include "OpenGLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

OpenGLViewController::~OpenGLViewController()
{

}

void	OpenGLViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	OpenGLViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

#include <iostream>

void	OpenGLViewController::loadScreen()
{
  std::cout << "Library LOADED" << std::endl;
}
