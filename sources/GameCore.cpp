//
// GameCore.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCore.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 18:01:13 2017 Loïc Lopez
// Last update Thu Mar 23 19:48:21 2017 Matthias Prost
//

#include "GameCore.hpp"

static std::string const removeSubstrs(std::string s, std::string const &p)
{
  std::string::size_type n = p.length();
  for (std::string::size_type i = s.find(p);
       i != std::string::npos;
       i = s.find(p))
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
  bool				created = false;
  play_function_type		play_function;
  load_library_function_type	load_library_function;
  void				*game = NULL;
  void				*library = NULL;
  IGameModel			*GameInstance;
  ILibraryViewController	*libraryInstance;

  this->fillVector(Games, "./games");
  this->fillVector(Libs, "./lib");
  currentLib = this->getCurrentLibrary(Libs);
  while (!exit)
    {
      if (currentGame == Games.size())
	currentGame = 0;
      if (currentLib == Libs.size())
	currentLib = 0;
      if (currentLib > Libs.size())
        currentLib = Libs.size() - 1;
      game = this->openLibrary(Games.at(currentGame).c_str());
      library = this->openLibrary(Libs.at(currentLib).c_str());
      play_function = this->getcreateInstanceGameFunction(game);
      load_library_function = this->getLibrary(library);
      if (!created)
	      GameInstance = play_function(Libs.at(currentLib));
      libraryInstance = load_library_function();
      created = GameInstance->play(libraryInstance, currentGame, currentLib, exit);
      delete libraryInstance;
      Cencapsulation::c_dlclose(library);
    }

  delete GameInstance;
  Cencapsulation::c_dlclose(game);
}
