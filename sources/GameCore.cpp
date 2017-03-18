//
// GameCore.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCore.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 18:01:13 2017 Loïc Lopez
// Last update Fri Mar 17 18:47:35 2017 Matthias Prost
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

void	*GameCore::openLibrary(char const *libraryName)
{
  void	*file;

  file = Cencapsulation::c_dlopen(libraryName, RTLD_LAZY);
  if (!file)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (file);
}

load_library_function_type	GameCore::getLibrary(void *library)
{
  load_library_function_type	play_function;

  play_function = reinterpret_cast<load_library_function_type>(Cencapsulation::c_dlsym(library, "loadLibrary"));
  if (!play_function)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (play_function);
}

play_function_type	GameCore::getPlayFunction(void *game)
{
  play_function_type	play_function;

  play_function = reinterpret_cast<play_function_type>(Cencapsulation::c_dlsym(game, "Play"));
  if (!play_function)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (play_function);
}

void	GameCore::GameLauncher()
{
  std::vector<std::string>	Games;
  std::vector<std::string>	Libs;
  play_function_type	play_function;
  load_library_function_type	load_library_function;
  void	*game;
  void	*library;


  Libs.push_back(this->library_name.c_str());
  Games.push_back("./games/snake.so");
  DIR   *dirp;
  struct dirent *entry;

  if ((dirp = Cencapsulation::c_opendir("./games")) == NULL)
    {
      std::cerr << "[ERROR] : opendir problem\n" << std::endl;
      exit(EXIT_FAILURE);
    }
  while ((entry = Cencapsulation::c_readdir(dirp)) != NULL)
    {
      if (entry == NULL)
	exit(EXIT_FAILURE);
      if (entry->d_name[0] != '.' && Cencapsulation::c_strstr(entry->d_name, ".so") != NULL)
	{
	  // la il faut push dans les vectors
	}
    }
  Cencapsulation::c_closedir(dirp);


  play_function = this->getPlayFunction(Games.at(0));
  load_library_function = this->getLibrary(Libs.at(0));

  IGameModel *GameInstance = play_function(this->library_name.c_str());
  ILibraryViewController *libraryInstance = load_library_function();

  GameInstance->getInputs();
  libraryInstance->drawMenu();
  delete game;
  delete library;
  Cencapsulation::c_dlclose(Libs.at(0));
  Cencapsulation::c_dlclose(Games.at(0));
}
