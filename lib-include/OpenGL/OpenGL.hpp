/*
** OpenGL.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 08 21:53:11 2017 Loïc Lopez
** Last update sam. avr. 08 21:53:11 2017 Loïc Lopez
*/

#ifndef OPENGL_HPP
#define OPENGL_HPP
#include "OpenGL_Include/GL/glew.h"
#include <GL/glut.h>
#include <linux/limits.h>
#include <unistd.h>
#include "OpenGL_Include/GLFW/glfw3.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include "Vector2f.hpp"

class	OpenGL
{
 public:
  OpenGL();
  static ssize_t _readlink(const char *__restrict __path,
			  char *__restrict __buf, size_t __len);
  static void _glutInit( int* pargc, char** argv );
  static int _glfwWindowShouldClose(GLFWwindow* window);
  static int _glfwGetKey(GLFWwindow* window, int key);
  static void _glfwSetWindowShouldClose(GLFWwindow* window, int value);
  static const GLFWvidmode* _glfwGetVideoMode(GLFWmonitor* monitor);
  static GLFWmonitor* _glfwGetPrimaryMonitor(void);
  static GLFWwindow* _glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
  static GLFWcharfun _glfwSetCharCallback(GLFWwindow* window, GLFWcharfun cbfun);
  static void _glfwMakeContextCurrent(GLFWwindow* window);
  static void _glfwSetInputMode(GLFWwindow* window, int mode, int value);
  static void _glfwDestroyWindow(GLFWwindow* window);
  static void _glfwTerminate(void);
  static void _glfwPollEvents(void);
  static void _glfwSwapBuffers(GLFWwindow* window);
  static void _glMatrixMode (GLenum mode);
  static void _glLoadIdentity (void);
  static void _glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
  static void _glPushAttrib (GLbitfield mask);
  static void _glPushMatrix (void);
  static void _glColor3ub (GLubyte red, GLubyte green, GLubyte blue);
  static void _glTranslatef (GLfloat x, GLfloat y, GLfloat z);
  static void _glBegin (GLenum mode);
  static void _glVertex2f (GLfloat x, GLfloat y);
  static void _glEnd (void);
  static void _glPopAttrib (void);
  static void _glPopMatrix (void);
  static void _glClear (GLbitfield mask);
  static void _glRasterPos2f (GLfloat x, GLfloat y);
  static void _glutBitmapCharacter( void* font, int character );
  static void _glfwSetClipboardString(GLFWwindow* window, const char* string);
  static int _glfwInit(void);
};

#endif /* OPENGL_HPP */