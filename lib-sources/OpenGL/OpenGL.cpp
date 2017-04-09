/*
** OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 08 21:53:11 2017 Loïc Lopez
** Last update sam. avr. 08 21:53:11 2017 Loïc Lopez
*/

#include "OpenGL.hpp"

OpenGL::OpenGL()
{
}

ssize_t	OpenGL::_readlink(const char *__path, char *__buf, size_t __len)
{
  return (readlink(__path, __buf, __len));
}
void OpenGL::_glutInit(int *pargc, char **argv)
{
  glutInit(pargc, argv);
}

int OpenGL::_glfwWindowShouldClose(GLFWwindow *window)
{
  return (glfwWindowShouldClose(window));
}

int OpenGL::_glfwGetKey(GLFWwindow *window, int key)
{
  return (glfwGetKey(window, key));
}

void OpenGL::_glfwSetInputMode(GLFWwindow *window, int mode, int value)
{
  glfwSetInputMode(window, mode, value);
}

void OpenGL::_glfwSetWindowShouldClose(GLFWwindow *window, int value)
{
  glfwSetWindowShouldClose(window, value);
}

const GLFWvidmode* OpenGL::_glfwGetVideoMode(GLFWmonitor *monitor)
{
  return (glfwGetVideoMode(monitor));
}

GLFWmonitor* OpenGL::_glfwGetPrimaryMonitor()
{
  return (glfwGetPrimaryMonitor());
}
GLFWwindow* OpenGL::_glfwCreateWindow(int width, int height, const char *title,
				     GLFWmonitor *monitor, GLFWwindow *share)
{
  return (glfwCreateWindow(width, height, title, monitor, share));
}

void OpenGL::_glfwMakeContextCurrent(GLFWwindow *window)
{
  glfwMakeContextCurrent(window);
}

void OpenGL::_glfwDestroyWindow(GLFWwindow *window)
{
  glfwDestroyWindow(window);
}

void OpenGL::_glfwTerminate()
{
  glfwTerminate();
}

void OpenGL::_glfwPollEvents()
{
  glfwPollEvents();
}

void OpenGL::_glfwSwapBuffers(GLFWwindow *window)
{
  glfwSwapBuffers(window);
}

void OpenGL::_glMatrixMode(GLenum mode)
{
  glMatrixMode(mode);
}

void OpenGL::_glLoadIdentity()
{
  glLoadIdentity();
}

void OpenGL::_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
  glViewport(x, y, width, height);
}

void OpenGL::_glPushAttrib(GLbitfield mask)
{
  glPushAttrib(mask);
}

void OpenGL::_glPushMatrix()
{
  glPushMatrix();
}

void OpenGL::_glColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
  glColor3ub(red, green, blue);
}

void OpenGL::_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
  glTranslatef(x, y, z);
}
void OpenGL::_glBegin(GLenum mode)
{
  glBegin(mode);
}

void OpenGL::_glVertex2f(GLfloat x, GLfloat y)
{
  glVertex2f(x, y);
}

void OpenGL::_glEnd()
{
  glEnd();
}
void OpenGL::_glPopAttrib()
{
  glPopAttrib();
}

void OpenGL::_glPopMatrix()
{
  glPopMatrix();
}

void OpenGL::_glClear(GLbitfield mask)
{
  glClear(mask);
}

void OpenGL::_glRasterPos2f(GLfloat x, GLfloat y)
{
  glRasterPos2f(x, y);
}

void OpenGL::_glutBitmapCharacter(void *font, int character)
{
  glutBitmapCharacter(font, character);
}

void OpenGL::_glfwSetClipboardString(GLFWwindow* window, const char* string)
{
  glfwSetClipboardString(window, string);
}

GLFWcharfun OpenGL::_glfwSetCharCallback(GLFWwindow *window, GLFWcharfun cbfun)
{
  return (glfwSetCharCallback(window, cbfun));
}

int OpenGL::_glfwInit()
{
  return (glfwInit());
}

void	OpenGL::_glfwSwapInterval(int interval)
{
  glfwSwapInterval(interval);
}