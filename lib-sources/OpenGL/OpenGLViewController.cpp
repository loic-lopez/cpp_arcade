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
 -1.0f,-1.0f,-1.0f,
 -1.0f,-1.0f, 1.0f,
 -1.0f, 1.0f, 1.0f,
 1.0f, 1.0f,-1.0f,
 -1.0f,-1.0f,-1.0f,
 -1.0f, 1.0f,-1.0f,
 1.0f,-1.0f, 1.0f,
 -1.0f,-1.0f,-1.0f,
 1.0f,-1.0f,-1.0f,
 1.0f, 1.0f,-1.0f,
 1.0f,-1.0f,-1.0f,
 -1.0f,-1.0f,-1.0f,
 -1.0f,-1.0f,-1.0f,
 -1.0f, 1.0f, 1.0f,
 -1.0f, 1.0f,-1.0f,
 1.0f,-1.0f, 1.0f,
 -1.0f,-1.0f, 1.0f,
 -1.0f,-1.0f,-1.0f,
 -1.0f, 1.0f, 1.0f,
 -1.0f,-1.0f, 1.0f,
 1.0f,-1.0f, 1.0f,
 1.0f, 1.0f, 1.0f,
 1.0f,-1.0f,-1.0f,
 1.0f, 1.0f,-1.0f,
 1.0f,-1.0f,-1.0f,
 1.0f, 1.0f, 1.0f,
 1.0f,-1.0f, 1.0f,
 1.0f, 1.0f, 1.0f,
 1.0f, 1.0f,-1.0f,
 -1.0f, 1.0f,-1.0f,
 1.0f, 1.0f, 1.0f,
 -1.0f, 1.0f,-1.0f,
 -1.0f, 1.0f, 1.0f,
 1.0f, 1.0f, 1.0f,
 -1.0f, 1.0f, 1.0f,
 1.0f,-1.0f, 1.0f
};

// One color for each vertex. They were generated randomly.
static const GLfloat g_color_buffer_data[] = {
 0.583f,  0.771f,  0.014f,
 0.609f,  0.115f,  0.436f,
 0.327f,  0.483f,  0.844f,
 0.822f,  0.569f,  0.201f,
 0.435f,  0.602f,  0.223f,
 0.310f,  0.747f,  0.185f,
 0.597f,  0.770f,  0.761f,
 0.559f,  0.436f,  0.730f,
 0.359f,  0.583f,  0.152f,
 0.483f,  0.596f,  0.789f,
 0.559f,  0.861f,  0.639f,
 0.195f,  0.548f,  0.859f,
 0.014f,  0.184f,  0.576f,
 0.771f,  0.328f,  0.970f,
 0.406f,  0.615f,  0.116f,
 0.676f,  0.977f,  0.133f,
 0.971f,  0.572f,  0.833f,
 0.140f,  0.616f,  0.489f,
 0.997f,  0.513f,  0.064f,
 0.945f,  0.719f,  0.592f,
 0.543f,  0.021f,  0.978f,
 0.279f,  0.317f,  0.505f,
 0.167f,  0.620f,  0.077f,
 0.347f,  0.857f,  0.137f,
 0.055f,  0.953f,  0.042f,
 0.714f,  0.505f,  0.345f,
 0.783f,  0.290f,  0.734f,
 0.722f,  0.645f,  0.174f,
 0.302f,  0.455f,  0.848f,
 0.225f,  0.587f,  0.040f,
 0.517f,  0.713f,  0.338f,
 0.053f,  0.959f,  0.120f,
 0.393f,  0.621f,  0.362f,
 0.673f,  0.211f,  0.457f,
 0.820f,  0.883f,  0.371f,
 0.982f,  0.099f,  0.879f
};

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new OpenGLViewController());
}

OpenGLViewController::OpenGLViewController()
{
  this->score = 0;
  this->camera = glm::vec3(0, -5, 10);
  this->horizontalAngle = 3.14f;
  this->verticalAngle = 0.5f;
  this->FoV = 30.0f;
  this->speed = 5.0f;
  this->lastTime = 0;
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

bool	OpenGLViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  if (this->lastTime == 0)
    this->lastTime = glfwGetTime();
  double currentTime = glfwGetTime();
  float deltaTime = float(currentTime - lastTime);

  (void)commandType;
  // Compute new orientation
  horizontalAngle += 0 * deltaTime * (1024 / 2);
  verticalAngle   += 0 * deltaTime * (768 / 2);

  // Direction : Spherical coordinates to Cartesian coordinates conversion
  glm::vec3 direction(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle),
   cos(verticalAngle) * cos(horizontalAngle));

  // Right vector
  glm::vec3 right = glm::vec3(sin(horizontalAngle - 3.14f/2.0f), 0,
   cos(horizontalAngle - 3.14f/2.0f));

  glm::vec3  up = glm::vec3(0, 1 ,0);

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
  if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS)
      this->camera += direction * deltaTime * speed;
  // Move backward
  if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS)
      this->camera -= direction * deltaTime * speed;
  // Strafe right
  if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS)
      this->camera += right * deltaTime * speed;
  // Strafe left
  if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS)
      this->camera -= right * deltaTime * speed;


  this->Projection = glm::perspective(this->FoV, 4.0f / 3.0f, 0.1f, 100.0f);
  this->View = glm::lookAt(this->camera, this->camera + direction, up);
  lastTime = currentTime;
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

  if (!(this->window = glfwCreateWindow(this->mode->width, this->mode->height, name.c_str(), NULL, NULL)))
      return (this->endScreen());

  glfwMakeContextCurrent(this->window); // Initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
    {
      std::cerr << "Failed to initialize GLEW\n" << std::endl;
      return;
    }

  glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
  // Hide the mouse and enable unlimited mouvement
  glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwPollEvents();
  glfwSetCursorPos(window, 1024/2, 768/2);

  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);

  glGenVertexArrays(1, &this->VertexArrayID);
  glBindVertexArray(this->VertexArrayID);

  this->programID =
   LoadShaders("./lib-sources/OpenGL/OpenGL-Shaders/SimpleTransform.glsl",
	       "./lib-sources/OpenGL/OpenGL-Shaders/SimpleColor.glsl");
  this->MatrixID = glGetUniformLocation(programID, "MVP");
  this->Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  this->Model      = glm::mat4(1.0f);

  glGenBuffers(1, &this->vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  glGenBuffers(1, &colorbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
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
  glDeleteBuffers(1, &this->vertexbuffer);
  glDeleteBuffers(1, &this->colorbuffer);
  glDeleteProgram(this->programID);
  glDeleteVertexArrays(1, &this->VertexArrayID);
  glfwTerminate();
}

void  OpenGLViewController::refresh()
{
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Use our shader
  glUseProgram(this->programID);

  this->MVP = this->Projection * this->View * this->Model;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &this->MVP[0][0]);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  // 2nd attribute buffer : colors
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);

  // Swap buffers
  glfwSwapBuffers(this->window);
  glfwPollEvents();
}

void	OpenGLViewController::drawSquare(int x, int y, Color const &color)
{
  (void)x;
  (void)y;
  (void)color;
}

std::string	OpenGLViewController::getLibraryName()
{
  return ("OpenGL");
}