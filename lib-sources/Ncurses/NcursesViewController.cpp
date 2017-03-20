//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Mon Mar 20 11:23:06 2017 Matthias Prost
//

#include "NcursesViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::~NcursesViewController()
{

}

void	NcursesViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	NcursesViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

void	NcursesViewController::loadScreen()
{
	NcursesEncap::n_initscr();
	NcursesEncap::n_refresh();
  while(1){};
	NcursesEncap::n_endwin();
}
