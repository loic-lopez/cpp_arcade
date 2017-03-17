//
// GameCore.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCore.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 18:01:13 2017 Loïc Lopez
// Last update Fri Mar 17 17:38:12 2017 Matthias Prost
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

void GameCore::GameLauncher()
{
  IAssistant *(*external_func)(); // Pointer of function of funcName
  void *handle;

  if (libName.empty() || funcName.empty())
    return (-1);
  handle = dlopen(libName.c_str(), RTLD_LAZY);
  if (!handle)
    {
      dlerror();
      return (-1);
    }
  external_func = reinterpret_cast<IAssistant *(*)()>(dlsym(handle, funcName.c_str()));
  if (!external_func)
    {
      dlerror();
      return (-1);
    }
  IAssistant *bob = external_func();
  bob->talk() // Call the function talk()
  dlclose(handle);
  return (0);
}
