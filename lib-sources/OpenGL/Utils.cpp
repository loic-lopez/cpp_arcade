/*
** Utils.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Utils.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 08 19:10:42 2017 Loïc Lopez
** Last update sam. avr. 08 19:10:42 2017 Loïc Lopez
*/

#include "OpenGLViewController.hpp"

void	print(float x, float y, std::string str)
{
  OpenGL::_glMatrixMode(GL_MODELVIEW);
  OpenGL::_glPushMatrix();
  OpenGL::_glLoadIdentity();
  OpenGL::_glRasterPos2f(x, y);
  for (size_t i = 0; i < str.size(); ++i)
    OpenGL::_glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  OpenGL::_glPopMatrix();
}