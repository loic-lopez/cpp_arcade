//
// OpenGL.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/OpenGL.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update Thu Mar 23 20:42:57 2017 Matthias Prost
//

#include <iostream>
#include "OpenGLViewController.hpp"

static const GLfloat g_vertex_buffer_data[] = {
 -1.0f, -1.0f, 0.0f,
 1.0f, -1.0f, 0.0f,
 0.0f,  1.0f, 0.0f,
};


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
  if (glfwWindowShouldClose(this->window)
      || glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(this->window, GL_TRUE);
      exit = true;
      return (false);
    }
  else if (glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS)
      action = ILibraryViewController::Key::NEXT_GAME;
  else if (glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
      action = ILibraryViewController::Key::PREV_GAME;

  return (true);
}

void	OpenGLViewController::initScreen(std::string const &name)
{
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  this->mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  /* Create a windowed mode window and its OpenGL context */
  if (!(this->window = glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());

  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental=true; // Needed in core profile
  if (glewInit() != GLEW_OK)
    {
      std::cerr << "Failed to initialize GLEW\n" << std::endl;
      return;
    }

  glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  glGenVertexArrays(1, &this->VertexArrayID);
  glBindVertexArray(this->VertexArrayID);


  // Create and compile our GLSL program from the shaders
  this->programID =
   LoadShaders("./lib-sources/OpenGL/OpenGL-Shaders/SimpleVertexShader.glsl",
	       "./lib-sources/OpenGL/OpenGL-Shaders/SimpleFragmentShader.glsl");

  glGenBuffers(1, &this->vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
	       g_vertex_buffer_data, GL_STATIC_DRAW);
}

void	OpenGLViewController::displayText(std::string const &Game, std::string const &libraryName) const
{
  (void)Game;
  (void)libraryName;
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
  // Cleanup VBO
  glDeleteBuffers(1, &this->vertexbuffer);
  glDeleteVertexArrays(1, &this->VertexArrayID);
  glDeleteProgram(this->programID);
  glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  glClear( GL_COLOR_BUFFER_BIT );

  // Use our shader
  glUseProgram(this->programID);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
  glVertexAttribPointer(
   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
   3,                  // size
   GL_FLOAT,           // type
   GL_FALSE,           // normalized?
   0,                  // stride
   (void*)0            // array buffer offset
  );

  // Draw the triangle !
  glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

  glDisableVertexAttribArray(0);

  // Swap buffers
  glfwSwapBuffers(this->window);
  glfwPollEvents();
}

void	OpenGLViewController::drawMap(int mapsize_x, int mapsize_y)
{
  (void)mapsize_x;
  (void)mapsize_y;
}

std::string	OpenGLViewController::getLibraryName()
{
  return ("OpenGL");
}