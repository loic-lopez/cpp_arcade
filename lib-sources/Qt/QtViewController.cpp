//
// Qt.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Qt.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:40 2017 Loïc Lopez
// Last update jeu. mars 16 15:07:40 2017 Loïc Lopez
//

#include "QtViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new QtViewController());
}

QtViewController::~QtViewController()
{

}

void	QtViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	QtViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

#include <iostream>

void	QtViewController::drawMenu()
{
  std::cout << "Library LOADED" << std::endl;
}