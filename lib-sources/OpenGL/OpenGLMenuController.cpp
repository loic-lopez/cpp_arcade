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

void	OpenGLViewController::drawMenu(size_t &currentGame,
					   std::vector<std::string> const &games,
					   bool &exit, size_t &currentLibrary,
					   ChangeCommandType &action)
{

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
    "Space to shoot (SolarFox)"
   };
/*  if ((glfwReadImage("assets/BorneArcade.png", GLFW_NO_RESCALE_BIT)) != GL_TRUE)
    std::cerr << "ERROR: cannot found BorneArcade in assets/ make sure it exist" << std::endl;*/
  action = ChangeCommandType::PLAY;
  (void)currentLibrary;
  (void)texts;
  (void)currentGame;
  (void)games;
  (void)exit;
}