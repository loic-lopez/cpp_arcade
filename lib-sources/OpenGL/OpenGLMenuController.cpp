/*
** OpenGLMenuController.cpp for cpp_arcade in /home/jabbar_y/delivery/cpp_arcade/OpenGLMenuController.cpp
**
** Made by Yassir Jabbari
** Login   <yassir.jabbari@epitech.eu>
**
** Started on  Sat Apr 08 14:18:04 2017	Yassir Jabbari
** Last update Sat Apr 08 14:18:04 2017	Yassir Jabbari
*/

#include "OpenGLViewController.hpp"

std::string keys = "";

static	void 	printMenu(const char *texts[], float  &startY)
{
  startY = 0.85f;
  for (size_t i = 0; i < 14; ++i)
    {
      print(-0.85f, startY, texts[i]);
      startY -= 0.05f;
    }
}

static void	printChoices(const char *choices[], int r[], int g[], int b[])
{
  float startY = 0.5f;
  for (int i = 0; i < 3; ++i)
    {
      OpenGL::_glPushAttrib( GL_CURRENT_BIT );
      glColor3ub(r[i], b[i], g[i]);
      print(-0.00f, startY, choices[i]);
      startY -= 0.05f;
      glPopAttrib();
    }
}

void	character_callback(GLFWwindow* window, unsigned int codepoint)
{
  static_cast<void>(window);
  keys += static_cast<char>(codepoint);
}

void	OpenGLViewController::drawMenu(size_t &currentGame,
					   std::vector<std::string> const &games,
					   bool &exit, size_t &currentLibrary,
					   ChangeCommandType &action, std::string &playerName)
{
  const	char 	*ItemStrings[] =
   {
    "Snake",
    "SolarFox",
    "Exit"
   };
  const	char	*texts[] =
   {
    "Move the cursor menu to select a game.",
    "Press enter to choose a game.",
    "In Game :",
    "Key 2 : move to previous graphical library.",
    "Key 3 : move to next graphical library.",
    "Key 4 : move to previous game.",
    "Key 5 : move to next game.",
    "Key 8 : restart the game.",
    "Key 9 : display this menu.",
    "Key Escape : quit the game or menu.",
    "Move character with arrows.",
    "Space to shoot (SolarFox)",
    "\n",
    "Player Name: "
   };
  int	index = 0;
  bool _exit = false;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  long long int elapsed_milliseconds;
  int 	r[3];
  int 	g[3];
  int 	b[3];
  float	startY = 0.85f;

  keys = playerName;
  this->initScreen("OpenGL", "");
  OpenGL::_glfwSetClipboardString(this->window, "");
  r[0] = 0;
  b[0] = 255;
  g[0] = 255;
  for (int i = 1; i < 3; ++i)
    {
      r[i] = 255;
      b[i] = 255;
      g[i] = 255;
    }
  start = std::chrono::system_clock::now();
  while (!_exit)
    {
      end = std::chrono::system_clock::now();
      elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
      printChoices(ItemStrings, r, g ,b);
      printMenu(texts, startY);
      print(-0.85f, startY, keys);
      if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(this->window))
	_exit = true;
      else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS)
	{
	  this->endScreen();
	  action = ChangeCommandType::NEXT_LIBRARY;
	  currentLibrary++;
	  return;
	}
      else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
    	{
	  this->endScreen();
	  action = ChangeCommandType::PREV_LIBRARY;
	  currentLibrary--;
	  return;
    	}
      else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS && elapsed_milliseconds > 200)
	{
	  if (index - 1 >= 0)
	    {
	      r[index] = 255;
	      b[index] = 255;
	      g[index] = 255;
	      index--;
	      r[index] = 0;
	      b[index] = 255;
	      g[index] = 255;
	    }
	  start = end;
	}
      else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_DOWN) == GLFW_PRESS && elapsed_milliseconds > 200)
	{
	  if (index + 1 < 3)
	    {
	      r[index] = 255;
	      b[index] = 255;
	      g[index] = 255;
	      index++;
	      r[index] = 0;
	      b[index] = 255;
	      g[index] = 255;
	    }
	  start = end;
	}
      else if (OpenGL::_glfwGetKey(this->window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
	  playerName = keys;
	  action = ChangeCommandType::PLAY;
	  std::string 	currentText = ItemStrings[index];
	  std::transform(currentText.begin(), currentText.end(),
			 currentText.begin(), ::tolower);
	  if (currentText == "exit")
	    {
	      exit = true;
	      this->endScreen();
	      return;
	    }
	  for (index = 0; index < static_cast<int>(games.size()); ++index)
	    {
	      if (games.at(index).find(currentText) != std::string::npos)
		{
		  currentGame = static_cast<size_t >(index);
		  this->endScreen();
		  return;
		}
	    }
	  if (index == static_cast<int>(games.size()))
	    {
	      exit = true;
	      this->endScreen();
	      return;
	    }
	}
      if ((OpenGL::_glfwGetKey(this->window, GLFW_KEY_BACKSPACE) == GLFW_PRESS
	       || glfwGetKey(this->window, GLFW_KEY_DELETE) == GLFW_PRESS)
	  && elapsed_milliseconds > 200 && keys.size() > 0)
	{
	  keys.pop_back();
	  start = end;
	}
      OpenGL::_glfwSetCharCallback(this->window, character_callback);
      this->refresh();
    }
  exit = _exit;
  this->endScreen();
}