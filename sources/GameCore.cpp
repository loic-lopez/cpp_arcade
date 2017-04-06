//
// GameCore.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCore.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 18:01:13 2017 Loïc Lopez
// Last update Thu Mar 30 17:46:28 2017 Matthias Prost
//

#include "GameCore.hpp"

static std::string const removeSubstrs(std::string s, std::string const &p)
{
  std::string::size_type n = p.length();
  for (std::string::size_type i = s.find(p); i != std::string::npos; i = s.find(p))
    s.erase(i, n);
  return (s);
}

GameCore::GameCore(const std::string &library_name) : library_name("./" + removeSubstrs(library_name, "./"))
{
}

GameCore::GameCore(GameCore const &controller) : library_name(controller.library_name)
{
}

GameCore	&GameCore::operator=(GameCore const &controller)
{
  if (this != &controller) {}
  return (*this);
}

void	GameCore::GameLauncher()
{
  std::vector<std::string>	Games;
  std::vector<std::string>	Libs;
  size_t			currentLib = 0;
  size_t			currentGame = 0;
  bool				exit = false;
  ChangeCommandType		action = ChangeCommandType::STANDBY;
  play_function_type		play_function;
  load_library_function_type	load_library_function;
  void				*game = NULL;
  void				*library = NULL;
  IGameModel			*GameInstance = NULL;
  ILibraryViewController	*libraryInstance = NULL;

  this->fillVector(Games, "./games");
  this->fillVector(Libs, "./lib");
  currentLib = this->getCurrentLibrary(Libs);
  while (!exit)
    {
      if (action == ChangeCommandType::STANDBY
	  || action == ChangeCommandType::NEXT_LIBRARY
	  || action == ChangeCommandType::PREV_LIBRARY)
	{
	  library = this->openLibrary(Libs.at(currentLib).c_str());
	  load_library_function = this->getLibrary(library);
	  libraryInstance = load_library_function();
	}
      if (action == ChangeCommandType::STANDBY || action == ChangeCommandType::DISPLAY_MENU)
	{
	  libraryInstance->drawMenu(currentGame, Games, exit);
	  if (exit) break;
	}
      if (action == ChangeCommandType::STANDBY
	  || action == ChangeCommandType::NEXT_GAME
	  || action == ChangeCommandType::PREV_GAME
	  || action == ChangeCommandType::DISPLAY_MENU)
	{
	  game = this->openLibrary(Games.at(currentGame).c_str());
	  play_function = this->getcreateInstanceGameFunction(game);
	  GameInstance = play_function(Libs.at(currentLib));
	}
      action = GameInstance->play(libraryInstance, currentGame, currentLib, exit);
      if (currentGame == Games.size())
        currentGame = 0;
      else if (currentGame > Games.size())
	currentGame = Games.size() - 1;
      if (currentLib == Libs.size())
        currentLib = 0;
      else if (currentLib > Libs.size())
        currentLib = Libs.size() - 1;
      if ((action == ChangeCommandType::NEXT_GAME
	  || action == ChangeCommandType::PREV_GAME
	   || action == ChangeCommandType::DISPLAY_MENU) && !exit)
        {
          delete GameInstance;
          Cencapsulation::c_dlclose(game);
	  GameInstance = NULL;
        }
      else if ((action == ChangeCommandType::NEXT_LIBRARY
	  || action == ChangeCommandType::PREV_LIBRARY) && !exit)
	{
	  delete libraryInstance;
	  Cencapsulation::c_dlclose(library);
	  libraryInstance = NULL;
	}
    }

  if (libraryInstance != NULL)
    {
      delete libraryInstance;
      Cencapsulation::c_dlclose(library);
    }
  if (GameInstance != NULL)
    {
      delete GameInstance;
      Cencapsulation::c_dlclose(game);
    }
}
