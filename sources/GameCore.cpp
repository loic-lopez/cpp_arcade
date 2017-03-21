//
// GameCore.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCore.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 18:01:13 2017 Loïc Lopez
// Last update Mon Mar 20 10:41:32 2017 Matthias Prost
//

#include "GameCore.hpp"

GameCore::GameCore(const std::string &library_name) : library_name(library_name)
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
  size_t	currentLib;
  size_t	currentGame;
  bool	exit;
  play_function_type	play_function;
  load_library_function_type	load_library_function;
  void	*game;
  void	*library;
  IGameModel *GameInstance;
  ILibraryViewController *libraryInstance;

  this->fillVector(Games, "./games");
  this->fillVector(Libs, "./lib");
  currentLib = this->getCurrentLibrary(Libs);
  currentGame = 0;
  exit = false;
  while (!exit)
    {
      if (currentGame == Games.size())
	currentGame = 0;
      if (currentLib == Libs.size())
	currentLib = 0;
      game = this->openLibrary(Games.at(currentGame).c_str());
      library = this->openLibrary(Libs.at(currentLib).c_str());
      play_function = this->getPlayFunction(game);
      load_library_function = this->getLibrary(library);
      GameInstance = play_function(this->library_name.c_str());
      libraryInstance = load_library_function();
      GameInstance->getInputs();
      libraryInstance->loadScreen();
      exit = true;
    }

  delete GameInstance;
  delete libraryInstance;
  Cencapsulation::c_dlclose(game);
  Cencapsulation::c_dlclose(library);
}
