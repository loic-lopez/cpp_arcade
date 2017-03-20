//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Mon Mar 20 10:57:22 2017 Matthias Prost
//

#include "SFMLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return new SFMLViewController();
}

SFMLViewController::~SFMLViewController()
{

}

void	SFMLViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	SFMLViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

void	SFMLViewController::loadScreen()
{
}
