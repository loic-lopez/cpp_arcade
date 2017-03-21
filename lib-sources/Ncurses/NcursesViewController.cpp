//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Tue Mar 21 19:01:15 2017 Matthias Prost
//

#include "NcursesViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::NcursesViewController()
{

}

NcursesViewController::~NcursesViewController()
{

}

void NcursesViewController::drawMenu()
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
  int     key;

	NcursesEncap::n_newterm();
  NcursesEncap::n_curs_set();
  NcursesEncap::n_noecho();
  NcursesEncap::n_nodelay();
  NcursesEncap::n_keypad();
  while(key != 27)
  {
    NcursesEncap::n_mvprintw(1, 1, "Ncurse");
    NcursesEncap::n_refresh();
    key = NcursesEncap::n_getch();
  }
	NcursesEncap::n_endwin();
}
