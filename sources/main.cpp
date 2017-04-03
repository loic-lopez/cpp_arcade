//
// main.cpp for arcade in /Users/loiclopez/Documents/Shared/Epitech/year_2016/cpp/cpp_arcade/sources/
//
// Made by Loic Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  Mon Mar  6 10:30:47 2017 Loic Lopez
// Last update Mon Apr  3 19:20:33 2017 Matthias Prost
//

#include "Arcade.hpp"

void help()
{
  std::cerr << "USAGE: ./arcade ./lib/lib_arcade_XXX.so" << std::endl;
}

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      std::cerr << "ERROR: Invalid number of arguments" << std::endl;
      help();
      return (-1);
    }
  else
    {
      IGameCore *GCore;
      GCore = new GameCore(av[1]);
      GCore->GameLauncher();
      delete GCore;
    }
}
