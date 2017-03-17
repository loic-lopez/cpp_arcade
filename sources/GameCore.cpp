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

GameCore& GameCore::operator=(GameCore const &controller)
{
  if (this != &controller) {}
  return (*this);
}

void *GameCore::openLibrary(char const *libraryName)
{
  void  *file;

  file = Cencapsulation::c_dlopen(libraryName, RTLD_LAZY);
  if (!file)
    {
      std::cerr << Cencapsulation::c_dlerror() << '\n';
      exit(EXIT_FAILURE);
    }
  return (file);
}

play_function_type GameCore::getPlayFunction(void *game)
{
  IGameModel *(*play_function)(std::string const &);

  play_function = reinterpret_cast<IGameModel *(*)(std::string const &)>(Cencapsulation::c_dlsym(game, "Play"));
  if (!play_function)
    {
      std::cerr << Cencapsulation::c_dlerror() << '\n';
      exit(EXIT_FAILURE);
    }
  return (play_function);
}

void GameCore::GameLauncher()
{
  std::vector<void *> Games;
  std::vector<void *> Libs;
  IGameModel *(*play_function)(std::string const &);


  Libs.push_back(this->openLibrary(this->library_name.c_str()));
  Games.push_back(this->openLibrary("./lib/snake.so"));
  play_function = this->getPlayFunction(Games.at(0));
  IGameModel *game = play_function(this->library_name.c_str());

  game->getInputs();
  Cencapsulation::c_dlclose(Libs.at(0));
  Cencapsulation::c_dlclose(Games.at(0));
}
