/*
** LoadShaders.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/LoadShaders.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. mars 25 11:37:43 2017 Loïc Lopez
// Last update Sat Mar 25 14:52:57 2017 Matthias Prost
*/

#include "OpenGLViewController.hpp"

std::string	const	readFile(std::ifstream &file)
{
  std::string	ShaderCode;
  std::string Line = "";

  while(std::getline(file, Line))
    ShaderCode += "\n" + Line;
  file.close();
  return (ShaderCode);
}

void	compileShader(GLuint Shader, std::string const &ShaderCode, GLint &Result)
{
  int InfoLogLength;
  char const * VertexSourcePointer = ShaderCode.c_str();
  glShaderSource(Shader, 1, &VertexSourcePointer , NULL);
  glCompileShader(Shader);

  // Check Vertex Shader
  glGetShaderiv(Shader, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(Shader, GL_INFO_LOG_LENGTH, &InfoLogLength);

  if (InfoLogLength < 0)
    {
      std::vector<char> VertexShaderErrorMessage((unsigned long) (InfoLogLength + 1));
      glGetShaderInfoLog(Shader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
      std::cerr <<  &VertexShaderErrorMessage[0] << std::endl;
    }
}

GLuint	LoadShaders(const char	*vertex_file_path, const char 	*fragment_file_path)
{
  GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  GLint Result = GL_FALSE;
  int InfoLogLength;
  std::string FragmentShaderCode;
  std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
  std::string VertexShaderCode;
  std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);

  if(VertexShaderStream.is_open() && FragmentShaderStream.is_open())
    {
      FragmentShaderCode = readFile(FragmentShaderStream);
      VertexShaderCode = readFile(VertexShaderStream);
    }
  else
    {
      if (VertexShaderStream.is_open())
	std::cerr << "Unable to found : " << vertex_file_path << std::endl;
      else
	std::cerr << "Unable to found : " << fragment_file_path << std::endl;
      return (0);
    }

  // Compile Vertex Shader
  compileShader(VertexShaderID, VertexShaderCode, Result);

  // Compile Fragment Shader
  compileShader(FragmentShaderID, FragmentShaderCode, Result);

  // Link the program
  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID, VertexShaderID);
  glAttachShader(ProgramID, FragmentShaderID);
  glLinkProgram(ProgramID);

  // Check the program
  glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
  glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if (InfoLogLength < 0)
    {
      std::vector<char> ProgramErrorMessage((unsigned long) (InfoLogLength + 1));
      glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
      std::cerr << &ProgramErrorMessage[0] << std::endl;
    }

  glDetachShader(ProgramID, VertexShaderID);
  glDetachShader(ProgramID, FragmentShaderID);

  glDeleteShader(VertexShaderID);
  glDeleteShader(FragmentShaderID);

  return ProgramID;
}
