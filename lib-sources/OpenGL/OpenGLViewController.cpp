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

GLuint	LoadShaders(const char * vertex_file_path, const char * fragment_file_path)
{
  GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  GLint Result = GL_FALSE;
  int InfoLogLength;
  std::string FragmentShaderCode;
  std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
  std::string VertexShaderCode;
  std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);

  if(VertexShaderStream.is_open())
    {
      std::string Line = "";
      while(getline(VertexShaderStream, Line))
	VertexShaderCode += "\n" + Line;
      VertexShaderStream.close();
    }
  else
      return 0;

  // Read the Fragment Shader code from the file
  if(FragmentShaderStream.is_open())
    {
      std::string Line = "";
      while(std::getline(FragmentShaderStream, Line))
	FragmentShaderCode += "\n" + Line;
      FragmentShaderStream.close();
    }


  // Compile Vertex Shader
  char const * VertexSourcePointer = VertexShaderCode.c_str();
  glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
  glCompileShader(VertexShaderID);

  // Check Vertex Shader
  glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

  if (InfoLogLength <= 0)
    {
      std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
      glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
      std::cerr <<  &VertexShaderErrorMessage[0] << std::endl;
    }
  // Compile Fragment Shader
  char const * FragmentSourcePointer = FragmentShaderCode.c_str();
  glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
  glCompileShader(FragmentShaderID);

  // Check Fragment Shader
  glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if (InfoLogLength <= 0)
    {
      std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
      glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
      std::cerr << &FragmentShaderErrorMessage[0] << std::endl;
    }

  // Link the program
  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID, VertexShaderID);
  glAttachShader(ProgramID, FragmentShaderID);
  glLinkProgram(ProgramID);

  // Check the program
  glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
  glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if (InfoLogLength <= 0)
    {
      std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
      glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
      std::cerr << &ProgramErrorMessage[0] << std::endl;
    }

  glDetachShader(ProgramID, VertexShaderID);
  glDetachShader(ProgramID, FragmentShaderID);

  glDeleteShader(VertexShaderID);
  glDeleteShader(FragmentShaderID);

  return ProgramID;
}


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
  this->programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

  glGenBuffers(1, &this->vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
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